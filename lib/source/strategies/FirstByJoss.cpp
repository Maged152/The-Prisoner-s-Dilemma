#include "strategies.hpp"

namespace qlm
{
    // constructor
    FirstByJoss::FirstByJoss()
    {
        name = "First by Joss: 0.9";
        info = "This rule cooperates 90% of the time after a cooperation by the other. It > always defects after a defection by the other.";
        probabilistic_action = true;
        properties.niceness = 0; // the others are not obvious or important as this
        flags.reset();
    }

    // First action function
    Choice FirstByJoss::FirstAction()
    {
        const Choice action = Choice::COOPERATE;
        my_history.push_back(action);
        return action;
    }

    // Action function
    Choice FirstByJoss::Action(const Choice opponent_play)
    {
        constexpr float probability = 0.9;
        Choice action = Choice::DEFECT;

        // check players previous moves 
        if (opponent_play == Choice::COOPERATE)
        {
            // cooperates with probability 0.9
            action = random_gen.random_choice(probability);
        }

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

    // rest function
    void FirstByJoss::Reset()
    {
        flags.reset();
        my_history.clear();
        opponent_history.clear();
        random_gen.Reset();
    }

}