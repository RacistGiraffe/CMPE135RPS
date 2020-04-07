#include "../include/ButtonPanel.h"

void ButtonPanel::init()
{
    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);

    // Round panel
    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *round_text = new wxStaticText(round_panel, wxID_ANY, "Round:");
    round_text->SetFont(round_text->GetFont().Larger());
    round_sizer->Add(round_text, 0, wxALIGN_RIGHT, 0);
    round_sizer->AddSpacer(20);

    // Panel to display current round
    round_count_value = new wxStaticText(round_panel, wxID_ANY, "");
    round_count_value->SetFont(round_count_value->GetFont().Larger());
    round_sizer->Add(round_count_value, 0, 0, 0);
    round_sizer->AddSpacer(20);

    round_panel->SetSizer(round_sizer);

    // Human Panel
    wxPanel *human_panel = new wxPanel(this, wxID_ANY);
    wxSizer *human_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *human_text = new wxStaticText(human_panel, wxID_ANY, "Human");
    human_text->SetFont(human_text->GetFont().Larger());
    human_sizer->Add(human_text, 0, 0, 0);
    human_sizer->AddSpacer(20);

    human_panel->SetSizer(human_sizer);

    // Button panel

    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 "Choose:");
    wxButton *rock_button     = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(ROCK));
    wxButton *paper_button    = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(PAPER));
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(SCISSORS));

    rock_button->Bind    (wxEVT_BUTTON, &ButtonPanel::on_rock, this);
    paper_button->Bind   (wxEVT_BUTTON, &ButtonPanel::on_paper, this);
    scissors_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_scissors, this);

    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(rock_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(paper_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(scissors_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);

    // Choice panel

    wxPanel *choice_panel = new wxPanel(this, wxID_ANY);
    wxSizer *choice_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *chosen_object_label =
            new wxStaticText(choice_panel, wxID_ANY, "Human chooses: ");
    chosen_button_name = new wxStaticText(choice_panel, wxID_ANY, "");
    chosen_button_name->SetFont(chosen_button_name->GetFont().Larger());

    choice_sizer->Add(chosen_object_label, 0, wxALIGN_RIGHT, 0);
    choice_sizer->Add(chosen_button_name, 0, 0, 0);
    choice_panel->SetSizer(choice_sizer);

    // Computer panel
    wxPanel *computer_panel = new wxPanel(this, wxID_ANY);
	wxSizer *computer_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *computer_text = new wxStaticText(computer_panel, wxID_ANY, "Computer");
	computer_text->SetFont(computer_text->GetFont().Larger());
	computer_sizer->Add(computer_text, 0, wxALIGN_CENTER, 0);
	computer_sizer->AddSpacer(20);
	computer_panel->SetSizer(computer_sizer);

	//Computer Prediction panel
	wxPanel *computer_predict_panel = new wxPanel(this, wxID_ANY);
	wxSizer *computer_predict_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *computer_predict_text = new wxStaticText(computer_predict_panel, wxID_ANY,
			"Computer predicts: ");
	computer_predict_text->SetFont(computer_predict_text->GetFont().Larger());
	computer_predict_sizer->Add(computer_predict_text, 0, wxALIGN_RIGHT, 0);
	computer_predict_sizer->AddSpacer(5);

	computer_choice_value = new wxStaticText(computer_predict_panel, wxID_ANY, "");
	computer_choice_value->SetFont(computer_choice_value->GetFont().Larger());
	computer_predict_sizer->Add(computer_choice_value, 0, 0, 0);
	computer_predict_sizer->AddSpacer(20);
	computer_predict_panel->SetSizer(computer_predict_sizer);

	//Computer selection panel
	wxPanel *computer_actual_panel = new wxPanel(this, wxID_ANY);
	wxSizer *computer_actual_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *computer_actual_text = new wxStaticText(computer_actual_panel, wxID_ANY,
			"So computer picks: ");
	computer_actual_text->SetFont(computer_actual_text->GetFont().Larger());
	computer_actual_sizer->Add(computer_actual_text, 0, wxALIGN_RIGHT, 0);
	computer_actual_sizer->AddSpacer(20);

	computer_actual_value = new wxStaticText(computer_actual_panel, wxID_ANY, "");
	computer_actual_value->SetFont(computer_actual_value->GetFont().Larger());
	computer_actual_sizer->Add(computer_actual_value, 0, 0, 0);
	computer_actual_sizer->AddSpacer(20);
	computer_actual_panel->SetSizer(computer_actual_sizer);


	wxPanel *winner_panel = new wxPanel(this, wxID_ANY);
	wxSizer *winner_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *winner_text = new wxStaticText(winner_panel, wxID_ANY,
			"Winner: ");
	winner_text->SetFont(winner_text->GetFont().Larger());
	winner_sizer->Add(winner_text, 0, wxALIGN_CENTER, 0);
	winner_sizer->AddSpacer(20);

	winner = new wxStaticText(winner_panel, wxID_ANY, "");
	winner->SetFont(winner->GetFont().Larger());
	winner_sizer->Add(winner, 0, 0, 0);
	winner_sizer->AddSpacer(20);
	winner_panel->SetSizer(winner_sizer);

	winner_panel->SetSizer(winner_sizer);

	// Statistics panel
	wxPanel *statistics_panel = new wxPanel(this, wxID_ANY);
	wxSizer *statistics_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *statistics_text = new wxStaticText(statistics_panel, wxID_ANY, "Statistics");
	statistics_text->SetFont(statistics_text->GetFont().Larger());
	statistics_sizer->Add(statistics_text, 0, wxALIGN_CENTER, 0);
	statistics_sizer->AddSpacer(20);
	statistics_panel->SetSizer(statistics_sizer);

	// Player wins panel
	wxPanel *player_wins_panel = new wxPanel(this, wxID_ANY);
	wxSizer *player_wins_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *player_wins_text = new wxStaticText(player_wins_panel, wxID_ANY,
			"Human wins: ");
	player_wins_text->SetFont(player_wins_text->GetFont().Larger());
	player_wins_sizer->Add(player_wins_text, 0, wxALIGN_CENTER, 0);
	player_wins_sizer->AddSpacer(20);

	player_wins_count = new wxStaticText(player_wins_panel, wxID_ANY, "");
	player_wins_count->SetFont(player_wins_count->GetFont().Larger());
	player_wins_sizer->Add(player_wins_count, 0, 0, 0);
	player_wins_sizer->AddSpacer(20);
	player_wins_panel->SetSizer(player_wins_sizer);

	// Computer wins panel
	wxPanel *computer_wins_panel = new wxPanel(this, wxID_ANY);
	wxSizer *computer_wins_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *computer_wins_text = new wxStaticText(computer_wins_panel, wxID_ANY,
			"Computer wins: ");
	computer_wins_text->SetFont(computer_wins_text->GetFont().Larger());
	computer_wins_sizer->Add(computer_wins_text, 0, wxALIGN_CENTER, 0);
	computer_wins_sizer->AddSpacer(20);

	computer_wins_count = new wxStaticText(computer_wins_panel, wxID_ANY, "");
	computer_wins_count->SetFont(computer_wins_count->GetFont().Larger());
	computer_wins_sizer->Add(computer_wins_count, 0, 0, 0);
	computer_wins_sizer->AddSpacer(20);
	computer_wins_panel->SetSizer(computer_wins_sizer);

	// Tie panel
	wxPanel *tie_panel = new wxPanel(this, wxID_ANY);
	wxSizer *tie_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *tie_text = new wxStaticText(tie_panel, wxID_ANY,
			"Ties: ");
	tie_text->SetFont(tie_text->GetFont().Larger());
	tie_sizer->Add(tie_text, 0, wxALIGN_CENTER, 0);
	tie_sizer->AddSpacer(20);

	tie_count = new wxStaticText(tie_panel, wxID_ANY, "");
	tie_count->SetFont(tie_count->GetFont().Larger());
	tie_sizer->Add(tie_count, 0, 0, 0);
	tie_sizer->AddSpacer(20);
	tie_panel->SetSizer(tie_sizer);



    // Main panel
    main_panel_sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(human_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(5);
    main_panel_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(5);
    main_panel_sizer->Add(choice_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(computer_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(5);
	main_panel_sizer->Add(computer_predict_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(5);
	main_panel_sizer->Add(computer_actual_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(20);
	main_panel_sizer->Add(winner_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(20);
	main_panel_sizer->Add(statistics_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(5);
	main_panel_sizer->Add(player_wins_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(5);
	main_panel_sizer->Add(computer_wins_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(5);
	main_panel_sizer->Add(tie_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(5);

    SetSizer(main_panel_sizer);
}

void ButtonPanel::on_rock(wxCommandEvent& event)
{
    update_button_choice_text(ROCK);

}

void ButtonPanel::on_paper(wxCommandEvent& event)
{
    update_button_choice_text(PAPER);
}

void ButtonPanel::on_scissors(wxCommandEvent& event)
{
    update_button_choice_text(SCISSORS);
}

void ButtonPanel::update_button_choice_text(const Choice choice)
{
    chosen_button_name->SetLabelText(choice_to_wxString(choice));

    if(choice == ROCK)
    	RPS->player.setplayerselection(1);
    else if (choice == PAPER)
    	RPS->player.setplayerselection(2);
    else
    	RPS->player.setplayerselection(3);

    update_computer_actual_text(ROCK);
    update_computer_choice_text(ROCK);
    update_winner(0);
}

void ButtonPanel::update_computer_choice_text(const Choice choice)
{
	//int temp = RPS->computer->get_guess();
	int temp = 1;
	if(temp == 1)
		computer_choice_value->SetLabelText(choice_to_wxString(ROCK));
	else if (temp == 2)
		computer_choice_value->SetLabelText(choice_to_wxString(PAPER));
	else if (temp == 3)
		computer_choice_value->SetLabelText(choice_to_wxString(SCISSORS));
	else
		computer_choice_value->SetLabelText(choice_to_wxString(NONE));
}

void ButtonPanel::update_computer_actual_text(const Choice choice)
{
    RPS->computer->setcomputerselection();
    int temp = RPS->computer->getcomputerselection();
    if(temp == 1)
    	computer_actual_value->SetLabelText(choice_to_wxString(ROCK));
    else if (temp == 2)
    	computer_actual_value->SetLabelText(choice_to_wxString(PAPER));
    else if (temp == 3)
    	computer_actual_value->SetLabelText(choice_to_wxString(SCISSORS));
}

void ButtonPanel::update_winner(int x)
{
    round_counter++;
	int temp = RPS->gameresult(RPS->player.getplayerselection(), RPS->computer->getcomputerselection());
	if(temp == 0)
		winner->SetLabelText("Tie");
	else if (temp == 1)
		winner->SetLabelText("Player");
	else if (temp == 2)
		winner->SetLabelText("Computer");
    round_count_value->SetLabelText(std::to_string(round_counter));
	update_statistics(temp);
}

void ButtonPanel::update_statistics(int x){
	if(x == 2) {
		player_wins_count->SetLabelText(std::to_string(RPS->get_player_score()));
	}

	else if (x == 1) {
		computer_wins_count->SetLabelText(std::to_string(RPS->get_computer_score()));
	}

	else {
		tie_count->SetLabelText(std::to_string(RPS->get_tie_score()));

	}
}

