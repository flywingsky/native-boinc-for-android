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

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "AdvancedFrame.h"
#endif

#ifdef __APPLE__
#include "mac/MacGUI.pch"
#endif

#include "stdwx.h"
#include "version.h"
#include "diagnostics.h"
#include "str_util.h"
#include "mfile.h"
#include "miofile.h"
#include "parse.h"
#include "BOINCGUIApp.h"
#include "Events.h"
#include "SkinManager.h"
#include "MainDocument.h"
#include "BOINCBaseFrame.h"
#include "BOINCBaseView.h"
#include "BOINCTaskBar.h"
#include "BOINCDialupManager.h"
#include "AdvancedFrame.h"
#include "ViewProjects.h"
#include "ViewWork.h"
#include "ViewTransfers.h"
#include "ViewMessages.h"
#include "ViewStatistics.h"
#include "ViewResources.h"
#include "DlgAbout.h"
#include "DlgOptions.h"
#include "DlgSelectComputer.h"
#include "DlgGenericMessage.h"
#include "wizardex.h"
#include "BOINCWizards.h"
#include "BOINCBaseWizard.h"
#include "WizardAttachProject.h"
#include "DlgAdvPreferences.h"

#include "res/connect.xpm"
#include "res/disconnect.xpm"


enum STATUSBARFIELDS {
    STATUS_TEXT,
    STATUS_CONNECTION_STATUS
};


IMPLEMENT_DYNAMIC_CLASS(CStatusBar, wxStatusBar)

BEGIN_EVENT_TABLE(CStatusBar, wxStatusBar)
    EVT_SIZE(CStatusBar::OnSize)
END_EVENT_TABLE()


CStatusBar::CStatusBar() {
    wxLogTrace(wxT("Function Start/End"), wxT("CStatusBar::CStatusBar - Default Constructor Function Begin"));
    wxLogTrace(wxT("Function Start/End"), wxT("CStatusBar::CStatusBar - Default Constructor Function End"));
}


CStatusBar::CStatusBar(wxWindow *parent) :
    wxStatusBar(parent, ID_STATUSBAR, wxST_SIZEGRIP, _T("statusBar"))
{
    wxLogTrace(wxT("Function Start/End"), wxT("CStatusBar::CStatusBar - Function Begin"));

    const int widths[] = {-1, 300, 20};
    SetFieldsCount(WXSIZEOF(widths), widths);

    m_pbmpConnected = new wxStaticBitmap(this, -1, wxIcon(connect_xpm));
    wxASSERT(m_pbmpConnected);
    m_pbmpConnected->Hide();

    m_ptxtConnected = new wxStaticText(this, -1, _("Connected"), wxPoint(0, 0), wxDefaultSize, wxALIGN_LEFT);
    wxASSERT(m_ptxtConnected);
    m_ptxtConnected->Hide();

    m_pbmpDisconnect = new wxStaticBitmap(this, -1, wxIcon(disconnect_xpm));
    wxASSERT(m_pbmpDisconnect);
    m_pbmpDisconnect->Hide();

    m_ptxtDisconnect = new wxStaticText(this, -1, _("Disconnected"), wxPoint(0, 0), wxDefaultSize, wxALIGN_LEFT);
    wxASSERT(m_ptxtDisconnect);
    m_ptxtDisconnect->Hide();

    wxSizeEvent evt;
    AddPendingEvent(evt);

    wxLogTrace(wxT("Function Start/End"), wxT("CStatusBar::CStatusBar - Function End"));
}


CStatusBar::~CStatusBar()
{

}


void CStatusBar::OnSize(wxSizeEvent& event) {
    wxLogTrace(wxT("Function Start/End"), wxT("CStatusBar::OnSize - Function Begin"));

    if (IsShown()) {
        wxRect rect;
        wxSize size;

        GetFieldRect(STATUS_CONNECTION_STATUS, rect);

        if (m_pbmpConnected) {
            size = m_pbmpConnected->GetSize();
            m_pbmpConnected->Move(rect.x + 1,
                                  rect.y + (rect.height - size.y) / 2);
        }

        if (m_ptxtConnected) {
            m_ptxtConnected->Move((rect.x + size.x) + 2,
                                  (rect.y + (rect.height - size.y) / 2) + 1);
        }

        if (m_pbmpDisconnect) {
            size = m_pbmpConnected->GetSize();
            m_pbmpDisconnect->Move(rect.x + 1,
                                   rect.y + (rect.height - size.y) / 2);
        }

        if (m_ptxtDisconnect) {
            m_ptxtDisconnect->Move((rect.x + size.x) + 2,
                                   (rect.y + (rect.height - size.y) / 2) + 1);
        }
    }

    event.Skip();

    wxLogTrace(wxT("Function Start/End"), wxT("CStatusBar::OnSize - Function End"));
}


IMPLEMENT_DYNAMIC_CLASS(CAdvancedFrame, CBOINCBaseFrame)

BEGIN_EVENT_TABLE (CAdvancedFrame, CBOINCBaseFrame)
    // View
    EVT_MENU_RANGE(ID_ADVPROJECTSVIEW, ID_ADVNEWSVIEW, CAdvancedFrame::OnChangeView)
    EVT_MENU(ID_CHANGEGUI, CAdvancedFrame::OnChangeGUI)
    // Tools
    EVT_MENU(ID_WIZARDATTACH, CAdvancedFrame::OnWizardAttach)
    EVT_MENU(ID_WIZARDUPDATE, CAdvancedFrame::OnWizardUpdate)
    EVT_MENU(ID_WIZARDDETACH, CAdvancedFrame::OnWizardDetach)
    // Activity
    EVT_MENU_RANGE(ID_ADVACTIVITYRUNALWAYS, ID_ADVACTIVITYSUSPEND, CAdvancedFrame::OnActivitySelection)
    EVT_MENU_RANGE(ID_ADVACTIVITYGPUALWAYS, ID_ADVACTIVITYGPUSUSPEND, CAdvancedFrame::OnGPUSelection)
    EVT_MENU_RANGE(ID_ADVNETWORKRUNALWAYS, ID_ADVNETWORKSUSPEND, CAdvancedFrame::OnNetworkSelection)
    // Advanced
    EVT_MENU(ID_OPTIONS, CAdvancedFrame::OnOptions)
	EVT_MENU(ID_PREFERENCES, CAdvancedFrame::OnPreferences)
    EVT_MENU(ID_SELECTCOMPUTER, CAdvancedFrame::OnSelectComputer)
    EVT_MENU(ID_SHUTDOWNCORECLIENT, CAdvancedFrame::OnClientShutdown)
    EVT_MENU(ID_RUNBENCHMARKS, CAdvancedFrame::OnRunBenchmarks)
    EVT_MENU(ID_RETRYCOMMUNICATIONS, CAdvancedFrame::OnRetryCommunications)
	EVT_MENU(ID_READPREFERENCES, CAdvancedFrame::OnReadPreferences)
	EVT_MENU(ID_READCONFIG, CAdvancedFrame::OnReadConfig)
    // Help
    EVT_MENU(ID_HELPBOINC, CAdvancedFrame::OnHelpBOINC)
    EVT_MENU(ID_HELPBOINCMANAGER, CAdvancedFrame::OnHelpBOINC)
    EVT_MENU(ID_HELPBOINCWEBSITE, CAdvancedFrame::OnHelpBOINC)
    EVT_MENU(wxID_ABOUT, CAdvancedFrame::OnHelpAbout)
    EVT_HELP(wxID_ANY, CAdvancedFrame::OnHelp)
    // Custom Events & Timers
    EVT_FRAME_CONNECT(CAdvancedFrame::OnConnect)
    EVT_FRAME_UPDATESTATUS(CAdvancedFrame::OnUpdateStatus)
    EVT_TIMER(ID_REFRESHSTATETIMER, CAdvancedFrame::OnRefreshState)
    EVT_TIMER(ID_FRAMERENDERTIMER, CAdvancedFrame::OnFrameRender)
    EVT_NOTEBOOK_PAGE_CHANGED(ID_FRAMENOTEBOOK, CAdvancedFrame::OnNotebookSelectionChanged)
END_EVENT_TABLE ()


CAdvancedFrame::CAdvancedFrame() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CAdvancedFrame - Default Constructor Function Begin"));
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CAdvancedFrame - Default Constructor Function End"));
}


CAdvancedFrame::CAdvancedFrame(wxString title, wxIcon* icon, wxIcon* icon32, wxPoint position, wxSize size) : 
    CBOINCBaseFrame((wxFrame *)NULL, ID_ADVANCEDFRAME, title, position, size, wxDEFAULT_FRAME_STYLE)
{
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CAdvancedFrame - Function Begin"));
    
    m_pMenubar = NULL;
    m_pNotebook = NULL;
    m_pStatusbar = NULL;

    // Working Variables
    m_strBaseTitle = title;

    // Initialize Application
    wxIconBundle icons;
    icons.AddIcon(*icon);
    icons.AddIcon(*icon32);
    SetIcons(icons);

    // Create UI elements
    wxCHECK_RET(CreateMenu(), _T("Failed to create menu bar."));
    wxCHECK_RET(CreateNotebook(), _T("Failed to create notebook."));
    wxCHECK_RET(CreateStatusbar(), _T("Failed to create status bar."));

    RestoreState();

    m_pRefreshStateTimer = new wxTimer(this, ID_REFRESHSTATETIMER);
    wxASSERT(m_pRefreshStateTimer);
#ifdef __WXMAC__
    m_pRefreshStateTimer->Start(300000);            // Send event every 5 minutes
#else
    m_pRefreshStateTimer->Start(5000);              // Send event every 5 seconds
#endif

    m_pFrameRenderTimer = new wxTimer(this, ID_FRAMERENDERTIMER);
    wxASSERT(m_pFrameRenderTimer);
    m_pFrameRenderTimer->Start(1000);               // Send event every 1 second


    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CAdvancedFrame - Function End"));
}


