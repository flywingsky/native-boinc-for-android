/* 
 * NativeBOINC - Native BOINC Client with Manager
 * Copyright (C) 2011, Mateusz Szpakowski
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

package edu.berkeley.boinc.lite;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;

import sk.boinc.nativeboinc.debug.Logging;
import android.util.Log;
import android.util.Xml;

/**
 * @author mat
 *
 */
public class AccountMgrRPCReplyParser extends BaseParser {
	private static final String TAG = "AccountMgrRPCReplyParser";

	private AccountMgrRPCReply mPAR;
	
	public AccountMgrRPCReply getAccountMgrRPCReply() {
		return mPAR;
	}
	
	public static AccountMgrRPCReply parse(String rpcResult) {
		try {
			AccountMgrRPCReplyParser parser = new AccountMgrRPCReplyParser();
			Xml.parse(rpcResult, parser);
			return parser.getAccountMgrRPCReply();
		} catch (SAXException e) {
			if (Logging.DEBUG) Log.d(TAG, "Malformed XML:\n" + rpcResult);
			else if (Logging.INFO) Log.i(TAG, "Malformed XML");
			return null;
		}
	}
	
	@Override
	public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
		super.startElement(uri, localName, qName, attributes);
		if (localName.equalsIgnoreCase("acct_mgr_rpc_reply")) {
			if (Logging.INFO) { 
				if (mPAR != null) {
					// previous <acct_mgr_rpc_reply> not closed - dropping it!
					Log.i(TAG, "Dropping unfinished <acct_mgr_rpc_reply> data");
				}
			}
			mPAR = new AccountMgrRPCReply();
		}
		else {
			// Another element, hopefully primitive and not constructor
			// (although unknown constructor does not hurt, because there will be primitive start anyway)
			mElementStarted = true;
			mCurrentElement.setLength(0);
		}
	}
	
	@Override
	public void endElement(String uri, String localName, String qName) throws SAXException {
		super.endElement(uri, localName, qName);
		try {
			if (mPAR != null) {
				// we are inside <acct_mgr_rpc_reply>
				if (localName.equalsIgnoreCase("acct_mgr_rpc_reply")) {
					// Closing tag of <acct_mgr_rpc_reply> - nothing to do at the moment
				}
				else {
					// Not the closing tag - we decode possible inner tags
					trimEnd();
					if (localName.equalsIgnoreCase("error_num")) {
						mPAR.error_num = Integer.parseInt(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("message")) {
						mPAR.messages.add(mCurrentElement.toString());
					}
				}
			}
		} catch (NumberFormatException e) {
			if (Logging.INFO) Log.i(TAG, "Exception when decoding " + localName);
		}
		mElementStarted = false;
	}
}
