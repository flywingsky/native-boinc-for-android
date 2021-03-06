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
public class GlobalPreferencesParser extends BaseParser {
	private static final String TAG = "GlobalPreferencesParser";
	
	private GlobalPreferences mPreferences = null;
	
	public GlobalPreferences getGlobalPreferences() {
		return mPreferences;
	}
	
	public static GlobalPreferences parse(String rpcResult) {
		try {
			GlobalPreferencesParser parser = new GlobalPreferencesParser();
			Xml.parse(rpcResult, parser);
			return parser.getGlobalPreferences();
		} catch (SAXException e) {
			if (Logging.DEBUG) Log.d(TAG, "Malformed XML:\n" + rpcResult);
			else if (Logging.INFO) Log.i(TAG, "Malformed XML");
			return null;
		}
	}
	
	@Override
	public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
		super.startElement(uri, localName, qName, attributes);
		if (localName.equalsIgnoreCase("global_preferences")) {
			if (Logging.INFO) { 
				if (mPreferences!= null) {
					// previous <global_preferences> not closed - dropping it!
					Log.i(TAG, "Dropping unfinished <global_preferences> data");
				}
			}
			mPreferences = new GlobalPreferences();
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
			if (mPreferences != null) {
				// we are inside <global_preferences>
				if (localName.equalsIgnoreCase("global_preferences")) {
					// Closing tag of <global_preferences> - nothing to do at the moment
				}
				else {
					// Not the closing tag - we decode possible inner tags
					trimEnd();
					if (localName.equalsIgnoreCase("run_on_batteries")) {
						mPreferences.run_on_batteries = Integer.parseInt(mCurrentElement.toString()) != 0;
					} else if (localName.equalsIgnoreCase("run_gpu_if_user_active")) {
						mPreferences.run_gpu_if_user_active = Integer.parseInt(mCurrentElement.toString()) != 0;
					} else if (localName.equalsIgnoreCase("run_if_user_active")) {
						mPreferences.run_if_user_active = Integer.parseInt(mCurrentElement.toString()) != 0;
					} else if (localName.equalsIgnoreCase("idle_time_to_run")) {
						mPreferences.idle_time_to_run = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("suspend_cpu_usage")) {
						mPreferences.suspend_cpu_usage = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("leave_apps_in_memory")) {
						mPreferences.leave_apps_in_memory = Integer.parseInt(mCurrentElement.toString()) != 0;
					} else if (localName.equalsIgnoreCase("dont_verify_images")) {
						mPreferences.dont_verify_images = Integer.parseInt(mCurrentElement.toString()) != 0;
					} else if (localName.equalsIgnoreCase("work_buf_min_days")) {
						mPreferences.work_buf_min_days = Double.parseDouble(mCurrentElement.toString());
						if (mPreferences.work_buf_min_days < 0.00001)
							mPreferences.work_buf_min_days = 0.00001;
					} else if (localName.equalsIgnoreCase("work_buf_additional_days")) {
						mPreferences.work_buf_additional_days = Double.parseDouble(mCurrentElement.toString());
						if (mPreferences.work_buf_additional_days < 0.0)
							mPreferences.work_buf_additional_days = 0.0;
					} else if (localName.equalsIgnoreCase("max_ncpus_pct")) {
						mPreferences.max_ncpus_pct = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("cpu_scheduling_period_minutes")) {
						mPreferences.cpu_scheduling_period_minutes = Double.parseDouble(mCurrentElement.toString());
						if (mPreferences.cpu_scheduling_period_minutes < 0.00001)
							mPreferences.cpu_scheduling_period_minutes = 60;
					} else if (localName.equalsIgnoreCase("disk_interval")) {
						mPreferences.disk_interval = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("disk_max_used_gb")) {
						mPreferences.disk_max_used_gb = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("disk_max_used_pct")) {
						mPreferences.disk_max_used_pct = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("disk_min_free_gb")) {
						mPreferences.disk_min_free_gb = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("ram_max_used_busy_pct")) {
						mPreferences.ram_max_used_busy_frac = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("ram_max_used_idle_pct")) {
						mPreferences.ram_max_used_idle_frac = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("max_bytes_sec_up")) {
						mPreferences.max_bytes_sec_up = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("max_bytes_sec_down")) {
						mPreferences.max_bytes_sec_down = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("cpu_usage_limit")) {
						mPreferences.cpu_usage_limit = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("daily_xfer_limit_mb")) {
						mPreferences.daily_xfer_limit_mb = Double.parseDouble(mCurrentElement.toString());
					} else if (localName.equalsIgnoreCase("daily_xfer_period_days")) {
						mPreferences.daily_xfer_period_days = Integer.parseInt(mCurrentElement.toString());
					}
				}
			}
		} catch (NumberFormatException e) {
			if (Logging.INFO) Log.i(TAG, "Exception when decoding " + localName);
		}
		mElementStarted = false;
	}
}