CAdvancedFrame::~CAdvancedFrame() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::~CAdvancedFrame - Function Begin"));

    wxASSERT(m_pRefreshStateTimer);
    wxASSERT(m_pFrameRenderTimer);
    wxASSERT(m_pMenubar);
    wxASSERT(m_pNotebook);
    wxASSERT(m_pStatusbar);

    SaveState();

    if (m_pRefreshStateTimer) {
        m_pRefreshStateTimer->Stop();
        delete m_pRefreshStateTimer;
        m_pRefreshStateTimer = NULL;
    }

    if (m_pFrameRenderTimer) {
        m_pFrameRenderTimer->Stop();
        delete m_pFrameRenderTimer;
        m_pFrameRenderTimer = NULL;
    }

    if (m_pStatusbar)
        wxCHECK_RET(DeleteStatusbar(), _T("Failed to delete status bar."));

    if (m_pNotebook)
        wxCHECK_RET(DeleteNotebook(), _T("Failed to delete notebook."));

    if (m_pMenubar)
        wxCHECK_RET(DeleteMenu(), _T("Failed to delete menu bar."));

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::~CAdvancedFrame - Function End"));
}


bool CAdvancedFrame::CreateMenu() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CreateMenu - Function Begin"));

    CMainDocument*     pDoc = wxGetApp().GetDocument();
    CSkinAdvanced*     pSkinAdvanced = wxGetApp().GetSkinManager()->GetAdvanced();
    ACCT_MGR_INFO      ami;
    bool               is_acct_mgr_detected = false;
    wxString           strMenuName;
    wxString           strMenuDescription;
    
    wxASSERT(pDoc);
    wxASSERT(pSkinAdvanced);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));
    wxASSERT(wxDynamicCast(pSkinAdvanced, CSkinAdvanced));

    // Account managers have a different menu arrangement
    if (pDoc->IsConnected()) {
        pDoc->rpc.acct_mgr_info(ami);
        is_acct_mgr_detected = ami.acct_mgr_url.size() ? true : false;
    }

    // File menu
    wxMenu *menuFile = new wxMenu;

    // %s is the application name
    //    i.e. 'BOINC Manager', 'GridRepublic Manager'
    strMenuDescription.Printf(
        _("Close the %s window"), 
        pSkinAdvanced->GetApplicationName().c_str()
    );
    strMenuName = _("&Close Window");
    strMenuName += wxT("\tCtrl+W");
    menuFile->Append(
        ID_CLOSEWINDOW,
        strMenuName,
        strMenuDescription
    );

    // %s is the application name
    //    i.e. 'BOINC Manager', 'GridRepublic Manager'
    strMenuDescription.Printf(
        _("Exit %s"), 
        pSkinAdvanced->GetApplicationName().c_str()
    );
    menuFile->Append(
        wxID_EXIT,
        _("E&xit"),
        strMenuDescription
    );

    // View menu
    wxMenu *menuView = new wxMenu;

    menuView->Append(
        ID_ADVPROJECTSVIEW,
        _("&Projects\tCtrl+Shift+P"),
        _("Display projects")
    );

    menuView->Append(
        ID_ADVTASKSVIEW,
        _("&Tasks\tCtrl+Shift+T"),
        _("Display tasks")
    );

    menuView->Append(
        ID_ADVTRANSFERSVIEW,
        _("Trans&fers\tCtrl+Shift+X"),
        _("Display transfers")
    );

    menuView->Append(
        ID_ADVMESSAGESVIEW,
        _("&Messages\tCtrl+Shift+M"),
        _("Display messages")
    );

    menuView->Append(
        ID_ADVSTATISTICSVIEW,
        _("&Statistics\tCtrl+Shift+S"),
        _("Display statistics")
    );

    menuView->Append(
        ID_ADVRESOURCEUSAGEVIEW,
        _("&Disk usage\tCtrl+Shift+D"),
        _("Display disk usage")
    );

    menuView->AppendSeparator();

    menuView->Append(
        ID_CHANGEGUI,
        _("Simple &View...\tCtrl+Shift+V"),
        _("Display the simple graphical interface.")
    );

    // Screen too small?
    if (wxGetDisplaySize().GetHeight() < 600) {
        menuView->Enable(ID_CHANGEGUI, false);
    }

    // Is an accessibility aid running?
    if (wxGetApp().IsAccessibilityEnabled()) {
        menuView->Enable(ID_CHANGEGUI, false);
    }


    // Tools menu
    wxMenu *menuTools = new wxMenu;

    if (!is_acct_mgr_detected) {
        menuTools->Append(
            ID_WIZARDATTACH, 
            _("&Attach to project or account manager..."),
            _("Volunteer for any or all of 30+ projects in many areas of science")
        );
    } else {
        strMenuName.Printf(
            _("&Synchronize with %s"), 
            wxString(ami.acct_mgr_name.c_str(), wxConvUTF8).c_str()
        );
        strMenuDescription.Printf(
            _("Get current settings from %s"), 
            wxString(ami.acct_mgr_name.c_str(), wxConvUTF8).c_str()
        );
        menuTools->Append(
            ID_WIZARDUPDATE, 
            strMenuName,
            strMenuDescription
        );

        menuTools->Append(
            ID_WIZARDATTACH, 
            _("Attach to &project..."),
            _("Attach to a project to begin processing work")
        );

        strMenuName.Printf(
            _("&Stop using %s..."), 
            wxString(ami.acct_mgr_name.c_str(), wxConvUTF8).c_str()
        );
        menuTools->Append(
            ID_WIZARDDETACH, 
            strMenuName,
            _("Remove client from account manager control.")
        );
    }

    // Activity menu
    wxMenu *menuActivity = new wxMenu;

    menuActivity->AppendRadioItem(
        ID_ADVACTIVITYRUNALWAYS,
        _("&Run always"),
        _("Allow work regardless of preferences")
    );
    menuActivity->AppendRadioItem(
        ID_ADVACTIVITYRUNBASEDONPREPERENCES,
        _("Run based on &preferences"),
        _("Allow work according to your preferences")
    );
    menuActivity->AppendRadioItem(
        ID_ADVACTIVITYSUSPEND,
        _("&Suspend"),
        _("Stop work regardless of preferences")
    );

    if (pDoc->state.have_cuda || pDoc->state.have_ati) {

#ifndef __WXGTK__
        menuActivity->AppendSeparator();
#else
        // for some reason, the above radio items do not display the active
        // selection on linux (wxGtk library) with the separator here,
        // so we add a blank disabled menu item instead
        //
        wxMenuItem* pItem = menuActivity->Append(
            ID_MENUSEPARATOR1,
            (const wxChar *) wxT(" "),
                // wxEmptyString here causes a wxWidgets assertion when debugging
            wxEmptyString,
            wxITEM_NORMAL
                // wxITEM_SEPARATOR here causes a wxWidgets assertion when debugging
        );
        pItem->Enable(false); // disable this menu item
#endif

        menuActivity->AppendRadioItem(
            ID_ADVACTIVITYGPUALWAYS,
            _("Use GPU always"),
            _("Allow GPU work regardless of preferences")
        );
        menuActivity->AppendRadioItem(
            ID_ADVACTIVITYGPUBASEDONPREPERENCES,
            _("Use GPU based on &preferences"),
            _("Allow GPU work according to your preferences")
        );
        menuActivity->AppendRadioItem(
            ID_ADVACTIVITYGPUSUSPEND,
            _("Use GPU never"),
            _("Stop GPU work regardless of preferences")
        );
    }

#ifndef __WXGTK__
        menuActivity->AppendSeparator();
#else
        // for some reason, the above radio items do not display the active
        // selection on linux (wxGtk library) with the separator here,
        // so we add a blank disabled menu item instead
        //
        wxMenuItem* pItem = menuActivity->Append(
            ID_MENUSEPARATOR2,
            (const wxChar *) wxT(" "),
                // wxEmptyString here causes a wxWidgets assertion when debugging
            wxEmptyString,
            wxITEM_NORMAL
                // wxITEM_SEPARATOR here causes a wxWidgets assertion when debugging
        );
        pItem->Enable(false); // disable this menu item
