#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <limits>

int emberStrength = 10;
const int EMBER_CRITICAL = 3;
const int EMBER_FADING = 6;
void pause(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void type_text(const std::string& text, int delay_ms = 50) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
    std::cout << std::endl;
}

void displayEmberStatus() {
    std::cout << "[ ";
    if (emberStrength <= 0) {
        type_text("The ember is extinguished.", 60);
    } else if (emberStrength <= EMBER_CRITICAL) {
        type_text("The ember is a tiny, fragile spark, threatening to wink out at any moment.", 60);
    } else if (emberStrength <= EMBER_FADING) {
        type_text("The ember glows weakly, pulsing faintly.", 60);
    } else {
        type_text("The ember provides a frail, flickering light.", 60);
    }
    std::cout << " ]" << std::endl;
    pause(1);
}

std::string getChoice(const std::string& prompt1, const std::string& prompt2) {
    std::string choice;
    while (true) {
        std::cout << "\nDo you: " << std::endl;
        std::cout << "1. " << prompt1 << std::endl;
        std::cout << "2. " << prompt2 << std::endl;
        std::cout << "> ";
        std::cin >> choice;

        if (choice == "1" || choice == "2") {
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        } else {
            std::cout << "The cold numbs your thoughts. Choose 1 or 2." << std::endl;
             std::cin.clear(); 
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            pause(1);
        }
    }
}

void introduction() {
    type_text("Silence, save for the wind's mournful howl.", 70);
    pause(2);
    type_text("It bites, cold and relentless through your threadbare cloak.", 70);
    pause(2);
    type_text("Each breath aches, a plume of white against the oppressive grey dusk.", 70);
    pause(2);
    type_text("You cradle your hands, shielding the last ember.", 70);
    displayEmberStatus();
    pause(2);
    type_text("It remembers warmth. It remembers light. But the memory fades.", 80);
    pause(3);
    type_text("Sunstone Ridge. You must reach it. Before the last light dies.", 70);
    type_text("Before *you* die.", 100);
    pause(3);
    std::cout << std::endl;
}

void stage_forest() {
    type_text("Skeletal trees claw at the sky. Their branches scrape in the wind.", 60);
    pause(2);
    type_text("Snowdrifts obscure the path, swallowing the faint trail.", 60);
    pause(2);
    type_text("Your legs tremble. A deep weariness settles in your bones, colder than the air.", 70);
    pause(2);
    displayEmberStatus();
    pause(1);
    type_text("A fleeting image: firelight on a smiling face. Gone, like smoke.", 80);
    pause(3);

    std::string choice = getChoice(
        "Force a path through the deep snow (Faster, Costs Strength)",
        "Seek a longer, clearer path around (Slower, Conserves Strength)"
    );

    if (choice == "1") {
        type_text("\nYou plunge into the drift. Icy powder bites your face.", 70);
        type_text("Each step is a monumental effort, stealing breath and heat.", 70);
        emberStrength -= 3; 
        type_text("The exertion makes your vision swim. The ember shrinks, visibly dimmer.", 80);
        pause(3);
    } else { 
        type_text("\nYou follow the treeline, the snow shallower but the way longer.", 70);
        type_text("Time bleeds away into the encroaching night. The wind finds every gap in your clothing.", 70);
        emberStrength -= 1; 
         type_text("Shivering, you glance down. The ember seems frail, starved for warmth.", 80);
        pause(3);
    }


    if (emberStrength <= 0) return;

    displayEmberStatus();
    std::cout << std::endl;
}

void stage_ascent() {
     if (emberStrength <= 0) return;

    type_text("The ridge looms - an imposing wall of rock and ice.", 60);
    pause(2);
    type_text("The wind shrieks here, tearing at you, threatening to rip the ember from your grasp.", 70);
    pause(2);
    type_text("A rattling cough shakes your frame. Your breath catches. Black spots dance.", 80);
    pause(3);
    displayEmberStatus();
    pause(1);
    type_text("So close... just a little further...", 100);
    pause(2);


    std::string choice = getChoice(
        "Rest briefly, shield the ember (Risk freezing, Small Ember Gain?)",
        "Begin the final climb now (Risk exhaustion, Major Ember Cost)"
    );


    if (choice == "1") {
        type_text("\nYou crouch behind an icy boulder, curling around your cupped hands.", 70);
        type_text("The wind howls overhead. For a moment, the ember pulses slightly brighter.", 80);
        emberStrength += 1; 
        pause(3);
        type_text("But the stillness allows the deep cold to truly sink in. Your limbs grow heavy, numb.", 70);
        emberStrength -= 1; 
        type_text("Was it worth it? The spark flickers precariously.", 90);
        pause(3);
    } else { 
        type_text("\nYou grit your teeth and start scrambling upwards.", 70);
        type_text("Icy rock scrapes numb fingers. Muscles scream in protest.", 70);
        type_text("Every upward lurch sends tremors through you.", 80);
        emberStrength -= 4; 
        type_text("A wave of dizziness washes over you. The ember flares violently, then settles, terrifyingly small.", 90);
        pause(3);
    }



    displayEmberStatus();
    std::cout << std::endl;
}

void final_moments() {
    
    if (emberStrength <= 0) {
         type_text("Darkness overtook you before the summit.", 90);
         pause(3);
         type_text("The snow is your only blanket now.", 100);
         pause(4);
         return; 
    }


    type_text("The crest... You're here. Almost.", 80);
    pause(3);
    type_text("Ahead... the Sunstone. Bathed in the absolute final rays of the dying sun.", 70);
    type_text("It pulses with a soft, deep warmth, a stark contrast to the world.", 70);
    pause(3);

    if (emberStrength > EMBER_CRITICAL) {
         type_text("You take a step. Another.", 90);
         type_text("Hope, fragile and unexpected, flickers within you.", 80);
         pause(2);
         emberStrength = 1; 
    } else {
         type_text("You drag yourself forward, crawling.", 90);
          type_text("Just... inches...", 120);
         pause(2);
    }


    type_text("Your knees strike the frozen ground.", 100);
    pause(3);
    type_text("You reach out a trembling hand...", 80);
    pause(2);
    type_text("...fingertips brush the stone's impossible warmth...", 110);
    pause(3);
    type_text("In your other hand, the ember...", 90);
    pause(3);
    type_text("...gives one last, soft sigh of light...", 120);
    pause(4);
    type_text("...and is gone.", 150);
    pause(4);
    type_text("The warmth on your fingertips fades.", 100);
    pause(2);
    type_text("Darkness claims your sight.", 200);
    pause(3);
    type_text("Silence answers the wind.", 200);
    pause(4);
    type_text("You lie still on the ridge, hand upon the cooling stone.", 80);
    type_text("The snow falls softly, blanketing the world in white.", 80);
    pause(5);
}


int main() {
    introduction();

    if (emberStrength > 0) {
        stage_forest();
    }

    if (emberStrength > 0) {
        stage_ascent();
    }

    final_moments(); 

    std::cout << "\n\n\n[ THE LAST EMBER ]" << std::endl;
    pause(3);
    std::cout << "\nPress Enter to exit...";
    std::cin.get(); 

    return 0;
}