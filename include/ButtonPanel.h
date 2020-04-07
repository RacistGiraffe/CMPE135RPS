#ifndef BUTTONPANEL_H_
#define BUTTONPANEL_H_

#include "ButtonDemo.h"
#include "Choice.h"
#include "../include/Game.h"

/**
 * The button panel of the application frame.
 */
class ButtonPanel : public wxPanel
{
public:
    /**
     * Constructor.
     * @param parent the parent frame.
     */
    ButtonPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
    	RPS = new Game;
        init();
    }

    void new_game()
    {
    	delete RPS;
    	RPS = new Game;
    }

    /**
     * Event handler for the rock button.
     * @param event the button click event.
     */
    void on_rock(wxCommandEvent& event);

    /**
     * Event handler for the paper button.
     * @param event the button click event.
     */
    void on_paper(wxCommandEvent& event);

    /**
     * Event handler for the scissors button.
     * @param event the button click event.
     */
    void on_scissors(wxCommandEvent& event);
    void update_round_count(int x);
    void new_game_screen();



private:
    Game *RPS;
    wxStaticText *chosen_button_name;
    wxStaticText *round_count_value;
    wxStaticText *computer_choice_value;
    wxStaticText *computer_actual_value;
    wxStaticText *winner;
    wxStaticText *player_wins_count;
    wxStaticText *computer_wins_count;
    wxStaticText *tie_count;
    int round_counter = 0;


    /**
     * Initialize the panel contents.
     */
    void init();

    /**
     * Update the displayed button choice object.
     * @param choice the chosen object.
     */
    void update_button_choice_text(const Choice choice);
    void update_computer_choice_text(const Choice choice);
    void update_computer_actual_text(const Choice choice);
    void update_winner(int x);
    void update_statistics(int x);
    void game_over();
};

#endif /* BUTTONPANEL_H_ */