#endif

    menuActivity->AppendRadioItem(
        ID_ADVNETWORKRUNALWAYS,
        _("&Network activity always available"),
        _("Allow network activity regardless of preferences")
    );
    menuActivity->AppendRadioItem(
        ID_ADVNETWORKRUNBASEDONPREPERENCES,
        _("Network activity based on pre&ferences"),
        _("Allow network activity according to your preferences")
    );
    menuActivity->AppendRadioItem(
        ID_ADVNETWORKSUSPEND,
        _("Network activity s&uspended"),
        _("Stop BOINC network activity")
    );

    // Advanced menu
    wxMenu *menuAdvanced = new wxMenu;
    menuAdvanced->Append(
        ID_OPTIONS, 
        _("&Options..."),
        _("Configure GUI options and proxy settings")
    );
    menuAdvanced->Append(
		ID_PREFERENCES, 
        _("&Preferences..."),
        _("Configure local preferences")
    );

    // %s is the project name
    //    i.e. 'BOINC', 'GridRepublic'
    strMenuDescription.Printf(
        _("Connect to another computer running %s"), 
        pSkinAdvanced->GetApplicationShortName().c_str()
    );
    menuAdvanced->Append(
        ID_SELECTCOMPUTER, 
        _("Select computer..."),
        strMenuDescription
    );
    menuAdvanced->Append(
        ID_SHUTDOWNCORECLIENT, 
        _("Shut down connected client..."),
        _("Shut down the currently connected core client")
    );
    menuAdvanced->Append(
        ID_RUNBENCHMARKS, 
        _("Run CPU &benchmarks"),
        _("Runs BOINC CPU benchmarks")
    );
    menuAdvanced->Append(
        ID_RETRYCOMMUNICATIONS, 
        _("Do network &communication"),
        _("Do all pending network communication.")
    );
    menuAdvanced->Append(
        ID_READCONFIG, 
        _("Read config file"),
        _("Read configuration info from cc_config.xml.")
    );
    menuAdvanced->Append(
        ID_READPREFERENCES, 
        _("Read local prefs file"),
        _("Read preferences from global_prefs_override.xml.")
    );


    // Help menu
    wxMenu *menuHelp = new wxMenu;

    // %s is the project name
    //    i.e. 'BOINC', 'GridRepublic'
    strMenuName.Printf(
        _("%s &help"), 
        pSkinAdvanced->GetApplicationShortName().c_str()
    );
    // %s is the project name
    //    i.e. 'BOINC', 'GridRepublic'
    strMenuDescription.Printf(
        _("Show information about %s"), 
        pSkinAdvanced->GetApplicationShortName().c_str()
    );
    menuHelp->Append(
        ID_HELPBOINC,
        strMenuName, 
        strMenuDescription
    );

    // %s is the application name
    //    i.e. 'BOINC Manager', 'GridRepublic Manager'
    strMenuName.Printf(
        _("&%s help"), 
        pSkinAdvanced->GetApplicationName().c_str()
    );
    // %s is the application name
    //    i.e. 'BOINC Manager', 'GridRepublic Manager'
    strMenuDescription.Printf(
        _("Show information about the %s"), 
        pSkinAdvanced->GetApplicationName().c_str()
    );
    menuHelp->Append(
        ID_HELPBOINCMANAGER,
        strMenuName, 
        strMenuDescription
    );

    // %s is the project name
    //    i.e. 'BOINC', 'GridRepublic'
    strMenuName.Printf(
        _("%s &website"), 
        pSkinAdvanced->GetApplicationShortName().c_str()
    );
    // %s is the application name
    //    i.e. 'BOINC Manager', 'GridRepublic Manager'
    strMenuDescription.Printf(
        _("Show information about BOINC and %s"),
        pSkinAdvanced->GetApplicationName().c_str()
    );
    menuHelp->Append(
        ID_HELPBOINCWEBSITE,
        strMenuName, 
        strMenuDescription
    );

    // %s is the project name
    //    i.e. 'BOINC Manager', 'GridRepublic Manager'
    strMenuName.Printf(
        _("&About %s..."), 
        pSkinAdvanced->GetApplicationName().c_str()
    );
    menuHelp->Append(
        wxID_ABOUT,
        strMenuName, 
        _("Licensing and copyright information.")
    );

    // construct menu
    m_pMenubar = new wxMenuBar;
    m_pMenubar->Append(
        menuFile,
        _("&File")
    );
    m_pMenubar->Append(
        menuView,
        _("&View")
    );
    m_pMenubar->Append(
        menuTools,
        _("&Tools")
    );
    m_pMenubar->Append(
        menuActivity,
        _("&Activity")
    );
    m_pMenubar->Append(
        menuAdvanced,
        _("A&dvanced")
    );
    m_pMenubar->Append(
        menuHelp,
        _("&Help")
    );

    wxMenuBar* m_pOldMenubar = GetMenuBar();
    SetMenuBar(m_pMenubar);
#ifdef __WXMAC__
    m_pMenubar->MacInstallMenuBar();
#endif
    if (m_pOldMenubar) {
        delete m_pOldMenubar;
    }
    
#ifdef __WXMAC__
    // Enable Mac OS X's standard Preferences menu item (handled in MacSysMenu.cpp)
    EnableMenuCommand(NULL, kHICommandPreferences);
    
    // Set HELP key as keyboard shortcut
    m_Shortcuts[0].Set(wxACCEL_NORMAL, WXK_HELP, ID_HELPBOINCMANAGER);
    m_pAccelTable = new wxAcceleratorTable(1, m_Shortcuts);
    SetAcceleratorTable(*m_pAccelTable);
 #endif

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CreateMenu - Function End"));
    return true;
}


bool CAdvancedFrame::CreateNotebook() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CreateNotebook - Function Begin"));

    // create frame panel
    wxPanel *pPanel = new wxPanel(this, -1, wxDefaultPosition, wxDefaultSize,
                                 wxTAB_TRAVERSAL|wxCLIP_CHILDREN|wxNO_BORDER);
    pPanel->SetAutoLayout(TRUE);

    // initialize notebook
    m_pNotebook = new wxNotebook(pPanel, ID_FRAMENOTEBOOK, wxDefaultPosition, wxDefaultSize,
                                wxNB_FIXEDWIDTH|wxCLIP_CHILDREN);

    // layout frame panel
    wxBoxSizer *pPanelSizer = new wxBoxSizer(wxVERTICAL);

    pPanelSizer->Add(new wxStaticLine(pPanel, -1), 0, wxEXPAND);
	pPanelSizer->Add(0, 5);
    pPanelSizer->Add(m_pNotebook, 1, wxEXPAND);

    // Display default views
    RepopulateNotebook();

    pPanel->SetSizer(pPanelSizer);
    pPanel->Layout();

#ifdef __WXMAC__
    //Accessibility
    HIObjectSetAccessibilityIgnored((HIObjectRef)pPanel->GetHandle(), true);
#endif

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CreateNotebook - Function End"));
    return true;
}


bool CAdvancedFrame::RepopulateNotebook() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::RepopulateNotebook - Function Begin"));

    DeleteNotebook();

    // Create the various notebook pages
    CreateNotebookPage(new CViewProjects(m_pNotebook));
    CreateNotebookPage(new CViewWork(m_pNotebook));
    CreateNotebookPage(new CViewTransfers(m_pNotebook));
    CreateNotebookPage(new CViewMessages(m_pNotebook));
    CreateNotebookPage(new CViewStatistics(m_pNotebook));
    CreateNotebookPage(new CViewResources(m_pNotebook));

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::RepopulateNotebook - Function End"));
    return true;
}


bool CAdvancedFrame::CreateNotebookPage( CBOINCBaseView* pwndNewNotebookPage) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CreateNotebookPage - Function Begin"));

    wxImageList*    pImageList;
    int         iImageIndex = 0;

    wxASSERT(pwndNewNotebookPage);
    wxASSERT(m_pNotebook);
    wxASSERT(wxDynamicCast(pwndNewNotebookPage, CBOINCBaseView));


    pImageList = m_pNotebook->GetImageList();
    if (!pImageList) {
        pImageList = new wxImageList(16, 16, true, 0);
        wxASSERT(pImageList != NULL);
        m_pNotebook->SetImageList(pImageList);
    }
    
    iImageIndex = pImageList->Add(wxBitmap(pwndNewNotebookPage->GetViewIcon()));
    m_pNotebook->AddPage(pwndNewNotebookPage, pwndNewNotebookPage->GetViewDisplayName(), TRUE, iImageIndex);

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CreateNotebookPage - Function End"));
    return true;
}


bool CAdvancedFrame::CreateStatusbar() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CreateStatusbar - Function Begin"));

    if (m_pStatusbar)
        return true;

    m_pStatusbar = new CStatusBar(this);
    wxASSERT(m_pStatusbar);

    SetStatusBar(m_pStatusbar);
    SetStatusBarPane(0);

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::CreateStatusbar - Function End"));
    return true;
}


bool CAdvancedFrame::DeleteMenu() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::DeleteMenu - Function Begin"));
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::DeleteMenu - Function End"));
    return true;
}


bool CAdvancedFrame::DeleteNotebook() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::DeleteNotebook - Function Begin"));

    wxASSERT(m_pNotebook);

    // Delete all existing pages
    m_pNotebook->DeleteAllPages();

    // Delete all existing images
    wxImageList* pImageList = m_pNotebook->GetImageList();
    if (pImageList) {
        pImageList->RemoveAll();
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::DeleteNotebook - Function End"));
    return true;
}


bool CAdvancedFrame::DeleteStatusbar() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::DeleteStatusbar - Function Begin"));

    if (!m_pStatusbar)
        return true;

    SetStatusBar(NULL);

    delete m_pStatusbar;
    m_pStatusbar = NULL;

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::DeleteStatusbar - Function End"));
    return true;
}


