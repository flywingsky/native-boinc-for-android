// This file is part of BOINC.
// http://boinc.berkeley.edu
// Copyright (C) 2008 University of California
//
// BOINC is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// BOINC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with BOINC.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _VIEWWORKGRID_H_
#define _VIEWWORKGRID_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "ViewWorkGrid.cpp"
#endif

// Set to TRUE to prevent mutliple selections
#define PREVENT_MULTIPLE_TASK_SELECTIONS FALSE

#include "BOINCBaseView.h"
#include "BOINCGridCtrl.h"

class CViewWorkGrid : public CBOINCBaseView
{
    DECLARE_DYNAMIC_CLASS( CViewWorkGrid )
    DECLARE_EVENT_TABLE()
	
public:
    CViewWorkGrid();
    CViewWorkGrid(wxNotebook* pNotebook);

    ~CViewWorkGrid();

    virtual wxString&       GetViewName();
    virtual wxString&       GetViewDisplayName();
    virtual const char**    GetViewIcon();

    virtual wxInt32         GetDocCount();

    void                    OnWorkSuspend( wxCommandEvent& event );
    void                    OnWorkShowGraphics( wxCommandEvent& event );
    void                    OnWorkAbort( wxCommandEvent& event );

    void                    OnProjectWebsiteClicked( wxEvent& event );

protected:
#if PREVENT_MULTIPLE_TASK_SELECTIONS
    virtual void            OnCellLeftClick( wxGridEvent& event );
    virtual void            OnGridSelectRange( wxGridRangeSelectEvent& event );
#endif
    virtual void            UpdateSelection();

    virtual bool            OnSaveState( wxConfigBase* pConfig );
    virtual bool            OnRestoreState( wxConfigBase* pConfig );
    virtual void            OnListRender( wxTimerEvent& event );	

    wxInt32                 FormatProjectName( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatApplicationName( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatName( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatCPUTime( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatProgress( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatTimeToCompletion( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatReportDeadline( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatStatus( wxInt32 item, wxString& strBuffer ) const;
    wxInt32                 FormatProjectURL( wxInt32 item, wxString& strBuffer ) const;

    void                    UpdateWebsiteSelection(long lControlGroup, PROJECT* project);
	
	CBOINCGridCtrl*			m_pGridPane;
};


#endif

