#include "../include/DemoFrame.h"
// The event table.
wxBEGIN_EVENT_TABLE(DemoFrame, wxFrame)
    EVT_MENU(RPS_About, DemoFrame::on_about)
    EVT_MENU(RPS_Quit,  DemoFrame::on_quit)
	EVT_MENU(ID_Restart, DemoFrame::on_new_game)
	EVT_MENU(ID_Setrounds, DemoFrame::on_set)
wxEND_EVENT_TABLE()
const int SIDE_MARGINS = 40;
DemoFrame::DemoFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title),
      button_panel(new ButtonPanel(this))
{
    init();
    wxSize size = GetSize();
    size.SetWidth (size.GetWidth() + SIDE_MARGINS);
    SetSize(size);
}
DemoFrame::~DemoFrame()
{
    delete button_panel;
}
void DemoFrame::init()
{
    init_menu_bar();
    init_sizer();
    wxSize size = GetBestSize();
    SetMinClientSize(size);
}
void DemoFrame::init_sizer()
{
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);
    frame_sizer->AddSpacer(20);
    frame_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    SetSizerAndFit(frame_sizer);
}
void DemoFrame::init_menu_bar()
{
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(RPS_Quit,  "&Exit\tAlt-X", "Quit program");
    wxMenu *gameMenu = new wxMenu;
    gameMenu->Append(ID_Setrounds, "Set Rounds");
    gameMenu->Append(ID_Restart, "New game");
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(RPS_About, "&About\tF1",   "Show about dialog");
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(gameMenu, "&Game");
    menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar);
}
void DemoFrame::on_about(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format(
                    "This is a rock paper scissors game\n"
                    "built with %s\n"
                    "and running under %s.\n"
    				"Written by: \n"
    				"Omar Habra\n"
    				"Zachary Nguyen\n"
    				"Shalvin Prasad\n"
    				"Ryota Suzuki",
                    wxVERSION_STRING,
                    wxGetOsDescription()
                ),
                "About the button demo",
                wxOK | wxICON_INFORMATION,
                this);
}
void DemoFrame::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}

//Function to clear screen of values
void DemoFrame::on_new_game(wxCommandEvent& WXUNUSED(event))
{
	button_panel->new_game_screen();
}

//Function to change max number of rounds. Forces a new game.
void DemoFrame::on_set(wxCommandEvent& WXUNUSED(event))
{
    wxString rounds_input;
    wxTextEntryDialog new_rounds;
    new_rounds.Create(this, "Enter the new number of rounds you want to play");
    new_rounds.ShowModal();
    rounds_input = new_rounds.GetValue();
    int rounds = wxAtoi(rounds_input);
    wxMessageBox(wxString::Format("Beginning new game, press 'OK' to start\n"));
    button_panel->new_game();
    button_panel->update_round_count(rounds);
}