bool CAdvancedFrame::SaveState() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::SaveState - Function Begin"));

    wxString        strBaseConfigLocation = wxString(wxT("/"));
    wxConfigBase*   pConfig = wxConfigBase::Get(FALSE);
    wxWindow*       pwndNotebookPage = NULL;
    CBOINCBaseView* pView = NULL;
    wxString        strConfigLocation;
    wxString        strPreviousLocation;
    wxString        strBuffer;
    int             iIndex = 0;
    int             iItemCount = 0;


    wxASSERT(pConfig);
    wxASSERT(m_pNotebook);

    CBOINCBaseFrame::SaveState();

    // An odd case happens every once and awhile where wxWidgets looses
    //   the pointer to the config object, or it is cleaned up before
    //   the window has finished it's cleanup duty.  If we detect a NULL
    //   pointer, return false.
    if (!pConfig) return false;

    //
    // Save Frame State
    //
    pConfig->SetPath(strBaseConfigLocation);

    // Store the latest window dimensions.
    SaveWindowDimensions();

    pConfig->Write(wxT("CurrentPage"), m_pNotebook->GetSelection());

    //
    // Save Page(s) State
    //
 
    // Convert to a zero based index
    iItemCount = (int)m_pNotebook->GetPageCount() - 1;

    for (iIndex = 0; iIndex <= iItemCount; iIndex++) {   
        pwndNotebookPage = m_pNotebook->GetPage(iIndex);
        wxASSERT(wxDynamicCast(pwndNotebookPage, CBOINCBaseView));

        pView = wxDynamicCast(pwndNotebookPage, CBOINCBaseView);
        wxASSERT(pView);

        strPreviousLocation = pConfig->GetPath();
        strConfigLocation = strPreviousLocation + pView->GetViewName();

        pConfig->SetPath(strConfigLocation);
        pView->FireOnSaveState(pConfig);
        pConfig->SetPath(strPreviousLocation);
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::SaveState - Function End"));
    return true;
}


bool CAdvancedFrame::RestoreState() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::RestoreState - Function Begin"));

    wxString        strBaseConfigLocation = wxString(wxT("/"));
    wxConfigBase*   pConfig = wxConfigBase::Get(FALSE);
    wxWindow*       pwndNotebookPage = NULL;
    CBOINCBaseView* pView = NULL;
    wxString        strConfigLocation;
    wxString        strPreviousLocation;
    wxString        strBuffer;
    wxString        strValue;
    long            iIndex;
    long            iPageCount;
    long            iCurrentPage;


    wxASSERT(pConfig);
    wxASSERT(m_pNotebook);


    CBOINCBaseFrame::RestoreState();


    // An odd case happens every once and awhile where wxWidgets looses
    //   the pointer to the config object, or it is cleaned up before
    //   the window has finished it's cleanup duty.  If we detect a NULL
    //   pointer, return false.
    if (!pConfig) return false;

    //
    // Restore Frame State
    //
    pConfig->SetPath(strBaseConfigLocation);

    if (wxGetApp().GetSkinManager()->GetAdvanced()->GetDefaultTab()) {
        m_pNotebook->SetSelection(wxGetApp().GetSkinManager()->GetAdvanced()->GetDefaultTab());
    } else {
        pConfig->Read(wxT("CurrentPage"), &iCurrentPage, (ID_LIST_WORKVIEW - ID_LIST_BASE));
        m_pNotebook->SetSelection(iCurrentPage);
    }

    //
    // Restore Page(s) State
    //

    // Convert to a zero based index
    iPageCount = (long)m_pNotebook->GetPageCount() - 1;

    for (iIndex = 0; iIndex <= iPageCount; iIndex++) {   

        pwndNotebookPage = m_pNotebook->GetPage(iIndex);
        wxASSERT(wxDynamicCast(pwndNotebookPage, CBOINCBaseView));

        pView = wxDynamicCast(pwndNotebookPage, CBOINCBaseView);
        wxASSERT(pView);

        strPreviousLocation = pConfig->GetPath();
        strConfigLocation = strPreviousLocation + pView->GetViewName();

        pConfig->SetPath(strConfigLocation);
        pView->FireOnRestoreState(pConfig);
        pConfig->SetPath(strPreviousLocation);

    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::RestoreState - Function End"));
    return true;
}


void CAdvancedFrame::SaveWindowDimensions() {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::SaveWindowDimensions - Function Begin"));

    wxString        strBaseConfigLocation = wxString(wxT("/"));
    wxConfigBase*   pConfig = wxConfigBase::Get(FALSE);

    wxASSERT(pConfig);

    pConfig->SetPath(strBaseConfigLocation);

    pConfig->Write(wxT("WindowIconized"), IsIconized());
    pConfig->Write(wxT("WindowMaximized"), IsMaximized());
    pConfig->Write(wxT("Width"), GetSize().GetWidth());
    pConfig->Write(wxT("Height"), GetSize().GetHeight());
    pConfig->Write(wxT("XPos"), GetPosition().x);
    pConfig->Write(wxT("YPos"), GetPosition().y);

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::SaveWindowDimensions - Function End"));
}
    

int CAdvancedFrame::_GetCurrentViewPage() {
    switch (m_pNotebook->GetSelection()) {
    case 0:
        return VW_PROJ;
    case 1:
        return VW_TASK;
    case 2:
        return VW_XFER;
    case 3:
        return VW_MSGS;
    case 4:
        return VW_STAT;
    case 5:
        return VW_DISK;
    }
    return 0;       // Should never happen.
}


void CAdvancedFrame::OnChangeView(wxCommandEvent& event) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnChangeView - Function Begin"));

    m_pNotebook->SetSelection(event.GetId() - ID_ADVVIEWBASE);

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnChangeView - Function End"));
}


void CAdvancedFrame::OnChangeGUI(wxCommandEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnChangeGUI - Function Begin"));

    wxGetApp().SetActiveGUI(BOINC_SIMPLEGUI, true);

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnChangeGUI - Function End"));
}


void CAdvancedFrame::OnWizardAttach( wxCommandEvent& WXUNUSED(event) ) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnWizardAttach - Function Begin"));

    CMainDocument* pDoc     = wxGetApp().GetDocument();

    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));

    if (!pDoc->IsUserAuthorized())
        return;

    if (pDoc->IsConnected()) {
        UpdateStatusText(_("Attaching to project or account manager..."));

        // Stop all timers so that the wizard is the only thing doing anything
        StopTimers();

        CWizardAttachProject* pWizard = new CWizardAttachProject(this);

        wxString strName = wxEmptyString;
        wxString strURL = wxEmptyString;
        std::string foo;
        pWizard->Run( strName, strURL, foo, false );

        if (pWizard)
            pWizard->Destroy();

        DeleteMenu();
        CreateMenu();

        // Restart timers to continue normal operations.
        StartTimers();

        UpdateStatusText(wxT(""));

        pDoc->ForceCacheUpdate();
        FireRefreshView();
    } else {
        ShowNotCurrentlyConnectedAlert();
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnWizardAttach - Function End"));
}


void CAdvancedFrame::OnWizardUpdate(wxCommandEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnWizardUpdate - Function Begin"));

    CMainDocument*            pDoc = wxGetApp().GetDocument();

    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));

    if (!pDoc->IsUserAuthorized())
        return;

    if (pDoc->IsConnected()) {
        // Stop all timers so that the wizard is the only thing doing anything
        StopTimers();

        CWizardAttachProject* pWizard = new CWizardAttachProject(this);

        pWizard->SyncToAccountManager();

        if (pWizard)
            pWizard->Destroy();

        DeleteMenu();
        CreateMenu();
        pDoc->ForceCacheUpdate();
        FireRefreshView();
        ResetReminderTimers();

        // Restart timers to continue normal operations.
        StartTimers();
    } else {
        ShowNotCurrentlyConnectedAlert();
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnWizardUpdate - Function End"));
}


void CAdvancedFrame::OnWizardDetach(wxCommandEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnWizardDetach - Function Begin"));

    CMainDocument* pDoc           = wxGetApp().GetDocument();
    CSkinAdvanced* pSkinAdvanced = wxGetApp().GetSkinManager()->GetAdvanced();
    wxInt32        iAnswer        = 0; 
    wxString       strTitle       = wxEmptyString;
    wxString       strMessage     = wxEmptyString;
    ACCT_MGR_INFO  ami;

    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));
    wxASSERT(pSkinAdvanced);
    wxASSERT(wxDynamicCast(pSkinAdvanced, CSkinAdvanced));

    if (!pDoc->IsUserAuthorized())
        return;

    if (pDoc->IsConnected()) {

        pDoc->rpc.acct_mgr_info(ami);

        strTitle.Printf(
            _("%s - Detach from %s"),
            pSkinAdvanced->GetApplicationName().c_str(),
            wxString(ami.acct_mgr_name.c_str(), wxConvUTF8).c_str()
        );
        strMessage.Printf(
            _("If you stop using %s,\nyou'll keep all your current projects,\nbut you'll have to manage projects manually.\n\nDo you want to stop using %s?"), 
            wxString(ami.acct_mgr_name.c_str(), wxConvUTF8).c_str(),
            wxString(ami.acct_mgr_name.c_str(), wxConvUTF8).c_str()
        );

        iAnswer = wxGetApp().SafeMessageBox(
            strMessage,
            strTitle,
            wxYES_NO | wxICON_QUESTION,
            this
        );

        if (wxYES == iAnswer) {
            std::string url, name, passwd;
            pDoc->rpc.acct_mgr_rpc(
                url.c_str(),
                name.c_str(),
                passwd.c_str(),
                false
            );
        }

        DeleteMenu();
        CreateMenu();
        pDoc->ForceCacheUpdate();
        FireRefreshView();

    } else {
        ShowNotCurrentlyConnectedAlert();
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnWizardDetach - Function End"));
}


void CAdvancedFrame::OnActivitySelection(wxCommandEvent& event) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnActivitySelection - Function Begin"));

    CMainDocument* pDoc      = wxGetApp().GetDocument();

    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));

    if (event.IsChecked()) {
        switch(event.GetId()) {
        case ID_ADVACTIVITYRUNALWAYS:
            pDoc->SetActivityRunMode(RUN_MODE_ALWAYS, 0);
            break;
        case ID_ADVACTIVITYSUSPEND:
            pDoc->SetActivityRunMode(RUN_MODE_NEVER, 0);
            break;
        case ID_ADVACTIVITYRUNBASEDONPREPERENCES:
            pDoc->SetActivityRunMode(RUN_MODE_AUTO, 0);
            break;
        }
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnActivitySelection - Function End"));
}

void CAdvancedFrame::OnGPUSelection(wxCommandEvent& event) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnGPUSelection - Function Begin"));

    CMainDocument* pDoc      = wxGetApp().GetDocument();

    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));

    if (event.IsChecked()) {
        switch(event.GetId()) {
        case ID_ADVACTIVITYGPUALWAYS:
            pDoc->SetGPURunMode(RUN_MODE_ALWAYS, 0);
            break;
        case ID_ADVACTIVITYGPUSUSPEND:
            pDoc->SetGPURunMode(RUN_MODE_NEVER, 0);
            break;
        case ID_ADVACTIVITYGPUBASEDONPREPERENCES:
            pDoc->SetGPURunMode(RUN_MODE_AUTO, 0);
            break;
        }
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnGPUSelection - Function End"));
}


void CAdvancedFrame::OnNetworkSelection(wxCommandEvent& event) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnNetworkSelection - Function Begin"));

    CMainDocument* pDoc      = wxGetApp().GetDocument();

    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));

    if (event.IsChecked()) {
        switch(event.GetId()) {
        case ID_ADVNETWORKRUNALWAYS:
            pDoc->SetNetworkRunMode(RUN_MODE_ALWAYS, 0);
            break;
        case ID_ADVNETWORKSUSPEND:
            pDoc->SetNetworkRunMode(RUN_MODE_NEVER, 0);
            break;
        case ID_ADVNETWORKRUNBASEDONPREPERENCES:
            pDoc->SetNetworkRunMode(RUN_MODE_AUTO, 0);
            break;
        }
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnNetworkSelection - Function End"));
}

   
void CAdvancedFrame::OnOptions(wxCommandEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnOptions - Function Begin"));

    CMainDocument* pDoc = wxGetApp().GetDocument();
    CSkinAdvanced* pSkinAdvanced = wxGetApp().GetSkinManager()->GetAdvanced();
    CDlgOptions    dlg(this);
    int            iBuffer = 0;
    wxString       strBuffer = wxEmptyString;
    wxArrayString  astrDialupConnections;
    bool           bRetrievedProxyConfiguration = false;

    wxASSERT(pDoc);
    wxASSERT(pSkinAdvanced);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));
    wxASSERT(wxDynamicCast(pSkinAdvanced, CSkinAdvanced));

    // General Tab
    dlg.m_LanguageSelectionCtrl->Append(wxGetApp().GetSupportedLanguages());

    dlg.m_LanguageSelectionCtrl->SetSelection(m_iSelectedLanguage);
    dlg.m_ReminderFrequencyCtrl->SetValue(m_iReminderFrequency);
    dlg.m_EnableBOINCManagerExitMessageCtrl->SetValue(wxGetApp().GetBOINCMGRDisplayExitMessage());
#ifdef __WXMSW__
    dlg.m_EnableBOINCManagerAutoStartCtrl->SetValue(!wxGetApp().GetBOINCMGRDisableAutoStart());

    // Connection Tab
    if (m_pDialupManager) {
        m_pDialupManager->GetISPNames(astrDialupConnections);

        dlg.m_DialupConnectionsCtrl->Append(astrDialupConnections);
        dlg.SetDefaultDialupConnection(m_strNetworkDialupConnectionName);
    } else {
        dlg.m_DialupSetDefaultCtrl->Disable();
        dlg.m_DialupClearDefaultCtrl->Disable();
    }
#endif

    // Proxy Tabs
    bRetrievedProxyConfiguration = (0 == pDoc->GetProxyConfiguration());
    if(!bRetrievedProxyConfiguration) {
        // We were unable to get the proxy configuration, so disable
        //   the controls
        dlg.m_EnableHTTPProxyCtrl->Enable(false);
        dlg.m_EnableSOCKSProxyCtrl->Enable(false);
    } else {
        dlg.m_EnableHTTPProxyCtrl->Enable(true);
        dlg.m_EnableSOCKSProxyCtrl->Enable(true);
    }

    dlg.m_EnableHTTPProxyCtrl->SetValue(pDoc->proxy_info.use_http_proxy);
    dlg.m_HTTPAddressCtrl->SetValue(wxString(pDoc->proxy_info.http_server_name.c_str(), wxConvUTF8));
    dlg.m_HTTPUsernameCtrl->SetValue(wxString(pDoc->proxy_info.http_user_name.c_str(), wxConvUTF8));
    dlg.m_HTTPPasswordCtrl->SetValue(wxString(pDoc->proxy_info.http_user_passwd.c_str(), wxConvUTF8));
	dlg.m_HTTPNoProxiesCtrl->SetValue(wxString(pDoc->proxy_info.noproxy_hosts.c_str(), wxConvUTF8));
    strBuffer.Printf(wxT("%d"), pDoc->proxy_info.http_server_port);
    dlg.m_HTTPPortCtrl->SetValue(strBuffer);

    dlg.m_EnableSOCKSProxyCtrl->SetValue(pDoc->proxy_info.use_socks_proxy);
    dlg.m_SOCKSAddressCtrl->SetValue(wxString(pDoc->proxy_info.socks_server_name.c_str(), wxConvUTF8));
    dlg.m_SOCKSUsernameCtrl->SetValue(wxString(pDoc->proxy_info.socks5_user_name.c_str(), wxConvUTF8));
    dlg.m_SOCKSPasswordCtrl->SetValue(wxString(pDoc->proxy_info.socks5_user_passwd.c_str(), wxConvUTF8));
	dlg.m_SOCKSNoProxiesCtrl->SetValue(wxString(pDoc->proxy_info.noproxy_hosts.c_str(),wxConvUTF8));
    strBuffer.Printf(wxT("%d"), pDoc->proxy_info.socks_server_port);
    dlg.m_SOCKSPortCtrl->SetValue(strBuffer);

    if (wxID_OK == dlg.ShowModal()) {
        // General Tab
        if (m_iSelectedLanguage != dlg.m_LanguageSelectionCtrl->GetSelection()) {
            wxString strDialogTitle;
            wxString strDialogMessage;

            // %s is the application name
            //    i.e. 'BOINC Manager', 'GridRepublic Manager'
            strDialogTitle.Printf(
                _("%s - Language Selection"),
                pSkinAdvanced->GetApplicationName().c_str()
            );

            // %s is the application name
            //    i.e. 'BOINC Manager', 'GridRepublic Manager'
            strDialogMessage.Printf(
                _("The %s's default language has been changed, in order for this change to take affect you must restart the %s."),
                pSkinAdvanced->GetApplicationName().c_str(),
                pSkinAdvanced->GetApplicationName().c_str()
            );

            ShowAlert(
                strDialogTitle,
                strDialogMessage,
                wxOK | wxICON_INFORMATION
           );
        }

        m_iSelectedLanguage = dlg.m_LanguageSelectionCtrl->GetSelection();
        m_iReminderFrequency = dlg.m_ReminderFrequencyCtrl->GetValue();
        wxGetApp().SetBOINCMGRDisplayExitMessage(dlg.m_EnableBOINCManagerExitMessageCtrl->GetValue());
#ifdef __WXMSW__
        wxGetApp().SetBOINCMGRDisableAutoStart(!dlg.m_EnableBOINCManagerAutoStartCtrl->GetValue());

        // Connection Tab
        m_strNetworkDialupConnectionName = dlg.GetDefaultDialupConnection();
#endif

        // Proxy Tabs
        if (bRetrievedProxyConfiguration) {
            pDoc->proxy_info.use_http_proxy = dlg.m_EnableHTTPProxyCtrl->GetValue();
            pDoc->proxy_info.http_server_name = (const char*)dlg.m_HTTPAddressCtrl->GetValue().mb_str();
            pDoc->proxy_info.http_user_name = (const char*)dlg.m_HTTPUsernameCtrl->GetValue().mb_str();
            pDoc->proxy_info.http_user_passwd = (const char*)dlg.m_HTTPPasswordCtrl->GetValue().mb_str();
			if(pDoc->proxy_info.use_http_proxy) {
				pDoc->proxy_info.noproxy_hosts = (const char*)dlg.m_HTTPNoProxiesCtrl->GetValue().mb_str();
			}
            strBuffer = dlg.m_HTTPPortCtrl->GetValue();
            strBuffer.ToLong((long*)&iBuffer);
            pDoc->proxy_info.http_server_port = iBuffer;

            pDoc->proxy_info.use_socks_proxy = dlg.m_EnableSOCKSProxyCtrl->GetValue();
            pDoc->proxy_info.socks_server_name = (const char*)dlg.m_SOCKSAddressCtrl->GetValue().mb_str();
            pDoc->proxy_info.socks5_user_name = (const char*)dlg.m_SOCKSUsernameCtrl->GetValue().mb_str();
            pDoc->proxy_info.socks5_user_passwd = (const char*)dlg.m_SOCKSPasswordCtrl->GetValue().mb_str();
			if(pDoc->proxy_info.use_socks_proxy) {
				pDoc->proxy_info.noproxy_hosts = (const char*)dlg.m_SOCKSNoProxiesCtrl->GetValue().mb_str();
			}
            strBuffer = dlg.m_SOCKSPortCtrl->GetValue();
            strBuffer.ToLong((long*)&iBuffer);
            pDoc->proxy_info.socks_server_port = iBuffer;

            pDoc->SetProxyConfiguration();
        }
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnOptions - Function End"));
}


void CAdvancedFrame::OnPreferences(wxCommandEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnPreferences - Function Begin"));

    CDlgAdvPreferences dlg(this);
	dlg.ShowModal();

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnPreferences - Function End"));
}


void CAdvancedFrame::OnSelectComputer(wxCommandEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnSelectComputer - Function Begin"));

    CMainDocument*      pDoc = wxGetApp().GetDocument();
    CDlgSelectComputer  dlg(this);
    size_t              lIndex = 0;
    long                lRetVal = -1;
    wxArrayString       aComputerNames;

    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));


    // Lets copy the template store in the system state
    aComputerNames = m_aSelectedComputerMRU;

    // Lets populate the combo control with the MRU list
    dlg.m_ComputerNameCtrl->Clear();
    for (lIndex = 0; lIndex < aComputerNames.Count(); lIndex++) {
        dlg.m_ComputerNameCtrl->Append(aComputerNames.Item(lIndex));
    }

    if (wxID_OK == dlg.ShowModal()) {

        // Make a null hostname be the same thing as localhost
        if (wxEmptyString == dlg.m_ComputerNameCtrl->GetValue()) {
            lRetVal = pDoc->Connect(
                wxT("localhost"),
                GUI_RPC_PORT,
                wxEmptyString,
                TRUE,
                TRUE
            );
        } else {
            // Connect to the remote machine
            wxString sHost = dlg.m_ComputerNameCtrl->GetValue(); 
            long lPort = GUI_RPC_PORT; 
            int iPos = sHost.Find(wxT(":")); 
            if (iPos != wxNOT_FOUND) { 
                wxString sPort = sHost.substr(iPos + 1); 
                if (!sPort.ToLong(&lPort)) lPort = GUI_RPC_PORT; 
                sHost.erase(iPos); 
            } 
            lRetVal = pDoc->Connect(
                sHost,
                (int)lPort,
                dlg.m_ComputerPasswordCtrl->GetValue(),
                TRUE,
                FALSE
            );
        }
        if (lRetVal) {
            ShowConnectionFailedAlert();
        }

        // Insert a copy of the current combo box value to the head of the
        //   computer names string array
        if (wxEmptyString != dlg.m_ComputerNameCtrl->GetValue()) {
            aComputerNames.Insert(dlg.m_ComputerNameCtrl->GetValue(), 0);
        }

        // Loops through the computer names and remove any duplicates that
        //   might exist with the new head value
        for (lIndex = 1; lIndex < aComputerNames.Count(); lIndex++) {
            if (aComputerNames.Item(lIndex) == aComputerNames.Item(0))
                aComputerNames.RemoveAt(lIndex);
        }

        // Store the modified computer name MRU list back to the system state
        m_aSelectedComputerMRU = aComputerNames;
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnSelectComputer - Function End"));
}


void CAdvancedFrame::OnClientShutdown(wxCommandEvent& WXUNUSED(event)) {
    wxCommandEvent     evtSelectNewComputer(wxEVT_COMMAND_MENU_SELECTED, ID_SELECTCOMPUTER);
    CMainDocument*     pDoc = wxGetApp().GetDocument();
    CSkinAdvanced*     pSkinAdvanced = wxGetApp().GetSkinManager()->GetAdvanced();
    CDlgGenericMessage dlg(this);
    wxString           strDialogTitle = wxEmptyString;
    wxString           strDialogMessage = wxEmptyString;

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnClientShutdown - Function Begin"));

    wxASSERT(pDoc);
    wxASSERT(pSkinAdvanced);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));
    wxASSERT(wxDynamicCast(pSkinAdvanced, CSkinAdvanced));


    // Stop all timers
    StopTimers();


    // %s is the application name
    //    i.e. 'BOINC Manager', 'GridRepublic Manager'
    strDialogTitle.Printf(
        _("%s - Shutdown the current client..."),
        pSkinAdvanced->GetApplicationName().c_str()
    );

    // 1st %s is the application name
    //    i.e. 'BOINC Manager', 'GridRepublic Manager'
    // 2nd %s is the project name
    //    i.e. 'BOINC', 'GridRepublic'
    strDialogMessage.Printf(
        _("%s will shut down the currently connected client,\nand prompt you for another host to connect to.\n"),
        pSkinAdvanced->GetApplicationName().c_str()
    );

    dlg.SetTitle(strDialogTitle);
    dlg.m_DialogMessage->SetLabel(strDialogMessage);
    dlg.Fit();
    dlg.Centre();

    if (wxID_OK == dlg.ShowModal()) {
        pDoc->CoreClientQuit();
        pDoc->ForceDisconnect();
        
        // Since the core cliet we were connected to just shutdown, prompt for a new one.
        ProcessEvent(evtSelectNewComputer);
    }


    // Restart timers
    StartTimers();

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnClientShutdown - Function End"));
}


void CAdvancedFrame::OnRunBenchmarks(wxCommandEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnRunBenchmarks - Function Begin"));

    CMainDocument* pDoc = wxGetApp().GetDocument();
    wxASSERT(m_pNotebook);
    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));

    m_pNotebook->SetSelection(ID_LIST_MESSAGESVIEW - ID_LIST_BASE);
    pDoc->RunBenchmarks();

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnRunBenchmarks - Function End"));
}


void CAdvancedFrame::OnRetryCommunications( wxCommandEvent& WXUNUSED(event) ) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnRetryCommunications - Function Begin"));

    CMainDocument* pDoc     = wxGetApp().GetDocument();
    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));

    UpdateStatusText(_("Retrying communications for project(s)..."));
    pDoc->rpc.network_available();
    UpdateStatusText(wxT(""));

    FireRefreshView();

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnRetryCommunications - Function End"));
}


void CAdvancedFrame::OnReadConfig(wxCommandEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnReadConfig - Function Begin"));

    CMainDocument* pDoc = wxGetApp().GetDocument();

    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));

    pDoc->rpc.read_cc_config();

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnReadConfig - Function End"));
}


void CAdvancedFrame::OnReadPreferences(wxCommandEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnReadPreferences - Function Begin"));

    CMainDocument* pDoc = wxGetApp().GetDocument();

    wxASSERT(pDoc);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));

    pDoc->rpc.read_global_prefs_override();

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnReadPreferences - Function End"));
}


void CAdvancedFrame::OnHelp(wxHelpEvent& event) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnHelpBOINCManager - Function Begin"));

    if (IsShown()) {
	    wxString strURL = wxGetApp().GetSkinManager()->GetAdvanced()->GetOrganizationHelpUrl();

		wxString wxurl;
		wxurl.Printf(
            wxT("%s?target=advanced&version=%s&controlid=%d"),
            strURL.c_str(),
            wxString(BOINC_VERSION_STRING, wxConvUTF8).c_str(),
            event.GetId()
        );
        ExecuteBrowserLink(wxurl);
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnHelpBOINCManager - Function End"));
}


void CAdvancedFrame::OnHelpBOINC(wxCommandEvent& event) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnHelpBOINC - Function Begin"));

    if (IsShown()) {
    	wxString strURL = wxGetApp().GetSkinManager()->GetAdvanced()->GetOrganizationHelpUrl();

		wxString wxurl;
		wxurl.Printf(
            wxT("%s?target=advanced&version=%s&controlid=%d"),
            strURL.c_str(),
            wxString(BOINC_VERSION_STRING, wxConvUTF8).c_str(),
            event.GetId()
        );
        ExecuteBrowserLink(wxurl);
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnHelpBOINC - Function End"));
}


void CAdvancedFrame::OnHelpAbout(wxCommandEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnHelpAbout - Function Begin"));

    CDlgAbout dlg(this);
    dlg.ShowModal();

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnHelpAbout - Function End"));
}


void CAdvancedFrame::OnRefreshView(CFrameEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnRefreshView - Function Begin"));

    if (IsShown()) {
        wxWindow*       pwndNotebookPage = NULL;
        CBOINCBaseView* pView = NULL;
        wxTimerEvent    timerEvent;

        wxASSERT(m_pNotebook);

        pwndNotebookPage = m_pNotebook->GetPage(m_pNotebook->GetSelection());
        wxASSERT(pwndNotebookPage);

        pView = wxDynamicCast(pwndNotebookPage, CBOINCBaseView);
        wxASSERT(pView);

        pView->FireOnListRender(timerEvent);
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnRefreshView - Function End"));
}


void CAdvancedFrame::OnConnect(CFrameEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnConnect - Function Begin"));
    
    CMainDocument* pDoc = wxGetApp().GetDocument();
    CSkinAdvanced* pSkinAdvanced = wxGetApp().GetSkinManager()->GetAdvanced();
    CWizardAttachProject* pAPWizard = NULL;
    wxString strComputer = wxEmptyString;
    wxString strName = wxEmptyString;
    wxString strURL = wxEmptyString;
    wxString strDialogTitle = wxEmptyString;
    wxString strDialogDescription = wxEmptyString;
    bool bCachedCredentials = false;
    ACCT_MGR_INFO ami;
    PROJECT_INIT_STATUS pis;
	CC_STATUS     status;
    wxWindow* pwndNotebookPage = NULL;
    CBOINCBaseView* pView = NULL;
    int iItemCount = 0, iIndex;
    int wasShown = 0;

    wxASSERT(m_pNotebook);
    wxASSERT(pDoc);
    wxASSERT(pSkinAdvanced);
    wxASSERT(wxDynamicCast(pDoc, CMainDocument));
    wxASSERT(wxDynamicCast(pSkinAdvanced, CSkinAdvanced));

    pDoc->GetCoreClientStatus(status, true);

    // Do we need to bug out to the simple view?
    if (status.simple_gui_only) {
        wxGetApp().SetActiveGUI(BOINC_SIMPLEGUI, true);
        FireConnect();
        return;
    }


    // Stop all timers so that the wizard is the only thing doing anything
    StopTimers();


    // If we are connected to the localhost, run a really quick screensaver
    //   test to trigger a firewall popup.
    pDoc->GetConnectedComputerName(strComputer);
    if (pDoc->IsComputerNameLocal(strComputer)) {
        wxGetApp().StartBOINCScreensaverTest();
        wxGetApp().StartBOINCDefaultScreensaverTest();
    }

    // Clear selected rows in all tab pages when connecting to a different host
    iItemCount = (int)m_pNotebook->GetPageCount() - 1;
    for (iIndex = 0; iIndex <= iItemCount; iIndex++) {   
        pwndNotebookPage = m_pNotebook->GetPage(iIndex);
        wxASSERT(wxDynamicCast(pwndNotebookPage, CBOINCBaseView));

        pView = wxDynamicCast(pwndNotebookPage, CBOINCBaseView);
        wxASSERT(pView);
        
        pView->ClearSelections();
    }

    pDoc->RefreshRPCs();
    pDoc->ForceCacheUpdate();

    pDoc->rpc.get_project_init_status(pis);
    pDoc->rpc.acct_mgr_info(ami);
    if (ami.acct_mgr_url.size() && !ami.have_credentials) {
        if (IsShown()) {
            wasShown = 1;
        } else {
            Show();
        }

        pAPWizard = new CWizardAttachProject(this);
        if (pAPWizard->SyncToAccountManager()) {

#if defined(__WXMSW__) || defined(__WXMAC__)
            // If successful, hide the main window if we showed it
            if (!wasShown) {
                Hide();
            }
#endif

            // %s is the application name
            //    i.e. 'BOINC Manager', 'GridRepublic Manager'
            strDialogTitle.Printf(
                _("%s"),
                pSkinAdvanced->GetApplicationName().c_str()
            );

            // %s is the application name
            //    i.e. 'BOINC Manager', 'GridRepublic Manager'
            // %s is the project name
            //    i.e. 'BOINC', 'GridRepublic'
            strDialogDescription.Printf(
                _("%s has successfully attached to %s"),
                pSkinAdvanced->GetApplicationName().c_str(),
                pSkinAdvanced->GetApplicationShortName().c_str()
            );

            ShowAlert(
                strDialogTitle,
                strDialogDescription,
                wxOK | wxICON_INFORMATION,
                true
            );
        } else {
            // If failure, display the messages tab
            m_pNotebook->SetSelection(ID_LIST_MESSAGESVIEW - ID_LIST_BASE);
        }
    } else if ((pis.url.size() || (0 >= pDoc->GetProjectCount())) && !status.disallow_attach) {
        if (!IsShown()) {
            Show();
        }

        pAPWizard = new CWizardAttachProject(this);
        strName = wxString(pis.name.c_str(), wxConvUTF8);
        strURL = wxString(pis.url.c_str(), wxConvUTF8);
        bCachedCredentials = pis.url.length() && pis.has_account_key;

        if (pAPWizard->Run(strName, strURL, pis.team_name, bCachedCredentials)) {
            // If successful, display the work tab
            m_pNotebook->SetSelection(ID_LIST_WORKVIEW - ID_LIST_BASE);
        } else {
            // If failure, display the messages tab
            m_pNotebook->SetSelection(ID_LIST_MESSAGESVIEW - ID_LIST_BASE);
        }
    }

    // Update the menus
    DeleteMenu();
    CreateMenu();
#ifdef __WXMAC__
    wxGetApp().GetMacSystemMenu()->BuildMenu();
#endif

    // Restart timers to continue normal operations.
    StartTimers();


    // Set the correct refresh interval, then manually fire the refresh
	//   event to do the initial population of the view.
    UpdateRefreshTimerInterval(m_pNotebook->GetSelection());
    FireRefreshView();


    if (pAPWizard)
        pAPWizard->Destroy();

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnConnect - Function End"));
}


void CAdvancedFrame::OnUpdateStatus(CFrameEvent& event) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnUpdateStatus - Function Begin"));

    m_pStatusbar->SetStatusText(event.m_message);
    ::wxSleep(0);

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnUpdateStatus - Function End"));
}


void CAdvancedFrame::OnRefreshState(wxTimerEvent& WXUNUSED(event)) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnRefreshState - Function Begin"));

    // Write a snapshot of the current state to the config
    //   module, on Win9x systems we don't always shutdown
    //   in a nice way, if we are terminated by the user
    //   we still want the UI state to have been stored
    //   for their next use
    SaveState();

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnRefreshState - Function End"));
}


void CAdvancedFrame::OnFrameRender(wxTimerEvent& WXUNUSED(event)) {
    CMainDocument*    pDoc     = wxGetApp().GetDocument();
    wxMenuBar*        pMenuBar = GetMenuBar();

    if (m_pFrameRenderTimer->IsRunning()) {
        if (IsShown()) {
            if (pDoc) {
                wxASSERT(wxDynamicCast(pDoc, CMainDocument));
                wxASSERT(wxDynamicCast(pMenuBar, wxMenuBar));
                wxASSERT(wxDynamicCast(m_pStatusbar, CStatusBar));

                // Update the menu bar
                CC_STATUS  status;
                if ((pDoc->IsConnected()) && (0 == pDoc->GetCoreClientStatus(status))) {
                    UpdateActivityModeControls(status);
                    if (pDoc->state.have_cuda || pDoc->state.have_ati) {
                        UpdateGPUModeControls(status);
                    }
                    UpdateNetworkModeControls(status);

                    if (status.disallow_attach) {
                        pMenuBar->Enable(ID_WIZARDATTACH, false);
                    }
                }

                // Update the statusbar
                if (pDoc->IsConnected() || pDoc->IsReconnecting()) {
                    m_pStatusbar->m_pbmpConnected->Show();
                    m_pStatusbar->m_ptxtConnected->Show();
                    m_pStatusbar->m_pbmpDisconnect->Hide();
                    m_pStatusbar->m_ptxtDisconnect->Hide();

                    wxString strBuffer = wxEmptyString;
                    wxString strComputerName = wxEmptyString;
                    wxString strComputerVersion = wxEmptyString;
                    wxString strStatusText = wxEmptyString;
                    wxString strTitle = m_strBaseTitle;
     
                    if (pDoc->IsReconnecting()) {
                        pDoc->GetConnectingComputerName(strComputerName);
                    } else {
                        pDoc->GetConnectedComputerName(strComputerName);
                        pDoc->GetConnectedComputerVersion(strComputerVersion);
                    }

                    if (pDoc->IsComputerNameLocal(strComputerName)) {
                        strComputerName = wxT("localhost");
                    }

                    strTitle.Printf(_("%s - (%s)"), m_strBaseTitle.c_str(), strComputerName.c_str());

                    if (pDoc->IsReconnecting()) {
                        strStatusText.Printf(_("Connecting to %s"), strComputerName.c_str());
                    } else {
                        strStatusText.Printf(
                            _("Connected to %s (%s)"),
                            strComputerName.c_str(),
                            strComputerVersion.c_str()
                        );
                    }

                    // The Mac takes a huge performance hit redrawing this window, 
                    //   window, so don't change the text unless we really have too.
                    if (GetTitle() != strTitle) {
                        SetTitle(strTitle);
                    }
                    if (m_pStatusbar->m_ptxtConnected->GetLabel() != strStatusText) {
                        m_pStatusbar->m_ptxtConnected->SetLabel(strStatusText);
                    }
                } else {
                    m_pStatusbar->m_pbmpConnected->Hide();
                    m_pStatusbar->m_ptxtConnected->Hide();
                    m_pStatusbar->m_pbmpDisconnect->Show();
                    m_pStatusbar->m_ptxtDisconnect->Show();

                    if (GetTitle() != m_strBaseTitle)
                        SetTitle(m_strBaseTitle);
                }
            }
        }
    }
}


void CAdvancedFrame::OnNotebookSelectionChanged(wxNotebookEvent& event) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnNotebookSelectionChanged - Function Begin"));

    wxWindow*       pwndNotebookPage = NULL;
    CBOINCBaseView* pView = NULL;
    int             selection = event.GetSelection();
    
    if ((-1 != selection)) {
        UpdateRefreshTimerInterval(selection);

        CMainDocument*  pDoc = wxGetApp().GetDocument();
        wxASSERT(wxDynamicCast(pDoc, CMainDocument));
        
        pDoc->RefreshRPCs();
        pDoc->RunPeriodicRPCs();
    }

    pwndNotebookPage = m_pNotebook->GetPage(selection);
    wxASSERT(wxDynamicCast(pwndNotebookPage, CBOINCBaseView));

    pView = wxDynamicCast(pwndNotebookPage, CBOINCBaseView);
    wxASSERT(pView);
    
    pView->RefreshTaskPane();
    event.Skip();

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::OnNotebookSelectionChanged - Function End"));
}


void CAdvancedFrame::ResetReminderTimers() {
#ifdef __WXMSW__
    wxASSERT(m_pDialupManager);
    wxASSERT(wxDynamicCast(m_pDialupManager, CBOINCDialUpManager));

    m_pDialupManager->ResetReminderTimers();
#endif
}


void CAdvancedFrame::UpdateActivityModeControls( CC_STATUS& status ) {
    wxMenuBar* pMenuBar = GetMenuBar();
    wxASSERT(pMenuBar);
    wxASSERT(wxDynamicCast(pMenuBar, wxMenuBar));

    if ((RUN_MODE_ALWAYS == status.task_mode) && pMenuBar->IsChecked(ID_ADVACTIVITYRUNALWAYS)) return;
    if ((RUN_MODE_NEVER == status.task_mode) && pMenuBar->IsChecked(ID_ADVACTIVITYSUSPEND)) return;
    if ((RUN_MODE_AUTO == status.task_mode) && pMenuBar->IsChecked(ID_ADVACTIVITYRUNBASEDONPREPERENCES)) return;

    if (RUN_MODE_ALWAYS == status.task_mode) {
        if (!pMenuBar->IsChecked(ID_ADVACTIVITYRUNALWAYS)) {
            pMenuBar->Check(ID_ADVACTIVITYRUNALWAYS, true);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYSUSPEND)) {
            pMenuBar->Check(ID_ADVACTIVITYSUSPEND, false);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYRUNBASEDONPREPERENCES)) {
            pMenuBar->Check(ID_ADVACTIVITYRUNBASEDONPREPERENCES, false);
        }
    }
    if (RUN_MODE_NEVER == status.task_mode) {
        if (!pMenuBar->IsChecked(ID_ADVACTIVITYSUSPEND)) {
            pMenuBar->Check(ID_ADVACTIVITYSUSPEND, true);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYRUNALWAYS)) {
            pMenuBar->Check(ID_ADVACTIVITYRUNALWAYS, false);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYRUNBASEDONPREPERENCES)) {
            pMenuBar->Check(ID_ADVACTIVITYRUNBASEDONPREPERENCES, false);
        }
    }
    if (RUN_MODE_AUTO == status.task_mode) {
        if (!pMenuBar->IsChecked(ID_ADVACTIVITYRUNBASEDONPREPERENCES)) {
            pMenuBar->Check(ID_ADVACTIVITYRUNBASEDONPREPERENCES, true);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYRUNALWAYS)) {
            pMenuBar->Check(ID_ADVACTIVITYRUNALWAYS, false);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYSUSPEND)) {
            pMenuBar->Check(ID_ADVACTIVITYSUSPEND, false);
        }
    }
}

void CAdvancedFrame::UpdateGPUModeControls( CC_STATUS& status ) {
    wxMenuBar* pMenuBar = GetMenuBar();
    wxASSERT(pMenuBar);
    wxASSERT(wxDynamicCast(pMenuBar, wxMenuBar));

    if ((RUN_MODE_ALWAYS == status.gpu_mode) && pMenuBar->IsChecked(ID_ADVACTIVITYGPUALWAYS)) return;
    if ((RUN_MODE_NEVER == status.gpu_mode) && pMenuBar->IsChecked(ID_ADVACTIVITYGPUSUSPEND)) return;
    if ((RUN_MODE_AUTO == status.gpu_mode) && pMenuBar->IsChecked(ID_ADVACTIVITYGPUBASEDONPREPERENCES)) return;

    if (RUN_MODE_ALWAYS == status.gpu_mode) {
        if (!pMenuBar->IsChecked(ID_ADVACTIVITYGPUALWAYS)) {
            pMenuBar->Check(ID_ADVACTIVITYGPUALWAYS, true);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYGPUSUSPEND)) {
            pMenuBar->Check(ID_ADVACTIVITYGPUSUSPEND, false);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYGPUBASEDONPREPERENCES)) {
            pMenuBar->Check(ID_ADVACTIVITYGPUBASEDONPREPERENCES, false);
        }
    }
    if (RUN_MODE_NEVER == status.gpu_mode) {
        if (!pMenuBar->IsChecked(ID_ADVACTIVITYGPUSUSPEND)) {
            pMenuBar->Check(ID_ADVACTIVITYGPUSUSPEND, true);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYGPUALWAYS)) {
            pMenuBar->Check(ID_ADVACTIVITYGPUALWAYS, false);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYGPUBASEDONPREPERENCES)) {
            pMenuBar->Check(ID_ADVACTIVITYGPUBASEDONPREPERENCES, false);
        }
    }
    if (RUN_MODE_AUTO == status.gpu_mode) {
        if (!pMenuBar->IsChecked(ID_ADVACTIVITYGPUBASEDONPREPERENCES)) {
            pMenuBar->Check(ID_ADVACTIVITYGPUBASEDONPREPERENCES, true);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYGPUALWAYS)) {
            pMenuBar->Check(ID_ADVACTIVITYGPUALWAYS, false);
        }
        if (pMenuBar->IsChecked(ID_ADVACTIVITYGPUSUSPEND)) {
            pMenuBar->Check(ID_ADVACTIVITYGPUSUSPEND, false);
        }
    }
}


void CAdvancedFrame::UpdateNetworkModeControls( CC_STATUS& status ) {
    wxMenuBar* pMenuBar = GetMenuBar();
    wxASSERT(pMenuBar);
    wxASSERT(wxDynamicCast(pMenuBar, wxMenuBar));

    if ((RUN_MODE_ALWAYS == status.network_mode) && pMenuBar->IsChecked(ID_ADVNETWORKRUNALWAYS)) return;
    if ((RUN_MODE_NEVER == status.network_mode) && pMenuBar->IsChecked(ID_ADVNETWORKSUSPEND)) return;
    if ((RUN_MODE_AUTO == status.network_mode) && pMenuBar->IsChecked(ID_ADVNETWORKRUNBASEDONPREPERENCES)) return;

    if (RUN_MODE_ALWAYS == status.network_mode) {
        if (!pMenuBar->IsChecked(ID_ADVNETWORKRUNALWAYS)) {
            pMenuBar->Check(ID_ADVNETWORKRUNALWAYS, true);
        }
        if (pMenuBar->IsChecked(ID_ADVNETWORKSUSPEND)) {
            pMenuBar->Check(ID_ADVNETWORKSUSPEND, false);
        }
        if (pMenuBar->IsChecked(ID_ADVNETWORKRUNBASEDONPREPERENCES)) {
            pMenuBar->Check(ID_ADVNETWORKRUNBASEDONPREPERENCES, false);
        }
    }
    if (RUN_MODE_NEVER == status.network_mode) {
        if (!pMenuBar->IsChecked(ID_ADVNETWORKSUSPEND)) {
            pMenuBar->Check(ID_ADVNETWORKSUSPEND, true);
        }
        if (pMenuBar->IsChecked(ID_ADVNETWORKRUNALWAYS)) {
            pMenuBar->Check(ID_ADVNETWORKRUNALWAYS, false);
        }
        if (pMenuBar->IsChecked(ID_ADVNETWORKRUNBASEDONPREPERENCES)) {
            pMenuBar->Check(ID_ADVNETWORKRUNBASEDONPREPERENCES, false);
        }
    }
    if (RUN_MODE_AUTO == status.network_mode) {
        if (!pMenuBar->IsChecked(ID_ADVNETWORKRUNBASEDONPREPERENCES)) {
            pMenuBar->Check(ID_ADVNETWORKRUNBASEDONPREPERENCES, true);
        }
        if (pMenuBar->IsChecked(ID_ADVNETWORKRUNALWAYS)) {
            pMenuBar->Check(ID_ADVNETWORKRUNALWAYS, false);
        }
        if (pMenuBar->IsChecked(ID_ADVNETWORKSUSPEND)) {
            pMenuBar->Check(ID_ADVNETWORKSUSPEND, false);
        }
    }
}


void CAdvancedFrame::UpdateRefreshTimerInterval( wxInt32 iCurrentNotebookPage ) {
    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::UpdateRefreshTimerInterval - Function Begin"));

    if (IsShown()) {
        wxWindow*       pwndNotebookPage = NULL;
        CBOINCBaseView* pView = NULL;


        wxASSERT(m_pNotebook);

        pwndNotebookPage = m_pNotebook->GetPage(iCurrentNotebookPage);
        wxASSERT(pwndNotebookPage);

        pView = wxDynamicCast(pwndNotebookPage, CBOINCBaseView);
        wxASSERT(pView);

        CMainDocument*  pDoc = wxGetApp().GetDocument();

        if (m_pPeriodicRPCTimer && m_pPeriodicRPCTimer->IsRunning()) {
            m_pPeriodicRPCTimer->Stop();

            // View specific refresh rates only apply when a connection to the core
            //   client has been established, otherwise the refresh rate should be 1
            //   second.
            if (pDoc) {
                wxASSERT(wxDynamicCast(pDoc, CMainDocument));
                if (pDoc->IsConnected()) {
                    // Set new view specific refresh rate
                    m_pPeriodicRPCTimer->Start(pView->GetViewRefreshRate() * 1000); 
                } else {
                    // Set view refresh rate to 1 second
                    m_pPeriodicRPCTimer->Start(1000); 
                }
            }
        }
    }

    wxLogTrace(wxT("Function Start/End"), wxT("CAdvancedFrame::UpdateRefreshTimerInterval - Function End"));
}


void CAdvancedFrame::StartTimers() {
    wxASSERT(m_pRefreshStateTimer);
    wxASSERT(m_pFrameRenderTimer);
    CBOINCBaseFrame::StartTimers();
    m_pRefreshStateTimer->Start();
    m_pFrameRenderTimer->Start();
}


void CAdvancedFrame::StopTimers() {
    wxASSERT(m_pRefreshStateTimer);
    wxASSERT(m_pFrameRenderTimer);
    CBOINCBaseFrame::StopTimers();
    m_pRefreshStateTimer->Stop();
    m_pFrameRenderTimer->Stop();
}

