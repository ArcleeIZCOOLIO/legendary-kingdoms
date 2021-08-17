#ifndef __BOOK1__HPP__
#define __BOOK1__HPP__

#include "story.hpp"

namespace Book1
{
    auto Stories = std::vector<Story::Base *>();

    void LOST_SCHOLAR(Party::Base &party)
    {
        if (!Engine::VERIFY_CODES(party, {Codes::Type::LOST_SCHOLAR3}))
        {
            if (Engine::VERIFY_CODES(party, {Codes::Type::LOST_SCHOLAR2}))
            {
                Engine::GET_CODES(party, {Codes::Type::LOST_SCHOLAR3});
                Engine::LOSE_CODES(party, {Codes::Type::LOST_SCHOLAR2});
            }
            else if (Engine::VERIFY_CODES(party, {Codes::Type::LOST_SCHOLAR1}))
            {
                Engine::GET_CODES(party, {Codes::Type::LOST_SCHOLAR2});
                Engine::LOSE_CODES(party, {Codes::Type::LOST_SCHOLAR1});
            }
            else
            {
                Engine::GET_CODES(party, {Codes::Type::LOST_SCHOLAR1});
            }
        }
    }

    class Story001 : public Story::Base
    {
    public:
        Story001()
        {
            BookID = Book::Type::BOOK1;

            ID = 1;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Image = "images/legendary-kingdoms-logo.png";

            Text = "You stir into consciousness. Heat and blazing sunlight... the slow rumble of a wagon... heavy chains upon your limbs. You groan, your mouth dry, your stomach empty. As your eyes focus you can see your companions, fellow survivors of the brutal pirate attack, crushed together with you upon the floor of a rolling wagon. You remember little since then, except vowing to your newfound friends that you would stick together, come what may. You are relieved to see that they are still alive, but where are you?\n\nGazing through the bars of the wagon, your eyes focus on a blazing yellow-grey desert. To your left, filling the sky, are the Stonewalls -- a massive and impenetrable mountain range that divides the barbarian kingdoms of the south from the antique and mysterious lands of Drakehallow. But which side of the range are you? The answer becomes immediately apparent as you look beyond the smelly dragonyaks which are ponderously hauling your cage. A vast, crumbling city of minarets and run-down adobe buildings fills your view. The sting in the air and on your lips tells you all you need to know. This is Saltdad, cruel throne of the tyrant Iron King, one of half a dozen tin-pot dictators in the barbaric Valley of Bones. You are far from civilised lands here...\n\nThin-faced slavers with spears rattle the sides of your cage, barking at you to get down. You slump on your hindquarters. For the moment there is nothing you can do with you and your companions in chains. You swear you will regain your freedom and start your lives anew. But first, you must survive the horrors of slavery.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::STARTED_IN_BOOK1, Codes::Type::FIRSTTIME_SOLD_SALTDADARENA});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 631}; }
    };

    class Story002 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story002()
        {
            BookID = Book::Type::BOOK1;

            ID = 2;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The orcs snarl as they see you, lurching to attack.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            CanFlee = true;

            FleeRound = 0;

            Monsters = {
                Monster::Base("Orc", 6, 4, 4, 8, 0),
                Monster::Base("Orc", 4, 4, 3, 9, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::FLEE)
            {
                Bye = "The orcs chase you out of the dungeon.";

                destination = {Book::Type::BOOK1, 515};
            }
            else
            {
                destination = {Book::Type::BOOK1, 478};
            }
        }
    };

    class Story003 : public Story::Base
    {
    public:
        Story003()
        {
            BookID = Book::Type::BOOK1;

            ID = 3;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Text = "The treasure chest contains 200 silver coins and a BLUESTONE. Take what you wish.\n\nNote: You gained the code A45.";

            Bye = "Not wishing to tarry longer, you depart the chamber and return to the crossroads.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::BLUESTONE};

            Limit = 1;

            Engine::GAIN_MONEY(party, 200);

            Engine::GET_CODES(party, {Codes::A(45)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 46}; }
    };

    class Story004 : public Story::Base
    {
    public:
        Story004()
        {
            BookID = Book::Type::BOOK1;

            ID = 4;

            Text = "You swoop Amelia up into your arms just before she reaches the wine barrel. She shrieks in delight and throws an arm around your neck.\n\n\"Is it my prinsh charming?\" she slurs, nuzzling into your chest.\n\n\"Well... if by prince you meant castle pot-washer, then yes,\" you smile, carrying her over to her quarters in the palace.\n\n\"Tell me something,\" says Amelia dreamily, between snoozes, as you bear her through the palace. \"Why are you so charming to everyone except me?\"\n\n\"Charming is another word for lying,\" you say in a rare moment of honesty. \"I'd never lie to you, Amelia...\"\n\nHer snores cut off a potentially romantic moment. Tucking her into bed you go to join the rest of your companions.\n\nNote: Amelia has gained a heart for Brash. Brash also gains a heart for Amelia.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEARTS(party, Character::Type::AMELIA_PASS_DAYNE, Character::Type::BRASH, 1);
            Engine::GAIN_HEARTS(party, Character::Type::BRASH, Character::Type::AMELIA_PASS_DAYNE, 1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 280}; }
    };

    class Story005 : public Story::Base
    {
    public:
        Story005()
        {
            BookID = Book::Type::BOOK1;

            ID = 5;

            Location = Location::Type::LHASBREATH;

            Text = "You meet up with the lead scholar, Emlyn Pass-Ross, who is already loading supplies onto the mules. She is joined by three other young scholars who look fresh out of university. They don't look the type who could handle themselves in a dangerous jungle.\n\n\"We'll follow our established route into the jungle, and then branch off south once we reach the checkpoint,\" says Emlyn. \"We've discovered all sorts of interesting plants, but so far surprisingly little that is edible.\"\n\n\"What kind of dangers will we face?\" you ask.\n\n\"Most of the jungle beasts leave us alone... to be honest, the monkeys are the most dangerous things you'll find. They travel in huge packs. They're intelligent, thieving sorts. You should watch out for them.\"\n\nSir Lawrence emerges from his tent to kiss his daughter goodbye and to wish you luck. Soon you have emerged from the wooden gates of Lhasbreath and are making your way towards the wall of trees that is the Lhasbreath jungle. Within the canopy of the jungle it is hot and humid. The ground is moist and seems to be the nest of thousands of tiny, biting insects. It must have rained recently, for the path ahead is flooded. Emlyn curses. She intended to take that route through the jungle to reach the checkpoint.";

            Choices.clear();
            Choices.push_back(Choice::Base("Follow the flooded path anyway", {Book::Type::BOOK1, 609}));
            Choices.push_back(Choice::Base("Take the expedition off the path and lead them through the jungle", {Book::Type::BOOK1, 863}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story006 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story006()
        {
            BookID = Book::Type::BOOK1;

            ID = 6;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You have already attempted to find a SILVER IDOL in the Caves of Uranu.";

            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::SILVER_IDOL}))
            {
                PreText += " You were successful and you do not need to look again.";
            }
            else
            {
                PreText += " You failed, you will not find another here.";
            }

            PreText += " Either way, you must choose again.";

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 346}; }
    };

    class Story007 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story007()
        {
            BookID = Book::Type::BOOK1;

            ID = 7;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            auto jessica = Engine::IN_TEAM(party, Character::Type::SAR_JESSICA_DAYNE, Team::Type::DISTRACTION);
            auto akihiro = Engine::IN_TEAM(party, Character::Type::AKIHIRO_OF_CHALICE, Team::Type::DISTRACTION);

            if (jessica || akihiro)
            {
                if (jessica && akihiro)
                {
                    PreText = "Sar Jessica Dayne and Akihiro refuse";
                }
                else if (jessica)
                {
                    PreText = "Sar Jessica Dayne refuses";
                }
                else
                {
                    PreText = "Akihiro refuses";
                }

                PreText += " to comply. ";

                if (jessica && akihiro)
                {
                    PreText = "Their";
                }
                else if (jessica)
                {
                    PreText = "Sar Jessica Dayne's";
                }
                else
                {
                    PreText = "Akihiro's";
                }

                PreText += " sense of personal honour ";

                if (jessica && akihiro)
                {
                    PreText = "are";
                }
                else
                {
                    PreText = "is";
                }

                PreText += " too strict to attempt such a strategy.";
            }
            else
            {
                PreText = "The guards have been looking at you with hungry eyes recently. You sidle up to the gate-house guards, suggesting all sorts of pleasures could await them in exchange for a few paltry rations.";

                if (Engine::VERIFY_CODES(party, {Codes::Type::WEAPON_AND_DISTRACTION}))
                {
                    Choices.push_back(Choice::Base("Seduce the Guards (Team check: Charisma 3+, Successes: 2)", {Book::Type::BOOK1, 364}, {Book::Type::BOOK1, 588}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 3, 2));
                }
                else
                {
                    Choices.push_back(Choice::Base("Seduce the Guards (Team check: Charisma 3+, Successes: 2)", {Book::Type::BOOK1, 364}, {Book::Type::BOOK1, 588}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::DISTRACTION, {Attribute::Type::CHARISMA}, 3, 2));
                }
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 169}; }
    };

    class Story008 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story008()
        {
            BookID = Book::Type::BOOK1;

            ID = 8;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            PreText = "You cast your eye over the book. It seems to detail instructions about how to prepare skeletons for animation and control.";

            if (!Engine::VERIFY_CODES(party, {Codes::A(75)}))
            {
                PreText += "\n\nIt looks like the hard work has been done for you. Four skeletons have been laid out and prepared in exactly the right way for animation. The book claims you will even be able to have the skeletons fight for you, though they lack the wit for more complex tasks.";

                Choices.push_back(Choice::Base("Invoke the ritual", {Book::Type::BOOK1, 419}));
                Choices.push_back(Choice::Base("Return to the crossroads", {Book::Type::BOOK1, 310}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 419}; }
    };

    class Story009 : public Story::Base
    {
    public:
        Story009()
        {
            BookID = Book::Type::BOOK1;

            ID = 9;

            Text = "With a high kick you send the final monk sprawling. The other monks in the temple lower their eyes and return to their duties, unwilling to block your progress further. You retrieve your weapon and march smartly into the temple.\n\nHonnu is waiting for you, cross-legged on the floor. You join him in meditation for an hour or so, your companions venturing elsewhere in the city now they can see you are safe. \"It is rare for a supplicant to be granted the trials of perfection twice, but you are an unusual man, Akihiro. You must know that your father never returned from the trials. But I sense in you a steel he never had.\"\n\n\"Thank you, Honnu,\" you say, bowing your head.\n\n\"There would be little point in having you study at the temple, you are already skilled in your craft,\" shrugs Honnu. \"Instead I shall send you straight onto your tasks. Two must be completed before you are deemed worthy. It is traditional to send an applicant to retrieve some trifling artefact as proof of dedication; a tedious matter, since the only item of true worth is enlightenment. Therefore, I bid you find me a SILVER IDOL. Find yourself, Akihiro, whilst you are at it.\"\n\n\"Where can I find a SILVER IDOL?\" you ask unsurely.\n\n\"I'm sure more than one exists, but a man of open mind and willing to embrace his destiny might find one in the caves of Uranu,\" suggests Honnu. \"That place has tested, and slain, many a kensai aspirant. Go wisely, Akihiro. I shall see you soon.\"\n\nNote: You gained the code A50.";

            Bye = "You rise, bow, and go to re-join your companions.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(50)});

            Engine::REJOIN(party);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story010 : public Story::Base
    {
    public:
        Story010()
        {
            BookID = Book::Type::BOOK1;

            ID = 10;

            Text = "\"You should send the man to the Church of Cursus and have priests ritually scar him,\" says Ti'quon coldly.\n\n\"That way he shall be both punished and spiritually improved.\"\n\n\"Yes!\" hisses the King. \"The scarring is most painful. Send this dog to the church!\"\n\nThe poor man is dragged away, and the king retires with his councillors to discuss other business. You take the opportunity to slip away from the hall.\n\n\"A rather harsh punishment, ritual scarring,\" you mutter to Ti'quon as you exit the building.\n\n\"True enough,\" admits Ti'quon. \"Except that I noticed the poor man had already been scarred by the priests, and it is forbidden to perform the ritual twice. Getting him out of the sight of the mad king seemed to be the most important thing.\"\n\nYou shake your head, smiling.\n\nNote: You gained the code A34.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(34)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story011 : public Story::Base
    {
    public:
        Story011()
        {
            BookID = Book::Type::BOOK1;

            ID = 11;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You carefully begin to sneak out of the chamber, but you are out of luck. The orcs spot you as you attempt to climb the stairs, and leap to a savage attack.\n\nThe slaves cannot help you in this battle, as their chains are too short to attack the orcs now they are at the back of the chamber fighting you.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 213}; }
    };

    class Story012 : public Story::Base
    {
    public:
        Story012()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::WEST_ROAD;

            ID = 12;

            Text = "You are making your way across the Westroad, an ancient highway built-up to resist the burying sands of the Valley. Travellers and soldiers pass intermittently, making their way between the cities of Saltdad and Clifftop.";

            Choices.clear();
            Choices.push_back(Choice::Base("Random Event", {{2, NULL, {Book::Type::BOOK1, 466}}, {3, NULL, {Book::Type::BOOK1, 397}}, {6, NULL, {Book::Type::BOOK1, 569}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story013 : public Story::Base
    {
    public:
        Story013()
        {
            BookID = Book::Type::BOOK1;

            ID = 13;

            Location = Location::Type::MORDAIN;

            Text = "What do you wish to do now?";

            Choices.clear();
            Choices.push_back(Choice::Base("Board your ship", {Book::Type::BOOK1, 851}, Choice::Type::SHIP, Location::Type::MORDAIN));
            Choices.push_back(Choice::Base("Enter the wide tunnel", {Book::Type::BOOK1, 593}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story014 : public Story::Base
    {
    public:
        Story014()
        {
            BookID = Book::Type::BOOK1;

            ID = 14;

            Text = "You have returned to the Tumblestones, in the hope of discovering more ancient secrets. Alas, a recent sandstorm has buried the exposed stones, with only the stern face of the old king left unburied, to stare across his ruined empire for all eternity.\n\nDisappointed, you leave.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 453}; }
    };

    class Story015 : public Story::Base
    {
    public:
        Story015()
        {
            BookID = Book::Type::BOOK1;

            ID = 15;

            Text = "There are few valuables amongst the goblins, though you manage to scavenge 15 silver coins from the entire horde. Pleased to have survived you make your way onwards.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 15);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 395}; }
    };

    class Story016 : public Story::Base
    {
    public:
        Story016()
        {
            BookID = Book::Type::BOOK1;

            ID = 16;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You have chosen to battle one of the dark knights of Abraxas. Good luck!\n\nNote: On any round when Skallos does not take damage, he will unleash a roar of black magic. Each party member must lose 1 point of Health, and Skallos will restore 4 points of Health, up to his maximum of 20 Health points.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Skallos", Monster::Type::SKALLOS, 9, 4, 5, 20, 0),
                Monster::Base("Green Skeletons", 8, 4, 3, 30, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 811}; }
    };

    class Story017 : public Story::Base
    {
    public:
        Story017()
        {
            BookID = Book::Type::BOOK1;

            ID = 17;

            Text = "The Iron King is most displeased to see you. He clicks his fingers and soon you have been dragged away to the dungeons for a gruesome session of torture. Each party member loses 4 Health points. Afterwards, the king has the guards dispose of you as they see fit.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::TITHE_REPORT}))
            {
                return {Book::Type::BOOK1, 246};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -4);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 55}; }
    };

    class Story018 : public Story::Base
    {
    public:
        Story018()
        {
            BookID = Book::Type::BOOK1;

            ID = 18;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The door in front of you is stuck. To get it open you will have to force it.";

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(57)}))
            {
                return {Book::Type::BOOK1, 350};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            temp_string = "";

            Choices.clear();

            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::PRYBAR}))
            {
                Choices.push_back(Choice::Base("Force open the door (Individual check: Fighting 4+, Successes: 3)", {Book::Type::BOOK1, 350}, {Book::Type::BOOK1, -18}, {Attribute::Type::FIGHTING}, 4, 3, false));
            }
            else
            {
                Choices.push_back(Choice::Base("Force open the door (Individual check: Fighting 5+, Successes: 3)", {Book::Type::BOOK1, 350}, {Book::Type::BOOK1, -18}, {Attribute::Type::FIGHTING}, 5, 3, false));
            }

            Choices.push_back(Choice::Base("Consider other exits from the room", {Book::Type::BOOK1, 494}));
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (outcome)
            {
                Bye = "The door pops open. You can explore the corridor beyond.\n\nNote: You gained the code A57.";

                Engine::GET_CODES(party, {Codes::A(57)});
            }
            else
            {
                temp_string = std::string(party.Members[selection[0]].Name) + " loses 1 Health point.";

                Bye = temp_string.c_str();

                Engine::GAIN_HEALTH(party.Members[selection[0]], -1);
            }
        }
    };

    // Dummy event to trigger Bye message in BOOK1:018
    class Event018 : public Story::Base
    {
    public:
        Event018()
        {
            BookID = Book::Type::BOOK1;

            ID = -18;

            DisplayID = 18;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party) { return {Book::Type::BOOK1, 18}; }
    };

    class Story019 : public Story::Base
    {
    public:
        Story019()
        {
            BookID = Book::Type::BOOK1;

            ID = 19;

            Location = Location::Type::CLIFFTOP;

            IsCity = true;

            Image = "images/book1/dreadful_city.png";

            Text = "You are in a dreadful city of poor mud-brick and grass hovels, surrounded by weed-filled cropland. Even the most impressive buildings are little more than timber halls, sagging under the weight of their own roofs. The local peasants are care-worn and well whipped, scarcely better dressed than slaves. The wealthier members of the town dress less well than a Saltdad commoner. The dissonant bells of the church of Cursus clang across town, followed by dirge-like processions of rag-wearing choristers singing hymns of dull praise to their uncaring deity.\n\nThe whole rotten town is perched atop a cliff some fifty or so feet tall, and yet this is a port city. A gigantic cargo crane leers over a thin and precarious path to the wooden harbour below, where at least some signs of life and love can be heard from the cluster of taverns that serve the sailors.";

            Choices.clear();
            Choices.push_back(Choice::Base("Visit the king's hall", {Book::Type::BOOK1, 557}));
            Choices.push_back(Choice::Base("Go to the marketplace", {Book::Type::BOOK1, 759}));
            Choices.push_back(Choice::Base("Go to the slave market", {Book::Type::BOOK1, 152}));
            Choices.push_back(Choice::Base("Visit the harbourside taverns", {Book::Type::BOOK1, 505}));
            Choices.push_back(Choice::Base("Go to the Church of Cursus", {Book::Type::BOOK1, 207}));
            Choices.push_back(Choice::Base("Head to the dockyard", {Book::Type::BOOK1, 703}));
            Choices.push_back(Choice::Base("Explore the city", {Book::Type::BOOK1, 354}));
            Choices.push_back(Choice::Base("Leave the city east, along the road", {Book::Type::BOOK1, 12}));
            Choices.push_back(Choice::Base("Leave the city south, into the desert", {Book::Type::BOOK1, 725}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            party.CurrentShip = -1;
        }
    };

    class Story020 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story020()
        {
            BookID = Book::Type::BOOK1;

            ID = 20;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The passageway opens up into a long hall, lined with stamped bronze plates. Torches burn in brackets along the walls, illuminating hideous murals of serpents devouring animals, trees and rocks. You see daylight ahead and come upon a chamber whose roof is open to the blazing sun. It is another temple chamber with black altars and fine silverwork dominating the room.\n\nRising from his position in front of the high altar, a snakeman priest in flowing vestal robes turns to gaze at you with piercing eyes.\n\n\"The heretic slaves return!\" he hisses. \"Do not think that you can seek repentance from the lord of judgement now! Once a traitor, always a traitor!\"";

            Monsters.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(41)}))
            {
                PreText += "\n\n\"We have betrayed no one!\" you reply. \"You have trapped us here. Allow us to leave and we will do you no harm.\"\n\n\"Liars! You have stolen our god!\" spits the snakeman priest. \"Our breed faulters and dies. Now, you shall die with us!\" The snakeman hisses foul words of sorcery. Suddenly the temple walls begin to crack, and blocks of stone rain down upon you. Even as the temple collapses the snakeman priest advances towards you, brandishing his staff.";

                Monsters = {Monster::Base("Snakeman Priest", Monster::Type::SNAKEMAN_PRIEST, 4, 4, 3, 16, 0)};
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(41)}))
            {
                return {Book::Type::BOOK1, 714};
            }
            else
            {
                return {Book::Type::BOOK1, 881};
            }
        }
    };

    class Story021 : public Story::Base
    {
    public:
        Story021()
        {
            BookID = Book::Type::BOOK1;

            ID = 21;

            Location = Location::Type::CAPE_PORTA;

            Text = "You are steering along the jungle peninsula, across waters known as Cape Porta. It is a famous lair of pirates and other ne'er-do-wells.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::Random.UniformIntDistribution(1, 6);

            auto result = Engine::Random.NextInt();

            Choices.clear();

            if (result != 1)
            {
                Choices.push_back(Choice::Base("Sail north towards Clifftop", {Book::Type::BOOK1, 82}));
                Choices.push_back(Choice::Base("Sail east towards Cursus", {Book::Type::BOOK1, 814}));
                Choices.push_back(Choice::Base("(The Savage Lands) Sail west towards the Savage Lands", {Book::Type::BOOK5, 75}));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 429}; }
    };

    class Story022 : public Story::Base
    {
    public:
        Story022()
        {
            BookID = Book::Type::BOOK1;

            ID = 22;

            Text = "Avoiding Chellar's room, you still manage to secure a pretty horde of items. You may take any or all of the following: JEWELLERY BOX, CALLIGRAPHY INK, SILVER IDOL, GOLD PORTRAIT, BRONZE SCORPION. You emerge with Brekken back onto the landing. You decide, with a mutual nod, that you have pushed your luck far enough in the house and make your way back out of the windows and into the streets of the city.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::WALL_CLIMBING;

            Take = {Equipment::JEWELLERY_BOX, Equipment::CALLIGRAPHY_INK, Equipment::SILVER_IDOL, Equipment::GOLD_PORTRAIT, Equipment::BRONZE_SCORPION};

            Limit = 5;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 833}; }
    };

    class Story023 : public Story::Base
    {
    public:
        Story023()
        {
            BookID = Book::Type::BOOK1;

            ID = 23;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You emerge into a short corridor running west to east. To the west you can make out a crossroads. To the east a flight of stairs leads upwards. There is a door in the south wall.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go west", {Book::Type::BOOK1, 310}));
            Choices.push_back(Choice::Base("Go east, up the stairs", {Book::Type::BOOK1, 437}));
            Choices.push_back(Choice::Base("Go through the door in the south wall", {Book::Type::BOOK1, 604}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story024 : public Story::Base
    {
    public:
        Story024()
        {
            BookID = Book::Type::BOOK1;

            ID = 24;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You have entered a chamber which is well furnished with flags and banners. It has the feel of a Chalice temple, although there is no sign that anyone actually worships here. A statue of a kneeling monk sits at the far end of the room. There are two exits from the chamber, each of them leading to a tunnel with stairs ascending.\n\nSuddenly you see a light coming down the left-hand stairwell. Something is coming... but it is walking softly, as you cannot make out the sound of footsteps.\n\nNote: You gained the code A77.";

            Choices.clear();
            Choices.push_back(Choice::Base("Hide behind the statue", {Book::Type::BOOK1, 782}));
            Choices.push_back(Choice::Base("Confront whoever is coming down the stairs", {Book::Type::BOOK1, 757}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(77)});
        }
    };

    class Story025 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story025()
        {
            BookID = Book::Type::BOOK1;

            ID = 25;

            Location = Location::Type::SALT_MINES;

            Image = "images/book1/salt_mines.png";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You stand in the shadow of the Stonewalls, the finger-like crags soaring high into the burning sky. Cut into the roots of a tall mountain are the infamous salt mines of Saltdad. Dozens of warehouses are scattered around the entrance of the mine, with workers boiling away the salt from rock with water drawn from the Cold River to the east. Below your feet, and deep into the mountain, you know that thousands of slaves toil in the grim darkness.\n\nThe mine guards bring you to the owners, hard-faced men with unflinching stares.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(1)}))
            {
                PreText += "\n\n\"I suppose you are here about the troglodytes,\" sighs Clavod, the mine master. \"We are losing so many slaves it starts to become worth protecting them after a while. The deal is 25 silver for each troglodyte head you bring me. Take it or leave it.\"\n\nClavod sees your blank expression. \"Unless you came to arrange salt transportation, of course,\" he says hastily. \"We can transport salt to ships moored in Clifftop or Cursus.\"";

                Choices.push_back(Choice::Base("Accept the mission to hunt the troglodytes", {Book::Type::BOOK1, 681}));
                Choices.push_back(Choice::Base("Sell him some TROGLODYTE HEADS", {Book::Type::BOOK1, 233}, {Equipment::TROGLODYTE_HEAD}));
                Choices.push_back(Choice::Base("Express interest in buying salt for your ships", {Book::Type::BOOK1, 575}));
                Choices.push_back(Choice::Base("Apologise for wasting the mine master's time and leave", {Book::Type::BOOK1, 722}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 532}; }
    };

    class Story026 : public Story::Base
    {
    public:
        Story026()
        {
            BookID = Book::Type::BOOK1;

            ID = 26;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You pour the liquid metal into the well and cross your fingers. Soon, the runes around the circle blaze into light, dousing you with brilliant coloured energies. When the glow finally wears off you feel stronger than before.";

            Bye = "Feeling more vigorous than ever, you return to the crossroads.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member and increase their maximum, unwounded Health score by 1 point", {Book::Type::BOOK1, 566}, Choice::Type::ADD_MAX_HEALTH, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::QUICKSILVER});
        }
    };

    class Story027 : public Story::Base
    {
    public:
        Story027()
        {
            BookID = Book::Type::BOOK1;

            ID = 27;

            Text = "The Everchild presents you with a bar of GOLD BULLION to help convince the mercenaries to change sides. Ayleta has been in private communication with the mercenaries for some time and has already negotiated a safe path between the mercenary encampment and the Everchild's forces.\n\nYou are received coolly by the unit captain, who cautiously welcomes you into his tent with his officers and bodyguards around him. You state your opinion that the Everchild's victory in the coming conflict is all but certain, and that she is willing to let mercenary companies that co-operate with her depart safely. Matters soon turn to money, with the mercenary captain suggesting that quite a lot of additional money will be coming his way should the patriarch win the battle, and Saltdad and other cities need to be supressed. He is also worried about his reputation if he plays turncoat without fighting even a single battle for his employer.\n\nNote: Only party members assigned to the MERCENARY TEAM may assist with this skill check.\n\nIf you give the mercenaries a bar of GOLD BULLION, the DC of this check becomes 5+. If you give them two bars, the DC becomes 4+. If you give them three bars the DC becomes 2+.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();
            Choices.push_back(Choice::Base("Give the mercenaries a GOLD BULLION bar", {Book::Type::BOOK1, -27}, Choice::Type::BRIBE_CODEWORD, {Equipment::GOLD_BULLION}, {Codes::Type::BRIBE_GOLD_BULLION1}, 1));
            Choices.push_back(Choice::Base("Give the mercenaries two GOLD BULLION bars", {Book::Type::BOOK1, -27}, Choice::Type::BRIBE_CODEWORD, {Equipment::GOLD_BULLION}, {Codes::Type::BRIBE_GOLD_BULLION2}, 2));
            Choices.push_back(Choice::Base("Give the mercenaries three GOLD BULLION bars", {Book::Type::BOOK1, -27}, Choice::Type::BRIBE_CODEWORD, {Equipment::GOLD_BULLION}, {Codes::Type::BRIBE_GOLD_BULLION2}, 3));
            Choices.push_back(Choice::Base("Bribe the Mercenaries (Team check: Charisma 6+, Successes: 7)", {Book::Type::BOOK1, 122}, {Book::Type::BOOK1, 832}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::MERCENARY, {Attribute::Type::CHARISMA}, 6, 7));

            Take = {Equipment::GOLD_BULLION};

            Limit = 1;
        }
    };

    class Event027 : public Story::Base
    {
    public:
        Event027()
        {
            BookID = Book::Type::BOOK1;

            ID = -27;

            DisplayID = 27;

            Text = "Only party members assigned to the MERCENARY TEAM may assist with this skill check.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::VERIFY_CODES(party, {Codes::Type::BRIBE_GOLD_BULLION1}))
            {
                Choices.push_back(Choice::Base("Bribe the Mercenaries (Team check: Charisma 5+, Successes: 7)", {Book::Type::BOOK1, 122}, {Book::Type::BOOK1, 832}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::MERCENARY, {Attribute::Type::CHARISMA}, 5, 7));
            }
            else if (Engine::VERIFY_CODES(party, {Codes::Type::BRIBE_GOLD_BULLION2}))
            {
                Choices.push_back(Choice::Base("Bribe the Mercenaries (Team check: Charisma 4+, Successes: 7)", {Book::Type::BOOK1, 122}, {Book::Type::BOOK1, 832}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::MERCENARY, {Attribute::Type::CHARISMA}, 4, 7));
            }
            else if (Engine::VERIFY_CODES(party, {Codes::Type::BRIBE_GOLD_BULLION2}))
            {
                Choices.push_back(Choice::Base("Bribe the Mercenaries (Team check: Charisma 2+, Successes: 7)", {Book::Type::BOOK1, 122}, {Book::Type::BOOK1, 832}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::MERCENARY, {Attribute::Type::CHARISMA}, 2, 7));
            }
            else
            {
                Choices.push_back(Choice::Base("Bribe the Mercenaries (Team check: Charisma 6+, Successes: 7)", {Book::Type::BOOK1, 122}, {Book::Type::BOOK1, 832}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::MERCENARY, {Attribute::Type::CHARISMA}, 6, 7));
            }
        }
    };

    class Story028 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story028()
        {
            BookID = Book::Type::BOOK1;

            ID = 28;

            Location = Location::Type::DESERT;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            PreText = "You come across a group of zealots from Cursus, sweeping the land for any heretics or unbelievers they can find. ";

            Choices.clear();

            if (!Engine::HAS_STATUS(party, Character::Status::RITUAL_SCARRING_CURSUS))
            {
                PreText += "They bombard you with questions about the faith, to determine your worthiness.";

                Choices.push_back(Choice::Base("Answer Cursite zealots (Team check: Lore 4+, Successes: 4)", {Book::Type::BOOK1, 657}, {Book::Type::BOOK1, -28}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 4, 4));
            }
            else
            {
                PreText += "The zealots let you pass.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 657}; }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (outcome)
            {
                Bye = "The zealots reluctantly let you go.";
            }
        }
    };

    class Event028 : public Story::Base
    {
    public:
        Event028()
        {
            BookID = Book::Type::BOOK1;

            ID = -28;

            DisplayID = 28;

            Location = Location::Type::DESERT;

            Text = "Your heretical ignorance drives them into a killer frenzy and you must fight.\n\nNote: The zealot healer will only attack if he is the last opponent standing. Otherwise he will heal each zealot 2 Health points. These additional points can take them over their starting health.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Zealot", Monster::Type::ZEALOT, 3, 4, 4, 10, 0),
                Monster::Base("Zealot", Monster::Type::ZEALOT, 4, 4, 4, 11, 0),
                Monster::Base("Zealot", Monster::Type::ZEALOT, 3, 4, 4, 10, 0),
                Monster::Base("Zealot Healer", Monster::Type::ZEALOT_HEALER, 3, 4, 4, 15, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 63}; }
    };

    class Story029 : public Story::Base
    {
    public:
        Story029()
        {
            BookID = Book::Type::BOOK1;

            ID = 29;

            Text = "You curse as the thief fades from view. You cannot face the owner of the house for shame, and instead slip away into the city.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story030 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story030()
        {
            BookID = Book::Type::BOOK1;

            ID = 30;

            Location = Location::Type::WITHERED_STEPPES;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You sit down with the nomad chief and share a pipe of smoking weed with him. He is a jovial fellow, unaffected by the woes of a nomadic life.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(1)}) || Engine::VERIFY_CODES(party, {Codes::A(37)}))
            {
                PreText += "\n\nYou have nothing of importance to discuss with him.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (!Engine::VERIFY_CODES(party, {Codes::A(1)}) || Engine::VERIFY_CODES(party, {Codes::A(37)}))
            {
                return {Book::Type::BOOK1, 473};
            }
            else
            {
                return {Book::Type::BOOK1, 737};
            }
        }
    };

    class Story031 : public Story::Base
    {
    public:
        Story031()
        {
            BookID = Book::Type::BOOK1;

            ID = 31;

            Location = Location::Type::MORDAIN;

            Text = "As you approach the door you do not see the orcs from the nearby guardroom closing in behind you.\n\nNote: The orcs get the first combat turn, not you.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(56)}))
            {
                return {Book::Type::BOOK1, 788};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::LAST_IN_COMBAT});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 2}; }
    };

    class Story032 : public Story::Base
    {
    public:
        Story032()
        {
            BookID = Book::Type::BOOK1;

            ID = 32;

            Text = "You quietly utter the correct counter spells to render the arcane wards passive. Slipping inside you can see Descantos himself, an elderly wizard, in deep meditation -- no doubt preparing his spells for tomorrow's conflict.";

            Choices.clear();
            Choices.push_back(Choice::Base("Sneak up to the wizard and slit his throat", {Book::Type::BOOK1, 336}));
            Choices.push_back(Choice::Base("Overwhelm and stab the wizard to death in a sudden rush", {Book::Type::BOOK1, 877}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story033 : public Story::Base
    {
    public:
        Story033()
        {
            BookID = Book::Type::BOOK1;

            ID = 33;

            Location = Location::Type::CURSUS;

            Text = "The harbour of Cursus is long and shallow. The jetties reach far out beyond the coast, each wide enough for a pair of dragonyaks to drag the cargoes of ships to the warehouses on the beach.\n\nYou may buy a ship here, if you have enough money. The largest vessel for sale is the CURSITE WAR GALLEY, a coastal-hugging warship which carries little cargo, but is the only vessel that can even hope to compete with the more advanced vessels of Royce and Drakehallow. A smaller, but more efficient, single-masted COG is also available. The WAR GALLEY will cost 1500 silver coins, and the COG 800 silver coins. When you buy a ship note that it is currently docked in Cursus harbour.\n\nYou can repair any ship you have in Cursus harbour. Each Health point you restore costs 50 silver coins. You can restore your ship up to its starting Health value. You can sell a COG here for 250 silver coins, a CURSITE WAR GALLEY for 500 silver coins and a CARRACK for 1500 silver coins. You cannot sell other kinds of ship here.\n\nYou can buy cargo for your ship here, as well. These goods are too large for your characters to carry, but they can be loaded onto any ship you have in Cursus harbour. You cannot buy more cargo units than you can store in your ship (for instance, a Cog can carry 2 Cargo Units). You can also sell any goods you are carrying in your ships for the same price as well:\n\nSALT: 600 silver coins\nCROPS: 500 silver coins\nSTEEL: 3000 silver coins\nSPICES: 3300 silver coins\nWINE: 2100 silver coins\nSLAVES: 1000 silver coins";

            Choices.clear();
            Choices.push_back(Choice::Base("Return to the city centre", {Book::Type::BOOK1, 340}));
            Choices.push_back(Choice::Base("Set sail on one of your ships", {Book::Type::BOOK1, 499}, Choice::Type::SAIL, Location::Type::CURSUS));

            Controls = Story::Controls::HARBOUR;
        }

        void Event(Party::Base &party)
        {
            // TODO: Carrack Stats
            Ships = {
                {Ship::Base("COG", Ship::Type::COG, Location::Type::CURSUS, 4, 7, 2), 800, 250},
                {Ship::Base("CURSITE WAR GALLEY", Ship::Type::CURSITE_WAR_GALLEY, Location::Type::CURSUS, 6, 9, 1), 1500, 500},
                {Ship::Base("CARRACK", Ship::Type::CARRACK, Location::Type::CURSUS, 6, 9, 1), -1, 1500}};

            Cargo = {
                {Cargo::Type::SALT, 600, 600},
                {Cargo::Type::CROPS, 500, 500},
                {Cargo::Type::STEEL, 3000, 3000},
                {Cargo::Type::SPICES, 3300, 3300},
                {Cargo::Type::WINE, 2100, 2100},
                {Cargo::Type::SLAVES, 1000, 1000}

            };

            ShipRepairPrice = 50;
        }
    };

    class Story034 : public Story::Base
    {
    public:
        Story034()
        {
            BookID = Book::Type::BOOK1;

            ID = 34;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Text = "You return to the large burial chamber. The ghouls are long gone, and there is no more treasure to be found here. If you wish you can scribe the spell on the bronze tablet into your spellbook, if you have had reason to remove it:\n\nWisdom (Adventure)\n\nYour mind awakens with ancient knowledge. Cast this spell when you have failed a Lore check. You gain 3 automatic successes for this check only.\n\nRecharge: 50 silver";

            Bye = "You return to the crossroads.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Spells = {Spells::WISDOM};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 46}; }
    };

    class Story035 : public Story::Base
    {
    public:
        Story035()
        {
            BookID = Book::Type::BOOK1;

            ID = 35;

            Text = "\"You say the captain wishes to see us? And he mentioned a promotion?\" presses the guard.\n\n\"Apparently his current lieutenant is not up to scratch,\" shrugs Brash. \"He's asked to see other guards as well. I imagine the first to see the captain will probably get the promotion.\"\n\nThe guards push past you in their eagerness to get to the captain's office.\n\nNote: Your DISTRACTION TEAM can join up with the WEAPONS TEAM for all future checks.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::WEAPON_AND_DISTRACTION});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 456}; }
    };

    class Story036 : public Story::Base
    {
    public:
        Story036()
        {
            BookID = Book::Type::BOOK1;

            ID = 36;

            Text = "You are in the ogre's bedroom. It would be too unpleasant (not to mention unhygienic) to rest here yourselves, so you gingerly make your way back outside.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 310}; }
    };

    class Story037 : public Story::Base
    {
    public:
        Story037()
        {
            BookID = Book::Type::BOOK1;

            ID = 37;

            Text = "The Lhasbreath barbarian suddenly jolts, a blade sticking out of his chest. He falls away, to reveal a smirking Tash, her crude sword dripping with blood.\n\n\"Thanks, Tash,\" smiles Jessica, helped to her feet by the clever thief. Sar Jessica won't soon forget this.\n\nNote: Jessica has gained a heart for Tasha. Tasha also gains a heart for Sar Jessica.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEARTS(party, Character::Type::SAR_JESSICA_DAYNE, Character::Type::TASHA, 1);
            Engine::GAIN_HEARTS(party, Character::Type::TASHA, Character::Type::SAR_JESSICA_DAYNE, 1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 753}; }
    };

    class Story038 : public Story::Base
    {
    public:
        Story038()
        {
            BookID = Book::Type::BOOK1;

            ID = 38;

            Text = "You kill the orc in a single stroke. He keels over, the book slipping from his grasp.\n\nNote: You gained the code A71.";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine the black book he was reading", {Book::Type::BOOK1, 119}));
            Choices.push_back(Choice::Base("Close the door and go somewhere else", {Book::Type::BOOK1, 821}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(71)});
        }
    };

    class Story039 : public Story::Base
    {
    public:
        Story039()
        {
            BookID = Book::Type::BOOK1;

            ID = 39;

            Location = Location::Type::NORTH_ROAD;

            Text = "You join the disorganised caravan guards, barking orders at them to form a defensive line and protect their archers.";

            Choices.clear();
            Choices.push_back(Choice::Base("Order the caravan guards (Team check: Charisma 5+, Successes: 3)", {Book::Type::BOOK1, 542}, {Book::Type::BOOK1, 451}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 5, 3));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story040 : public Story::Base
    {
    public:
        Story040()
        {
            BookID = Book::Type::BOOK1;

            ID = 40;

            Text = "With a dramatic flourish you unroll the DRAGON HEAD from its wrappings. King Scarrenden stands in amazement, and a gasp echoes across the chamber. His councillors flock round the head, to confirm its origins.\n\n\"This is indeed impressive,\" agrees the king. \"I set you a challenge and you have overcome it. Therefore, I shall be as good as my word. I shall send the Everchild my finest berserkers to aid her struggle. She also has the loyalty of my city. May she be victorious in her endeavours, and may her glory be ours!\"\n\nThere is a mixed cheer from the hall. Not all are pleased that King Scarrenden has submitted his city to the rule of child. However, even here the Everchild's fame is evident, and the enthusiasm of some of the warriors cannot be mistaken.\n\nYou may add the following soldiers to the Luutanesh barracks:\n\n[Lhasbreath Berserkers]: Strength 5, Morale 2\n\nThese berserkers are strong but flighty troops, who will fight for you as long as the going is good.\n\nGaining King Scarrenden's support has been quite an endeavour.\n\nNote: You gained the code A16.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Survival", {Book::Type::BOOK1, 775}, Choice::Type::ROLL_FOR_ATTRIBUTE_INCREASE, {Attribute::Type::SURVIVAL}, 1, 2, 0));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::DRAGON_HEAD});

            auto location = Location::Type::LUUTANESH;

            if (Engine::VERIFY_CODES(party, {Codes::Type::QUEEN_IN_SALTDAD}))
            {
                location = Location::Type::SALTDAD;
            }

            Army = {Army::Base("Lhasbreath Berserkers", Army::Type::LHASBREATH_BERSERKERS, location, 5, 2)};

            Engine::GET_CODES(party, {Codes::A(16)});
        }
    };

    class Story041 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story041()
        {
            BookID = Book::Type::BOOK1;

            ID = 41;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "Dazzling sunlight almost blinds you as you emerge into daylight. You are in a sandy, secluded alleyway, the sounds of marketplace hawkers reaching your ears. You quickly help the Everchild out of the drains, hiding her behind some tall baskets as you check for the guards.\n\n\"We are free!\" she gasps. \"I feared I might die in that terrible place.\"\n\n\"What will you do now?\" you ask. \"You cannot stay in the city...\"\n\n\"No -- here we shall divide for safety,\" she agrees. \"Che Long can look after me from here on in. I cannot thank you enough for your safe delivery of myself and my followers. I can give you no reward, and you owe me nothing, but...\"\n\nYou silence her as you duck behind the baskets. A guard patrol of men in gleaming bronze armour clank past, wickedly shaped halberds in their grasp. \"The Bronzeguard,\" hisses Che Long. \"The elite warriors and boot lickers of the Iron King. Their amour is supposedly enchanted, dug up from the palace vaults by the Iron King's servants.\"\n\n\"They are still men underneath,\" you growl.\n\n\"If you hate tyranny and would see justice restored, come and find me in the Cold River Inn, in Luutanesh,\" implores the Everchild. \"The path to freedom is long and difficult, but together we can find a way to end the bloody reign of the Iron King forever.\"\n\nThe coast is clear, and Che Long quickly bows to you. \"We must go before the general alarm is raised. You have my thanks. Come majesty.\"\n\nAt that the Everchild dons a cowl over her head and slips into the crowds with her followers. Your experiences in the arena have taught you much. ";

            Choices.clear();

            if (Engine::VERIFY_CODES(party, {Codes::Type::STARTED_IN_BOOK1}))
            {
                PreText += "You may raise one skill (Fighting, Stealth, Lore, etc) by one point for each of your characters.";

                Choices.push_back(Choice::Base("Each of your characters raises one skill by one point", {Book::Type::BOOK1, 313}, Choice::Type::PARTY_RAISE_ATTRIBUTE, 1));
            }
            else
            {
                PreText += "Each of your party members can raise their maximum health points by one point.";

                Choices.push_back(Choice::Base("Raise the maximum health points of your party by one point", {Book::Type::BOOK1, 313}, Choice::Type::PARTY_RAISE_HEALTH, 1));
            }

            PreText += "\n\nNote: You gained the code A6.";

            Engine::GET_CODES(party, {Codes::A(6)});

            Text = PreText.c_str();
        }
    };

    class Story042 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story042()
        {
            BookID = Book::Type::BOOK1;

            ID = 42;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You return to the small reading room, mouldering books scattered across the tiny library.";

            if (!Engine::VERIFY_CODES(party, {Codes::Type::FIRST_TIME_SCROLL_OF_RAGE}))
            {
                PreText += "\n\nYou find a SCROLL OF RAGE here.";

                Engine::GET_CODES(party, {Codes::Type::FIRST_TIME_SCROLL_OF_RAGE});
            }
            else
            {
                if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::SCROLL_OF_RAGE}))
                {
                    PreText += "\n\nYou are surprised to see the SCROLL OF RAGE back on the shelf, in the same place you found it last time. It seems that the scroll teleports back here each time it is used.";
                }
                else
                {
                    PreText += "\n\nYou find nothing else of interest here.";
                }
            }

            Take.clear();

            Limit = 0;

            if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::SCROLL_OF_RAGE}))
            {
                Take = {Equipment::SCROLL_OF_RAGE};

                Limit = 1;

                PreText += "\n\nYou can take the SCROLL OF RAGE. ";
            }

            PreText += "You cannot have more than one SCROLL OF RAGE equipped at any given time. You can use it in combat to increase the Fighting score of each of your party members by 1 point until the end of the combat. After one use it will teleport back to the bookshelf in this room.";

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 494}; }
    };

    class Story043 : public Story::Base
    {
    public:
        Story043()
        {
            BookID = Book::Type::BOOK1;

            ID = 43;

            Location = Location::Type::LUUTANESH;

            Text = "Janus is overjoyed to see the LOCKET. You hand it over to him and he cradles it in his hands. \"Now I can remember Alidale always!\" he sighs. He opens the LOCKET to have a look inside, when suddenly there is a flash and a profusion of smoke.\n\nStepping out of the smoke comes a young woman, a wizard by the looks of her, coughing and waving the smoke away from her face. \"Alidale?\" gasps Janus. \"Why! You don't look a day older than when you left for that temple!\"\n\n\"Janus!\" she cries overjoyed. \"You... do look a bit older, if I'm honest. I must have been in that locket for a long time.\"\n\nAlidale explains that she was surrounded by hideous serpent men and was forced to transport herself inside her locket for protection. The snake men assumed she had teleported away, but in fact she has been trapped in the locket for all these years. She never expected a rescue would take forty summers. She has little to reward you with but shares with you some of her many discoveries and insights into the ancient world that she has uncovered in her travels.\n\nNote: You gained the code A29.";

            Bye = "Bidding the odd couple farewell, you resume your journey.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Lore", {Book::Type::BOOK1, 614}, Choice::Type::RAISE_ATTRIBUTE_SCORE, {Attribute::Type::LORE}, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::BRONZE_LOCKET});

            Engine::GET_CODES(party, {Codes::A(29)});
        }
    };

    class Story044 : public Story::Base
    {
    public:
        Story044()
        {
            BookID = Book::Type::BOOK1;

            ID = 44;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "Tackling the room will come in two stages. Firstly, you must attempt to figure out the safest route. By examining the positions of the orc bodies you might be able to figure out which parts of the room are safe and which parts are deadly traps. Secondly, someone must attempt to carefully sneak through the room.\n\nNote: You cannot fail this test.";

            Choices.clear();
            Choices.push_back(Choice::Base("Discern the safe route (Team check: Lore 5+, Successes: Special)", {Book::Type::BOOK1, -44}, {Book::Type::BOOK1, -44}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 5, 0));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event044 : public Story::Base
    {
    public:
        Event044()
        {
            BookID = Book::Type::BOOK1;

            ID = -44;

            DisplayID = 44;

            Text = "Next, pick someone to try and sneak through the room.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            int success = 7 - party.RecentSuccesses;

            if (success < 0)
            {
                success = 0;
            }

            temp_string = "Sneak through the room (Individual check: Stealth 4+, Successes: ";

            if (success > 0)
            {
                temp_string += std::to_string(success);
            }
            else
            {
                temp_string += "Guaranteed";
            }

            temp_string += ")";

            Choices.clear();

            Choices.push_back(Choice::Base(temp_string.c_str(), {Book::Type::BOOK1, 385}, {Book::Type::BOOK1, 769}, {Attribute::Type::STEALTH}, 4, success));
        }
    };

    class Story045 : public Story::Base
    {
    public:
        Story045()
        {
            BookID = Book::Type::BOOK1;

            ID = 45;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Timing it just right, you begin to shove one another in the water queue. To make it convincing, you start to exchange a few hard blows, attempting to drag other slaves in the queue into your rumble.\n\nEach party member involved in the fight loses 1 Health point.\n\nNote: Only party members assigned to the DISTRACTION TEAM can contribute to the check.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, Team::Type::DISTRACTION, -1);

            Choices.clear();

            if (Engine::VERIFY_CODES(party, {Codes::Type::WEAPON_AND_DISTRACTION}))
            {
                Choices.push_back(Choice::Base("Stage a convincing fight (Team check: Fighting 4+, Successes: 3)", {Book::Type::BOOK1, 837}, {Book::Type::BOOK1, 762}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::FIGHTING}, 4, 3, false));
            }
            else
            {
                Choices.push_back(Choice::Base("Stage a convincing fight (Team check: Fighting 4+, Successes: 3)", {Book::Type::BOOK1, 837}, {Book::Type::BOOK1, 762}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::DISTRACTION, {Attribute::Type::FIGHTING}, 4, 3, false));
            }
        }
    };

    class Story046 : public Story::Base
    {
    public:
        Story046()
        {
            BookID = Book::Type::BOOK1;

            ID = 46;

            Location = Location::Type::CROSSROADS;

            Text = "You have returned to the crossroads. Above you daylight streams through the exit shaft.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go northwest", {Book::Type::BOOK1, 761}));
            Choices.push_back(Choice::Base("Go northeast", {Book::Type::BOOK1, 801}));
            Choices.push_back(Choice::Base("Go southeast", {Book::Type::BOOK1, 869}));
            Choices.push_back(Choice::Base("Go southwest", {Book::Type::BOOK1, 217}));
            Choices.push_back(Choice::Base("Climb back up to the surface", {Book::Type::BOOK1, 426}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story047 : public Story::Base
    {
    public:
        Story047()
        {
            BookID = Book::Type::BOOK1;

            ID = 47;

            Text = "You gather round and attempt to pull apart the barrier, but despite its crude appearance it is actually very well built. Even sledgehammers and mules couldn't pull this barricade down from this side. Is this as far as the orcs have penetrated into the complex?\n\nGrumbling with irritation, you head back east towards the small room you came from.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 821}; }
    };

    class Story048 : public Story::Base
    {
    public:
        Story048()
        {
            BookID = Book::Type::BOOK1;

            ID = 48;

            Text = "The enemy are too numerous. Horns are sounded, and your forces begin a general retreat. Fortunately, you have the open desert to scatter into and a rearward base to reform at, but casualties are almost inevitable.\n\nThe queen is appalled at her loss but marshals her forces with a mother's tenderness. \"This is not the end,\" she vows. \"We must rebuild our forces and gather new allies. Clifftop isn't going anywhere, and neither am I.\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Retreat to Saltdad", {Book::Type::BOOK1, 620}, Choice::Type::RETREAT, Location::Type::SALTDAD, 2));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story049 : public Story::Base
    {
    public:
        Story049()
        {
            BookID = Book::Type::BOOK1;

            ID = 49;

            Text = "Your return trip to Lhasbreath is mercifully uneventful, and Sir Lawrence Ross lays on a grand banquet upon your arrival. You spend several days with the Ross's, recovering your strength and discussing your adventures.\n\nAll your party members are restored to maximum Health.\n\nWhen Emlyn reports her findings, the news is good. \"There are several herbs that appear to have medicinal qualities,\" she smiles. \"Additionally, one of the flowers is producing a sweet pepper which seems edible and delicious. If we can find a source of these in the wild, House Ross can enter the spice market.\"\n\nSir Lawrence is overjoyed with these results. You receive 600 silver coins as a reward. In addition, he presents you with a SEAL OF HOUSE ROSS. \"Should you ever travel to Strongstone, present this to the castle steward, Wyrran Glenpetre. You will be treated as an honoured guest.\"\n\nThis has been an amazing adventure.\n\nNote: You gained the code A85.";

            Bye = "Thanking Sir Lawrence and Emlyn for their generosity, you depart into the city.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Survival", {Book::Type::BOOK1, 775}, Choice::Type::RAISE_ATTRIBUTE_SCORE, {Attribute::Type::SURVIVAL}, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::SEAL_OF_HOUSE_ROSS};

            Limit = 1;

            Engine::GAIN_MONEY(party, 600);

            Engine::REST(party);

            Engine::GET_CODES(party, {Codes::A(85)});
        }
    };

    class Story050 : public Story::Base
    {
    public:
        Story050()
        {
            BookID = Book::Type::BOOK1;

            ID = 50;

            Location = Location::Type::WEST_ROAD;

            Text = "You manage to translate the brightly painted calendar, to the delight of Kopu. He is impressed with your work and presents you with a BLUESTONE as a reward. You ask what the stone is for.\n\n\"It is sacred to our priesthood,\" admits Kopu. \"You can exchange it for blessings at our temples.\"\n\n\"I thought you said Kalu had no temples anymore?\" you press.\n\n\"Well,\" he says. \"It's the thought that counts.\"\n\nGrumbling somewhat, you get some sleep whilst you wait out the storm.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::BLUESTONE};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 585}; }
    };

    class Story051 : public Story::Base
    {
    public:
        Story051()
        {
            BookID = Book::Type::BOOK1;

            ID = 51;

            Location = Location::Type::LHASBREATH_OASIS;

            Text = "Where will you travel next?";

            Choices.clear();
            Choices.push_back(Choice::Base("North, to the Granite Hills", {Book::Type::BOOK1, 275}));
            Choices.push_back(Choice::Base("East, into the desert", {Book::Type::BOOK1, 202}));
            Choices.push_back(Choice::Base("South, to the Mordain ruins", {Book::Type::BOOK1, 515}));
            Choices.push_back(Choice::Base("West, across the desert towards Lhasbreath", {Book::Type::BOOK1, 752}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story052 : public Story::Base
    {
    public:
        Story052()
        {
            BookID = Book::Type::BOOK1;

            ID = 52;

            Location = Location::Type::VIAAN_ISLAND;

            Text = "Your ship is boarded! Dozens of the Bando swamp the decks, their poisoned blow darts and spears making short work of any opposition. Surrounded, and realising the futility of your position, you surrender.\n\nYou are stripped and bound, along with the rest of your surviving crew. Your ship is looted and then sunk.\n\nAfter spending a few days with the Bando in cramped bamboo cages, the mercenary tribesmen sell you off to a passing slaver ship in return for a few gemstones and some curious-looking fabrics.";

            Choices.clear();
            Choices.push_back(Choice::Base("See where you are eventually sold", {{2, "You are sold to the Saltdad Arena", {Book::Type::BOOK1, 631}}, {4, "You are sold to the taskmasters of Clifftop", {Book::Type::BOOK1, 866}}, {6, "You are sold to the priests of Cursus", {Book::Type::BOOK1, 531}}}, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            party.Money = 0;

            Engine::SINK_SHIP(party);

            Engine::LOSE_ALL(party);
        }
    };

    class Story053 : public Story::Base
    {
    public:
        Story053()
        {
            BookID = Book::Type::BOOK1;

            ID = 53;

            Text = "There is no point in risking everyone at once.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to cross the beam first", {Book::Type::BOOK1, 208}, Choice::Type::CHOOSE_PARTY_MEMBER));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story054 : public Story::Base
    {
    public:
        Story054()
        {
            BookID = Book::Type::BOOK1;

            ID = 54;

            Location = Location::Type::LHASBREATH_RAPIDS;

            Text = "There are a number of close shaves, and even minor impacts, but the raft holds steady as you correct its course through the sloping rapids. Eventually the waters calm, and you ride the current downstream at a good speed. Looking at the densely packed jungle on either side you are glad to your soul that you didn't have to hack your way through all that vegetation. Eventually the jungle clears somewhat, and a wide, muddy bank comes into view. Emlyn thinks you have gone far enough, and you beach the raft onto the bank.\n\n\"Skilfully done,\" smiles Emlyn as you help her and the other scholars to shore. \"Let's explore the unknown, shall we?\"";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 763}; }
    };

    class Story055 : public Story::Base
    {
    public:
        Story055()
        {
            BookID = Book::Type::BOOK1;

            ID = 55;

            Text = "The guards strip you of your money and equipment. Jail space is at a premium, so you are sold into slavery.";

            Choices.clear();
            Choices.push_back(Choice::Base("See your fate", {{2, "You are sold to the Saltdad Arena", {Book::Type::BOOK1, 631}}, {4, "You are sold to the taskmasters of Clifftop", {Book::Type::BOOK1, 866}}, {6, "You are sold to the priests of Cursus", {Book::Type::BOOK1, 531}}}, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            party.Money = 0;

            Engine::LOSE_ALL(party);
        }
    };

    class Story056 : public Story::Base
    {
    public:
        Story056()
        {
            BookID = Book::Type::BOOK1;

            ID = 56;

            Location = Location::Type::SHADOW_LANDS;

            Text = "You kiss the burning, rich-yellow sands as you emerge from the shadow lands. You are free from the tyranny of the monochrome world.\n\nNote: You gained the code A23.";

            Bye = "You head north, directly away from the Blackwall.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Survival", {Book::Type::BOOK1, 511}, Choice::Type::RAISE_ATTRIBUTE_SCORE, {Attribute::Type::SURVIVAL}, 1));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(23)}))
            {
                return {Book::Type::BOOK1, 244};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(23)});
        }
    };

    class Story057 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story057()
        {
            BookID = Book::Type::BOOK1;

            ID = 57;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            PreText = "The goblin's grasp of your language is rather poor, but you endeavour to convince them that you are the enemies of their enslavers.";

            auto difficulty = 5;

            if (Engine::VERIFY_CODES(party, {Codes::Type::SPEAK_BANDO}))
            {
                PreText += "\n\nHowever, you speak Bando. Oddly, the goblins are quite familiar with this language.";

                difficulty = 4;
            }

            Choices.clear();

            temp_string = "Parlay with the goblin (Team check: Charisma " + std::to_string(difficulty) + "+, Successes: 3)";

            Choices.push_back(Choice::Base(temp_string.c_str(), {Book::Type::BOOK1, 828}, {Book::Type::BOOK1, 389}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, difficulty, 3));

            Text = PreText.c_str();
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (!outcome)
            {
                Bye = "The goblins get hostile.";
            }
        }
    };

    class Story058 : public Story::Base
    {
    public:
        Story058()
        {
            BookID = Book::Type::BOOK1;

            ID = 58;

            Text = "As you are pouring the POISON into the cauldron, the head chef catches your hand. \"What's that?\" she demands sharply. You drop the VIAL and bolt away, even as the chefs yell for the guards. You make a dash for the walls, hoping to be able to leap over the low barricades of the compound and into freedom. You make it to one of the squat towers that line the walls, but alas, three Bronzeguard soldiers stand alert in the room. Barricading the door behind you, the team grimly draw their weapons and prepare to fight!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::VIAL_OF_POISON});

            Monsters = {
                Monster::Base("Bronzeguard", 8, 4, 5, 12, 0),
                Monster::Base("Bronzeguard", 9, 4, 5, 10, 0),
                Monster::Base("Bronzeguard", 7, 4, 5, 11, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 623}; }
    };

    class Story059 : public Story::Base
    {
    public:
        Story059()
        {
            BookID = Book::Type::BOOK1;

            ID = 59;

            Text = "You knock the guards down into the dirt and surge forwards. There is nowhere to hide but in the city itself so you dash into the streets whilst the guards roar behind you.";

            Choices.clear();
            Choices.push_back(Choice::Base("Hide from the guards (Team check: Stealth 4+, Successes: 4)", {Book::Type::BOOK1, 698}, {Book::Type::BOOK1, 758}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::STEALTH}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story060 : public Story::Base
    {
    public:
        Engine::Destination destination;

        Story060()
        {
            BookID = Book::Type::BOOK1;

            ID = 60;

            Text = "The thief is almost in grabbing range. He turns a corner only to find himself in a dead-end alley. He curses and draws his sword. \"You've bitten off more than you can chew, foreigners!\" he spits.\n\nNote: Only party members still in the chase can fight in this battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::CHASE;

            Bye = NULL;

            Monsters = {Monster::Base("Thief of Royce", 5, 4, 4, 14, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                destination = {Book::Type::BOOK1, 391};
            }
            else if (Engine::COUNT(party) > 0)
            {
                Engine::LOSE_ALL(party, Team::Type::CHASE);

                Bye = "The team you sent to chase the thief are all dead. The thief has taken all of their possessions. The remaining party members are mourning the loss.";

                destination = {Book::Type::BOOK1, 450};
            }
        }
    };

    class Story061 : public Story::Base
    {
    public:
        Story061()
        {
            BookID = Book::Type::BOOK1;

            ID = 61;

            Text = "You carry Amelia to bed after a few feeble protestations. Once she is safely tucked-in the rest of the party retire as well.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                if (party.Members[party.LastSelected].Type == Character::Type::BRASH)
                {
                    return {Book::Type::BOOK1, 4};
                }
                else if (party.Members[party.LastSelected].Type == Character::Type::TASHA)
                {
                    return {Book::Type::BOOK1, 870};
                }
                else
                {
                    return {Book::Type::NONE, -1};
                }
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 280}; }
    };

    class Story062 : public Story::Base
    {
    public:
        Story062()
        {
            BookID = Book::Type::BOOK1;

            ID = 62;

            Text = "That night, you stroll along the terrace, the night a canopy of stars, reflected in the watery rice paddies that surround the house. You need some fresh air. Being treated as a hero all day and night can be exhausting.\n\nYou spy Brash leaning back on a chair, his feet up on the railings, a cup of rice wine in hand. He stares out over the still landscape.\n\n\"Silver for your thoughts,\" you say, causing Brash to yelp in surprise, fall off his chair and crash to ground.\n\n\"Ah! Akihiro! Always catching me at my best!\" Brash says sheepishly. You offer him a hand up, the fair lad accepting, pulled almost into an embrace. He blushes and backs away.\n\n\"Not like you to lose your tongue, my friend,\" you smile. \"You've been avoiding me, I sense.\"\n\n\"A bit,\" he says. \"I just don't know what to do with myself these days...\"\n\n\"How so?\" you ask. When he doesn't respond you flick him a silver coin, which he catches with his quick reflexes. He looks at it in his hand and realises he has been fooled.\n\n\"I've been thinking about you,\" he admits. \"Quite a bit. I don't know what to do about it. The kind of feelings I have aren't allowed in Royce.\"\n\n\"They are not allowed anywhere,\" you say, joining him at the railings. \"There are many men who would rather kill than love. And more who would kill to stop love, no matter how earnest. I will never hurry you, Brash, but I do not accept uncertainty. If you feel for me what I feel for you, you must be sure. Once done, we cannot undo it.\"\n\nYou are disturbed by a creak on the floorboards. You turn to see your sister arriving on the terrace. \"Come, Akihiro, you are asked for! Do not keep the people from their hero!\"\n\n\"The price of fame,\" you smile. \"Come, Brash. Walking out on a party is not done.\"\n\nYou offer him your hand, and he accepts, squeezing before releasing.\n\nNote: Akihiro has gained a heart for Brash. Brash also gains a heart for Akihiro. You gained the code A98.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(98)});

            Engine::GAIN_HEARTS(party, Character::Type::AKIHIRO_OF_CHALICE, Character::Type::BRASH, 1);
            Engine::GAIN_HEARTS(party, Character::Type::BRASH, Character::Type::AKIHIRO_OF_CHALICE, 1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story063 : public Story::Base
    {
    public:
        Story063()
        {
            BookID = Book::Type::BOOK1;

            ID = 63;

            Location = Location::Type::DESERT;

            Text = "The zealots had a few minor talismans and some gaudy jewellery you sell at a marketplace for 25 silver coins. It seems a paltry reward for such a battle.\n\nWhere will you travel now?";

            Choices.clear();
            Choices.push_back(Choice::Base("North, towards the Temple of the Unbroken", {Book::Type::BOOK1, 535}));
            Choices.push_back(Choice::Base("East, towards the city of Cursus", {Book::Type::BOOK1, 340}));
            Choices.push_back(Choice::Base("West, towards the Mordain Ruins", {Book::Type::BOOK1, 515}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 25);
        }
    };

    class Story064 : public Story::Base
    {
    public:
        Story064()
        {
            BookID = Book::Type::BOOK1;

            ID = 64;

            Text = "With the ascendancy of the Everchild the streets have become safer and justice more accessible to the common people. Good news for the city, but it makes for a dull walk through the ramshackle town.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story065 : public Story::Base
    {
    public:
        Story065()
        {
            BookID = Book::Type::BOOK1;

            ID = 65;

            Text = "The party member reading the book is standing immobile, lost in the mystic words of the cursed book.\n\nWhat does the rest of the party do?";

            Choices.clear();
            Choices.push_back(Choice::Base("Snatch the book from their grasp", {Book::Type::BOOK1, 771}));
            Choices.push_back(Choice::Base("Abandon the party member to their madness", {Book::Type::BOOK1, 84}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story066 : public Story::Base
    {
    public:
        Story066()
        {
            BookID = Book::Type::BOOK1;

            ID = 66;

            Location = Location::Type::LUUTANESH;

            Text = "You spend several days in the handsomely appointed Cold River Inn.\n\nNote: For every 5 silver coins you spend, each party member can recover 1 Health point.\n\nSpell casters can also spend silver here to recharge their spells, purchasing components in the nearby marketplace and going into meditation in the privacy of their rooms.";

            RestPrice = 5;
            CanRecharge = true;

            Choices.clear();
            Choices.push_back(Choice::Base("Return to the Everchild's hideout", {Book::Type::BOOK1, 263}));
            Choices.push_back(Choice::Base("Leave Luutanesh", {Book::Type::BOOK1, 614}));

            Controls = Story::Controls::INN;
        }
    };

    class Story067 : public Story::Base
    {
    public:
        Story067()
        {
            BookID = Book::Type::BOOK1;

            ID = 67;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You descend into the basement, carved out of cliff rock, and decorated with thick carpets and ever-burning candlesticks. Eventually you emerge into an oval chamber. To the south an archway leads to another circular room filled with strange, glowing runes. In the north wall is a strong, round steel door. It appears to have no handle or lock upon it. Perhaps this is the fabled vault of Unbraaki?\n\nOn either side of the vault are bookcases which are stacked with blank paper. Your entrance has created a draught, and a single blank sheet tumbles from the stacks to drift to the floor. You watch with growing nervousness as another sheet floats free and then another and another. The sheets of paper fold themselves rapidly, joining together and folding and refolding into shapes. Soon, a man-like figure has formed, followed by another and another. A paper tiger is folded into completion, as well as a fierce dragon. As one, the paper figures turn, swirls of sheets whipping around them like a snowstorm. They advance towards you.\n\nNotes: You cannot make armour saves against the attacks of these paper opponents.";

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(92)}))
            {
                return {Book::Type::BOOK1, 803};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::HAS_SPELL_ANY(party, {Spells::Type::ORB_OF_ANNIHILATION, Spells::Type::MAELSTROM}))
            {
                if (Engine::HAS_SPELL(party, {Spells::Type::ORB_OF_ANNIHILATION}))
                {
                    Choices.push_back(Choice::Base("Cast Orb of Annihilation", {Book::Type::BOOK1, 121}, Choice::Type::GET_CODES, {Codes::Type::CAST_ORB}));
                }

                if (Engine::HAS_SPELL(party, {Spells::Type::MAELSTROM}))
                {
                    Choices.push_back(Choice::Base("Cast Maelstrom", {Book::Type::BOOK1, 121}, Choice::Type::GET_CODES, {Codes::Type::CAST_MAELSTROM}));
                }

                Choices.push_back(Choice::Base("Defend yourselves against these weird opponents", {Book::Type::BOOK1, -67}));
            }
            else
            {
                Monsters = {
                    Monster::Base("Paper Golems", Monster::Type::PAPER, 4, 4, 4, 10, 0),
                    Monster::Base("Paper Tiger", Monster::Type::PAPER, 5, 4, 4, 6, 0),
                    Monster::Base("Paper Dragon", Monster::Type::PAPER, 5, 4, 4, 6, 0)};
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 168}; }
    };

    class Event067 : public Story::Base
    {
    public:
        Event067()
        {
            BookID = Book::Type::BOOK1;

            ID = -67;

            DisplayID = 67;

            Text = "Defend yourselves against these weird opponents.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Paper Golems", Monster::Type::PAPER, 4, 4, 4, 10, 0),
                Monster::Base("Paper Tiger", Monster::Type::PAPER, 5, 4, 4, 6, 0),
                Monster::Base("Paper Dragon", Monster::Type::PAPER, 5, 4, 4, 6, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 168}; }
    };

    class Story068 : public Story::Base
    {
    public:
        Story068()
        {
            BookID = Book::Type::BOOK1;

            ID = 68;

            Text = "Akini is delighted as you return her aunt to the family home. She thanks you profusely. \"I do not understand why strangers would perform such a kindness for me, but you have my eternal thanks,\" she smiles. She presents you with some FINE BOOTS (Stealth +2). \"These were cast out by my lady because one has a tiny scuff on the heel,\" says Akini. \"I shall never wear noble garments again. Let them be worn by those of noble heart, such as you.\"";

            Bye = "You bow and take your leave.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::FINE_BOOTS2};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story069 : public Story::Base
    {
    public:
        Story069()
        {
            BookID = Book::Type::BOOK1;

            ID = 69;

            Text = "You enter a small alchemical laboratory. A rack where potion bottles are stored is empty, presumably already looted by the orcs. However, two potions seem to be in the process of being brewed, an open book listing the instructions on a table which shares space with many alembics and beakers. There are two doors in this room, one to the west, and another to the east.";

            Choices.clear();
            Choices.push_back(Choice::Base("Attempt to complete the creation of the potions", {Book::Type::BOOK1, 482}));
            Choices.push_back(Choice::Base("Pass through the door in the western wall", {Book::Type::BOOK1, 256}));
            Choices.push_back(Choice::Base("Return to the corridor through the east door", {Book::Type::BOOK1, 755}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(73)}))
            {
                return {Book::Type::BOOK1, 873};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story070 : public Story::Base
    {
    public:
        Story070()
        {
            BookID = Book::Type::BOOK1;

            ID = 70;

            Location = Location::Type::CLIFFTOP;

            Text = "You track down Damned Suzanna through the dusty gulches in Clifftop. Eventually you find her, recovering from the wounds of her beating, sweltering in her open-doored shack. When she sees you her eyes light up, and she eagerly snatches the proffered REGISTRY PAPERS from your hands. She gazes with confusion as she reads.\n\n\"This can't be right!\" she exclaims. \"It says here that my grandfather legally sold his land to Unbraaki fifty years ago. But my father said...\"\n\n\"I'm afraid it was countersigned by the priests of Cursus,\" you say. \"I suppose it's possible that there was a conspiracy against your family, but it's rare for priests to conspire with sorcerers.\"\n\nSuzanna slumps upon her bed. \"Everything my father told me was a lie,\" she groans. \"I'm not the inheritor of a massive estate, I'm just... me.\"\n\n\"That should be good enough,\" you say. \"Wealth rarely comes to those who sit around for it. If you want to make something of yourself, get out there and do it. You're certainly tough enough.\"\n\nShe nods. \"You're right. It's time I stopped waiting for my life to get better; I've got nothing to lose going adventuring. I'll sign on with the next ship in port.\" She presses a GREY TALISMAN into your hand. \"It's not much, but I want you to have this. It was the last thing my father gave me. Time for a new life.\"\n\nNote: You gained the code A36.";

            Bye = "Waving Damned Suzanna farewell, you make your way on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::REGISTRY_PAPERS});

            Take = {Equipment::GREY_TALISMAN};

            Limit = 1;

            Engine::GET_CODES(party, {Codes::A(36)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story071 : public Story::Base
    {
    public:
        Story071()
        {
            BookID = Book::Type::BOOK1;

            ID = 71;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "With a final flourish, you slay your last opponent. Although there are other living slaves in the arena, the battle suddenly stops as the Iron King stands. In a thickly accented voice, the king declares you champions of the arena. The crowd go wild, cheering you heartily as you catch your breath from the intense battle.\n\nAny hopes you had that being made champion would grant you freedom are soon quashed. Instead you are disarmed and led back into the dungeons to nurse your wounds.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_ALL(party);

            Engine::GET_CODES(party, {Codes::Type::FOUGHT_IN_ARENA});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 608}; }
    };

    class Story072 : public Story::Base
    {
    public:
        Story072()
        {
            BookID = Book::Type::BOOK1;

            ID = 72;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "You can take up to four SHIELDs (Armour +2) from the fallen snakemen if you wish. Their weapons have unusual grips and are not useable for humans.\n\nYou glance around the temple chamber. Despite the cracks and structural damage the room has been kept in good condition, regularly swept clean of dirt and filth. But why would inhuman monsters care for an old Cursus temple?\n\nYou try lifting the portcullis, but it will not shift an inch. You will have to find another way out. Glancing around the chamber you can see a door in the back wall, and an archway in which a ramp leads upwards into the ziggurat. Which direction would you like to investigate?";

            Choices.clear();
            Choices.push_back(Choice::Base("The door", {Book::Type::BOOK1, 380}));
            Choices.push_back(Choice::Base("The archway", {Book::Type::BOOK1, 806}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::ZIGGURAT;

            Take = {Equipment::SHIELD2, Equipment::SHIELD2, Equipment::SHIELD2, Equipment::SHIELD2};

            Limit = 4;
        }
    };

    class Story073 : public Story::Base
    {
    public:
        Story073()
        {
            BookID = Book::Type::BOOK1;

            ID = 73;

            Location = Location::Type::SHADED_GATE;

            Text = "You come upon the Shaded Gate. You feel diminished, as if you were not real.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 1 Health", {Book::Type::BOOK1, -73}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event073 : public Story::Base
    {
    public:
        Event073()
        {
            BookID = Book::Type::BOOK1;

            ID = -73;

            DisplayID = 73;

            Location = Location::Type::SHADED_GATE;

            Text = "Where will you go?";

            Choices.clear();
            Choices.push_back(Choice::Base("Go through the Shaded Gate", {Book::Type::BOOK1, 56}));
            Choices.push_back(Choice::Base("West", {Book::Type::BOOK1, 273}));
            Choices.push_back(Choice::Base("South", {Book::Type::BOOK1, 886}));
            Choices.push_back(Choice::Base("East", {Book::Type::BOOK1, 537}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story074 : public Story::Base
    {
    public:
        Story074()
        {
            BookID = Book::Type::BOOK1;

            ID = 74;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You inform the guard that you wish to see Unbraaki again. You are escorted into his presence, though he seems surprised to see you. \"I have already given you my soldiers,\" he grumbles. \"What more could your queen possibly desire?\"\n\n\"What if we need reinforcements?\" you ask. \"Your soldiers may not be enough to complete the campaign.\"\n\n\"That is no concern of mine,\" snaps Unbraaki coldly. \"You'll get no more from me. I have spent a fortune replacing the soldiers I gave to the Everchild. Send her my regards -- but don't bother me again.\"";

            Bye = "Realising that Unbraaki can be pushed no further, you bow and depart.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 265}; }
    };

    class Story075 : public Story::Base
    {
    public:
        Story075()
        {
            BookID = Book::Type::BOOK1;

            ID = 75;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Image = "images/book1/saltdad_city.png";

            Text = "Saltdad is a city of tumbledown mud-brick houses clustered into claustrophobic alleyways. Above these ragtag structures stands a half-collapsed palace, a minareted masterpiece that has seen better days. Amidst the squalor there is wealth to be found, for Saltdad produces the major export of the valley -- rock salt, chiselled out of winding mines to the east of the city. The Great Westroad runs through the heart of the city, once a paved highway, now a poorly maintained tumble of stones which nonetheless allows wagons and carts to drag themselves above the desert sands. Where the road cuts through the city stand the marketplaces, inns, slave markets and other services the city is famed for. A constant chatter of voices is heard at all times, for Saltdad never closes its places of business, even in the dead of night.";

            Choices.clear();
            Choices.push_back(Choice::Base("Find an inn", {Book::Type::BOOK1, 172}));
            Choices.push_back(Choice::Base("Go to the marketplace", {Book::Type::BOOK1, 798}));
            Choices.push_back(Choice::Base("Go to the slave market", {Book::Type::BOOK1, 326}));
            Choices.push_back(Choice::Base("Visit the palace", {Book::Type::BOOK1, 633}));
            Choices.push_back(Choice::Base("Head to the barracks of the Bronzeguard", {Book::Type::BOOK1, 390}));
            Choices.push_back(Choice::Base("Track down the local Thieves guild", {Book::Type::BOOK1, 179}));
            Choices.push_back(Choice::Base("Visit the temple of Cursus", {Book::Type::BOOK1, 770}));
            Choices.push_back(Choice::Base("Visit the temple of Kalu", {Book::Type::BOOK1, 382}));
            Choices.push_back(Choice::Base("Explore the city", {Book::Type::BOOK1, 471}));
            Choices.push_back(Choice::Base("Head west along the road", {Book::Type::BOOK1, 511}));
            Choices.push_back(Choice::Base("Head east along the road", {Book::Type::BOOK1, 177}));
            Choices.push_back(Choice::Base("Head south into the desert", {Book::Type::BOOK1, 858}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story076 : public Story::Base
    {
    public:
        Story076()
        {
            BookID = Book::Type::BOOK1;

            ID = 76;

            Text = "This must be Garon the Bloody-mouthed, whom you were sent to find. His father will no doubt grieve to know his fate, but at least it will solve the mystery of his disappearance. You were not asked to return the body, but if you wish to do so, you can take the BARBARIAN BODY. Unfortunately, it takes up five inventory slots and must be carried by a single character.\n\nWhat now?";

            Choices.clear();
            Choices.push_back(Choice::Base("Take the BARBARIAN BODY", {Book::Type::BOOK1, -76}, Choice::Type::GET_EQUIPMENT_CODE, {Equipment::BARBARIAN_BODY}, {Codes::A(86)}, {}));
            Choices.push_back(Choice::Base("Examine the missing south wall", {Book::Type::BOOK1, 645}));
            Choices.push_back(Choice::Base("Leave the room and return to the crossroads", {Book::Type::BOOK1, 566}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event076 : public Story::Base
    {
    public:
        Event076()
        {
            BookID = Book::Type::BOOK1;

            ID = -76;

            DisplayID = 76;

            Text = "What now?";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine the missing south wall", {Book::Type::BOOK1, 645}));
            Choices.push_back(Choice::Base("Leave the room and return to the crossroads", {Book::Type::BOOK1, 566}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story077 : public Story::Base
    {
    public:
        Story077()
        {
            BookID = Book::Type::BOOK1;

            ID = 77;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "About halfway up the ramp you come to an archway. Through the archway you can see nothing; your lanterns cannot penetrate the darkness. You try experimentally poking a weapon through the archway, but it seems to come out unharmed.";

            Choices.clear();
            Choices.push_back(Choice::Base("Enter the archway", {Book::Type::BOOK1, 497}));
            Choices.push_back(Choice::Base("Keep going upwards", {Book::Type::BOOK1, 93}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story078 : public Story::Base
    {
    public:
        Story078()
        {
            BookID = Book::Type::BOOK1;

            ID = 78;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "This cave appears to be empty, but for the heaps of sand piled into it. Suddenly one of your party members begins to abruptly sink into the sand.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose the party member sinking into the sand", {Book::Type::BOOK1, -78}, Choice::Type::CHOOSE_PARTY_MEMBER));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event078 : public Story::Base
    {
    public:
        Event078()
        {
            BookID = Book::Type::BOOK1;

            ID = -78;

            DisplayID = 78;

            Text = "This is no normal quicksand, as there is not a drop of moisture in the cave. Nonetheless the hungry earth is pulling them down quickly.";

            Choices.clear();
            Choices.push_back(Choice::Base("Save your teammate (Team check: Survival 4+, Successes: 5)", {Book::Type::BOOK1, 586}, {Book::Type::BOOK1, 646}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 5));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story079 : public Story::Base
    {
    public:
        Story079()
        {
            BookID = Book::Type::BOOK1;

            ID = 79;

            Location = Location::Type::MORDAIN;

            Text = "You wander the merchant sector of the city, expecting to find nothing but lonely stones and whistling wind. You are surprised, therefore, to discover signs of a recent excavation. Near the entrance you see the bodies of several decomposing humans... and the body of a single, diseased-looking orc. Strange. Orcs are not native to this part of the world and normally call the Savage Lands their home. What are they doing all the way out here?\n\nBeyond the bodies an ancient set of steps lead into the earth, the walls of the tunnel made of well-set brick, and the floors of large flagstones.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go down the stairs, into the excavated dungeon", {Book::Type::BOOK1, 350}));
            Choices.push_back(Choice::Base("Go elsewhere in the city", {Book::Type::BOOK1, 515}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story080 : public Story::Base
    {
    public:
        Story080()
        {
            BookID = Book::Type::BOOK1;

            ID = 80;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Holding your torches high you begin to make your way into the crevice, carefully watching your feet in the dancing firelight as they crunch near the eggs. A giant spider above you crawls along the ceiling, as if tracking your progress through her nursery.\n\n\"Step where we step,\" you advise the Everchild's followers as you move carefully forwards.";

            Choices.clear();
            Choices.push_back(Choice::Base("Navigate the spider's nest (Team check: Survival 4+, Successes: 5)", {Book::Type::BOOK1, 461}, {Book::Type::BOOK1, 260}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 5));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story081 : public Story::Base
    {
    public:
        Story081()
        {
            BookID = Book::Type::BOOK1;

            ID = 81;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "Longport Bay is a county in the kingdom of Royce. It is famed for its steelwork, good agricultural land and the dreadful rivalry of its noble houses. The county is fiercely feudal, with commoners unable to travel freely without a lord's consent. It is also famous for its jousts and fairs, and in good years the locals can grow fat on the rich foodstuffs served at these frequent celebrations. According to the scroll, the county is currently ruled by House Bailey, who were once mere stewards of their rivals House Dayne. That house has seen something of a fall in fortunes lately, and now stand in lower esteem than the Baileys. However, the scroll warns you that all sorts could have changed since the time it was written, as the politics in Longport Bay is both bloody and unpredictable.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 680}; }
    };

    class Story082 : public Story::Base
    {
    public:
        Story082()
        {
            BookID = Book::Type::BOOK1;

            ID = 82;

            Location = Location::Type::NORTHWESTCOAST_VALLEY_OF_BONES;

            Text = "You are sailing along the northwest coast of the Valley of Bones. A steady sea breeze counters what would otherwise be an unbearably hot sun. Great cliffs line the coast. Atop them sits a ramshackle city of crude adobe buildings and assorted ruins. A harbour juts dangerously from the cliff face, moored ships bobbing like corks against the pounding waves. Drenched harbourside taverns sit squalidly amongst the docks.";

            Choices.clear();
            Choices.push_back(Choice::Base("Pull into Clifftop harbour", {Book::Type::BOOK1, 703}));
            Choices.push_back(Choice::Base("(Drakehallow) Sail north, past the Stonewalls", {Book::Type::BOOK6, 420}));
            Choices.push_back(Choice::Base("(Crown and Tower) Sail west into the Bayswater Channel", {Book::Type::BOOK2, 392}));
            Choices.push_back(Choice::Base("Sail south to Cape Porta", {Book::Type::BOOK1, 21}));
            Choices.push_back(Choice::Base("(Code: A32) Consider doing something else", {Book::Type::BOOK1, 643}, {Codes::A(32)}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story083 : public Story::Base
    {
    public:
        Story083()
        {
            BookID = Book::Type::BOOK1;

            ID = 83;

            Text = "You hold out the ENGAGEMENT RING. \"The RING was not sold, it was stolen,\" you insist. \"I found this in the hideout of a group of nefarious thieves. She wants you to have it. She loved you, she was not using you.\"\n\nDulcimer takes the RING, swallowing hard.\n\n\"Is my lord really so poor a judge of character?\" you continue. \"The girl has a noble spirit and an honest temperament. It was not witchcraft but love that was the cause of her deception. Do not damage your family name further with this ridiculous feud with a common house. There is nothing to gain but dishonour.\"\n\nDulcimer's father agrees. \"Now that there is no financial loss to the family this matter should be closed quickly. You may take the girl's aunt back to her family. However, Akini is not to cross our path again.\"\n\nAkini's aunt is released, and you escort her back to her home.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::ENGAGEMENT_RING});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 68}; }
    };

    class Story084 : public Story::Base
    {
    public:
        Story084()
        {
            BookID = Book::Type::BOOK1;

            ID = 84;

            Text = "It is all too obvious what has happened. Your companion is doomed for all time to read that cursed book -- but to disturb them would invoke such a terrible wrath you might not survive. You carefully remove the items and money your companions was carrying. After this you say your sorry farewells, hoping that some part of your friend is still aware deep down inside.\n\nNote: This party member is lost forever. Curiously, if you ever return to this room, the party member will have vanished.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            Limit = 0;

            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                Engine::LOSE_ALL(party.Members[party.LastSelected], Equipment::Class::ARMOUR);
                Engine::LOSE_ALL(party.Members[party.LastSelected], Equipment::Class::WEAPON);

                Take = party.Members[party.LastSelected].Equipment;

                Limit = Take.size();

                auto deadCharacter = Engine::FIND_CHARACTER(party.Order, party.Members[party.LastSelected].Type);

                if (deadCharacter >= 0 && deadCharacter < party.Order.size())
                {
                    party.Order.erase(party.Order.begin() + deadCharacter);
                }

                party.Members.erase(party.Members.begin() + party.LastSelected);

                party.CurrentCharacter = -1;

                party.LastSelected = -1;
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 821}; }
    };

    class Story085 : public Story::Base
    {
    public:
        Story085()
        {
            BookID = Book::Type::BOOK1;

            ID = 85;

            Text = "Only paupers use the rope bridges... as they have a tendency to suddenly break.";

            Choices.clear();
            Choices.push_back(Choice::Base("Random Event", {{1, NULL, {Book::Type::BOOK1, 824}}, {6, NULL, {Book::Type::BOOK1, 519}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story086 : public Story::Base
    {
    public:
        Story086()
        {
            BookID = Book::Type::BOOK1;

            ID = 86;

            Text = "You go amongst the king's councillors, trying to find one who might be able to arrange an appointment for you.";

            Choices.clear();
            Choices.push_back(Choice::Base("Arrange an audience (Team check: Charisma 5+, Successes: 5)", {Book::Type::BOOK1, 134}, {Book::Type::BOOK1, 775}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 5, 5));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (!outcome)
            {
                Bye = "You cannot find anyone to represent you. Eventually it gets dark and the hall is closed to foreigners.";
            }
        }
    };

    class Story087 : public Story::Base
    {
    public:
        Story087()
        {
            BookID = Book::Type::BOOK1;

            ID = 87;

            Text = "Water gushes in through the ripped hole in your ship. Your crew give a great cry and abandon ship, leaping into the frothing waves with a wail. You have scant seconds to prepare yourself to dive into the ocean. Any character wearing a suit of armour or robes discards it. You can carry no more than four items each before leaping into the sea -- any remaining items must be crossed off (there is no time to conjure a magic cabinet).";

            Bye = "You swim the base of the cliff, exhausted and freezing -- but there is nowhere to go but up.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::NO_VAULT_ACCESS});

            Engine::LOSE_ALL(party, Equipment::Class::ARMOUR);

            Engine::LOSE_ALL(party, Equipment::Class::ROBE);

            Engine::SINK_SHIP(party);

            Choices.clear();

            if (!Engine::VERIFY_EQUIPMENT_LIMIT(party, 4))
            {
                Choices.push_back(Choice::Base("Drop number of items down to 4", {Book::Type::BOOK1, -87001}, Choice::Type::LIMIT_EQUIPMENT, 4));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, -87001}; }
    };

    class E087_001 : public Story::Base
    {
    public:
        E087_001()
        {
            BookID = Book::Type::BOOK1;

            ID = -87001;

            DisplayID = 87;

            Text = "You attempt to scale the cliffsides leading to the jungle.";

            Choices.clear();
            Choices.push_back(Choice::Base("Climb the cliffside (Team check: Survival 5+, Successes: 4)", {Book::Type::BOOK1, 409}, {Book::Type::BOOK1, -87002}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 5, 4));

            Controls = Story::Controls::STANDARD;
        }
    };

    class E087_002 : public Story::Base
    {
    public:
        std::string PreText = "";

        E087_002()
        {
            BookID = Book::Type::BOOK1;

            ID = -87002;

            DisplayID = 87;

            Choices.clear();
            Choices.push_back(Choice::Base("Choose the party member lost in the climbing attempt", {Book::Type::BOOK1, -87003}, Choice::Type::CHOOSE_PARTY_MEMBER));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            if (Engine::COUNT(party) > 1)
            {
                PreText = "One of your party members loses their grip halfway up and plunges into the sea. They are never seen again.";
            }
            else
            {
                PreText = "You lose your grip halfway up and plunge into the sea. You are never seen again.";

                party.Members.clear();

                party.CurrentCharacter = -1;

                party.LastSelected = -1;
            }

            Text = PreText.c_str();
        }
    };

    class E087_003 : public Story::Base
    {
    public:
        E087_003()
        {
            BookID = Book::Type::BOOK1;

            ID = -87003;

            DisplayID = 87;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                party.Dead.push_back(party.Members[party.LastSelected].Type);

                party.Members[party.LastSelected].Equipment.clear();

                party.Members.erase(party.Members.begin() + party.LastSelected);

                party.CurrentCharacter = -1;

                party.LastSelected = -1;
            }

            return {Book::Type::BOOK1, -87001};
        }
    };

    class Story088 : public Story::Base
    {
    public:
        Story088()
        {
            BookID = Book::Type::BOOK1;

            ID = 88;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You dash after Yu Yan, the thief frantically attempting to negotiate the ledge, which you navigate with the skill of a mountain goat. She stumbles, and only just manages to catch the ledge before falling. You dash to her side.\n\n\"Need a hand?\" you ask.\n\n\"Let me guess... you want the damn SILVER IDOL, yes?\"\n\n\"I think I'll need all the treasure; it's only weighing you down,\" you respond smartly.\n\nYu Yan groans, but throws her loot bag up to you. It contains not only the SILVER IDOL, but 200 silver pieces as well. Grinning, you give her a hand up on to the ledge. She grasps the sides of the wall, breathing heavily as you lean casually against the hillside.\n\n\"Make yourself scarce, Yu Yan,\" you say to her. \"Up here, in the hills, this is my domain.\"\n\nShe thanks you for your mercy and shuffles away, dashing over the hillside as soon as she is on safer ground. You make your way back along the ledge, hoping to find the beautiful vista again, but you cannot find it. Perhaps it is the time of night, but the surroundings no longer look so beautiful and peaceful as they were before. You shrug, but you are pleased with your victory.";

            Bye = "You make your way back to the temple in Chalice.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 200);

            Engine::GET_EQUIPMENT(party, Character::Type::AKIHIRO_OF_CHALICE, {Equipment::SILVER_IDOL});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 856}; }
    };

    class Story089 : public Story::Base
    {
    public:
        Story089()
        {
            BookID = Book::Type::BOOK1;

            ID = 89;

            Text = "A great caravan of salt merchants, enroute to Clifftop, offer you their services. Their merchants have various odds and ends you might find useful.\n\nIf you have a ship docked in Clifftop, you can also buy up to three cargo units of SALT from the merchants for 500 silver coins each. They will deliver this cargo straight to your ship provided there is room for it.";

            Choices.clear();
            Choices.push_back(Choice::Base("Buy one cargo unit of SALT", {Book::Type::BOOK1, -89}, Choice::Type::DELIVER, {Cargo::Type::SALT}, Location::Type::CLIFFTOP, 500));
            Choices.push_back(Choice::Base("Buy two cargo units of SALT", {Book::Type::BOOK1, -89}, Choice::Type::DELIVER, {Cargo::Type::SALT, Cargo::Type::SALT}, Location::Type::CLIFFTOP, 1000));
            Choices.push_back(Choice::Base("Buy three cargo units of SALT", {Book::Type::BOOK1, -89}, Choice::Type::DELIVER, {Cargo::Type::SALT, Cargo::Type::SALT, Cargo::Type::SALT}, Location::Type::CLIFFTOP, 1500));
            Choices.push_back(Choice::Base("You have finished your trading", {Book::Type::BOOK1, 569}));

            Controls = Story::Controls::SHOP;
        }

        void Event(Party::Base &party)
        {
            Shop = {
                {Equipment::CRUDE_BLADE, 25, 10, -1, {}},
                {Equipment::MAUL, 50, 20, -1, {}},
                {Equipment::SHIELD2, 50, 25, -1, {}},
                {Equipment::INCENSE, -1, 90, -1, {}},
                {Equipment::BLUESTONE, -1, 45, -1, {}},
                {Equipment::TALISMAN_OF_ST_ELIAS, -1, 150, -1, {}}};
        }
    };

    class Event089 : public Story::Base
    {
    public:
        Event089()
        {
            BookID = Book::Type::BOOK1;

            ID = -89;

            DisplayID = 89;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party) { return {Book::Type::BOOK1, 89}; }
    };

    class Story090 : public Story::Base
    {
    public:
        Story090()
        {
            BookID = Book::Type::BOOK1;

            ID = 90;

            Location = Location::Type::LHASBREATH;

            Text = "Your return trip to Lhasbreath is mercifully uneventful, and Sir Lawrence Ross lays on a grand banquet upon your arrival. You spend several days with the Ross's, recovering your strength and discussing your adventures.\n\nWhen Emlyn reports her findings, the news is rather disappointing. \"We have recovered many pretty blooms,\" she admits. \"Certainly, the fragrances are quite striking... however, there are no medicinal or culinary plants, as far as I can tell. Nothing sellable.\"\n\n\"Curses!\" grumbles Sir Lawrence. \"This expedition is turning into an expensive failure.\"\n\nStill, Sir Lawrence is good to his word and presents you with a purse of 150 silver coins. Offering your consolations over the failed mission, you depart into the city.\n\nAlthough the expedition did not go perfectly you have learned a lot.\n\nNote: You gained the code A85.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Survival", {Book::Type::BOOK1, 775}, Choice::Type::ROLL_FOR_ATTRIBUTE_INCREASE, {Attribute::Type::SURVIVAL}, 1, 2, 0));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 150);

            Engine::REST(party);

            Engine::GET_CODES(party, {Codes::A(85)});
        }
    };

    class Story091 : public Story::Base
    {
    public:
        Story091()
        {
            BookID = Book::Type::BOOK1;

            ID = 91;

            Text = "Climbing through the window silently will take some skill.";

            Choices.clear();
            Choices.push_back(Choice::Base("Force open the door (Individual check: Stealth 5+, Successes: 3)", {Book::Type::BOOK1, 487}, {Book::Type::BOOK1, 724}, Choice::Type::ORDER_SKILL_CHECK, {Attribute::Type::STEALTH}, 1, 5, 3));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story092 : public Story::Base
    {
    public:
        Story092()
        {
            BookID = Book::Type::BOOK1;

            ID = 92;

            Text = "You creep up the stairs and reach a long landing. Peering out of the windows you can see Brekken and the wall-climbing team struggling to pry open the windows. With a grin you undo the latch, allowing the wall climbers easy access to the house.\n\nNote: For the rest of the break-in, when you make team checks, you can use the skills and combat abilities of your entire team, not just the wall-climbing team.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::WALL_CLIMBING_AND_DOOR});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 116}; }
    };

    class Story093 : public Story::Base
    {
    public:
        Story093()
        {
            BookID = Book::Type::BOOK1;

            ID = 93;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "The ramp continues to wind upwards until you reach a small room with statues of hideous snakemen in alcoves along the walls. Here your way divides.";

            Choices.clear();
            Choices.push_back(Choice::Base("Make your way left, down a tunnel with a good deal of hissing coming from it", {Book::Type::BOOK1, 538}));
            Choices.push_back(Choice::Base("Go to the right, where the tunnel narrows alarmingly", {Book::Type::BOOK1, 98}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story094 : public Story::Base
    {
    public:
        Story094()
        {
            BookID = Book::Type::BOOK1;

            ID = 94;

            Text = "You carefully lower yourself into the pit, being careful to avoid the spikes. Moving aside the timbers you check over the body. You find 15 silver coins spilling from a rotten pouch and a still intact DRAGONYAK HORN.\n\nNote: You gained the code A46.";

            Choices.clear();
            Choices.push_back(Choice::Base("Climb up the far side of the pit", {Book::Type::BOOK1, 303}));
            Choices.push_back(Choice::Base("Climb back up the way you came", {Book::Type::BOOK1, 761}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(46)}))
            {
                return {Book::Type::BOOK1, 624};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::DRAGONYAK_HORN};

            Limit = 1;

            Engine::GAIN_MONEY(party, 15);

            Engine::GET_CODES(party, {Codes::A(46)});
        }
    };

    class Story095 : public Story::Base
    {
    public:
        Story095()
        {
            BookID = Book::Type::BOOK1;

            ID = 95;

            Text = "The assassin falls, his dagger clattering to the ground. You quickly escort the Everchild to a safer location. \"I'm alright! I promise! I knew you would protect me,\" she smiles. \"You always have.\"\n\nThe Everchild looks unflustered and calm as the morning sun illuminates the horizon, and her presence on the field, astride a nomad steed, causes your army to cheer wildly. Confidence is high. Now it is time to see if your preparations for the coming battle have been enough.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 162}; }
    };

    class Story096 : public Story::Base
    {
    public:
        Story096()
        {
            BookID = Book::Type::BOOK1;

            ID = 96;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::COUNT(party, Team::Type::MERCENARY) > 0)
            {
                return {Book::Type::BOOK1, 27};
            }
            else
            {
                return {Book::Type::BOOK1, 545};
            }
        }
    };

    class Story097 : public Story::Base
    {
    public:
        Story097()
        {
            BookID = Book::Type::BOOK1;

            ID = 97;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You do not trust idly displayed skeletons these days. You make a point of shattering their skulls and ribcages, casting their bones about and generally demolishing their mortal remains. You feel a little bad about it afterwards, wondering if you have committed some sort of sacrilege, but there is no going back now.\n\nNote: You gained the code A75.";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine the book", {Book::Type::BOOK1, 8}));
            Choices.push_back(Choice::Base("Return to the crossroads", {Book::Type::BOOK1, 310}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(75)});
        }
    };

    class Story098 : public Story::Base
    {
    public:
        Story098()
        {
            BookID = Book::Type::BOOK1;

            ID = 98;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "The tunnel is extremely narrow, and you must proceed down it single file. Decide which party member is at the front of the group and which is at the back.";

            Choices.clear();
            Choices.push_back(Choice::Base("Select which party member is in FRONT", {Book::Type::BOOK1, -98}, Choice::Type::SET_STATUS_FROM_LIST, {Character::Status::FRONT, Character::Status::BACK}, 0));
            Choices.push_back(Choice::Base("Select which party member is at the BACK", {Book::Type::BOOK1, -98}, Choice::Type::SET_STATUS_FROM_LIST, {Character::Status::FRONT, Character::Status::BACK}, 1));
            Choices.push_back(Choice::Base("Proceed", {Book::Type::BOOK1, 849}, Choice::Type::HAS_STATUS, {Character::Status::FRONT, Character::Status::BACK}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event098 : public Story::Base
    {
    public:
        Event098()
        {
            BookID = Book::Type::BOOK1;

            ID = -98;

            DisplayID = 98;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party) { return {Book::Type::BOOK1, 98}; }
    };

    class Story099 : public Story::Base
    {
    public:
        Story099()
        {
            BookID = Book::Type::BOOK1;

            ID = 99;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The goblins chitter to each other in their native tongue, unsure of what to do. Such indecisive beasts!";

            Choices.clear();
            Choices.push_back(Choice::Base("Keep waiting", {Book::Type::BOOK1, 389}));
            Choices.push_back(Choice::Base("Leave the kitchen through the north door", {Book::Type::BOOK1, 366}));
            Choices.push_back(Choice::Base("Leave the kitchen through the south door", {Book::Type::BOOK1, 736}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story100 : public Story::Base
    {
    public:
        Story100()
        {
            BookID = Book::Type::BOOK1;

            ID = 100;

            Text = "With precise incantations you launch yourself into the ether, towards the Valley of Bones.\n\nWhere do you wish to appear?";

            Choices.clear();
            Choices.push_back(Choice::Base("Chalice", {Book::Type::BOOK1, 450}));
            Choices.push_back(Choice::Base("Clifftop", {Book::Type::BOOK1, 19}));
            Choices.push_back(Choice::Base("Cursus", {Book::Type::BOOK1, 340}));
            Choices.push_back(Choice::Base("Lhasbreath Oasis", {Book::Type::BOOK1, 590}));
            Choices.push_back(Choice::Base("Lhasbreath", {Book::Type::BOOK1, 775}));
            Choices.push_back(Choice::Base("Lhasbreath Jungle", {Book::Type::BOOK1, 370}));
            Choices.push_back(Choice::Base("Luutanesh", {Book::Type::BOOK1, 614}));
            Choices.push_back(Choice::Base("Saltdad", {Book::Type::BOOK1, 75}));
            Choices.push_back(Choice::Base("The Blackwall", {Book::Type::BOOK1, 691}));
            Choices.push_back(Choice::Base("The Caves of Uranu", {Book::Type::BOOK1, 346}));
            Choices.push_back(Choice::Base("The Granite Hills", {Book::Type::BOOK1, 275}));
            Choices.push_back(Choice::Base("The Palace of Unbraaki", {Book::Type::BOOK1, 890}));
            Choices.push_back(Choice::Base("The Ruins of Mordain", {Book::Type::BOOK1, 515}));
            Choices.push_back(Choice::Base("The Salt Mines of Saltdad", {Book::Type::BOOK1, 25}));
            Choices.push_back(Choice::Base("The Salt Plains", {Book::Type::BOOK1, 460}));
            Choices.push_back(Choice::Base("The Temple of the Unbroken", {Book::Type::BOOK1, 535}));
            Choices.push_back(Choice::Base("The Tumblestones", {Book::Type::BOOK1, 137}));
            Choices.push_back(Choice::Base("The Withered Steppes", {Book::Type::BOOK1, 115}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story101 : public Story::Base
    {
    public:
        Story101()
        {
            BookID = Book::Type::BOOK1;

            ID = 101;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Spitting on the blood-stained sands, you stride into the central battle, back to back, swords in hand.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Lhasbreth Barbarians", 7, 5, 3, 17, 0),
                Monster::Base("Chalice Swordsmen", 5, 4, 4, 10, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 71}; }
    };

    class Story102 : public Story::Base
    {
    public:
        Story102()
        {
            BookID = Book::Type::BOOK1;

            ID = 102;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Text = "This key has certainly travelled a long way from its lock -- but it fits! You hear a loud clang as you turn the key, its triple locks unbolting one by one. The key seems to be absorbed into the door mechanism itself and is pulled out of your hand. You step into a vast chamber beyond, filled with urns brimming with treasure. A stone sarcophagus of a mighty king dominates the middle of the enormous room, raised up on a high platform surmountable only by a long set of stairs.\n\nFrom the corners of the chamber you see something terrible. Two giant skeletons, clad in bronze armour, suddenly animate, blazing balefire in their eyes. They heft enormous swords, ten feet long each.\n\nIf you wish you can flee the chamber now -- but you can never return. The door will slam shut behind you.";

            Choices.clear();
            Choices.push_back(Choice::Base("Flee the chamber", {Book::Type::BOOK1, 46}));
            Choices.push_back(Choice::Base("Fight for your treasure", {Book::Type::BOOK1, -102}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::PYRAMIDAL_KEY});
        }
    };

    class Event102 : public Story::Base
    {
    public:
        Event102()
        {
            BookID = Book::Type::BOOK1;

            ID = -102;

            DisplayID = 102;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Text = "You have chosen to fight for your treasure.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Giant Skeleton", 8, 3, 5, 30, 0),
                Monster::Base("Giant Skeleton", 10, 3, 4, 25, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 178}; }
    };

    class Story103 : public Story::Base
    {
    public:
        Story103()
        {
            BookID = Book::Type::BOOK1;

            ID = 103;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "You open the cage and the bird immediately flies onto a low branch. You are about to move on when the bird addresses you. \"I'm grateful,\" it says. \"Not many humans would do such a thing without promise of reward.\"\n\n\"Not many birds can talk,\" you say, surprised.\n\n\"All animals can talk -- but rarely in your language,\" admits the bird. \"I can teach you our tongue, if you have any skill in sorcery.\"\n\nIf you want to accept the bird's offer you can learn the spell below if you have any spellcasters in your party:\n\nAnimal Speech (Adventure)\n\nYou are able to communicate using the secret speech of animals.\n\nRecharge: 50 silver";

            Bye = "You thank the bird and watch as it flies off above the jungle canopy.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Spells = {Spells::ANIMAL_SPEECH};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 618}; }
    };

    class Story104 : public Story::Base
    {
    public:
        Story104()
        {
            BookID = Book::Type::BOOK1;

            ID = 104;

            Text = "You cannot be certain, but the mural appears to be telling some sort of story. An image of a terrible demon, possibly Abraxas from legend, rises from the earth and demolishes a number of cities. From cracks in the ground come snakemen, slithering around the survivors and rounding them up. The humans are turned into slaves, building the snakemen a mighty temple, but soon even the slaves begin to worship at the altars of the temple as well. Here the mural ends abruptly. Make of it what you will.\n\nNote: You gained the code A41.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(41)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 77}; }
    };

    class Story105 : public Story::Base
    {
    public:
        Story105()
        {
            BookID = Book::Type::BOOK1;

            ID = 105;

            Location = Location::Type::LHASBREATH_RAPIDS;

            Text = "You make your way down to the riverbank, and eventually find the raft with Emlyn's help, covered over with weeds and bushes. Two long poles can be used to pilot the craft, and soon you are punting down the river, the sun shimmering through the canopy of trees onto the glittering water.\n\nThe raft begins to pick up speed, and as you round a corner you can see why. There are rapids ahead, the water splashing with thick foam against scattered rocks that peek through the surface of the river. If you were in canoes it would be easily navigable. On your raft it will take all your skill to avoid danger.";

            Choices.clear();
            Choices.push_back(Choice::Base("Navigate the rapids (Team check: Survival 5+, Successes: 3)", {Book::Type::BOOK1, 54}, {Book::Type::BOOK1, 337}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 5, 3));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story106 : public Story::Base
    {
    public:
        Story106()
        {
            BookID = Book::Type::BOOK1;

            ID = 106;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You pretend to offer aid; anything to get out of sight of the Everchild's rebellious followers. At the first opportunity you inform the guards about the rebel's intentions. A few days later Che Long, Milagros and her followers have vanished from the arena. Word reaches you about a bloody struggle in the cells, but there are few details. Not long after, the arena master releases you under orders of the Iron King. \"His majesty is most pleased with your loyalty; the identity of the rebel leaders has been a well-kept secret. He offers you this reward and asks you to attend him at his palace if you seek further remunerating work.\"\n\nThe arena master presents you with 200 silver pieces.\n\nNote: You gained the code A4.";

            Bye = "Weighing the price of treachery with a smile, you gleefully leave the arena.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 200);

            Engine::GET_CODES(party, {Codes::A(4)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story107 : public Story::Base
    {
    public:
        Story107()
        {
            BookID = Book::Type::BOOK1;

            ID = 107;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IN_PARTY(party, Character::Type::SAR_JESSICA_DAYNE))
            {
                return {Book::Type::BOOK1, 514};
            }
            else
            {
                return {Book::Type::BOOK1, 753};
            }
        }
    };

    class Story108 : public Story::Base
    {
    public:
        Story108()
        {
            BookID = Book::Type::BOOK1;

            ID = 108;

            Text = "You hear hoofbeats in the distance. Glancing over the top of dune you spot a group of Lhasbreath barbarians, riding on horseback. There are six of them -- quite a formidable group!";

            Choices.clear();
            Choices.push_back(Choice::Base("Attempt to hide from them by partially burying yourselves in the dunes", {Book::Type::BOOK1, 525}));
            Choices.push_back(Choice::Base("Greet them cordially", {Book::Type::BOOK1, 199}));
            Choices.push_back(Choice::Base("Attack them at long distance", {Book::Type::BOOK1, 297}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story109 : public Story::Base
    {
    public:
        Story109()
        {
            BookID = Book::Type::BOOK1;

            ID = 109;

            Text = "There are no exceptions. With dozens of guards at their command the priests strip you of all your taxable items (items that provide a +2 or greater bonus, except for shields). For good measure you are scourged with the whip as well. Each party member must lose 1 Health point.";

            Bye = "Appalled at this daylight robbery you make your way on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            for (auto i = 0; i < party.Members.size(); i++)
            {
                auto non_taxable = std::vector<Equipment::Base>();

                for (auto j = 0; j < party.Members[i].Equipment.size(); j++)
                {
                    if (party.Members[i].Equipment[j].Class == Equipment::Class::SHIELD || party.Members[i].Equipment[j].Attribute == Attribute::Type::NONE || party.Members[i].Equipment[j].Modifier < 2)
                    {
                        non_taxable.push_back(party.Members[i].Equipment[j]);
                    }
                }

                if (non_taxable.size() > 0)
                {
                    party.Members[i].Equipment = non_taxable;
                }
                else
                {
                    party.Members[i].Equipment.clear();
                }
            }

            Engine::GAIN_HEALTH(party, -1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 458}; }
    };

    // TODO: Characters with Ritual Scarring who entered the Ziggurat will be in Team Zigurrat until they return to town
    class Story110 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story110()
        {
            BookID = Book::Type::BOOK1;

            ID = 110;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(100)}))
            {
                return {Book::Type::BOOK1, 823};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::CONSOLIDATE(party);

            PreText = "The Grand Ziggurat is one of the largest buildings in the valley, dwarfed only by the colossal Saltdad palace. Guarding its steps are the fanatical Cursus Temple Guard, the elite soldiers of the patriarch. They halt you as you begin to climb the steps.\n\n\"Hold there, filthy heathens!\" they spit. \"Only true followers of Cursus are allowed within!\"";

            Choices.clear();

            if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::RING_OF_THE_PATRIARCH}))
            {
                PreText += "\n\nNote: Only party members who have Ritual Scarring (Cursus) are permitted to enter the ziggurat. Those without the scarring must wait outside, and you cannot use their equipment or abilities until you leave the ziggurat.";

                Choices.push_back(Choice::Base("Enter the ziggurat (party members without Ritual Scarring (Cursus) must wait outside)", {Book::Type::BOOK1, 574}, Choice::Type::HAS_STATUS, {Character::Status::RITUAL_SCARRING_CURSUS}));
                Choices.push_back(Choice::Base("Return to the town centre", {Book::Type::BOOK1, 340}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 387}; }
    };

    class Story111 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Team::Type previousTeam = Team::Type::NONE;

        int character = -1;

        Story111()
        {
            BookID = Book::Type::BOOK1;

            ID = 111;

            Text = "Sar Jessica is the first-born daughter of a baron of Royce. It is impossible for a nobleman such as Dulcimer to refuse the challenge and keep face in court. He emerges from the house, accompanied by his house guards, an Ozury rapier in his hand. His family, an endless procession of cousins, grandparents, brothers and sisters, gather in a circle to watch the duel.\n\nNote: Only Sar Jessica may engage in this battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::SAR_JESSICA_DAYNE;

            character = Engine::FIND_CHARACTER(party, Character::Type::SAR_JESSICA_DAYNE);

            if (Engine::IS_ACTIVE(party, character))
            {
                previousTeam = party.Members[character].Team;

                Engine::SET_TEAM(party.Members[character]);

                Monsters = {Monster::Base("Dulcimer", 4, 4, 4, 8, 0)};
            }
            else
            {
                Monsters.clear();
            }
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                if (Engine::IS_ACTIVE(party, character))
                {
                    Engine::SET_TEAM(party.Members[character], previousTeam);
                }

                Bye = "The family reluctantly release Akini's aunt, bidding you never to darken their doorstep again.";

                destination = {Book::Type::BOOK1, 68};
            }
            else
            {
                Bye = "Sar Jessica is slain. You take her equipment before leaving the house in disgrace.";

                destination = {Book::Type::BOOK1, 468};
            }
        }
    };

    class Story112 : public Story::Base
    {
    public:
        Story112()
        {
            BookID = Book::Type::BOOK1;

            ID = 112;

            Location = Location::Type::MORDAIN;

            Text = "Your new crew cheer as you come aboard. The ship is large and shabbily built -- but perhaps you can make something of it?\n\n[HULK] Fighting: 3, Health: 5, Cargo: 3 units\n\nNote: Your new ship is in Mordain harbour. What will you do now?";

            Choices.clear();
            Choices.push_back(Choice::Base("Depart in your new ship", {Book::Type::BOOK1, 851}, Choice::Type::SHIP, Location::Type::MORDAIN));
            Choices.push_back(Choice::Base("Enter the wide tunnel", {Book::Type::BOOK1, 593}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            party.Fleet.push_back(Ship::Base("HULK", Ship::Type::HULK, Location::Type::MORDAIN, 3, 5, 3));
        }
    };

    class Story113 : public Story::Base
    {
    public:
        Story113()
        {
            BookID = Book::Type::BOOK1;

            ID = 113;

            Location = Location::Type::NORTH_ROAD;

            Text = "You are travelling along the Northroad that stretches between Cursus and Luutanesh. Armed convoys from the mystical city of Chalice roll by, along with scores of travellers. Watering stops dot the ragged highway, with merchants paying a few silver coins a time to feed their labouring dragonyaks.";

            Choices.clear();
            Choices.push_back(Choice::Base("Random Event", {{1, NULL, {Book::Type::BOOK1, 694}}, {6, NULL, {Book::Type::BOOK1, 477}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story114 : public Story::Base
    {
    public:
        Story114()
        {
            BookID = Book::Type::BOOK1;

            ID = 114;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You cautiously peek into the room. Before you are four enormous orcs, armed to the teeth. Fortunately all four are dead, victims of a poisoning. It is a coward's weapon; but very effective!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 669}; }
    };

    class Story115 : public Story::Base
    {
    public:
        Story115()
        {
            BookID = Book::Type::BOOK1;

            ID = 115;

            Location = Location::Type::WITHERED_STEPPES;

            Image = "images/book1/rocky_desert.png";

            Text = "You are travelling across a stretch of rocky desert, that rolls and twists into great gulches and canyons. Paths have been worn into the stone from hundreds of years of travel by nomads and barbarians who avoid the well-guarded roads that link the cities. It is hot and dry, and getting lost is a distinct possibility.";

            Choices.clear();
            Choices.push_back(Choice::Base("Navigate the Withered Steppes (Team check: Survival 4+, Successes: 3)", {Book::Type::BOOK1, -115001}, {Book::Type::BOOK1, -115002}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 3));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (!outcome)
            {
                Bye = "Each party member loses 1 Health point as your rations dwindle.";

                Engine::GAIN_HEALTH(party, -1);
            }
            else
            {
                Bye = NULL;
            }
        }
    };

    class E115_001 : public Story::Base
    {
    public:
        E115_001()
        {
            BookID = Book::Type::BOOK1;

            ID = -115001;

            DisplayID = 115;

            Location = Location::Type::WITHERED_STEPPES;

            Image = "images/book1/rocky_desert.png";

            Text = "You manage to get your bearings enough to explore your surroundings.";

            Choices.clear();
            Choices.push_back(Choice::Base("Look for a nomad camp", {Book::Type::BOOK1, 253}));
            Choices.push_back(Choice::Base("Explore some of the canyons", {Book::Type::BOOK1, 884}));
            Choices.push_back(Choice::Base("Go west to the Granite Hills", {Book::Type::BOOK1, 275}));
            Choices.push_back(Choice::Base("Go southwest into the deep desert", {Book::Type::BOOK1, 202}));
            Choices.push_back(Choice::Base("Go south to the Temple of the Unbroken", {Book::Type::BOOK1, 535}));
            Choices.push_back(Choice::Base("Go east to the Northroad", {Book::Type::BOOK1, 113}));
            Choices.push_back(Choice::Base("Go northeast to Luutanesh", {Book::Type::BOOK1, 614}));
            Choices.push_back(Choice::Base("Go north to the Westroad", {Book::Type::BOOK1, 177}));
            Choices.push_back(Choice::Base("Go northeast towards Saltdad", {Book::Type::BOOK1, 858}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class E115_002 : public Story::Base
    {
    public:
        E115_002()
        {
            BookID = Book::Type::BOOK1;

            ID = -115002;

            DisplayID = 115;

            Location = Location::Type::WITHERED_STEPPES;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party) { return {Book::Type::BOOK1, 115}; }
    };

    class Story116 : public Story::Base
    {
    public:
        Story116()
        {
            BookID = Book::Type::BOOK1;

            ID = 116;

            Text = "You creep across the landing, looting rooms as you go.\n\nNote: Only members of the Wall-climbing team may help with the check.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::VERIFY_CODES(party, {Codes::Type::WALL_CLIMBING_AND_DOOR}))
            {
                Choices.push_back(Choice::Base("Rob the upper floor (Team check: Stealth 4+, Successes: 5)", {Book::Type::BOOK1, 22}, {Book::Type::BOOK1, 529}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::STEALTH}, 4, 5));
            }
            else
            {
                Choices.push_back(Choice::Base("Rob the upper floor (Team check: Stealth 4+, Successes: 5)", {Book::Type::BOOK1, 22}, {Book::Type::BOOK1, 529}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::WALL_CLIMBING, {Attribute::Type::STEALTH}, 4, 5));
            }
        }
    };

    class Story117 : public Story::Base
    {
    public:
        Story117()
        {
            BookID = Book::Type::BOOK1;

            ID = 117;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "Battle is joined! The ogre lumbers to its feet and attacks. Unbeknownst to you, the ogre's mate, Daisy, is not far away.\n\nNote: After the second round of combat she will join in the fight.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Skullcracker", 8, 4, 4, 12, 0),
                Monster::Base("Daisy", 9, 4, 4, 13, 0, 2)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 431}; }
    };

    class Story118 : public Story::Base
    {
    public:
        Story118()
        {
            BookID = Book::Type::BOOK1;

            ID = 118;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You try to elbow your way through the crowd, but by the time you have reached the carcass it has been almost stripped clean. You are forced to gnaw on empty bones, feeding on marrow and almost inedible ligaments. The lack of food begins to drain your spirits.\n\nEach party member must lose 1 Health point.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 865}; }
    };

    class Story119 : public Story::Base
    {
    public:
        Story119()
        {
            BookID = Book::Type::BOOK1;

            ID = 119;

            Text = "Pick a party member to read the book.";

            Choices.clear();
            Choices.push_back(Choice::Base("Make your choice", {Book::Type::BOOK1, 839}, Choice::Type::CHOOSE_PARTY_MEMBER));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story120 : public Story::Base
    {
    public:
        Story120()
        {
            BookID = Book::Type::BOOK1;

            ID = 120;

            Text = "After days of wandering you finally reach the banks of a wide and fast-running river. You plunge your faces into the freshwater, drinking your fill. Following the river downstream you come to a shabby city perched atop a massive cliff.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story121 : public Story::Base
    {
    public:
        Story121()
        {
            BookID = Book::Type::BOOK1;

            ID = 121;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "Concentrating tightly, you unfurl a magical spell of pure fire and roll it towards your flammable enemies. They have no defence against such terrible magic and are instantly consumed with a pitched wail. The smoke and glowing sheets force you back to the stairs for a time, but by the time their cries have subsided there is nothing left of the paper golems but ash.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::Type::CAST_ORB}))
            {
                Engine::LOSE_CODES(party, {Codes::Type::CAST_ORB});

                Engine::CAST_SPELL(party, Team::Type::NONE, Spells::Type::ORB_OF_ANNIHILATION);
            }

            if (Engine::VERIFY_CODES(party, {Codes::Type::CAST_MAELSTROM}))
            {
                Engine::LOSE_CODES(party, {Codes::Type::CAST_MAELSTROM});

                Engine::CAST_SPELL(party, Team::Type::NONE, Spells::Type::MAELSTROM);
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 168}; }
    };

    class Story122 : public Story::Base
    {
    public:
        Story122()
        {
            BookID = Book::Type::BOOK1;

            ID = 122;

            Text = "After strenuous negotiations the mercenaries finally agree to be discreetly absent during the battle tomorrow. Changing sides altogether would be a step too far for their precious reputations. This will have an enormous impact on the forthcoming battle.\n\nNote: You gained the code A96.";

            Bye = "Wishing them a speedy journey to their homelands you return triumphant.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(96)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 301}; }
    };

    class Story123 : public Story::Base
    {
    public:
        Story123()
        {
            BookID = Book::Type::BOOK1;

            ID = 123;

            Text = "Gurgling with effort, air bubbles blasting through the water from your mouth and nostrils, you finally wrench the block up high enough to get out. You roll under the block and through the shadow door, the stone block slamming down shut as you do so. You are soaking wet... but alive.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 717}; }
    };

    class Story124 : public Story::Base
    {
    public:
        Story124()
        {
            BookID = Book::Type::BOOK1;

            ID = 124;

            Text = "The command tent contains half a dozen agents; men and women from Lhasbreath and Chalice rub shoulders with freed slaves from Saltdad and Clifftop. You stand by the Everchild's side as she offers commissions.\n\n\"There are three tasks that must be done tonight,\" she says quietly. \"The assassination of Descantos, the hired wizard of Cursus. Convincing the mercenaries to abandon the patriarch's cause. And lastly, seeing to my personal security tonight. Each is important.\"\n\nShe turns to you. \"Which of these missions, my friends, will you undertake?\"\n\nYou must now decide how many missions your party will undertake, and who will go on each mission. Any missions you don't undertake will be performed by the Everchild's other agents -- although they have a slimmer chance of success. You can choose to undertake all three missions if you wish, or just one or two.";

            Choices.clear();
            Choices.push_back(Choice::Base("Decide who will undertake each mission", {Book::Type::BOOK1, 567}, Choice::Type::ASSIGN_TEAMS, {{Team::Type::ASSASSINATION_DESCANTOS, 0, 4}, {Team::Type::MERCENARY, 0, 4}, {Team::Type::EVERCHILD_SECURITY, 0, 4}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story125 : public Story::Base
    {
    public:
        Story125()
        {
            BookID = Book::Type::BOOK1;

            ID = 125;

            Location = Location::Type::DESERT;

            Text = "Sand surrounds you in all directions, though you can make out some hills to the north.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go north", {Book::Type::BOOK1, 275}));
            Choices.push_back(Choice::Base("Go west", {Book::Type::BOOK1, 590}));
            Choices.push_back(Choice::Base("Go south", {Book::Type::BOOK1, 515}));
            Choices.push_back(Choice::Base("Go east", {Book::Type::BOOK1, 535}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story126 : public Story::Base
    {
    public:
        Story126()
        {
            BookID = Book::Type::BOOK1;

            ID = 126;

            Location = Location::Type::CLIFFTOP;

            IsCity = true;

            Text = "Clifftop is currently under the governorship of Ayleta, one of the Everchild's generals. She welcomes you into the hall, and details to you her various plans for the improvement of the city. \"I want to create more permanent structures for the poor, and to reduce the amount of beatings the overseers issue to their farmworkers,\" she says. \"Progress is slow. The population is uneducated and tend to misbehave when they are not being brutalised. It may take many generations to change Clifftop for the better.\"\n\nIt seems a hard task, and not one suited to the abilities of adventurers.";

            Bye = "Wishing her well, you depart the hall.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story127 : public Story::Base
    {
    public:
        Story127()
        {
            BookID = Book::Type::BOOK1;

            ID = 127;

            Text = "The door opens into a small room which contains a bookcase and a broken reading chair. Searching the shelves is an unpleasant experience, as the books are damp and fall to pieces on contact with your fingers. You do manage to find a magic scroll which seems undamaged. It is a SCROLL OF RAGE. You can use it in combat to increase the Fighting score of each of your party members by 1 point until the end of the combat. After one use it will vanish.";

            Bye = "There is nothing else of value in the room, so you exit by the only door.";

            Choices.clear();
            Choices.push_back(Choice::Base("Take the SCROLL OF RAGE", {Book::Type::BOOK1, 494}, Choice::Type::GET_EQUIPMENT_CODE, {Equipment::SCROLL_OF_RAGE}, {Codes::A(59)}, {Codes::Type::FIRST_TIME_SCROLL_OF_RAGE}));
            Choices.push_back(Choice::Base("Leave it alone", {Book::Type::BOOK1, 494}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(59)}))
            {
                return {Book::Type::BOOK1, 42};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story128 : public Story::Base
    {
    public:
        Story128()
        {
            BookID = Book::Type::BOOK1;

            ID = 128;

            Text = "The Temple of Kalu is a squat tower of blue stone, built in a jumble-like pattern from the ruins of the old temple. The Everchild has decreed the temple should be rebuilt in defiance of the laws laid down by the patriarch of Cursus.\n\nWithin the temple tiny bells are softly chimed every minute, with parishioners and priests taking it in turns to strike the correct bell according to the time of day. The great calendar, a mosaic and guide to the planting dates of the year, is still incomplete, and requires more BLUESTONES to finish the work.\n\nIf you have any BLUESTONES you may exchange one for a blessing from the priests. If you are blessed, find the party member with the lowest Survival score in the team and increase their Survival by 1 point. You can assist with the repairs to the calendar.\n\nNote: You can only assist the priests with repairs to the calendar once.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::Type::NO_BLESSINGS_FOREVER}))
            {
                Choices.push_back(Choice::Base("Exchange a BLUESTONE for a blessing", {Book::Type::BOOK1, -128002}, {Equipment::BLUESTONE}));
            }

            if (!Engine::VERIFY_CODES(party, {Codes::Type::REPAIR_CALENDAR_KALU}))
            {
                Choices.push_back(Choice::Base("Repair the calendar (Team check: Lore 5+, Successes: 3)", {Book::Type::BOOK1, -128001}, {Book::Type::BOOK1, 75}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 5, 3));
            }

            Choices.push_back(Choice::Base("Your business here is complete", {Book::Type::BOOK1, 75}));
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            Engine::GET_CODES(party, {Codes::Type::REPAIR_CALENDAR_KALU});

            if (!outcome)
            {
                Bye = "The calendar is damaged, and the angry priests bans you from ever visiting the temple again.";
            }
        }
    };

    class E128_001 : public Story::Base
    {
    public:
        E128_001()
        {
            BookID = Book::Type::BOOK1;

            ID = -128001;

            DisplayID = 128;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::Type::NO_BLESSINGS_FOREVER}))
            {
                Text = "The calendar is repaired. You receive the blessing of the priests.";

                Choices.push_back(Choice::Base("Choose a member among your party with the lowest SURVIVAL score", {Book::Type::BOOK1, 75}, Choice::Type::RAISE_LOWEST_ATTRIBUTE, {Attribute::Type::SURVIVAL}, 1));
            }
            else
            {
                Text = "The calendar is repaired. Your business here is done.";
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class E128_002 : public Story::Base
    {
    public:
        E128_002()
        {
            BookID = Book::Type::BOOK1;

            ID = -128002;

            DisplayID = 128;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::BLUESTONE});

            return {Book::Type::BOOK1, -128001};
        }
    };

    class Story129 : public Story::Base
    {
    public:
        Story129()
        {
            BookID = Book::Type::BOOK1;

            ID = 129;

            Location = Location::Type::CLIFFTOP;

            Text = "You have found the great bronze cogwheel, lying almost buried in the wet sand. The wheel is quite heavy, and it will take many attempts to tie a strong knot around it, and in some dreadful currents.\n\nNote: Only the party member who made the last skill check can make the attempt.";

            Choices.clear();

            Choices.push_back(Choice::Base("Secure the cogwheel (Individual check: Survival 4+, Successes: 3)", {Book::Type::BOOK1, 745}, {Book::Type::BOOK1, 549}, Choice::Type::LAST_INDIVIDUAL_CHECK, {Attribute::Type::SURVIVAL}, 4, 3));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                Engine::GAIN_STATUS(party.Members[party.LastSelected], Character::Status::FOUND_COGWHEEL);
            }
        }
    };

    class Story130 : public Story::Base
    {
    public:
        Story130()
        {
            BookID = Book::Type::BOOK1;

            ID = 130;

            Location = Location::Type::LHASBREATH;

            Text = "The barbarians hail you as friends of Lhasbreath.\n\nAfter discussing the health of the queen you bid the barbarians farewell.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 219}; }
    };

    class Story131 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story131()
        {
            BookID = Book::Type::BOOK1;

            ID = 131;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Bye = "You carry on down the tunnel.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The RUNESWORD (FIGHTING +3) is a powerful weapon, however it also has the dreadful side effect of slowly leaching the wielder's life. If you carry this sword, the character bearing it loses 1 Health point each time you turn to a new reference number. You can share the sword around the party in order to spread out the damage, if you wish. You can discard the sword at any time to end the curse, but you cannot sell it, since its curse is immediately apparent to anyone who holds it.";

            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                if (Engine::SCORE(party.Members[party.LastSelected], Attribute::Type::HEALTH) > 0)
                {
                    PreText += "\n\n" + std::string(party.Members[party.LastSelected].Name) + " loses 1 Health point.";

                    Engine::GAIN_HEALTH(party.Members[party.LastSelected], -1);
                }
            }

            Take = {Equipment::RUNESWORD3};

            Limit = 1;

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 647}; }
    };

    class Story132 : public Story::Base
    {
    public:
        Story132()
        {
            BookID = Book::Type::BOOK1;

            ID = 132;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Text = "The only item of interest in the tomb is the SILVER SKULL, which seems to have stopped chanting.\n\nThe sarcophagus itself is empty.";

            Bye = "With nowhere else to go, you return to the crossroads.";

            Choices.clear();
            Choices.push_back(Choice::Base("Take the SILVER SKULL", {Book::Type::BOOK1, 46}, Choice::Type::GET_EQUIPMENT_CODE, {Equipment::SILVER_SKULL}, {Codes::A(47)}, {}));
            Choices.push_back(Choice::Base("Leave it alone", {Book::Type::BOOK1, 46}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story133 : public Story::Base
    {
    public:
        Story133()
        {
            BookID = Book::Type::BOOK1;

            ID = 133;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "In such a dangerous place battle appears inevitable. You confer with the Everchild, who agrees with your plan to strike first. She raises her hands and unleashes a terrible blast of power that jolts all the giant spiders clinging on the roof. They come tumbling down, but quickly regain their feet to rush to an attack.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Black Spider", 5, 5, 4, 6, 0),
                Monster::Base("Grey Spider", 4, 5, 4, 6, 0),
                Monster::Base("Green Spider", 5, 5, 4, 5, 0),
                Monster::Base("Red Spider", 4, 5, 4, 4, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 790}; }
    };

    class Story134 : public Story::Base
    {
    public:
        Story134()
        {
            BookID = Book::Type::BOOK1;

            ID = 134;

            Text = "You manage to find one fellow, a young and dynamic looking man, who claims he can arrange an appointment for you. However, it will cost 600 silver coins in administrative fees.";

            Choices.clear();
            Choices.push_back(Choice::Base("Pay the administrative fees (600 silver coins)", {Book::Type::BOOK1, 171}, Choice::Type::GAIN_MONEY, -600));
            Choices.push_back(Choice::Base("You have little choice but to leave the hall", {Book::Type::BOOK1, 775}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story135 : public Story::Base
    {
    public:
        Story135()
        {
            BookID = Book::Type::BOOK1;

            ID = 135;

            Location = Location::Type::SALT_MINES;

            Text = "Which level of the mines will you explore now?";

            Choices.clear();
            Choices.push_back(Choice::Base("Return to the surface", {Book::Type::BOOK1, 372}));
            Choices.push_back(Choice::Base("The twelfth level", {Book::Type::BOOK1, 739}));
            Choices.push_back(Choice::Base("The thirteenth level", {Book::Type::BOOK1, 388}));
            Choices.push_back(Choice::Base("The fourteenth level", {Book::Type::BOOK1, 597}));
            Choices.push_back(Choice::Base("The lowest level", {Book::Type::BOOK1, 222}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story136 : public Story::Base
    {
    public:
        Story136()
        {
            BookID = Book::Type::BOOK1;

            ID = 136;

            Text = "You complete the finishing touches, grinding the components to the necessary fineness, and sprinkling them with confidence into the brew. Soon you have completed two POTIONS OF INVULNERABILITY. Pleased with your new finds, you store them in your pack.\n\nNote: When a party member drinks this potion at the start of a combat round, they can ignore any amount of damage they take from the next attack that hits them. The potion wears off after absorbing the first hit, or if the combat ends.\n\nYou gained the code A73.";

            Choices.clear();
            Choices.push_back(Choice::Base("Pass through the door in the western wall", {Book::Type::BOOK1, 256}));
            Choices.push_back(Choice::Base("Return to the corridor through the east door", {Book::Type::BOOK1, 755}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::POTION_OF_INVULNERABILITY, Equipment::POTION_OF_INVULNERABILITY};

            Limit = 2;

            Engine::GET_CODES(party, {Codes::A(73)});
        }
    };

    class Story137 : public Story::Base
    {
    public:
        Story137()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::TUMBLESTONES;

            ID = 137;

            Image = "images/book1/statue_wreck.png";

            Text = "The sands whip against your face as you stagger through the desert. You seek shelter against the wreck of a once enormous statue, with only the sombre face of a long-forgotten king still visible in the lashing wind. Taking cover behind the hawkish nose of the stone face, you wait the storm out.\n\nWhen the wind dies down you examine the area. You realise where you are now. These are the Tumblestones, the remains of an ancient civilisation lost to the sands for all time. Historians from distant lands have attempted excavations here, but the heaped sands filled their trenches as fast as they could be dug, and the storms battered away their camps. Not much is left. A scattering of broken stones, perhaps once an enormous carved mural of some kind, lie revealed across the sands, the recent storms having unearthed them. Taking a casual look, you are surprised to see that they are fragments of a spell, carved in enormous letters.\n\nThe broken mural lies in pieces around you. It might be possible to fit the shattered mural together and decipher the spell if you are clever enough to puzzle it out.\n\nNote: You gained the code A17.";

            Choices.clear();
            Choices.push_back(Choice::Base("Rebuild the spell mural (Team check: Lore 4+, Successes: 4)", {Book::Type::BOOK1, 603}, {Book::Type::BOOK1, 368}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(17)}))
            {
                return {Book::Type::BOOK1, 14};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(17)});
        }
    };

    class Story138 : public Story::Base
    {
    public:
        Story138()
        {
            BookID = Book::Type::BOOK1;

            ID = 138;

            Text = "You make your way to the Expeditionary Guild but find the area empty. The blue tents of House Ross have been packed away and there is no sign of Sir Lawrence or Emlyn Pass-Ross. Shrugging, you return to the city centre.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story139 : public Story::Base
    {
    public:
        Story139()
        {
            BookID = Book::Type::BOOK1;

            ID = 139;

            Text = "After washing yourselves you sit upon the bank. Amelia has washed her long hair and is beginning to re-braid it, gazing into her own reflection in the oasis. On a whim Tasha offers to help her, and soon she is twisting her hair into tight braids in a style reminiscent of a Splintered Isle buccaneer. It is a moment of tender kindness, which have been rare since you came to the savage Valley of Bones. Amelia accepts Tasha's help, occasionally checking her progress by glancing into the water.\n\n\"You're going to make me look like a pirate!\" Amelia laughs. \"I quite like it.\"\n\n\"We can take it out if you have to meet any fine lords or ladies,\" Tasha says idly, continuing to braid.\n\n\"If it makes me look more like you, I don't care if some noble doesn't like it,\" shrugs Amelia. \"I'm a bastard girl. No one in Royce see's past my name. Not even my own father.\"\n\n\"Strange customs in your land,\" Tasha muses. \n\n\"Perhaps we'll sail to the Splintered Isles, next. That's true freedom. There's no kings or queens there.\"\n\n\"Or laws,\" laughs Amelia. \"Maybe they're better off for it.\"\n\nThis has been a kindly encounter.\n\nNote: Tasha has gained a heart for Amelia Pass-Dayne. Amelia Pass-Dayne also gains a heart for Tasha.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEARTS(party, Character::Type::TASHA, Character::Type::AMELIA_PASS_DAYNE, 1);
            Engine::GAIN_HEARTS(party, Character::Type::AMELIA_PASS_DAYNE, Character::Type::TASHA, 1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 51}; }
    };

    class Story140 : public Story::Base
    {
    public:
        Story140()
        {
            BookID = Book::Type::BOOK1;

            ID = 140;

            Text = "Although your trip into the shadow world was short, it was oddly disconcerting. You feel pleased to leave it behind. You head north, directly away from the Blackwall.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 858}; }
    };

    class Story141 : public Story::Base
    {
    public:
        Story141()
        {
            BookID = Book::Type::BOOK1;

            ID = 141;

            Text = "\"All right, then,\" nods the ogre. \"I hate them orcies anyway.\"\n\n\"It's madshards. That's what they're after,\" he says simply.\n\n\"What are madshards?\" you ask.\n\n\"You know... madshards,\" says the ogre, performing some kind of indistinct mime. \"Little bits of metal. From that broken talisman, thing? You know. It's what the whole orc uprising is about.\"\n\n\"And what is the orc uprising about?\" you press.\n\n\"Don't ask me,\" shrugs the ogre. \"I was hoping you could tell me.\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Try to convince the ogre to change sides", {Book::Type::BOOK1, 576}));
            Choices.push_back(Choice::Base("Kill the ogre", {Book::Type::BOOK1, 117}));
            Choices.push_back(Choice::Base("Leave the ogre in peace", {Book::Type::BOOK1, 310}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story142 : public Story::Base
    {
    public:
        Story142()
        {
            BookID = Book::Type::BOOK1;

            ID = 142;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "There is no central marketplace in Chalice, but rather the shops and stalls are spread out amongst the well-tended districts. Stern guards wearing fine longswords and ceremonial robes patrol the streets, watching you carefully as you go from shop to shop. The finest weapons in the valley are forged in this place, with techniques that rival those of Longport, although the very best swords are not available for foreigners.";

            Choices.clear();

            Controls = Story::Controls::SHOP;
        }

        void Event(Party::Base &party)
        {
            Shop = {
                {Equipment::CRUDE_BLADE, 25, 10, -1, {}},
                {Equipment::MAUL, -1, 25, -1, {}},
                {Equipment::IRON_SHORTSWORD1, 200, 100, -1, {}},
                {Equipment::IRON_GREATAXE2, -1, 150, -1, {}},
                {Equipment::STEEL_LONGSWORD2, 800, 400, -1, {}},
                {Equipment::STEEL_GREATSWORD3, -1, 450, -1, {}},
                {Equipment::MASTERWORK_BLADE3, -1, 900, -1, {}},
                {Equipment::MASTERWORK_GREATSWORD4, -1, 1250, -1, {}},
                {Equipment::SHIELD2, 50, 25, -1, {}},
                {Equipment::HIDE_ARMOUR1, -1, 30, -1, {}},
                {Equipment::BONE_ARMOUR2, -1, 150, -1, {}},
                {Equipment::BRONZE_ARMOUR4, -1, 2000, -1, {}},
                {Equipment::SOFT_BOOTS1, 500, 250, -1, {}},
                {Equipment::REFERENCE_BOOK1, 500, 250, -1, {}},
                {Equipment::WARM_CLOAK1, -1, 250, -1, {}},
                {Equipment::HANDSOME_BROOCH1, -1, 250, -1, {}},
                {Equipment::PRYBAR, 100, 50, -1, {}},
                {Equipment::INCENSE, -1, 90, -1, {}},
                {Equipment::GOLDWAX_CANDLE, -1, 100, -1, {}},
                {Equipment::ENGAGEMENT_RING, -1, 65, -1, {}},
                {Equipment::VIAL_OF_POISON, -1, 50, -1, {}},
                {Equipment::DRAGONYAK_HORN, -1, 35, -1, {}},
                {Equipment::LIZARD_HIDE, -1, 50, -1, {}}};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story143 : public Story::Base
    {
    public:
        Story143()
        {
            BookID = Book::Type::BOOK1;

            ID = 143;

            Text = "You spend a full month with Che Long training up the Bronzeguard. They are a formidable sight in their gleaming bronze armour and powerful steel weapons. Only the best recruits are permitted to stay in training, and soon you have a unit of the Everchild's fiercest supporters dressed in enchanted armour. The unit's morale is exceptional, and they are sure to make a powerful impression on the battlefield.\n\nYou may add the following unit to the Saltdad garrison:\n\n[Bronzeguard]: Strength 5, Morale 5\n\nYou cannot have more than one unit of [Bronzeguard] in existence at any given time as their equipment is irreplaceable. If the [Bronzeguard] are ever destroyed, you can train new recruits to use their equipment by spending another two GOLD BULLION bars. Feeling nigh indestructible, you return to the palace.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::MAGIC_VAULT});

            Army.clear();

            if (Engine::HAS_UNIT(party, Army::Type::BRONZEGUARD))
            {
                auto bronzeguard = Engine::FIND_UNIT(party.Army, Army::Type::BRONZEGUARD);

                if (bronzeguard >= 0 && bronzeguard < party.Army.size())
                {
                    party.Army[bronzeguard].Morale = 5;
                    party.Army[bronzeguard].Strength = 5;
                    party.Army[bronzeguard].Garrison = Location::Type::SALTDAD;
                }
            }
            else
            {
                Army = {Army::Base("Bronzeguard", Army::Type::BRONZEGUARD, Location::Type::SALTDAD, 5, 5, true)};
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 620}; }
    };

    class Story144 : public Story::Base
    {
    public:
        Story144()
        {
            BookID = Book::Type::BOOK1;

            ID = 144;

            Location = Location::Type::SOUTHCOAST_VALLEY_OF_BONES;

            Text = "You are mid-way along the south coast of the Valley of Bones. To the south is Viaan Island, occupied by the fierce Bando tribe.";

            Choices.clear();
            Choices.push_back(Choice::Base("Sail into the deep harbour of the Bando village", {Book::Type::BOOK1, 716}));
            Choices.push_back(Choice::Base("Sail west", {Book::Type::BOOK1, 814}));
            Choices.push_back(Choice::Base("Sail east", {Book::Type::BOOK1, 198}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story145 : public Story::Base
    {
    public:
        Story145()
        {
            BookID = Book::Type::BOOK1;

            ID = 145;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "You manage to recall the correct incantations to dispel darkness of this kind, and suddenly your lanterns illuminate the room. Within you can see strange coffers, some of which have loose piles of coin scattered over them. Opening the coffers you find a good deal more, some 200 silver coins in total, and a set of ornate BONE ARMOUR (Armour +2).";

            Bye = "Unsure if your reward was worth the dreadful battle to get it, you move on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::BONE_ARMOUR2};

            Limit = 1;

            Engine::GAIN_MONEY(party, 200);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 93}; }
    };

    class Story146 : public Story::Base
    {
    public:
        Story146()
        {
            BookID = Book::Type::BOOK1;

            ID = 146;

            Text = "Somewhere, deep within your subconscious, you realise that something is wrong. The book is constantly building to point, but never satisfying you. For pages and pages you have been utterly unenlightened, nor can you seem break away from reading it. Slowly, painfully, as if in a dream, you grasp the edge of a page and tear it out. The curse is instantly broken, and you continue to rip out pages until your consciousness clears. Your companions are relieved to see you have woken from your reverie. You have been standing immobile for a full ten minutes!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 695}; }
    };

    class Story147 : public Story::Base
    {
    public:
        Story147()
        {
            BookID = Book::Type::BOOK1;

            ID = 147;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "With perfect timing you slip into the room, jemmy open the overseer's table drawer and grab the key. You emerge just in time, ducking into a darkened corner as a pair of guards wander by. Once they have passed, you creep back to the gatehouse door, unlocking it and entering.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 611}; }
    };

    class Story148 : public Story::Base
    {
    public:
        Story148()
        {
            BookID = Book::Type::BOOK1;

            ID = 148;

            Text = "Sir Lawrence pours you a bottle of fine Almskirk wine, and bids you sit upon velvet cushioned chairs in his plush marquee. \"We are here to find spices,\" admits Sir Lawrence. \"House Ross has always been more interested in trade than the petty wars of Longport Bay. Let the Dayne's and the Bailey's fight like dogs -- we are interested in the larger world. We have expeditions elsewhere, but this one is all about exploring the jungles that lie to the west of Lhasbreath. If we can find enough interesting herbs or spices it might be profitable enough to set up a trade post or colony.\"\n\nSir Lawrence frowns. \"Unfortunately, we've hit a snag,\" he admits. \"The knights who were going to escort our scholars into the jungle have perished. They engaged in an honour duel with several barbarian locals... and came out of the battle poorly. Until I can find guards I can trust, I cannot send our scholars in. You seem cultured and capable folk. Perhaps you would be willing to act as expedition leaders? There would be an ample reward on offer!\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Accept Sir Lawrence's offer", {Book::Type::BOOK1, 5}));
            Choices.push_back(Choice::Base("You dot not feel ready to risk the jungle just yet", {Book::Type::BOOK1, 775}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story149 : public Story::Base
    {
    public:
        Story149()
        {
            BookID = Book::Type::BOOK1;

            ID = 149;

            Text = "The bull stands seven feet tall at the shoulder.\n\nThis will not be an easy battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            Limit = 0;

            Monsters = {Monster::Base("Dragonyak Bull", 6, 3, 4, 15, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 115}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Take = {Equipment::DRAGONYAK_HORN};

                Limit = 1;
            }
        }
    };

    class Story150 : public Story::Base
    {
    public:
        Story150()
        {
            BookID = Book::Type::BOOK1;

            ID = 150;

            Text = "You must fight!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 3, 4, 3, 7, 0),
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 4, 4, 3, 7, 0),
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 4, 4, 3, 5, 0),
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 3, 4, 3, 5, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 579}; }
    };

    class Story151 : public Story::Base
    {
    public:
        Story151()
        {
            BookID = Book::Type::BOOK1;

            ID = 151;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You open the door into a large chamber with a glowing floor. Strange circles and runes have been carved in the middle, but it is difficult to make out exactly what has been drawn as crawling over the mystic patterns are hundreds of beetles, their shiny black carapaces reflecting the light of your lanterns. Almost as one they stop and crawl round to look at you. The effect is rather eerie. Like a tiny phalanx they begin to advance upon you.";

            Choices.clear();
            Choices.push_back(Choice::Base("Cast a spell to disperse them", {Book::Type::BOOK1, 754}));
            Choices.push_back(Choice::Base("Attempt to crush the beetles underfoot", {Book::Type::BOOK1, 518}));
            Choices.push_back(Choice::Base("Slam the door shut to keep them out and return to the crossroads", {Book::Type::BOOK1, 566}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(61)}))
            {
                return {Book::Type::BOOK1, 685};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story152 : public Story::Base
    {
    public:
        Story152()
        {
            BookID = Book::Type::BOOK1;

            ID = 152;

            Location = Location::Type::CLIFFTOP;

            IsCity = true;

            Text = "The slaves of Clifftop are a lucky breed, compared to the citizens. Having paid money to acquire them, most masters are unwilling to whip their slaves to death, unlike the deathly ill peasants who toil in the fields.\n\nNote: If you have less than four party members in your team you may recruit some more from the slave market.\n\nIt costs 200 silver coins to buy another party member, and they start with no equipment. A party member without a weapon has their Fighting score reduced by 1 point in combat.";

            Choices.clear();

            Controls = Story::Controls::RECRUIT;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story153 : public Story::Base
    {
    public:
        Story153()
        {
            BookID = Book::Type::BOOK1;

            ID = 153;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "You show Mannus, the keeper of the holy purse, the IRON SCEPTRE -- a symbol that you speak with the Iron King's authority. He takes it and welcomes you, commanding a slave to pour you some wine and close the door. You begin to discuss the Saltdad tithe and convey the Iron King's wishes that it should be modified downwards as a point of principal. You also add that, coincidentally, the Iron King understands that Mannus is poorly compensated for his time in the tax office and that good conscience compels him to see that changed.";

            Choices.clear();
            Choices.push_back(Choice::Base("Bribe the official (Team check: Charisma 4+, Successes: 4)", {Book::Type::BOOK1, 476}, {Book::Type::BOOK1, 560}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::ZIGGURAT, {Attribute::Type::CHARISMA}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::IRON_SCEPTRE});
        }
    };

    class Story154 : public Story::Base
    {
    public:
        Story154()
        {
            BookID = Book::Type::BOOK1;

            ID = 154;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You bid your companions farewell, assuring them you will be alright and that you must face the coming trial alone. Reluctantly they agree to leave you, saying that they will stay in Chalice until your exploration of the caves is complete.\n\nYou wander the hills for many hours, passing many small and empty caves, pondering where exactly you should be going. After a while you sit upon a rock and enter a deep meditation.\n\nNote: Until you return to Chalice you cannot call on any of your other party members to make skill checks, fight battles or carry or transfer equipment. Akihiro is completely alone.\n\nNote: If Akihiro dies, eventually the rest of the party will realise he isn't coming back and continue their adventure. Any items of equipment he was carrying at the time of his death will also be lost.";

            Choices.clear();
            Choices.push_back(Choice::Base("Meditate on your destiny (Individual check: Lore 4+, Successes: 2)", {Book::Type::BOOK1, 683}, {Book::Type::BOOK1, 510}, {Attribute::Type::LORE}, 4, 2));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(77)}))
            {
                return {Book::Type::BOOK1, 6};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GO_SOLO(party, Character::Type::AKIHIRO_OF_CHALICE);
        }
    };

    class Story155 : public Story::Base
    {
    public:
        Story155()
        {
            BookID = Book::Type::BOOK1;

            ID = 155;

            Text = "Dulcimer cannot be swayed and throws you out of his house. Akini thanks you for your efforts but is resigned to a grisly death at the hands of her lover. You cannot stay to watch, and leave, shaking your head at the savagery of the Saltdad court.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story156 : public Story::Base
    {
    public:
        Story156()
        {
            BookID = Book::Type::BOOK1;

            ID = 156;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "The CRIER BIRD should fetch a tidy sum in a big city. Pleased with your find, you make your way out of the jungle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::CRIER_BIRD};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 618}; }
    };

    class Story157 : public Story::Base
    {
    public:
        Story157()
        {
            BookID = Book::Type::BOOK1;

            ID = 157;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The sound of drums and crowds roaring echo in your ears as you are once again lined up in the gatehouse in preparation for your latest bout. Up to four CRUDE BLADES (Fighting +0) can be equipped by your characters. Again, one character may be armed with a SHIELD (Armour +2), and another with a two-handed MAUL* (Fighting +1).\n\nEquip your characters as you wish.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::SHIELD2, Equipment::MAUL};

            Limit = 6;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 170}; }
    };

    class Story158 : public Story::Base
    {
    public:
        Story158()
        {
            BookID = Book::Type::BOOK1;

            ID = 158;

            Location = Location::Type::LHASBREATH;

            IsCity = true;

            Text = "The market of Lhasbreath is a noisy and vibrant place, based around a stone amphitheatre and bedecked with brightly coloured tents. Monkeys and birds chitter in the cool shadows, darting away as people approach, only to return to steal a loose berry or fruit.";

            Choices.clear();

            Controls = Story::Controls::SHOP;
        }

        void Event(Party::Base &party)
        {
            Shop = {
                {Equipment::CRUDE_BLADE, 25, 10, -1, {}},
                {Equipment::MAUL, 50, 25, -1, {}},
                {Equipment::IRON_SHORTSWORD1, 200, 100, -1, {}},
                {Equipment::IRON_GREATAXE2, 300, 150, -1, {}},
                {Equipment::STEEL_LONGSWORD2, -1, 400, -1, {}},
                {Equipment::STEEL_GREATSWORD3, -1, 450, -1, {}},
                {Equipment::SHIELD2, 50, 20, -1, {}},
                {Equipment::HIDE_ARMOUR1, 70, 35, -1, {}},
                {Equipment::BONE_ARMOUR2, 300, 150, -1, {}},
                {Equipment::BRONZE_ARMOUR4, -1, 2000, -1, {}},
                {Equipment::SOFT_BOOTS1, -1, 250, -1, {}},
                {Equipment::REFERENCE_BOOK1, -1, 250, -1, {}},
                {Equipment::WARM_CLOAK1, 500, 250, -1, {}},
                {Equipment::HANDSOME_BROOCH1, -1, 250, -1, {}},
                {Equipment::PRYBAR, 100, 50, -1, {}},
                {Equipment::INCENSE, -1, 90, -1, {}},
                {Equipment::BLUESTONE, -1, 45, -1, {}},
                {Equipment::GREY_TALISMAN, -1, 100, -1, {}},
                {Equipment::ENGAGEMENT_RING, -1, 65, -1, {}},
                {Equipment::VIAL_OF_POISON, -1, 50, -1, {}},
                {Equipment::DRAGONYAK_HORN, -1, 35, -1, {}},
                {Equipment::LIZARD_HIDE, -1, 25, -1, {}}};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story159 : public Story::Base
    {
    public:
        Story159()
        {
            BookID = Book::Type::BOOK1;

            ID = 159;

            Location = Location::Type::DESERT;

            Text = "As you cross a dune you come upon a strange sight. A monkey, just an arms-length tall, lies in the sand, breathing heavily, almost dehydrated. Such beasts are never seen outside the Lhasbreath jungles, and yet here is one apparently wandering the desert like a nomad. It is in a dreadful state.\n\nNote: You gained the code A42.";

            Choices.clear();
            Choices.push_back(Choice::Base("Give the monkey some water", {Book::Type::BOOK1, 552}));
            Choices.push_back(Choice::Base("Give it a wide berth", {Book::Type::BOOK1, 125}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(42)}))
            {
                return {Book::Type::BOOK1, 257};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(42)});
        }
    };

    class Story160 : public Story::Base
    {
    public:
        Story160()
        {
            BookID = Book::Type::BOOK1;

            ID = 160;

            Text = "You rip the book from the orc's hands. With a speed and bloodthirsty ferocity you would have thought was impossible from the placid creature, the orc rears up and stabs you in the neck with a knife he pulls from his sleeve.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 4 Health", {Book::Type::BOOK1, -160}, Choice::Type::GAIN_HEALTH, -4));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event160 : public Story::Base
    {
    public:
        Event160()
        {
            BookID = Book::Type::BOOK1;

            ID = -160;

            DisplayID = 160;

            Text = "The rest of your party manage to drag the orc away and stab him to death as he violently thrashes. The change over the orc seemed unbelievable. You didn't even realise orcs could read!\n\nNote: You gained the code A71.";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine the black book he was reading", {Book::Type::BOOK1, 119}));
            Choices.push_back(Choice::Base("Close the door and go somewhere else", {Book::Type::BOOK1, 821}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(71)});
        }
    };

    class Story161 : public Story::Base
    {
    public:
        Story161()
        {
            BookID = Book::Type::BOOK1;

            ID = 161;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You make good names for yourselves in the arena, but come to be feared and envied by the professional gladiators. They arrange with the arena master to have you sold on to less heroic duties.";

            Choices.clear();
            Choices.push_back(Choice::Base("See where you end up", {{3, "You are sold to the taskmasters of Clifftop", {Book::Type::BOOK1, 866}}, {6, "You are sold to the priests of Cursus", {Book::Type::BOOK1, 531}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story162 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story162()
        {
            BookID = Book::Type::BOOK1;

            ID = 162;

            Text = "It is the morning of battle. About you the soldiers of the Everchild ready their weapons and armour, looking down the gentle incline towards the city. You doubt the soldiers of Cursus will oblige you by fighting you on the slopes -- you will have to go down to meet them.\n\nYou may choose a maximum of six units from the Saltdad barracks to commit to this battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            EnemyArmy.clear();
            EnemySpells.clear();
            EnemyArmyStatus.clear();

            BattleLocation = Location::Type::SALTDAD;

            if (Engine::VERIFY_CODES(party, {Codes::A(40)}))
            {
                EnemyArmy.push_back(Army::Base("Cursite Infantry", Army::Type::CURSITE_INFANTRY, Location::Type::SALTDAD, Location::BattleField::LEFT_FLANK_FRONT, 4, 4, false));
            }
            else
            {
                EnemyArmy.push_back(Army::Base("Curzite Zealots", Army::Type::CURSITE_ZEALOTS, Location::Type::SALTDAD, Location::BattleField::LEFT_FLANK_FRONT, 4, 5, false));
                EnemyArmy.push_back(Army::Base("Cursite Infantry", Army::Type::CURSITE_INFANTRY, Location::Type::SALTDAD, Location::BattleField::LEFT_FLANK_SUPPORT, 4, 4, false));
            }

            if (!Engine::VERIFY_CODES(party, {Codes::A(95)}))
            {
                EnemySpells = {
                    {Spells::MassCombat::ENFEEBLEMENT_CENTER_FRONT, 0},
                    {Spells::MassCombat::CLINGING_DREAD_LEFT_FRONT, 1},
                    {Spells::MassCombat::ROUT_LEFT_FRONT, 2}};
            }

            if (Engine::VERIFY_CODES(party, {Codes::A(96)}))
            {
                EnemyArmy.push_back(Army::Base("Citizen Archers", Army::Type::CITIZEN_ARCHERS, Location::Type::SALTDAD, Location::BattleField::CENTER_FRONT, 2, 4, false));
                EnemyArmy.push_back(Army::Base("Cursite Riders", Army::Type::CURSITE_RIDERS, Location::Type::SALTDAD, Location::BattleField::RIGHT_FLANK_FRONT, 5, 4, false));
            }
            else
            {
                EnemyArmyStatus.push_back({Army::Status::STRENGTH1, EnemyArmy.size(), 0, 1});

                EnemyArmy.push_back(Army::Base("Mercenary Knights", Army::Type::MERCENARY_KNIGHTS, Location::Type::SALTDAD, Location::BattleField::CENTER_FRONT, 5, 3, false));
                EnemyArmy.push_back(Army::Base("Citizen Archers", Army::Type::CITIZEN_ARCHERS, Location::Type::SALTDAD, Location::BattleField::CENTER_SUPPORT, 2, 4, false));
                EnemyArmy.push_back(Army::Base("Cursite Riders", Army::Type::CURSITE_RIDERS, Location::Type::SALTDAD, Location::BattleField::RIGHT_FLANK_FRONT, 5, 4, false));
                EnemyArmy.push_back(Army::Base("Mercenary Spears", Army::Type::MERCENARY_SPEARS, Location::Type::SALTDAD, Location::BattleField::RIGHT_FLANK_SUPPORT, 3, 2, false));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                destination = {Book::Type::BOOK1, 316};
            }
            else
            {
                destination = {Book::Type::BOOK1, 220};
            }
        }
    };

    class Story163 : public Story::Base
    {
    public:
        Story163()
        {
            BookID = Book::Type::BOOK1;

            ID = 163;

            Text = "Swallowing your fear you crawl out of the tent and approach the strange light. You see it coalesce into a familiar figure. \"Mother...\" you say sadly.\n\n\"Aye, Amelia, it is I,\" responds your mother, her ghostly form wavering before you. \"I have travelled far from the Savage Lands to give you this warning. Beware Ashdain, lord of the third circle. He has fallen under the power of the dark one and is not your friend. Accept no quest or task he might give you.\"\n\n\"But... I have never heard of this man...\" you whisper. \"And who is this dark one you speak of...?\"\n\n\"I have said more than I should,\" responds the ghostly figure. \"Even your father, Baldwin, never treated me as wickedly as Ashdain. Find my bones... then you shall find the answers you seek.\"\n\n\"Where shall I find them?\" you ask desperately. \"Mother! Mother!\"\n\nBut it is too late. Your mother's image fades like moonlight and vanishes into the black sky. You are sobbing as you return to the tent, and your companions comfort you as best they can. If your mother is indeed dead, you will swear a vengeance upon her killer... if the ghost can be trusted.\n\nNote: You gained the code A49";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(49)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 840}; }
    };

    class Story164 : public Story::Base
    {
    public:
        Story164()
        {
            BookID = Book::Type::BOOK1;

            ID = 164;

            Text = "You are creeping through the shadowy compound, hardly daring to breathe as you tiptoe from one piece of cover to the next. Guards are everywhere!";

            Choices.clear();
            Choices.push_back(Choice::Base("Sneak into the kitchen", {Book::Type::BOOK1, 424}));
            Choices.push_back(Choice::Base("Prowl into the armoury", {Book::Type::BOOK1, 353}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story165 : public Story::Base
    {
    public:
        Story165()
        {
            BookID = Book::Type::BOOK1;

            ID = 165;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You are in a short corridor that twists to the west. A locked door is set in the nearby western wall. Around the bend the corridor terminates in another door with a large red 'x' painted across it. You try the nearby door but find it securely locked.";

            Choices.clear();
            Choices.push_back(Choice::Base("Unlock the nearby door using a RUSTY KEY", {Book::Type::BOOK1, 896}, {Equipment::RUSTY_KEY}));
            Choices.push_back(Choice::Base("Go through the door with red 'x' on it", {Book::Type::BOOK1, 793}));
            Choices.push_back(Choice::Base("Go back to the long corridor", {Book::Type::BOOK1, 634}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story166 : public Story::Base
    {
    public:
        Story166()
        {
            BookID = Book::Type::BOOK1;

            ID = 166;

            Text = "The sand shifts beneath your feet. Bursting from the desert come three giant desert scorpions, each as large as a war hound. The scuttle forwards, their stingers tensing and claws open to catch you.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(1)}) && !Engine::VERIFY_CODES(party, {Codes::A(22)}))
            {
                return {Book::Type::BOOK1, 636};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            Limit = 0;

            Monsters = {
                Monster::Base("Scorpion", 5, 4, 4, 5, 0),
                Monster::Base("Scorpion", 4, 4, 4, 4, 0),
                Monster::Base("Scorpion", 4, 4, 4, 3, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 804}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Take = {Equipment::VIAL_OF_POISON};

                Limit = 1;
            }
        }
    };

    class Story167 : public Story::Base
    {
    public:
        Story167()
        {
            BookID = Book::Type::BOOK1;

            ID = 167;

            Text = "You have returned to the funeral chamber of Imopposh the Mad. However, you have already defeated this vile shade and taken his treasures. There is nothing more to be done here.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 115}; }
    };

    class Story168 : public Story::Base
    {
    public:
        Story168()
        {
            BookID = Book::Type::BOOK1;

            ID = 168;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "With the golems defeated you must decide what to do next.\n\nNote: You gained the code A92.";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine the vault door", {Book::Type::BOOK1, 215}));
            Choices.push_back(Choice::Base("Check out the room to the south", {Book::Type::BOOK1, 484}));
            Choices.push_back(Choice::Base("Leave the palace", {Book::Type::BOOK1, 265}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(92)});
        }
    };

    class Story169 : public Story::Base
    {
    public:
        Story169()
        {
            BookID = Book::Type::BOOK1;

            ID = 169;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Your distraction team must divert the guard's attention from their posts at the gatehouses. What tactic do you think is best?";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::COUNT(party, Team::Type::DISTRACTION) > 1)
            {
                Choices.push_back(Choice::Base("Start a fight amongst yourselves", {Book::Type::BOOK1, 45}));
            }

            Choices.push_back(Choice::Base("Attempt to seduce the guards", {Book::Type::BOOK1, 7}));
            Choices.push_back(Choice::Base("Pretend to be a messenger, and say that their captain needs them urgently", {Book::Type::BOOK1, 875}));
        }
    };

    class Story170 : public Story::Base
    {
    public:
        Story170()
        {
            BookID = Book::Type::BOOK1;

            ID = 170;

            Image = "images/book1/ironking_and_malronac.png";

            Text = "You step out into broiling heat, the sun scorching the sands under your bare feet. You are the first competitors into the arena and receive a roaring cheer from the crowd as you appear. High above you the Iron King gazes down impassively, Malronac the Deathengine standing unflinching by his side. You look across the heat-swept arena as the far gate is opened. You cannot help but swallow as a pair of shaggy-haired desert lions come snarling out of the gate. Their manes are stained red with the blood of other victims, and they roar at you with filthy yellow teeth. You must fight for your lives.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::NO_COMBAT_SPELLS});

            Monsters = {
                Monster::Base("Lion", 4, 4, 4, 9, 0),
                Monster::Base("Lion", 3, 4, 4, 10, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 236}; }
    };

    class Story171 : public Story::Base
    {
    public:
        Story171()
        {
            BookID = Book::Type::BOOK1;

            ID = 171;

            Text = "The young man takes you to a small side room and asks you to wait while he organises introductions. You take a seat anxiously, hoping the young man is not some devious con artist who has just run off with your money.";

            Choices.clear();
            Choices.push_back(Choice::Base("Random Event", {{4, NULL, {Book::Type::BOOK1, 234}}, {6, NULL, {Book::Type::BOOK1, 308}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story172 : public Story::Base
    {
    public:
        Story172()
        {
            BookID = Book::Type::BOOK1;

            ID = 172;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "You find lodging at a large inn, The Iron Crown, which serves coffee and warm beer in a courtyard surrounded by rentable rooms. For every 5 silver coins you spend, each party member can recover 1 Health point. Spellcasters can also spend silver here to recharge their spells, purchasing components in the nearby marketplace and going into meditation in the privacy of their rooms.\n\nDuring your stay you ask about the nearby landmarks. \"The Blackwall is a place of ill reputation,\" confides a serving wench. \"No one knows why it was built, or what it is walling off, since it is easy to go around it. Still, those who become obsessed with it tend to disappear, never to be seen again!\" Frightening stuff!";

            RestPrice = 5;
            CanRecharge = true;

            Choices.clear();

            Controls = Story::Controls::INN;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story173 : public Story::Base
    {
    public:
        Story173()
        {
            BookID = Book::Type::BOOK1;

            ID = 173;

            Text = "You frown. This book is nothing but a pack of well-written lies. The truth in the world can only be found from within, not from the idle rantings of some long-dead scholar. You tear out a number of offending pages, the world coming back into focus again. Your companions are relieved to see you have woken from your reverie. You have been standing immobile for a full ten minutes!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 695}; }
    };

    class Story174 : public Story::Base
    {
    public:
        Story174()
        {
            BookID = Book::Type::BOOK1;

            ID = 174;

            Text = "The spiders above you merely watch as you carefully shuffle along the thin, crumbling ledge. Midway a part of the ledge flakes away, but you manage to keep your footing until you reach the far end. Soon, you have all crossed, the spiders wary of approaching such large, flame carrying prey. Another chamber beckons on the other side.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 347}; }
    };

    class Story175 : public Story::Base
    {
    public:
        Story175()
        {
            BookID = Book::Type::BOOK1;

            ID = 175;

            Text = "It will take skill and judgement to navigate the deadly shoals around Mordain. The city doesn't have a dire reputation for nothing!";

            Choices.clear();
            Choices.push_back(Choice::Base("Navigate the shoals (Team check: Survival 4+, Successes: 5)", {Book::Type::BOOK1, 662}, {Book::Type::BOOK1, 836}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 5));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (outcome)
            {
                Bye = "You manage to steer past the rocks and into the harbour.";
            }
            else
            {
                Bye = NULL;
            }
        }
    };

    class Story176 : public Story::Base
    {
    public:
        Story176()
        {
            BookID = Book::Type::BOOK1;

            ID = 176;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "\"We are emissaries sent by the Everchild,\" you say confidently. \"She wishes to discuss an important matter with the God King.\"\n\n\"The Everchild died a thousand summers ago,\" says the sister firmly. \"The God King does not deal with the emissaries of ghosts.\"\n\nThis will take some persuasion.";

            Choices.clear();
            Choices.push_back(Choice::Base("Convince the sister (Team check: Charisma 4+, Successes: 5)", {Book::Type::BOOK1, 709}, {Book::Type::BOOK1, 744}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 4, 5));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story177 : public Story::Base
    {
    public:
        Story177()
        {
            BookID = Book::Type::BOOK1;

            ID = 177;

            Location = Location::Type::EAST_ROAD;

            Text = "You are travelling on the Great Westroad, the western branch of a magnificent highway made in the elder times. The entire road is raised on a bank of earth some twenty feet high, and great sand dunes have piled up over the years on either side. It is busy with traffic, and with flatulent dragonyaks hauling many tons of goods in massive wagons between the great cities of the valley. To the north the Stonewalls act as a barrier between the consuming deserts of the south and the mysterious and powerful nation of Drakehallow.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go west to Saltdad", {Book::Type::BOOK1, 75}));
            Choices.push_back(Choice::Base("Go east to Luutanesh", {Book::Type::BOOK1, 614}));
            Choices.push_back(Choice::Base("Go north to the salt mines", {Book::Type::BOOK1, 25}));
            Choices.push_back(Choice::Base("Go south to the Withered Steppes", {Book::Type::BOOK1, 115}));
            Choices.push_back(Choice::Base("Talk to the caravan drivers", {Book::Type::BOOK1, 781}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story178 : public Story::Base
    {
    public:
        Story178()
        {
            BookID = Book::Type::BOOK1;

            ID = 178;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Text = "The final giant skeleton topples with a mighty crash. The treasures of the ancients are now yours to seize! There are 2250 silver coins to take. You also find a GOLDWAX CANDLE, a bar of GOLD BULLION and a CLOAK OF PROTECTION (Survival +3). In the coffin of the king, you prise a MAGICAL SHORTSWORD (Fighting +4) from his grasp.";

            Bye = "Pleased with your finds you stride out of the chamber with your treasures, the curious door slamming shut behind you as you leave.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::GOLD_BULLION, Equipment::GOLDWAX_CANDLE, Equipment::CLOAK_OF_PROTECTION3, Equipment::MAGICAL_SHORTSWORD4};

            Limit = 4;

            Engine::GAIN_MONEY(party, 2250);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 46}; }
    };

    class Story179 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story179()
        {
            BookID = Book::Type::BOOK1;

            ID = 179;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "It will be difficult indeed to track down the local thieves' guild without a contact.";

            if (!Engine::VERIFY_CODES(party, {Codes::A(5)}))
            {
                PreText += " Your enquiries are met with nothing but blank stares and snarls.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(5)}))
            {
                return {Book::Type::BOOK1, 216};
            }
            else
            {
                return {Book::Type::BOOK1, 75};
            }
        }
    };

    class Story180 : public Story::Base
    {
    public:
        Story180()
        {
            BookID = Book::Type::BOOK1;

            ID = 180;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You are in a long corridor, the remains of the barricade you dismantled spread thinly along its length. To the west, stone steps descend further into the complex. To the east is a simple wooden door.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go west, down the steps", {Book::Type::BOOK1, 747}));
            Choices.push_back(Choice::Base("Go east, through the door", {Book::Type::BOOK1, 821}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story181 : public Story::Base
    {
    public:
        Story181()
        {
            BookID = Book::Type::BOOK1;

            ID = 181;

            Text = "The normally straight-laced Amelia has enjoyed rather too much wine this evening. She is visibly tottering over to the wine barrel for more, to the raucous laughter of nearby soldiers.";

            Choices.clear();
            Choices.push_back(Choice::Base("Send a party member to escort her to bed", {Book::Type::BOOK1, 61}, Choice::Type::CHOOSE_PARTY_MEMBER));
            Choices.push_back(Choice::Base("Let the woman enjoy herself for once", {Book::Type::BOOK1, 594}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story182 : public Story::Base
    {
    public:
        Story182()
        {
            BookID = Book::Type::BOOK1;

            ID = 182;

            Location = Location::Type::LHASBREATH;

            IsCity = true;

            Text = "Lhasbreath is a bustling town, full of energy and life. Therefore, it is strange to encounter an older looking man looking glum upon his doorstep. \"My son, Garon the Bloody Mouthed is missing,\" he admits. \"He was adventuring near the cursed ruins of Mordain, but alas I have not seen him since. You are clearly travellers yourselves. If you should find my son, bring him home. You shall know him by his great beard which he paints red in honour of his grandfather.\"";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::BARBARIAN_BODY}))
            {
                return {Book::Type::BOOK1, 249};
            }
            else if (Engine::VERIFY_CODES_ANY(party, {Codes::A(67), Codes::A(86)}))
            {
                return {Book::Type::BOOK1, 331};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(66)}))
            {
                Bye = NULL;

                return {Book::Type::BOOK1, 286};
            }
            else
            {
                Bye = "You promise the old man that you will keep an eye out for him, and leave him to his misery.\n\nNote: You gained the code A67.";

                Engine::GET_CODES(party, {Codes::A(67)});

                return {Book::Type::BOOK1, 775};
            }
        }
    };

    class Story183 : public Story::Base
    {
    public:
        Story183()
        {
            BookID = Book::Type::BOOK1;

            ID = 183;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Image = "images/book1/vault_door.png";

            Text = "Dashing from one pillar to the next as each guard turns their back, you manage to creep as stealthily as mice until you are out of sight of the guards. Eventually you reach the back of the hallway and come to vault door itself. It is a colossal slab of black marble. It has no lock, nor handle, and needs none. Its weight alone is designed to ensure it stays closed. It would take half a dozen men to open this door in normal times. Can you manage it yourselves?";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            Choices.clear();

            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::PRYBAR}))
            {
                Choices.push_back(Choice::Base("Open the vault (Team check: Fighting 5+, Successes: 4)", {Book::Type::BOOK1, 498}, {Book::Type::BOOK1, -183}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::ZIGGURAT, {Attribute::Type::FIGHTING}, 5, 4, false));
            }
            else
            {
                Choices.push_back(Choice::Base("Open the vault (Team check: Fighting 6+, Successes: 4)", {Book::Type::BOOK1, 498}, {Book::Type::BOOK1, -183}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::ZIGGURAT, {Attribute::Type::FIGHTING}, 6, 4, false));
            }

            Choices.push_back(Choice::Base("Give up and return to the main floor", {Book::Type::BOOK1, 574}));
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (!outcome)
            {
                Bye = "Each party member loses 1 Health point from the strain.";

                Engine::GAIN_HEALTH(party, Team::Type::ZIGGURAT, -1);
            }
            else
            {
                Bye = NULL;
            }
        }
    };

    // Dummy event to trigger Bye message in BOOK1:0183
    class Event183 : public Story::Base
    {
    public:
        Event183()
        {
            BookID = Book::Type::BOOK1;

            ID = -183;

            DisplayID = 183;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party) { return {Book::Type::BOOK1, 183}; }
    };

    class Story184 : public Story::Base
    {
    public:
        Story184()
        {
            BookID = Book::Type::BOOK1;

            ID = 184;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You are almost sad as Yu Yan sprawls to the ground. The woman fought well, and it was a shame such talent should go to waste. You search her, her STONECUTTER SWORD (Fighting +2) is the most interesting possession she has. This weapon inflicts two points of Health damage for each success you score against rocky or stony opponents.\n\nShe also carries 135 silver pieces and, to your delight, a SILVER IDOL. You shake your head in amazement. You almost let the object of your quest slip through your fingers!";

            Bye = "Pleased to have completed your quest so promptly, you make your way out of the cave, and back to the temple in Chalice.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            Limit = 0;

            auto akihiro = Engine::FIND_CHARACTER(party, Character::Type::AKIHIRO_OF_CHALICE);

            if (Engine::IS_ACTIVE(party, akihiro))
            {
                Engine::GET_EQUIPMENT(party.Members[akihiro], {Equipment::STONECUTTER_SWORD2, Equipment::SILVER_IDOL});
            }
            else
            {
                Take = {Equipment::STONECUTTER_SWORD2, Equipment::SILVER_IDOL};

                Limit = 2;
            }

            Engine::GAIN_MONEY(party, 135);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 856}; }
    };

    class Story185 : public Story::Base
    {
    public:
        Story185()
        {
            BookID = Book::Type::BOOK1;

            ID = 185;

            Location = Location::Type::LUUTANESH;

            Text = "You get into a conversation with an old man named Janus about his adventurous wife, Alidale. Apparently Alidale was a great explorer of the Valley in the times before the rise of the Iron King. She had heard of the Temple of the Unbroken, the birthplace of the Cursus religion, and wanted to explore the ruins. Sadly, she never returned. It has been forty years since then, and Janus has never taken another wife. He asks for you to keep an eye out for a bronze locket if you should ever chance to venture into the temple yourself. It was a gift Janus bought his wife when they were courting, and he would like it back to member her by.\n\nYou assure him you will keep your eyes peeled before moving on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::BRONZE_LOCKET}))
            {
                return {Book::Type::BOOK1, 43};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(29)}))
            {
                return {Book::Type::BOOK1, 893};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 614}; }
    };

    class Story186 : public Story::Base
    {
    public:
        Story186()
        {
            BookID = Book::Type::BOOK1;

            ID = 186;

            Text = "A howling storm whips up from the cape to the west. The powerful gusts are blowing you closer and closer to the rocks!";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (!Engine::HAS_SPELL(party, {Spells::Type::NATURE_WARD}))
            {
                Choices.push_back(Choice::Base("Navigate the storm (Individual check: Survival 6+, Successes: Special)", {Book::Type::BOOK1, -186}, {Book::Type::BOOK1, -186}, {Attribute::Type::SURVIVAL}, 6, 0));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 892}; }
    };

    class Event186 : public Story::Base
    {
    public:
        std::string PreText = "";

        int damage = 0;

        Event186()
        {
            BookID = Book::Type::BOOK1;

            ID = -186;

            DisplayID = 186;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::SHIP_INTACT(party))
            {
                damage = 8 - party.RecentSuccesses;

                Engine::GAIN_HEALTH(party.Fleet[party.CurrentShip], -damage);

                if (party.Fleet[party.CurrentShip].Health > 0)
                {
                    return {Book::Type::NONE, -1};
                }
                else
                {
                    return {Book::Type::BOOK1, 484};
                }
            }
            else
            {
                return {Book::Type::BOOK1, 484};
            }
        }

        void Event(Party::Base &party)
        {
            PreText = "Your ship suffers " + std::to_string(damage) + " damage.\n\nYou manage to avoid the worst of the dreadful weather, despite some damage to the ship. Relieved at your good fortune you resolutely sail on.";

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 240}; }
    };

    class Story187 : public Story::Base
    {
    public:
        Story187()
        {
            BookID = Book::Type::BOOK1;

            ID = 187;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The rogues react with surprise and alarm as you stand up and make your way down the ladder that links the balcony to the ground floor. Evidently they have never received visitors before. You attempt to calm them, letting them know that you mean them no harm.";

            Choices.clear();
            Choices.push_back(Choice::Base("Calm the thieves (Team check: Charisma 4+, Successes: 3)", {Book::Type::BOOK1, 430}, {Book::Type::BOOK1, 266}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 4, 3));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story188 : public Story::Base
    {
    public:
        int attempts = 0;

        Story188()
        {
            BookID = Book::Type::BOOK1;

            ID = 188;

            Text = "You tie a few ropes together and bind them strongly to the most intact parts of the remaining wall, and then begin to abseil down the cliffside.";

            Choices.clear();

            Choices.push_back(Choice::Base("Climb down the cliff side (Team check: Survival 3+, Successes: 4)", {Book::Type::BOOK1, 662}, {Book::Type::BOOK1, -188}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 3, 4));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            temp_string = "";

            attempts++;

            if (!outcome)
            {
                if (attempts >= 4)
                {
                    attempts = 0;

                    Bye = "After several attempts, your entire party has made it down, one way or another!";

                    Choices[0].DestinationFailed = {Book::Type::BOOK1, 662};
                }
                else
                {
                    Choices[0].DestinationFailed = {Book::Type::BOOK1, -188};
                }
            }
            else
            {
                attempts = 0;
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 662}; }
    };

    class Event188 : public Story::Base
    {
    public:
        std::string PreText = "";

        Event188()
        {
            BookID = Book::Type::BOOK1;

            ID = -188;

            DisplayID = 188;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            temp_string = "";

            Bye = NULL;

            Choices.clear();

            if (Engine::COUNT(party) > 1)
            {
                PreText = "One of your party members falls about halfway down.";

                Choices.push_back(Choice::Base("Choose the party member who falls halfway down", {Book::Type::BOOK1, 188}, Choice::Type::GAIN_HEALTH, -3));
            }
            else
            {
                PreText = "You fall about halfway down.";

                auto character = Engine::FIRST(party);

                if (Engine::IS_ACTIVE(party, character))
                {
                    Engine::GAIN_HEALTH(party.Members[character], -3);
                }
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 188}; }
    };

    class Story189 : public Story::Base
    {
    public:
        Story189()
        {
            BookID = Book::Type::BOOK1;

            ID = 189;

            Text = "You meet with the Everchild in the war room at the palace. She and her generals are pouring over a huge map of the valley, with a particular focus on the city of Clifftop. \"Welcome back, my friends,\" she smiles. \"As you can see, we are planning our attack on Clifftop. Due to the relative fertility of the land, and reinforcements from Cursus, Clifftop possesses a large, if undisciplined army. I would feel confident going into battle against them with six units from the Saltdad garrison. Any less than that would be... risky. However, you've been stalwart commanders of my forces, and you got me this city. So tell me.\n\nAre we ready to launch an attack on Clifftop?\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Order the attack", {Book::Type::BOOK1, 610}));
            Choices.push_back(Choice::Base("Wait until you have more soldiers", {Book::Type::BOOK1, 620}));
            Choices.push_back(Choice::Base("Have a private word with the Everchild", {Book::Type::BOOK1, 488}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(100)}))
            {
                return {Book::Type::BOOK1, 421};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(33)}))
            {
                return {Book::Type::BOOK1, 540};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::MAGIC_VAULT});
        }
    };

    class Story190 : public Story::Base
    {
    public:
        Story190()
        {
            BookID = Book::Type::BOOK1;

            ID = 190;

            Text = "At first you are unsure if the rumours are true. Can there really be an Expeditionary Guild in a city as raucous and illiterate as Lhasbreath? You find the 'guild' in the tent city, a collection of gloriously decorated marquees embroidered with the heraldic crest of House Ross (a stag's head on a field of blue and gold). This noble house of Royce is based in the county of Longport Bay, which means they are a long way from home.\n\nYou are soon spotted by the leader of the guild, Sir Lawrence Ross, uncle to Baroness Carissa, the head of the house. He is overjoyed to see some cultured travellers in Lhasbreath and immediately invites you into his tent for a drink.";

            Choices.clear();
            Choices.push_back(Choice::Base("Accept his offer", {Book::Type::BOOK1, 148}));
            Choices.push_back(Choice::Base("Politely decline and return to the city centre", {Book::Type::BOOK1, 775}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(85)}))
            {
                return {Book::Type::BOOK1, 138};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story191 : public Story::Base
    {
    public:
        Story191()
        {
            BookID = Book::Type::BOOK1;

            ID = 191;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "In order to get the weapons, you will need to split up your party. Choose up to three party members to perform a distraction, and up to two party members to steal the weapons. You must have at least one party member performing each mission.";

            Choices.clear();
            Choices.push_back(Choice::Base("Decide who will undertake each task", {Book::Type::BOOK1, 169}, Choice::Type::ASSIGN_TEAMS, {{Team::Type::WEAPONS, 1, 2}, {Team::Type::DISTRACTION, 1, 3}}, 2));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story192 : public Story::Base
    {
    public:
        Story192()
        {
            BookID = Book::Type::BOOK1;

            ID = 192;

            Text = "You believe you have deciphered the clever code in the writing. You find a narrow knothole in the rock and plunge your arm inside. You pull out a magnificent silver chalice, which you can sell in town for 100 silver coins.";

            Bye = "Pleased with your find, you depart.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 100);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 395}; }
    };

    class Story193 : public Story::Base
    {
    public:
        Story193()
        {
            BookID = Book::Type::BOOK1;

            ID = 193;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You twist sharply and slip from Tommul's grasp. He crashes to the floor, his companion clumsily tripping over him. With a laugh you quickly dash away, back to the safety of your companions.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 157}; }
    };

    class Story194 : public Story::Base
    {
    public:
        Story194()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::LUUTANESH;

            ID = 194;

            Text = "You stroll away from Luutanesh, the sun climbing the sky as you make your way back to the great road.";

            Choices.clear();
            Choices.push_back(Choice::Base("West, towards Saltdad", {Book::Type::BOOK1, 177}));
            Choices.push_back(Choice::Base("North, to the salt mines", {Book::Type::BOOK1, 25}));
            Choices.push_back(Choice::Base("East, towards Chalice", {Book::Type::BOOK1, 442}));
            Choices.push_back(Choice::Base("South, to the Withered Steppes", {Book::Type::BOOK1, 115}));
            Choices.push_back(Choice::Base("Southeast, along the Northroad to Cursus", {Book::Type::BOOK1, 113}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story195 : public Story::Base
    {
    public:
        Story195()
        {
            BookID = Book::Type::BOOK1;

            ID = 195;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "You point out that the definition of a religious ceremony and a funeral observance are quite different things in Chalice law. Simply passing by a temple is not a ceremony in itself, and therefore no law is broken. The kensai pause a moment to consult a monk in a nearby temple, but soon realise that you are correct in the most literal sense. In deference to the dead man's life of selfless service to the state they allow the casket to pass.\n\nThe mourners give a most impious cheer before continuing their wake. The monk who advised the kensai congratulates you. \"Young men are good at war, but poor in wisdom,\" he says. \"With the exception of the young people I see before me. Thank you for avoiding bloodshed. Perhaps this gift will aid you in gaining even greater wisdom?\"\n\nThe monk presents you with a block of INCENSE.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::INCENSE};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story196 : public Story::Base
    {
    public:
        Story196()
        {
            BookID = Book::Type::BOOK1;

            ID = 196;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The tunnel ends in a door with a black triangle painted on it. Blood leaks from the gap under the door.";

            Choices.clear();
            Choices.push_back(Choice::Base("Open the door carefully", {Book::Type::BOOK1, 578}));
            Choices.push_back(Choice::Base("Return to the crossroads", {Book::Type::BOOK1, 310}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story197 : public Story::Base
    {
    public:
        Story197()
        {
            BookID = Book::Type::BOOK1;

            ID = 197;

            Text = "You stagger from the chasm, pulling the Everchild from the pit as you do so. You have all suffered wounds, and one of the Everchild's followers lies dead in the crevice. \"Saint Elias watch over his spirit,\" mutters the Everchild, as she glances back into the bloody pit. \"We must go on, or all was for naught.\"\n\nYou stagger, wounded, through the only exit.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 347}; }
    };

    class Story198 : public Story::Base
    {
    public:
        Story198()
        {
            BookID = Book::Type::BOOK1;

            ID = 198;

            Location = Location::Type::AZURE_DEEP;

            Text = "Your ship is crashing through the rolling waves of the Azure Deep, the near-boundless ocean that covers the valley's southern coast. To the north are high cliffs, from which blasts of gritty sand, blown from the strong coastal breezes, pour from the cliffsides. It has the appearance of sulphur-yellow rivers, dashing down into the oblivion of the sea.";

            Choices.clear();
            Choices.push_back(Choice::Base("Random Event", {{2, NULL, {Book::Type::BOOK1, 721}}, {6, NULL, {Book::Type::BOOK1, 851}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story199 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story199()
        {
            BookID = Book::Type::BOOK1;

            ID = 199;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(16)}))
            {
                PreText = "The barbarians treat you as friends. After exchanging pleasantries they ride on.";
            }
            else
            {
                PreText = "The barbarians have only looting on their minds, not fine words.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(16)}))
            {
                return {Book::Type::BOOK1, 840};
            }
            else
            {
                return {Book::Type::BOOK1, 238};
            }
        }
    };

    class Story200 : public Story::Base
    {
    public:
        Story200()
        {
            BookID = Book::Type::BOOK1;

            ID = 200;

            Text = "Battles at sea are very similar to personal combat. Your ship makes the first attack, unless the text tells you otherwise. Make a Fighting check using the Fighting score of your ship. The Defence of ships is always 4+ in ship combat. For every success you score you can reduce the Health of the enemy ship by 1 point. The enemy ship then attacks you in the same way.\n\nIf you have a spellcaster with any Sea Combat spells, they can cast one spell before each attack you make. Only spells marked 'Sea Combat' can be used when ships fight.\n\nThe combat ends when either your ship or the enemy are reduced to 0 or fewer Health points.\n\nGood luck, captain!";

            Choices.clear();

            Controls = Story::Controls::NONE;
        }
    };

    class Story201 : public Story::Base
    {
    public:
        Story201()
        {
            BookID = Book::Type::BOOK1;

            ID = 201;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "At first you fear you will have to stay in one of the religious hostelries that dot the city. A nightly whipping does not appeal, so fortunately you discover a single inn that caters to foreigners; The Sign of the Sand, built in the harbour district. Though it is built of stone, it reminds you of the kind of traditional inn you might find in Royce, with warm beer and comfortable rooms aplenty. It was built with the permission of the priests a hundred years ago, to encourage sea trade to the city. Its future is constantly in doubt, as hard-line priests detest its presence in the city, but so far economics has trumped religious politics.\n\nFor every 5 silver coins you spend, each party member can recover 1 Health point. Spell casters can also spend silver here to recharge their spells, purchasing components in the nearby marketplace and going into meditation in the privacy of their rooms.\n\nYou get into a discussion with some travellers from Drakehallow, who seem set on exploring the ruins of Mordain. \"There are vast tunnels and dungeons located beneath the surface,\" says one, a wizard from the magical school Animus Mast. \"No one has mapped them all, but a wise explorer will try. It's easy to get turned around in those deathly arcades.\"";

            RestPrice = 5;
            CanRecharge = true;

            Choices.clear();

            Controls = Story::Controls::INN;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 340}; }
    };

    class Story202 : public Story::Base
    {
    public:
        Story202()
        {
            BookID = Book::Type::BOOK1;

            ID = 202;

            Location = Location::Type::DESERT;

            Text = "You are deep in the central deserts of the valley, where it is sometimes years between rainfall and civilisation is all but unknown.";

            Choices.clear();
            Choices.push_back(Choice::Base("Manage your water (Team check: Survival 4+, Successes: 4)", {Book::Type::BOOK1, -202}, {Book::Type::BOOK1, -202}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (outcome)
            {
                Bye = "You manage to conserve water by travelling mostly at night and sheltering from the worst of the sun.";
            }
            else
            {
                Bye = "Each party member loses 1 Health from heatstroke.";

                Engine::GAIN_HEALTH(party, -1);
            }
        }
    };

    class Event202 : public Story::Base
    {
    public:
        Event202()
        {
            BookID = Book::Type::BOOK1;

            ID = -202;

            DisplayID = 202;

            Location = Location::Type::DESERT;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            auto result = Engine::ROLL(1);

            if (result < 3)
            {
                return {Book::Type::BOOK1, 159};
            }
            else
            {
                return {Book::Type::BOOK1, 125};
            }
        }
    };

    class Story203 : public Story::Base
    {
    public:
        Story203()
        {
            BookID = Book::Type::BOOK1;

            ID = 203;

            Text = "Hacking your way through the library you at last manage to break through the swarm of bashing, flapping books. When the last party member has escaped you slam the door shut, the thud of books impacting on the door shuddering through your body. Eventually the noise stops, and you presume the books have returned to their shelves. Hoping you will have no more book-related perils you make your way onwards.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 69}; }
    };

    class Story204 : public Story::Base
    {
    public:
        Story204()
        {
            BookID = Book::Type::BOOK1;

            ID = 204;

            Text = "\"This is a poor show, my lord, for a noble house to exert such effort against a common one,\" you say sadly. \"Has the house of Dulcimer dropped so low that it can only feud with peasants and serving girls? Are they your equals that you summon such a show of force and indignity? Such rustics should be ignored, not dignified with vengeance. Release the girl's aunt before you are made a laughingstock before the king!\" Panicked by your words, Dulcimer quickly agrees to release Akini's aunt, on your agreement that you will never mention this awkwardness in court. You agree and are soon escorting Akini's aunt back home.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 68}; }
    };

    class Story205 : public Story::Base
    {
    public:
        Story205()
        {
            BookID = Book::Type::BOOK1;

            ID = 205;

            Text = "Your decent is relatively straightforward, though you are compelled to light your lanterns to see anything more than the entry shaft. Tunnels lead off in four directions, carved out of the antique sandstone.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go northwest", {Book::Type::BOOK1, 761}));
            Choices.push_back(Choice::Base("Go northeast", {Book::Type::BOOK1, 801}));
            Choices.push_back(Choice::Base("Go southeast", {Book::Type::BOOK1, 869}));
            Choices.push_back(Choice::Base("Go southwest", {Book::Type::BOOK1, 217}));
            Choices.push_back(Choice::Base("Climb back up to the surface", {Book::Type::BOOK1, 426}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story206 : public Story::Base
    {
    public:
        Story206()
        {
            BookID = Book::Type::BOOK1;

            ID = 206;

            Location = Location::Type::BANDO_VILLAGE;

            Text = "You greet the Bando tribesmen like old friends, and soon there is singing and cheering across the village. As a good will offering you present the Bando with a few surplus tools and ropes from the ship, and you are presented in turn with sweet, intoxicating fruit drinks and a well-crafted SPEAR (Fighting +0).";

            Bye = "Soon you are escorted to see the shaman.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::SPEAR};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 381}; }
    };

    class Story207 : public Story::Base
    {
    public:
        Story207()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::CLIFFTOP;

            IsCity = true;

            ID = 207;

            Text = "The Church of Cursus in Clifftop is unique in the valley, in that it is made of jungle timbers rather than stone. The city is poor, and not even the faithful have the means to pay for the impressive black stone ziggurats more common to Cursus temples. Within the hall you can see flagellated parishioners begging for forgiveness from their distant god, whilst poor priests while away the endless hours with chants they must recite from memory for lack of expensive books to refer to.\n\nThe high priest is eager for donations. If you pay him 1,000 silver coins he will clumsily bless you. Find the party member with the lowest Stealth score in the team, and if their Stealth score is less than 3, increase their Stealth by 1 point. If all your party member's Stealth scores are already 3 or above, the blessing will have no effect.\n\nYou may also receive some Ritual Scarring (Cursus), which are runes sacred to Cursus carved across the chest of the subject. The priests are bound to perform this service to any who ask for it. If one of your party members wants some Ritual Scarring (Cursus), they must lose 1 point of Health permanently.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::Type::NO_BLESSINGS_FOREVER}))
            {
                Choices.push_back(Choice::Base("Select party member with lowest Stealth score", {Book::Type::BOOK1, -207}, Choice::Type::RAISEATTRIBUTE_WITH_BLESSING, {Attribute::Type::STEALTH}, 1000, 3, 1));
            }

            Choices.push_back(Choice::Base("Receive some Ritual Scarring (Cursus)", {Book::Type::BOOK1, -207}, Choice::Type::PAYFORSTATUS_WITH_HEALTH, {Character::Status::RITUAL_SCARRING_CURSUS}, -1));
            Choices.push_back(Choice::Base("You are finished here", {Book::Type::BOOK1, 19}));
        }
    };

    class Event207 : public Story::Base
    {
    public:
        Event207()
        {
            BookID = Book::Type::BOOK1;

            ID = -207;

            DisplayID = 207;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party) { return {Book::Type::BOOK1, 207}; }
    };

    class Story208 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story208()
        {
            BookID = Book::Type::BOOK1;

            ID = 208;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You are about halfway across the plank when it suddenly breaks in two. You plunge down into the pit and onto the spikes.";

            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                auto result = Engine::ROLL(1);

                Engine::GAIN_HEALTH(party.Members[party.LastSelected], -result);

                PreText += "\n\n" + std::string(party.Members[party.LastSelected].Name) + " loses " + std::to_string(result) + " Health point";

                if (result > 1)
                {
                    PreText += "s";
                }

                PreText += ".";
            }

            PreText += "\n\nYou watch as the timber plank which 'broke' above you suddenly snaps back into place. Only now, from this position, can you see that the plank is hinged on either side, and is designed to separate when someone puts their weight on it and then reset immediately afterwards. You curse the ingenuity of the trap maker as your companions quickly come to your rescue, bending down to offer you their hands. You scrabble out of the pit.";

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 761}; }
    };

    class Story209 : public Story::Base
    {
    public:
        Story209()
        {
            BookID = Book::Type::BOOK1;

            ID = 209;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You return to the excavated cavern dug out by the invading orcs. The short tunnels lead to nothing but dead ends. After giving the chamber one last look, you make your way back up the stairs.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 634}; }
    };

    class Story210 : public Story::Base
    {
    public:
        Story210()
        {
            BookID = Book::Type::BOOK1;

            ID = 210;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Image = "images/book1/attic_bunkbeds.png";

            Text = "You are standing in a comfortable attic room which contains dozens of bunkbeds. Monkeys sleep in the beds, blankets tucked tight around themselves. A few monkeys are still up, sitting in small chairs, reading books by candlelight. Tiny wardrobes contain robes, turbans and hats. What kind of madhouse is this? The monkeys resolutely ignore you as you make your way across the floor. It seems as if you are free to explore the house. Where will you go?";

            Choices.clear();
            Choices.push_back(Choice::Base("To Unbraaki's study", {Book::Type::BOOK1, 659}));
            Choices.push_back(Choice::Base("To the library", {Book::Type::BOOK1, 459}));
            Choices.push_back(Choice::Base("To the basement", {Book::Type::BOOK1, 67}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story211 : public Story::Base
    {
    public:
        Story211()
        {
            BookID = Book::Type::BOOK1;

            ID = 211;

            Text = "You are in the room with the open coffin. Shattered skeletons surround you.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go through the north door", {Book::Type::BOOK1, 717}));
            Choices.push_back(Choice::Base("Go through the south door", {Book::Type::BOOK1, 18}));
            Choices.push_back(Choice::Base("Go through the south-west door", {Book::Type::BOOK1, 127}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story212 : public Story::Base
    {
    public:
        Story212()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            ID = 212;

            Text = "Puffing yourselves up, you and your companions put on a brave show before the slaves, shoving them hard and roaring bold threats. This will require a good deal of bravery and force.";

            Choices.clear();
            Choices.push_back(Choice::Base("Threaten greedy slaves (Team check: Fighting 4+, Successes: 4)", {Book::Type::BOOK1, 526}, {Book::Type::BOOK1, 572}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::FIGHTING}, 4, 4, false));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story213 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story213()
        {
            BookID = Book::Type::BOOK1;

            ID = 213;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You draw your weapons and prepare for a mighty battle. You are pleased to see the slaves, who realise that this is their best chance of escape, turn on their masters with their picks and shovels.\n\nNote: The slaves will assist you in this battle. After all your party members have attacked, the slaves will inflict ";

            if (Engine::VERIFY_CODES(party, {Codes::Type::SLAVES_DAMAGE_FOR2}))
            {
                PreText += "2 points";
            }
            else
            {
                PreText += "1 point";
            }

            PreText += " of Health damage on each orc, except the orc leader -- they are too terrified to strike him!";

            Monsters = {
                Monster::Base("Orc", Monster::Type::ORC, 4, 4, 4, 9, 0),
                Monster::Base("Orc", Monster::Type::ORC, 5, 4, 4, 11, 0),
                Monster::Base("Orc", Monster::Type::ORC, 4, 4, 4, 10, 0),
                Monster::Base("Orc", Monster::Type::ORC, 3, 4, 4, 10, 0),
                Monster::Base("Orc", Monster::Type::ORC, 4, 4, 4, 6, 0),
                Monster::Base("Orc Leader", Monster::Type::ORC_LEADER, 7, 4, 4, 14, 0)};

            Allies = {Allies::Type::SLAVES};

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 707}; }
    };

    class Story214 : public Story::Base
    {
    public:
        Story214()
        {
            BookID = Book::Type::BOOK1;

            ID = 214;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "The Iron King's armies cannot hold off against you. They break and run, scattering into the desert. The Everchild commands the army forward into the city of Saltdad itself. A number of guards and priests of Cursus attempt to stand in your army's way, and the battle dissolves into furious street fight between your forces. Incredibly, despite your overwhelming victory on the field, it looks like the Iron King might be able to hold you off until the desert night freezes your troops away.\n\nThe deadlock has to be broken! Leaving the Everchild in charge of the army you break through the lines to storm the palace itself. Kicking open the door to the throne room you can see the Iron King in his full battle regalia, waiting with his elite guards.\n\n\"Foreign devils!\" he spits, still proudly wearing his jagged crown. \"This city is mine! I'll not hand over the reins of power to a child!\"\n\nHe grimly advances. The final battle for Saltdad has begun!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters.clear();

            Monsters.push_back(Monster::Base("The Iron King", 6, 4, 4, 15, 0));

            if (!Engine::VERIFY_CODES(party, {Codes::A(13)}))
            {
                Monsters.push_back(Monster::Base("Malronac the Deathengine", 6, 3, 4, 30, 0, 0, 2));
            }

            if (!Engine::VERIFY_CODES(party, {Codes::A(8)}))
            {
                Monsters.push_back(Monster::Base("Bronzeguard", 9, 4, 5, 12, 0));
            }

            Monsters.push_back(Monster::Base("Sgt. Kheller", 5, 4, 4, 7, 0));
            Monsters.push_back(Monster::Base("Sgt. Tacitus", 5, 4, 4, 6, 0));
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 309}; }
    };

    class Story215 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story215()
        {
            BookID = Book::Type::BOOK1;

            ID = 215;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You look over the vault door. As you surmised there appears to be no way to open it. Without a key or a handle, the vault seems inaccessible.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(43)}))
            {
                PreText += " Perhaps you can find an expert to help you with the vault door?\n\nNote: You gained the code A11.";

                Engine::GET_CODES(party, {Codes::A(11)});

                Choices.push_back(Choice::Base("Check out the room to the south", {Book::Type::BOOK1, 484}));
                Choices.push_back(Choice::Base("Leave the palace", {Book::Type::BOOK1, 265}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(93)}))
            {
                return {Book::Type::BOOK1, 348};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(12)}))
            {
                return {Book::Type::BOOK1, 258};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 293}; }
    };

    class Story216 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story216()
        {
            BookID = Book::Type::BOOK1;

            ID = 216;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You make your way under the city to see Brekken, the leader of the thieves' gang you encountered in the tunnels beneath the arena. He is pleased to see you again and celebrates the occasion by opening a bottle of wine.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(10)}))
            {
                PreText += "\n\n\"It was quite a feat, you sneaking out of the Saltdad Arena like that,\" muses Brekken over a glass of white wine. \"It's a shame to waste such talents merely on matters of survival. Perhaps you'd be willing to do a little wealth redistribution? Namely, from the silver stores of a rich man into the pockets of the poor -- in other words, us?\"\n\n\"What's the job?\" you ask neutrally.\n\n\"The city jeweller, Chellar, a former chancellor of the Iron King,\" says Brekken. \"He's as rich as a king himself. We go in, grab everything we can, and get out. Of course, his brother is a sorcerer, so they say the whole place is protected by magical defences. That's where you come in. You help us deal with the magic, and we'll help get through the more mundane protections, like locks and stubborn guards. We split the rewards fifty-fifty. Deal?\"";

                Engine::GET_CODES(party, {Codes::A(11)});

                Choices.push_back(Choice::Base("Agree to the heist", {Book::Type::BOOK1, 617}));
                Choices.push_back(Choice::Base("Politely decline", {Book::Type::BOOK1, 75}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 663}; }
    };

    class Story217 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story217()
        {
            BookID = Book::Type::BOOK1;

            ID = 217;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You continue down the tunnel for a while before it ends at a rather grand door with a strange, three-pronged lock set in its centre. The door is solidly constructed and will not budge an inch, nor is the lock something that can be easily picked.";

            Bye = NULL;

            if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::PYRAMIDAL_KEY}))
            {
                Bye = "There is nothing else for you to do here, so you return to the crossroads.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::PYRAMIDAL_KEY}))
            {
                return {Book::Type::BOOK1, 102};
            }
            else
            {
                return {Book::Type::BOOK1, 46};
            }
        }
    };

    class Story218 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story218()
        {
            BookID = Book::Type::BOOK1;

            ID = 218;

            Bye = "Sadly, there is now no chance of recovering the idol. Accepting your failure lightly, you decide to return to the Chalice temple and face your fate.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You sit upon the ledge side, on a small outcropping of rock, crossing your legs and calming your breathing. In the distance Yu Yan looks at you with amazement, before slipping away into the dusk.\n\nYou gaze out into the beautiful landscape, considering the perfect arrangement of the world before you. Sky, water, rock and sand lay in harmony with each other. All is still, with the setting sun casting the sky into scarlet. Soon the stars emerge, one by one, until a celestial sea revolves around your head, adding the heavens into a mix of perfect symmetry. As you gaze upon the sight, abandoning your quest for the idol, the weight of failure seems to lift from you. Your thoughts enter balance, and suddenly your ambitions seem as weightless as the air.";

            if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::PYRAMIDAL_KEY}))
            {
                auto result = Engine::FIND_CHARACTER(party, Character::Type::AKIHIRO_OF_CHALICE);

                if (Engine::IS_ACTIVE(party, result))
                {
                    PreText += "\n\nAkihiro has achieved Enlightenment. Akihiro also gains 1 point of Lore.";

                    Engine::GAIN_STATUS(party.Members[result], Character::Status::ENLIGHTENED);
                }
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 856}; }
    };

    class Story219 : public Story::Base
    {
    public:
        Story219()
        {
            BookID = Book::Type::BOOK1;

            ID = 219;

            Location = Location::Type::WEST_ROAD;

            Text = "Where do you wish to go from here?";

            Choices.clear();
            Choices.push_back(Choice::Base("Continue west along the road", {Book::Type::BOOK1, 12}));
            Choices.push_back(Choice::Base("South, towards the Blackwall", {Book::Type::BOOK1, 691}));
            Choices.push_back(Choice::Base("North-west into The Salt Plains", {Book::Type::BOOK1, 460}));
            Choices.push_back(Choice::Base("East, to Saltdad", {Book::Type::BOOK1, 75}));
            Choices.push_back(Choice::Base("South-west, to the Tumblestones", {Book::Type::BOOK1, 137}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story220 : public Story::Base
    {
    public:
        Story220()
        {
            BookID = Book::Type::BOOK1;

            ID = 220;

            Text = "The odds are impossible! Your forces are overwhelmed. You watch in despair as the Everchild's encampment is overridden by a hundred horsemen. You share her fate, the merciless army of Cursus chasing you down and cutting your throats. The dream of freedom in the valley, and your adventure, is over.";

            Type = Story::Type::DOOM;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story221 : public Story::Base
    {
    public:
        Story221()
        {
            BookID = Book::Type::BOOK1;

            ID = 221;

            Text = "The whole family have gathered outside onto the terrace as you approach, their neighbours craning their necks to see you. Janu, your brother-in-law, bows deeply as you approach. \"You honour us with your visit, kensai,\" he says honestly. \"My house is yours. It would please me if you and your companions would stay with us during your visit to the city.\"\n\n\"Thank you, Janu,\" you say. \"Your offer is most kind.\" That night the children sit at your feet as you recount tales of your adventures. Your mother and sister glow with pride to see you in your fine robes, your confidence returned.\n\nYou may stay in the house as long as you like. All party members can restore their Health scores to maximum. Spell casters can also spend silver here to recharge their spells, purchasing components in the nearby marketplace and going into meditation in the privacy of their rooms.";

            RestPrice = 0;
            CanRecharge = true;

            Choices.clear();

            Controls = Story::Controls::INN;
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::IN_PARTY(party, Character::Type::SAR_JESSICA_DAYNE) && Engine::HEARTS(party, Character::Type::SAR_JESSICA_DAYNE, Character::Type::AKIHIRO_OF_CHALICE) > 0)
            {
                return {Book::Type::BOOK1, 607};
            }
            else if (Engine::IN_PARTY(party, Character::Type::BRASH) && Engine::HEARTS(party, Character::Type::BRASH, Character::Type::AKIHIRO_OF_CHALICE) > 0)
            {
                return {Book::Type::BOOK1, 62};
            }
            else
            {
                return {Book::Type::BOOK1, 450};
            }
        }
    };

    class Story222 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story222()
        {
            BookID = Book::Type::BOOK1;

            ID = 222;

            Location = Location::Type::SALT_MINES;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The lift slams onto the surface of the fifteenth level. This is the deepest portion of the mine, long since abandoned by the workers.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(27)}))
            {
                PreText += "\n\nYou creep carefully down the tunnels until they open into a sizable cavern. Curled up into a tight ball, you see the fish-white scales of a terrible salt dragon, sleeping on a pile of human bones and scattered treasure. Its eyes flick open, and it puffs sharply, trying to scare you off.";

                Engine::GET_CODES(party, {Codes::A(11)});

                Choices.push_back(Choice::Base("Fight the dragon", {Book::Type::BOOK1, 787}));
                Choices.push_back(Choice::Base("Carefully back away to the lift", {Book::Type::BOOK1, 135}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 344}; }
    };

    class Story223 : public Story::Base
    {
    public:
        Story223()
        {
            BookID = Book::Type::BOOK1;

            ID = 223;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Soon it is time for another bloody battle in the arena. Each character is given a CRUDE BLADE (Fighting +0) and pushed out to face the current arena champions.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            for (auto i = 0; i < Engine::COUNT(party); i++)
            {
                Take.push_back(Equipment::CRUDE_BLADE);
            }

            Limit = Take.size();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, -223}; }
    };

    class Event223 : public Story::Base
    {
    public:
        Event223()
        {
            BookID = Book::Type::BOOK1;

            ID = -223;

            DisplayID = 223;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The crowd roar -- they recognise you from your previous battles and know that this should prove an entertaining fight.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Grim Gladiator", 8, 4, 4, 12, 0),
                Monster::Base("Mighty Gladiator", 5, 3, 4, 10, 0),
                Monster::Base("Agile Gladiator", 6, 3, 5, 6, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 161}; }
    };

    class Story224 : public Story::Base
    {
    public:
        Story224()
        {
            BookID = Book::Type::BOOK1;

            ID = 224;

            Text = "Perhaps it would be wiser if only a few people entered the room? Decide who is passing through the shadow door and who is staying behind. You can send your whole party in if you wish, or change your mind and close off the shadow door.";

            Choices.clear();
            Choices.push_back(Choice::Base("Select the party members who will pass through the shadow door", {Book::Type::BOOK1, -224}, Choice::Type::ASSIGN_TEAMS, {{Team::Type::SHADOW_ROOM, 0, 4}}, 0));
            Choices.push_back(Choice::Base("Close the shadow door", {Book::Type::BOOK1, 717}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event224 : public Story::Base
    {
    public:
        Event224()
        {
            BookID = Book::Type::BOOK1;

            ID = -224;

            DisplayID = 224;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::COUNT(party, Team::Type::SHADOW_ROOM) > 0)
            {
                return {Book::Type::BOOK1, 903};
            }
            else
            {
                return {Book::Type::BOOK1, 717};
            }
        }
    };

    class Story225 : public Story::Base
    {
    public:
        Story225()
        {
            BookID = Book::Type::BOOK1;

            ID = 225;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "You have a most pleasant stroll through the centre of Chalice. The streets are peaceful and the people orderly. You have a cup of rice wine by the river to relax and watch as a graceful dune-swan and its chicks paddle down waterway.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story226 : public Story::Base
    {
    public:
        Story226()
        {
            BookID = Book::Type::BOOK1;

            ID = 226;

            Text = "Security is much too tight around the archwizard. All the party members assigned to the assassination have been captured. What happens to them now is down to you. If you capture the city of Cursus you can free them from prison. If your army is defeated, the party members will be executed. Either way, the captured party members can take no further part in the battle until rescued.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            for (auto i = 0; i < party.Members.size(); i++)
            {
                if (Engine::SCORE(party.Members[i], Attribute::Type::HEALTH) > 0 && party.Members[i].Team == Team::Type::ASSASSINATION_DESCANTOS)
                {
                    Engine::GAIN_STATUS(party.Members[i], Character::Status::CAPTURED);
                }
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 96}; }
    };

    class Story227 : public Story::Base
    {
    public:
        Story227()
        {
            BookID = Book::Type::BOOK1;

            ID = 227;

            Text = "The salt mine is only moderately populated. Many of the ex-slaves have deserted mine work for more pleasant pursuits above ground. Those who remain are better dressed and equipped than they were before but look just as unhealthy.\n\nWhich level of the mines will you explore?";

            Choices.clear();
            Choices.push_back(Choice::Base("The twelfth level", {Book::Type::BOOK1, 739}));
            Choices.push_back(Choice::Base("The thirteenth level", {Book::Type::BOOK1, 388}));
            Choices.push_back(Choice::Base("The fourteenth level", {Book::Type::BOOK1, 597}));
            Choices.push_back(Choice::Base("The lowest level", {Book::Type::BOOK1, 222}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story228 : public Story::Base
    {
    public:
        Story228()
        {
            BookID = Book::Type::BOOK1;

            ID = 228;

            Text = "You believe you have deciphered the clever code in the writing. You find a narrow knothole in the rock and plunge your arm inside. You cry out in shock as a savage blade slices into your hand. Pulling it out you are astonished you did not lose the whole thing.";

            Choices.clear();

            Choices.push_back(Choice::Base("Choose a party member to lose 5 Health points and 1 point of Fighting.", {Book::Type::BOOK1, 395}, Choice::Type::GAIN_HEALTH_ATTRIBUTE, {Attribute::Type::FIGHTING}, -5, -1, 0));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story229 : public Story::Base
    {
    public:
        Story229()
        {
            BookID = Book::Type::BOOK1;

            ID = 229;

            Text = "You furrow your brow as you attempt to mar the runes on the window frame.";

            Choices.clear();
            Choices.push_back(Choice::Base("Dispel the runes (Team check: Lore 4+, Successes: 5)", {Book::Type::BOOK1, 791}, {Book::Type::BOOK1, 831}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 4, 5));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story230 : public Story::Base
    {
    public:
        Story230()
        {
            BookID = Book::Type::BOOK1;

            ID = 230;

            Text = "The bookcase contains a number of valuable tomes, including a REFERENCE BOOK (LORE +1). There is also an interesting tome on herb lore. You flick through it briefly, and come upon a reference to the Lhasbreath Jungles, here in the Valley of Bones. \"...it is a well-known fact that the yellow Hygliph Flower is proof against all snakes, even the wicked snakemen in the Temple of the Unbroken, who react poorly to its pungent perfume.\" Interesting.\n\nYou may take the REFERENCE BOOK. You grab a few of the more PRECIOUS TOMES AS well.";

            Choices.clear();
            Choices.push_back(Choice::Base("Snatch the golden candlestick, if you haven't already", {Book::Type::BOOK1, 644}));
            Choices.push_back(Choice::Base("Head upstairs to help the climbing team", {Book::Type::BOOK1, 92}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::MAGICAL_DOOR;

            Take = {Equipment::REFERENCE_BOOK1, Equipment::PRECIOUS_TOMES};

            Limit = 2;
        }
    };

    class Story231 : public Story::Base
    {
    public:
        Story231()
        {
            BookID = Book::Type::BOOK1;

            ID = 231;

            Text = "Choose a party member to sneak into the chamber.";

            Choices.clear();
            Choices.push_back(Choice::Base("Sneak into the chamber (Individual check: Stealth 5+, Successes: 2)", {Book::Type::BOOK1, 428}, {Book::Type::BOOK1, 799}, {Attribute::Type::STEALTH}, 5, 2));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story232 : public Story::Base
    {
    public:
        Story232()
        {
            BookID = Book::Type::BOOK1;

            ID = 232;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "To your mixed delight and horror, the [SKELETONS] rise from the dead, their bones clicking and clacking as they stand up straight before you. The [SKELETONS] will be useful allies.\n\nNote: There are [SKELETONS] for each party member to control. While a party member has a [SKELETON] following them, they gain an additional 2 points to their Fighting skill, which combines with any other bonuses from weapons or other items. Additionally, your [SKELETONS] will bravely take damage for you. Each skeleton has 6 Health points. When a party member takes damage in combat (not from any other source) the skeleton will step in the way and take the damage for that character. They have no armour, and are destroyed when they are reduced to 0 Health. Skeletons cannot regain Health points. Your [SKELETONS] can only exist whilst you are in the Mordain ruins. As soon as you step outside they will crumble to dust.\n\nYou gained the code A75.";

            Bye = "Pleased with your new companions, you make your way back to the crossroads.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            for (auto i = 0; i < party.Members.size(); i++)
            {
                if (Engine::SCORE(party.Members[i], Attribute::Type::HEALTH) > 0)
                {
                    Engine::GAIN_FOLLOWERS(party.Members[i], {Follower::Base("Skeleton", Follower::Type::MORDAIN_SKELETONS, 6)});
                }
            }

            Engine::GET_CODES(party, {Codes::A(75)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 310}; }
    };

    class Story233 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story233()
        {
            BookID = Book::Type::BOOK1;

            ID = 233;

            Location = Location::Type::SALT_MINES;

            Choices.clear();
            Choices.push_back(Choice::Base("Return to the mine to hunt more troglodytes", {Book::Type::BOOK1, 681}));
            Choices.push_back(Choice::Base("Make your excuses and leave the mine", {Book::Type::BOOK1, 722}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            auto count = Engine::COUNT_EQUIPMENT(party, {Equipment::Type::TROGLODYTE_HEAD});

            Engine::GAIN_MONEY(party, count * 25);

            PreText = "You received " + std::to_string(count * 25) + " silver coins for the TROGLODYTE HEADs.\n\n\"Keep up the good work,\" he enthuses. \"I'm sure the slaves appreciate your valiant efforts.\"";

            Text = PreText.c_str();
        }
    };

    class Story234 : public Story::Base
    {
    public:
        Story234()
        {
            BookID = Book::Type::BOOK1;

            ID = 234;

            Text = "The man is a devious con artist who has just run off with your money. Eventually a surprised looking servant enters the room and sadly tells you that the king has retired to his chambers, and that all foreigners must now leave the hall until morning. Upon interrogation the servant reveals that the man you gave money to had never been seen in the hall until today. Cursing your naivety, you storm out of the hall.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story235 : public Story::Base
    {
    public:
        Story235()
        {
            BookID = Book::Type::BOOK1;

            ID = 235;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "You invoke your spell, concentrating on hard on your destination. You can feel the portal links that connect to this location. Where will you travel?";

            Choices.clear();
            Choices.push_back(Choice::Base("The Palace of Unbraaki", {Book::Type::BOOK1, 484}));
            Choices.push_back(Choice::Base("(Crown and Tower) The city of Longport", {Book::Type::BOOK2, 321}));
            Choices.push_back(Choice::Base("(Pirates of the Splintered) Thalsia", {Book::Type::BOOK3, 108}));
            Choices.push_back(Choice::Base("(The Gilded Throne) Ozury", {Book::Type::BOOK4, 500}));
            Choices.push_back(Choice::Base("(The Savage Lands) The Hallowed Grove", {Book::Type::BOOK5, 45}));
            Choices.push_back(Choice::Base("(Drakehallow) Dagon", {Book::Type::BOOK6, 230}));
            Choices.push_back(Choice::Base("(Drakehallow) Animus Mast", {Book::Type::BOOK6, 600}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::CAST_SPELL(party, Team::Type::NONE, Spells::Type::TELEPORT_CIRCLE);
        }
    };

    class Story236 : public Story::Base
    {
    public:
        Story236()
        {
            BookID = Book::Type::BOOK1;

            ID = 236;

            Text = "The cheers from the crowd resound across the arena as the final lion falls dead. You cannot help but stifle a tear at the death of the noble beasts, cruelly plucked from the wild to fight for the entertainment of the savage crowd.\n\nFeeling more bestial than even a lion, you are taken from the arena and disarmed again, eager for another bowl of water to slake your aching thirst. You come upon a sight of even greater cruelty. Poor Milagros is being shouted at and struck by an angry guard, enraged at receiving a splash of soup across his armour. The poor girl is on the ground, in his shadow, nursing a bruise on her cheek as the guard pulls out his whip to punish her further.";

            Choices.clear();
            Choices.push_back(Choice::Base("Dash to her defence", {Book::Type::BOOK1, 812}));
            Choices.push_back(Choice::Base("Keep well out of it", {Book::Type::BOOK1, 319}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_ALL(party, Equipment::Class::ARMOUR);

            Engine::LOSE_ALL(party, Equipment::Class::WEAPON);
        }
    };

    class Story237 : public Story::Base
    {
    public:
        Story237()
        {
            BookID = Book::Type::BOOK1;

            ID = 237;

            Image = "images/book1/spiders_attack.png";

            Text = "A terrible battle begins!\n\nNote: At the end of each combat round, after the spiders have made their attacks, each party member loses 1 Health from being bitten by the swarms of tiny spiders at their feet.";

            Bye = "You manage to survive.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {
                Monster::Base("Black Spider", Monster::Type::SPIDER_WITH_SWARM, 5, 5, 4, 7, 0),
                Monster::Base("Grey Spider", Monster::Type::SPIDER_WITH_SWARM, 4, 5, 4, 7, 0),
                Monster::Base("Green Spider", Monster::Type::SPIDER_WITH_SWARM, 5, 5, 4, 6, 0),
                Monster::Base("Red Spider", Monster::Type::SPIDER_WITH_SWARM, 4, 4, 4, 5, 0),
            };
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 197}; }
    };

    class Story238 : public Story::Base
    {
    public:
        Story238()
        {
            BookID = Book::Type::BOOK1;

            ID = 238;

            Text = "You must fend them off!";

            Bye = "You loot 20 silver coins from their bodies before moving on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {
                Monster::Base("Lhasbreath Barbarians", 9, 5, 3, 16, 0),
                Monster::Base("Barbarian Leader", 4, 4, 4, 7, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 840}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Engine::GAIN_MONEY(party, 20);
            }
        }
    };

    class Story239 : public Story::Base
    {
    public:
        Team::Type previousTeam = Team::Type::NONE;

        Story239()
        {
            BookID = Book::Type::BOOK1;

            ID = 239;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You'll not back down in front of a knave like Tommul. You must fight this battle alone.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            previousTeam = Team::Type::NONE;

            RoundLimit = 3;

            Monsters = {
                Monster::Base("Tommul", Monster::Type::TOMMUL, 3, 5, 4, 7, 0),
                Monster::Base("Brute", 2, 5, 3, 6, 0)};

            party.CurrentCharacter = Engine::FIND_SOLO(party);

            if (Engine::IS_ACTIVE(party, party.CurrentCharacter))
            {
                previousTeam = party.Members[party.CurrentCharacter].Team;

                Engine::SET_TEAM(party.Members[party.CurrentCharacter]);

                Team = party.Members[party.CurrentCharacter].Team;
            }
            else if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                previousTeam = party.Members[party.LastSelected].Team;

                Engine::SET_TEAM(party.Members[party.LastSelected]);

                Team = party.Members[party.LastSelected].Team;
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 157}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            auto target = -1;

            if (Engine::IS_ACTIVE(party, party.CurrentCharacter))
            {
                target = party.CurrentCharacter;
            }
            else if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                target = party.LastSelected;
            }

            if (target >= 0 && target < party.Members.size())
            {
                party.Members[target].Team = previousTeam;
            }

            if (result == Engine::Combat::EXCEED_LIMIT)
            {
                temp_string = "The guards arrive and pull you away to your cell.";

                if (!Engine::HAS_MONSTER(Monsters, Monster::Type::TOMMUL))
                {
                    temp_string += " You have defeated Tommul.";

                    if (target >= 0 && target < party.Members.size())
                    {
                        auto result = Engine::ROLL(1);

                        if (result > Engine::SCORE(party.Members[target], Attribute::Type::FIGHTING))
                        {
                            Engine::GAIN_SCORE(party.Members[target], Attribute::Type::FIGHTING, 1);

                            temp_string += "\n\n" + std::string(party.Members[target].Name) + "'s Fighting skill improved by 1.";
                        }
                    }
                }

                Bye = temp_string.c_str();
            }
        }
    };

    class Story240 : public Story::Base
    {
    public:
        Story240()
        {
            BookID = Book::Type::BOOK1;

            ID = 240;

            Text = "You are sailing just south of the Lhasbreath Jungle.";

            Choices.clear();
            Choices.push_back(Choice::Base("Sail west", {Book::Type::BOOK1, 21}));
            Choices.push_back(Choice::Base("Sail east", {Book::Type::BOOK1, 516}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story241 : public Story::Base
    {
    public:
        Story241()
        {
            BookID = Book::Type::BOOK1;

            ID = 241;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "You report your failure to retrieve the SILVER IDOL but speak instead of the revelation you had on the hilltop. \"Excellent!\" claps Honnu. \"Well, I think we can skip he bit about you bringing me the SILVER IDOL.\"\n\nYou flinch. \"But surely if I am to pass the test...?\" \"What do I need of a silver idol, anyway?\" snaps Honnu. \"You will not find your kensai spirit stamped on the base of an idol. Let the thief be pleased with herself. Your spiritual reward will last longer than her reward in coin, I promise you that.\"\n\nYou smile at the cunning old man. Clearly there is more to these tests than meets the eye.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 530}; }
    };

    class Story242 : public Story::Base
    {
    public:
        Story242()
        {
            BookID = Book::Type::BOOK1;

            ID = 242;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "After a short journey the tunnel leads to an old door, long since smashed to pieces. Beyond lie empty racks and armour stands, the chamber having been looted long ago, and a tunnel continues into the darkness beyond. Only one weapon remains, clutched in the hand of a dusty skeleton. The sword is carved of dark blue metal, with spidery runes engraved across its blade.\n\n\"I sense some enchantments, but also a strong curse,\" notes the Everchild. \"I would advise you to leave the blade and continue.\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to pick up the blade", {Book::Type::BOOK1, 131}, Choice::Type::CHOOSE_PARTY_MEMBER));
            Choices.push_back(Choice::Base("Leave the sword where it is and continue onwards", {Book::Type::BOOK1, 647}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story243 : public Story::Base
    {
    public:
        Story243()
        {
            BookID = Book::Type::BOOK1;

            ID = 243;

            Location = Location::Type::MORDAIN;

            Text = "You attempt to make your way to the historic harbour of the city, but the way is blocked with piles of rubble. Mordain, like many coastal cities in the Valley of Bones, was raised on a clifftop in order to deter coastal raiders. However, with the curtain wall of the city in ruins, it is impossible now to even approach the cliffside, let alone get a view down the cliffs. Perhaps it would be easier to get there by sea?";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 515}; }
    };

    class Story244 : public Story::Base
    {
    public:
        Story244()
        {
            BookID = Book::Type::BOOK1;

            ID = 244;

            Location = Location::Type::WEST_ROAD;

            Text = "Once again you leave the labyrinth that is the shadow land. Feeling weak and drained you head north towards civilisation.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 858}; }
    };

    class Story245 : public Story::Base
    {
    public:
        Story245()
        {
            BookID = Book::Type::BOOK1;

            ID = 245;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The ogre seems stunned that such thin and puny creatures could possess so much money. \"Beats me why you wander 'round dungeons when you have that kind of dosh lining your pockets, but well'a'day.\"\n\nThe ogre rises to his feet. \"Skullcracker's the name,\" he says. \"I don't do cities, and I don't do boats. Other than that, I'll hang around with you for a bit.\n\nSkullcracker hands you a RUSTY KEY. \"This is the key to the room I'm supposed to be guarding,\" he says. \"Why don't we loot it, instead? Just go north, then east a bit, and you'll find it.\"\n\nNote: Skullcracker can be treated just like an ordinary party member. He possesses the following skills:\n\nFighting: 8, Stealth: 1, Lore: 1, Survival: 3, Charisma: 2, Health: 12\n\nSkullcracker has a number of special rules as a party member:\n\n* He is lazy and he will not carry any equipment for you, even items that boost his skills. Skullcracker wields a CLUB, but it is nothing special. Should the party ever lose their equipment he will be able to replace the CLUB instantly with a bit of large bone, table leg or other such item. Effectively, Skullcracker is never disarmed.\n\n* He won't enter a city, which includes the following locations: Chalice, Clifftop, Cursus, Lhasbreath, Luutanesh or Saltdad. If you go to these places, Skullcracker will wait outside until you leave. Ogres aren't very popular in civilised places.\n\n* Even though he can't stay in human inns, Skullcracker will recover Health points at the same rate as your other party members when you pay to stay at an inn.\n\n* He won't board a ship. He had a queasy tummy on the orc boat and won't tolerate going aboard another. If you insist on going sailing, he will leave the party.\n\n* His contract with you ends when you travel to another land. At this point, Skullcracker with take his leave and wander into the desert.\n\nYou gained the code A76.";

            Bye = "Thanking your new companion, you return to the crossroads.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            if (!Engine::IN_PARTY(party, Character::Type::SKULLCRACKER))
            {
                party.Members.push_back(Character::SKULLCRACKER);
            }

            Engine::GET_CODES(party, {Codes::A(76)});

            Take = {Equipment::RUSTY_KEY};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 310}; }
    };

    class Story246 : public Story::Base
    {
    public:
        Story246()
        {
            BookID = Book::Type::BOOK1;

            ID = 246;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "The king nods as he scans over the document with his eyes. \"A good reduction, and a modest bribe, this is well,\" he concedes. \"Though it pains me to sully our court with the intrigues of foreigners. Take your reward and never come in our presence again.\"\n\nThe Iron King waves to one of his councillors, who reluctantly places 350 silver pieces and an IRON GREATAXE* (Fighting +2) into your hands.";

            Bye = "Not wishing to tarry longer, you depart the chamber and return to the crossroads.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::TITHE_REPORT});

            Take = {Equipment::IRON_GREATAXE2};

            Limit = 1;

            Engine::GAIN_MONEY(party, 350);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story247 : public Story::Base
    {
    public:
        Story247()
        {
            BookID = Book::Type::BOOK1;

            ID = 247;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "This small room contains a very large ogre. In fact, there is actually bedding down for two of these enormous creatures, but currently only one is here, chewing on the leg bone of a sand lizard. He eyes you lazily.";

            Choices.clear();
            Choices.push_back(Choice::Base("Attempt to speak with the ogre", {Book::Type::BOOK1, 693}));
            Choices.push_back(Choice::Base("Rush to an attack", {Book::Type::BOOK1, 117}));
            Choices.push_back(Choice::Base("Politely excuse yourself and return to the crossroads", {Book::Type::BOOK1, 310}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(76)}))
            {
                return {Book::Type::BOOK1, 36};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story248 : public Story::Base
    {
    public:
        Story248()
        {
            BookID = Book::Type::BOOK1;

            ID = 248;

            Text = "The dragonyak bull bows to you as you speak in the ancient tongue of beasts. \"You are an animal friend,\" he intones. \"Our legends say that it has been an eon since any dragonyak was so addressed. You honour us.\" The dragonyak unleashes a bellowing roar, which is repeated by his herd. One dragonyak immerses herself in the water of the oasis and emerges sometime later with a CLOAK, sodden with water, but miraculously unharmed by the passage of years. The bull insists you take the cloak, for he is aware that man-apes such as yourself favour them.\n\nYou take THE RUGGED CLOAK (Survival +2) so as not to offend the mighty bull and make your way onwards.\n\nNote: You gained the code A38.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::CAST_SPELL(party, Team::Type::NONE, Spells::Type::ANIMAL_SPEECH);

            Take = {Equipment::RUGGED_CLOAK2};

            Limit = 1;

            Engine::GET_CODES(party, {Codes::A(38)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 115}; }
    };

    class Story249 : public Story::Base
    {
    public:
        Story249()
        {
            BookID = Book::Type::BOOK1;

            ID = 249;

            Text = "You seek out the father of Garon the Bloody Mouthed. He is still sitting sadly upon his doorstep when you return, bearing his son's body in your arms. The father gives a great howl and clasps his son's body.\n\n\"It is as I feared,\" he weeps. \"I thank you for returning his body so it may be buried with honour. I was to present my son with his grandfather's magical amulet upon his successful return -- but now I have no sons left to inherit. I wish you to have it. It is what Garon would have wanted.\"\n\nThe old man presents you with an AMULET OF HEALTH (Health +1). It would be churlish to refuse it. You leave the old man to his sorrows.\n\nNote: You gained the code A86.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::AMULET_OF_HEALTH1};

            Limit = 1;

            Engine::GET_CODES(party, {Codes::A(86)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story250 : public Story::Base
    {
    public:
        Story250()
        {
            BookID = Book::Type::BOOK1;

            ID = 250;

            Text = "It's not your city. You shoulder the loot bag and slide back down the rope. Once you are a few neighbourhoods away you stroll along as if nothing had happened.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::HANDSOME_BROOCH1};

            Limit = 1;

            Engine::GAIN_MONEY(party, 200);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story251 : public Story::Base
    {
    public:
        Story251()
        {
            BookID = Book::Type::BOOK1;

            ID = 251;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "With the beetles destroyed you brush them away from the mystic circle and examine it. It appears to be some kind of health boosting magic circle with a small indentation in the middle, not unlike an ink well. Indeed, the instructions for its use have been usefully painted upon the walls of the chamber. It appears that if you pour some QUICKSILVER into the central well the circle will activate and imbue you with power.\n\nNote: You gained the code A61.";

            Choices.clear();
            Choices.push_back(Choice::Base("You have some QUICKSILVER and want to try it out", {Book::Type::BOOK1, 26}, {Equipment::QUICKSILVER}));
            Choices.push_back(Choice::Base("There is nothing more to do here: Return to the crossroads", {Book::Type::BOOK1, 566}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(61)});
        }
    };

    class Story252 : public Story::Base
    {
    public:
        Story252()
        {
            BookID = Book::Type::BOOK1;

            ID = 252;

            Text = "You are greeted by Honnu and the other monks, and go into meditation with them for a few days. There is nothing more Honnu can teach a fully trained kensai, so after a few days of peace you make your way onwards.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story253 : public Story::Base
    {
    public:
        Story253()
        {
            BookID = Book::Type::BOOK1;

            ID = 253;

            Location = Location::Type::WITHERED_STEPPES;

            Text = "Although you know that the nomads make their home in the Withered Steppes, their territory covers hundreds of square miles of desert. Finding them will not be easy.";

            Choices.clear();
            Choices.push_back(Choice::Base("Locate the nomads (Team check: Survival 5+, Successes: 3)", {Book::Type::BOOK1, 473}, {Book::Type::BOOK1, 422}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 5, 3));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story254 : public Story::Base
    {
    public:
        Story254()
        {
            BookID = Book::Type::BOOK1;

            ID = 254;

            Text = "You cannot ward the assassin away. He ducks under your blade and stabs the Everchild in the leg. She squeals and kicks him away, and you impale the knave through the back. Casting his body aside you rush to the Everchild. \"It's not bad!\" she assures you, gripping her bleeding thigh. A quick examination of the assassin's dagger tells you otherwise... it has been poisoned.\n\nSoon she in a critical condition, unable to stand, her flesh looking as grey as stone. In her fevered delirium she insists on leading the troops into battle, but this is clearly impossible. You command her to concentrate on getting better, and to focus all her healing energies on herself.\n\nWord soon gets around about the Everchild's condition. Each army unit in the Saltdad barracks must lose 1 point of Morale. You dread the coming of the dawn, but you realise you cannot escape now. You must face what comes with as much courage as you can muster.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::EVERCHILD_POISONED});

            Engine::GAIN_MORALE(party, Location::Type::SALTDAD, -1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 162}; }
    };

    class Story255 : public Story::Base
    {
    public:
        Story255()
        {
            BookID = Book::Type::BOOK1;

            ID = 255;

            Image = "images/book1/roughly_dressed_man.png";

            Text = "You clamber up to the open window and peek inside. A roughly dressed man is standing in a finely appointed room, hurriedly searching through cupboards and trunks, casting clothes and knick-knacks over his shoulders. A large bag is thrown on the bed, glittering treasures peeking out of the top.";

            Choices.clear();
            Choices.push_back(Choice::Base("Try and sneak up on the man", {Book::Type::BOOK1, 91}));
            Choices.push_back(Choice::Base("Demand the man tell you what he is doing", {Book::Type::BOOK1, 724}));
            Choices.push_back(Choice::Base("Quickly depart before the man sees you", {Book::Type::BOOK1, 450}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story256 : public Story::Base
    {
    public:
        Story256()
        {
            BookID = Book::Type::BOOK1;

            ID = 256;

            Text = "You have entered a small, cramped library, with bookstacks lining the walls and standing in rows before you. Several books are on the floor, apparently hacked apart with swords. Besides this crude vandalism, the books seem in good condition.";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine some of the tomes", {Book::Type::BOOK1, 558}));
            Choices.push_back(Choice::Base("Shut the door and return to the alchemical chamber", {Book::Type::BOOK1, 69}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story257 : public Story::Base
    {
    public:
        Story257()
        {
            BookID = Book::Type::BOOK1;

            ID = 257;

            Location = Location::Type::DESERT;

            Text = "Skittering across the desert sands at unbelievable speed come a pair of giant sand lizards. These beasts alternate between lazily sitting in the sun or hunting prey with energetic intensity. These ones are obviously hungry, and scuttle forwards, their mouths as wide as crocodiles.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            Limit = 0;

            Monsters = {
                Monster::Base("Sand Lizard", 4, 3, 4, 7, 0),
                Monster::Base("Sand Lizard", 4, 3, 4, 9, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 840}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Take = {Equipment::LIZARD_HIDE};

                Limit = 1;
            }
        }
    };

    class Story258 : public Story::Base
    {
    public:
        Story258()
        {
            BookID = Book::Type::BOOK1;

            ID = 258;

            Text = "There is a strange sound in the room to the south, and you instinctively draw your weapons. Fortunately, it is just Brekken and the rest of his thieves. You wondered when they would get here!\n\n\"An old friend of ours in Chalice offered us an easy route into the palace,\" explains Brekken. \"We thought it might be easier than sneaking past all those guards.\"\n\n\"Yes... but how did you know when to arrive,\" you ask, mystified.\n\n\"Well... he's quite knowledgeable, is our friend,\" winks Brekken. \"Shall we get on with it?\"\n\nYou nod, and soon Brekken and his gang are surrounding the vault, their hands pouring over it, scratching their beards and muttering to each other. You catch Brekken producing a scroll, which he reads from. Suddenly the door begins to swing open.\n\n\"I suppose your friend gave you that as well!\" you say, indicating the magic scroll which even now is disintegrating into ash.\n\n\"Well -- he moves in mysterious ways, doesn't he?\" grins Brekken.\n\nNote: You may now loot the vault. However, you must give three items from the treasure list to Brekken and his gang. The silver coins count as one item.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::BANDITS_GET3});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 416}; }
    };

    class Story259 : public Story::Base
    {
    public:
        Story259()
        {
            BookID = Book::Type::BOOK1;

            ID = 259;

            Location = Location::Type::BLACKWALL;

            Text = "After days of monotony, you finally come upon an arch in the wall. It is the Shaded Gate, though how you knew its name is a mystery to you. Beyond the arch the desert continues... except the land is a shadowy haze, a dark reflection of the real world.";

            Choices.clear();
            Choices.push_back(Choice::Base("Will you enter the Shaded Gate", {Book::Type::BOOK1, 410}));
            Choices.push_back(Choice::Base("Break off from the wall and head north", {Book::Type::BOOK1, 858}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story260 : public Story::Base
    {
    public:
        Story260()
        {
            BookID = Book::Type::BOOK1;

            ID = 260;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The flickering torch deceives your eyes, shadows from your companions making it look like your foot is in a safe place. There is an audible crunch as you step upon a juicy egg. Tiny spiderlings emerge in their hundreds. Suddenly the giant spiders move as one, descending upon your companions and the Everchild's followers. Eggs crack open as careless feet release more baby spiders.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 237}; }
    };

    class Story261 : public Story::Base
    {
    public:
        Story261()
        {
            BookID = Book::Type::BOOK1;

            ID = 261;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "\"I'm glad I found you. I must tell you some sad news,\" you say gravely. \"I met one of your kind in the desert. An apprentice of Unbraaki. Alas, he perished. He did not return to you because he feared Unbraaki would harm you if he found him hiding here. I am sorry to bring you such sad news.\"\n\nThe chattering in the treetops instantly stops, to be replaced by mournful howls. \"Curse you for bringing such dreadful tidings!\" cries one of the monkeys. \"For you speak of my own son! Oh! Misery! Misery!\"\n\nThe monkeys depart solemnly above you, their howls rending your ears. Emlyn looks on in wonder as the monkeys vanish. \"What did you say to them?\" she asks, astonished.\n\n\"I haven't the heart to tell you,\" you say sadly, wiping a tear from your eye.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 740}; }
    };

    class Story262 : public Story::Base
    {
    public:
        Story262()
        {
            BookID = Book::Type::BOOK1;

            ID = 262;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "Saint Elias is considered the holiest man in the world, a spokesman from the celestial court who has lived on the world for two thousand years. He is a silver elf, a faerie given human form, who rejected his fey heritage to study the majesty of the gods. He resides in a mighty tower called Tier Mundus, the last of the great towers of the elder time (all the rest were destroyed by Abraxas during the desolation). It is believed that he is personally responsible for the banishment of Abraxas into the centre of the earth at the climax of the desolation, and that he is therefore not merely the vicar of the gods, but also a powerful sorcerer in his own right. He still lives today, and grants blessings to pilgrims. Sometimes he advises the world's mightiest rulers, if they will hear his wisdom, but he has always remained neutral in all political affairs.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 680}; }
    };

    class Story263 : public Story::Base
    {
    public:
        Story263()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::LUUTANESH;

            ID = 263;

            Text = "You are in the Everchild's hideout in Luutanesh. Around you generals and captains of her armies swirl in great preparation for the forthcoming battle.";

            Choices.clear();
            Choices.push_back(Choice::Base("Take the opportunity to rest at the inn", {Book::Type::BOOK1, 66}));
            Choices.push_back(Choice::Base("Speak with the Everchild", {Book::Type::BOOK1, 898}));
            Choices.push_back(Choice::Base("Order the attack on Saltdad to begin", {Book::Type::BOOK1, 376}));
            Choices.push_back(Choice::Base("Leave Luutanesh", {Book::Type::BOOK1, 194}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story264 : public Story::Base
    {
    public:
        Story264()
        {
            BookID = Book::Type::BOOK1;

            ID = 264;

            Text = "This will be a fraught battle.\n\nNote: The skeleton archers do not attack in hand-to-hand combat, but will try and shoot party members if they are not kept busy. If, at the end of the combat turn, the skeleton archers have not taken any damage, they unleash their arrows. Choose two party members to lose 2 Health points -- armour cannot reduce this damage.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {
                Monster::Base("Skeleton Warriros", 9, 4, 4, 12, 0),
                Monster::Base("Skeleton Archers", Monster::Type::SKELETON_ARCHERS, 0, 0, 4, 13, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 555}; }
    };

    class Story265 : public Story::Base
    {
    public:
        Story265()
        {
            BookID = Book::Type::BOOK1;

            ID = 265;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You are leaving the Palace of Unbraaki. Where will you venture now?";

            Choices.clear();
            Choices.push_back(Choice::Base("Go north, towards Clifftop", {Book::Type::BOOK1, 725}));
            Choices.push_back(Choice::Base("Go east, to the Tumblestones", {Book::Type::BOOK1, 137}));
            Choices.push_back(Choice::Base("Go southeast, to Lhasbreath", {Book::Type::BOOK1, 775}));
            Choices.push_back(Choice::Base("Head south, into the jungle", {Book::Type::BOOK1, 370}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story266 : public Story::Base
    {
    public:
        Story266()
        {
            BookID = Book::Type::BOOK1;

            ID = 266;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You have only just begun your negotiations when one of the thieves shouts out, \"They're agents of the Iron King! Slay them before they get away!\" The thieves draw their weapons, the Everchild rising with her allies to lend you aid.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 889}; }
    };

    class Story267 : public Story::Base
    {
    public:
        Story267()
        {
            BookID = Book::Type::BOOK1;

            ID = 267;

            Text = "You cannot help but shed a tear as your bloodied companion sprawls to the ground, dead by your hand. They were too dangerous to be left alive, but that doesn't mean your actions will not haunt your dreams for weeks to come. You may take any possessions from the dead party member that you wish. Kicking away the black book, you exit the chamber.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 821}; }
    };

    class Story268 : public Story::Base
    {
    public:
        Story268()
        {
            BookID = Book::Type::BOOK1;

            ID = 268;

            Text = "Through the desert haze, the legions of the Everchild go on the march. Dust rises on the Northroad as the combined forces of the valley descend upon the defiant city of Cursus. The Everchild calls a halt on a raised perch of land where the city and its harbour can be clearly seen. In the blood-red light of the setting sun you can see that the harbour of Cursus is packed with cogs, hulks and carracks of many nations and heraldry. The patriarch has emptied his treasury to gain followers for his last stand. Spies loyal to the Everchild report that the high priest of Cursus might have access to as many as six thousand fighting men.\n\n\"They do not have space for such a large deployment in the field,\" observes Che Long. \"Or, if they did, such numbers would be unmanageable.\"\n\n\"Are those knights? Has the patriarch brought foreign knights here?\" asks the Everchild, peering into the gloom.\n\n\"They will not be able to wear their heavy armour in the desert,\" says Che Long. \"Unlike the Bronzeguard, their armour is not enchanted and does not keep them cool in the sun.\"\n\nLady Ayleta approaches the Everchild and bows. \"My lady, your agents are assembled in the command tent.\"\n\nThe Everchild bids you follow her as she approaches the tent. \"I have many agents who follow me now, but none are as experienced as you. I shall give you priority over which missions you wish to undertake. All are hazardous, so do not stretch yourselves too thinly.\"";

            Bye = "Nodding, you enter the tent with the queen.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 124}; }
    };

    class Story269 : public Story::Base
    {
    public:
        Story269()
        {
            BookID = Book::Type::BOOK1;

            ID = 269;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "As you round the corner of the corridor you come face to face with a hideous female ogre. She hefts her club to attack, when she suddenly sees Skullcracker lollop into view.\n\n\"Oi! What's going on 'ere then?\" she asks, confused.\n\n\"I've ganged up with this lot,\" growls Skullcracker. \"Can't be bothered to work for the orcs anymore.\"\n\n\"What am I supposed to do, then?\" snaps the female ogre.\n\n\"What 'yer like,\" shrugs Skullcracker. \"It would be impertinent of me to suggest a course of action that influences your sense of agency one way or the other. And you smell.\"\n\n\"Git,\" snaps the lady ogre. \"I suppose I'll sod off myself then.\"\n\n\"Good idea,\" grumbles Skullcracker.\n\nYou are almost teary at this sad parting, but eventually Daisy the ogre shambles away.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 165}; }
    };

    class Story270 : public Story::Base
    {
    public:
        Story270()
        {
            BookID = Book::Type::BOOK1;

            ID = 270;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "You stroll around the city, getting a closer look at the spiralling towers that Chalice is famous for. The streets are almost empty as you walk through the neighbourhoods. Unlike in many cities almost everyone in Chalice works, if not in the fields than in the temples or guard towers of the kensai. As a consequence, the streets are relatively quiet except around the well-ordered shops and market stalls. As you pass through a pleasant borough you spot something curious. A rope is dangling from the window of a tall house with a curved red roof. It reaches all the way to the ground. Strangely there seems to be no one around.\n\nNote: You gained the code A54.";

            Choices.clear();
            Choices.push_back(Choice::Base("Climb up the rope and investigate", {Book::Type::BOOK1, 358}));
            Choices.push_back(Choice::Base("Stroll past and don't get involved", {Book::Type::BOOK1, 450}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(54)}))
            {
                return {Book::Type::BOOK1, 696};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(54)});
        }
    };

    class Story271 : public Story::Base
    {
    public:
        Story271()
        {
            BookID = Book::Type::BOOK1;

            ID = 271;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The Saltdad Arena is the second largest complex in the city, with only the ancient palace looming larger. Its dungeons go deep into the earth, where prisoners, slaves and monstrous animals are kept in large vaults, with only the feeblest light pouring through barred arches set high in the ceilings.\n\nYour quarters are a large and ancient hall, whose walls bear the sigils and faded murals of a more civilised age. Within this chamber are crammed nearly a hundred hungry captives, sleeping rough upon the gravel floor and relieving themselves in stinking buckets stacked in a far corner. You ask about feeding arrangements from one of your fellow prisoners, who give you hollow looks. \"You'll know it when it happens,\" he warns.\n\nSuddenly a hatch at the top of the hall is swung open, and the barely-cooked carcass of a mountain goat is dropped carelessly into the middle of the hall. There is a great crush as the prisoners surge as one to tear off strips of flesh from the animal. A group of strong men from Lhasbreath, slaves like you, batter the crowd away with threats, claiming first rights over the animal. You are starving.";

            Choices.clear();
            Choices.push_back(Choice::Base("Challenge the men to first rights over the meat", {Book::Type::BOOK1, 212}));
            Choices.push_back(Choice::Base("Attempt to side with the men, to ensure you get something", {Book::Type::BOOK1, 282}));
            Choices.push_back(Choice::Base("Wait your turn to get something to eat", {Book::Type::BOOK1, 118}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_CODES(party, {Codes::Type::FIRSTTIME_SOLD_SALTDADARENA});
        }
    };

    class Story272 : public Story::Base
    {
    public:
        Story272()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::CURSUS;

            IsCity = true;

            ID = 272;

            Text = "Even the smaller temples to Cursus are fantastic in their ornamentation. Gold ornaments lustre against the deep black stone, and haunting choral odes echo through the square chamber, as if the singers were surrounding you.\n\nIf you have any INCENSE, you may exchange some for a blessing from the priests. Find the party member with the lowest Stealth score in the team and increase their Stealth by 1 point.\n\nYou may also receive some Ritual Scarring (Cursus), which are runes sacred to Cursus carved across the chest of the subject. The priests are bound to perform this service to any who ask for it. If one of your party members wants some Ritual Scarring (Cursus), they must lose 1 point of Health permanently.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::Type::NO_BLESSINGS_FOREVER}))
            {
                Choices.push_back(Choice::Base("(INCENSE) Select party member with lowest Stealth score", {Book::Type::BOOK1, -272}, Choice::Type::PAYFORBLESSING_WITH_ITEM, {Equipment::INCENSE}, {Attribute::Type::STEALTH}, 1));
            }

            Choices.push_back(Choice::Base("Receive some Ritual Scarring (Cursus)", {Book::Type::BOOK1, -272}, Choice::Type::PAYFORSTATUS_WITH_HEALTH, {Character::Status::RITUAL_SCARRING_CURSUS}, -1));
            Choices.push_back(Choice::Base("You are finished here", {Book::Type::BOOK1, 340}));
        }
    };

    class Event272 : public Story::Base
    {
    public:
        Event272()
        {
            BookID = Book::Type::BOOK1;

            ID = -272;

            DisplayID = 272;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party) { return {Book::Type::BOOK1, 272}; }
    };

    class Story273 : public Story::Base
    {
    public:
        Story273()
        {
            BookID = Book::Type::BOOK1;

            ID = 273;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "The only sound is your boots as you crunch across a gravel-strewn plain. You feel so lonely you fear you might die.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 1 Health", {Book::Type::BOOK1, -273}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event273 : public Story::Base
    {
    public:
        Event273()
        {
            BookID = Book::Type::BOOK1;

            ID = -273;

            DisplayID = 273;

            Text = "Where will you go?";

            Choices.clear();
            Choices.push_back(Choice::Base("North", {Book::Type::BOOK1, 886}));
            Choices.push_back(Choice::Base("West", {Book::Type::BOOK1, 676}));
            Choices.push_back(Choice::Base("South", {Book::Type::BOOK1, 537}));
            Choices.push_back(Choice::Base("East", {Book::Type::BOOK1, 589}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story274 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story274()
        {
            BookID = Book::Type::BOOK1;

            ID = 274;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You examine the body. The man was strongly built, with a great beard with flecks of red paint in it.\n\nNote: You gained the code A66.";

            Engine::GET_CODES(party, {Codes::A(66)});

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(67)}))
            {
                PreText += "\n\nThere is nothing more you can do here.";

                Choices.push_back(Choice::Base("Examine the missing south wall", {Book::Type::BOOK1, 645}));
                Choices.push_back(Choice::Base("Return to the crossroads", {Book::Type::BOOK1, 566}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 76}; }
    };

    class Story275 : public Story::Base
    {
    public:
        Story275()
        {
            BookID = Book::Type::BOOK1;

            ID = 275;

            Location = Location::Type::GRANITE_HILLS;

            Image = "images/book1/wilderness.png";

            Text = "You are strolling through a rolling wilderness of dry hills, whose ancient, crumbling sides show plenty of evidence of ancient stone quarries and other industries. Although it is hot, you are able to make good progress by walking along shady parts of the hillsides and checking your location by climbing the taller hills. The rough terrain makes this place unpopular with nomads and barbarians, so your time here is relatively safe.";

            Choices.clear();
            Choices.push_back(Choice::Base("Explore the hills", {Book::Type::BOOK1, 688}));
            Choices.push_back(Choice::Base("Go northwest, to the Blackwall", {Book::Type::BOOK1, 691}));
            Choices.push_back(Choice::Base("Go north, towards Saltdad", {Book::Type::BOOK1, 858}));
            Choices.push_back(Choice::Base("Go northeast into the Withered Steppes", {Book::Type::BOOK1, 115}));
            Choices.push_back(Choice::Base("Go southeast, into desert", {Book::Type::BOOK1, 202}));
            Choices.push_back(Choice::Base("Go south towards Lhasbreath Oasis", {Book::Type::BOOK1, 590}));
            Choices.push_back(Choice::Base("Go southwest towards Lhasbreath", {Book::Type::BOOK1, 752}));
            Choices.push_back(Choice::Base("Go west to the Tumblestones", {Book::Type::BOOK1, 137}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story276 : public Story::Base
    {
    public:
        Story276()
        {
            BookID = Book::Type::BOOK1;

            ID = 276;

            Location = Location::Type::LHASBREATH;

            Text = "The inns are a little unusual in Lhasbreath. Rather than being solid structures, inns are vast canvas tents without separate rooms. Here you rub shoulders with many young and old barbarians who are not successful enough to own their own houses. They are known as 'doss tents', and great casks and tables occupy the centre of the tent where ale and food is served. Loud music and singing make sleep difficult, and you must stay constantly vigilant for thieves. For every 3 silver coins you spend, each party member can recover 1 Health point. However, spellcasters cannot recharge their spells here, as there is not enough privacy to attain the necessary meditative state. You are warned by a hairy barbarian not to venture into the Salt Plains. \"The lack of moisture there will suck the water right from your bones and leave you as dry as a husk,\" he roars, spittle drooling from his chin. \"Only the most experienced ranger stands a chance of survival.\"";

            RestPrice = 3;

            Choices.clear();

            Controls = Story::Controls::INN;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story277 : public Story::Base
    {
    public:
        Story277()
        {
            BookID = Book::Type::BOOK1;

            ID = 277;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "You examine the coffer carefully, but it does not seem to be trapped. Inside are 125 silver coins and a BRONZE LOCKET.";

            Bye = "You continue down the tunnel.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::BRONZE_LOCKET};

            Limit = 1;

            Engine::GAIN_MONEY(party, 125);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 20}; }
    };

    class Story278 : public Story::Base
    {
    public:
        Story278()
        {
            BookID = Book::Type::BOOK1;

            ID = 278;

            Text = "Clearly your allegiance to the Everchild has not gone unnoticed. You search the zealots, finding three CRUDE BLADES (Fighting +0), 60 silver coins and the Sorcerer's spell book! Sadly, the book has been badly damaged in the battle, but at least one interesting spell has survived:\n\nDazing Lights (Combat)\n\nSwirling lights dazzle your foes' eyes. When your opponent's attack this round, they must reduce the score of each of their dice by 1 point.\n\nRecharge: 50 silver\n\nAny of your spellcasters can add this spell to their spellbooks if they wish, but remember that you cannot have more than six spells in a single spellbook at any given time.\n\nNote: You gained the code A22.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 60);

            Take = {Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE};

            Limit = 3;

            Spells = {Spells::DAZING_LIGHTS};

            Engine::GET_CODES(party, {Codes::A(22)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 804}; }
    };

    class Story279 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Team::Type previousTeam = Team::Type::NONE;

        int character = -1;

        Story279()
        {
            BookID = Book::Type::BOOK1;

            ID = 279;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You make your way up the stairs, Yu Yan eying the route cautiously. She suddenly puts an arm in front of you and tells you to stop. She draws her green-bladed sword and presses down on a step before you. A blade flashes across the higher step, at what would have been head height, with enough force to ensure decapitation. Instead, it sails harmlessly over your head.\n\nYou smile and nod at Yu Yan, before continuing onwards. You emerge into a stale smelling chamber, roughly oval in shape, with more stairs leading upwards ahead. Within the room you can see an impressive pile of treasure, but also something more troublesome. Rising from his crude mattress comes a Dragonyakman, a scaly, bull headed man, some nine feet tall, hefting a great iron axe.\n\nYou nod to Yu Yan to flank, as you go in for the kill.\n\nNote: After you attack, Yu Yan will also make an attack using 5 attack dice. She is very agile, so the dragonyakman will focus all his attacks just on you.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            Team = Team::Type::AKIHIRO_OF_CHALICE;

            party.CurrentCharacter = Engine::FIND_SOLO(party);

            if (Engine::IS_ACTIVE(party, party.CurrentCharacter) && party.Members[party.CurrentCharacter].Type == Character::Type::AKIHIRO_OF_CHALICE)
            {
                character = party.CurrentCharacter;
            }
            else
            {
                character = Engine::FIND_CHARACTER(party, Character::Type::AKIHIRO_OF_CHALICE);
            }

            if (character >= 0 && character < party.Members.size())
            {
                previousTeam = party.Members[character].Team;

                Engine::SET_TEAM(party.Members[character]);

                Monsters = {Monster::Base("Dragonyakman", 6, 5, 3, 15, 0)};

                Allies = {Allies::Type::YU_YUAN};
            }
            else
            {
                Monsters.clear();

                Allies.clear();
            }
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                if (Engine::IS_ACTIVE(party, character))
                {
                    Engine::SET_TEAM(party.Members[character], previousTeam);
                }

                destination = {Book::Type::BOOK1, 635};
            }
            else
            {
                Bye = "Akihiro is slain.";

                destination = {Book::Type::BOOK1, 450};
            }
        }
    };

    class Story280 : public Story::Base
    {
    public:
        Story280()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            ID = 280;

            Text = "Over the next few days the Everchild consolidates her rule. All your soldiers in the Luutanesh barracks are transferred to the Saltdad barracks. The morale of all your soldiers is restored to maximum. The Everchild presents you with 1250 silver coins for your labours to gain her the throne.\n\n\"Our next target is Clifftop,\" says the Everchild as you attend her war council. \"I need access to a good port if I am to take full control of the valley. Their King, Lothor the Ugly, is a zealous follower of Cursus so he cannot be swayed. Lothor has more troops than the Iron King, so I am reluctant to attack straight away.\"\n\n\"Is there anyone else who can reinforce us?\" you ask.\n\n\"It's possible that Unbraaki might,\" she says. \"He is a sorcerer of some power who lives in a palace just south of Clifftop. He would never have considered sending soldiers to me whilst I was a revolutionary, but he might be willing to do so now I am a queen. Ask him what he wants in exchange for support and see if he can be accommodated. You might also have some luck with the nomads of the desert. I have some connection with these people so they might be swayed. Good fortune to you, friends.\"";

            Bye = "You bow and leave the palace.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 1250);

            Engine::TRANSFER(party, Location::Type::LUUTANESH, Location::Type::SALTDAD);

            Engine::RESTORE_MORALE(party, Location::Type::SALTDAD);

            Engine::GET_CODES(party, {Codes::Type::QUEEN_IN_SALTDAD});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story281 : public Story::Base
    {
    public:
        Story281()
        {
            BookID = Book::Type::BOOK1;

            ID = 281;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "Acting casually, you take a flight of steps down into the bowels of the pyramid. You hear the sounds of guards ahead, and cautiously peek around a corner. A long, wide hallway held aloft by pillars, leads into the darkness. A guard post, occupied by the Temple Guard, has been set up here. A dozen guards whisper and game by torchlight. To sneak past so many will require great skill.";

            Choices.clear();
            Choices.push_back(Choice::Base("Sneak past the Temple Guard (Team check: Stealth 5+, Successes: 4)", {Book::Type::BOOK1, 183}, {Book::Type::BOOK1, 55}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::ZIGGURAT, {Attribute::Type::STEALTH}, 5, 4));
            Choices.push_back(Choice::Base("Return to the main floor", {Book::Type::BOOK1, 574}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(83)}))
            {
                return {Book::Type::BOOK1, 327};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story282 : public Story::Base
    {
    public:
        Story282()
        {
            BookID = Book::Type::BOOK1;

            ID = 282;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You attempt to get the violent-looking slaves on side, offering to join their gang and share the spoils of the goat evenly.";

            Choices.clear();
            Choices.push_back(Choice::Base("Join Slave Gang (Team check: Charisma 4+, Successes: 4)", {Book::Type::BOOK1, 838}, {Book::Type::BOOK1, 374}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story283 : public Story::Base
    {
    public:
        Story283()
        {
            BookID = Book::Type::BOOK1;

            ID = 283;

            Text = "You have returned to the torture chamber with the massive hole in the south wall.";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine the missing south wall", {Book::Type::BOOK1, 645}));
            Choices.push_back(Choice::Base("Return to the crossroads", {Book::Type::BOOK1, 566}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story284 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story284()
        {
            BookID = Book::Type::BOOK1;

            ID = 284;

            Location = Location::Type::LUUTANESH;

            Image = "images/book1/cold_river_inn.png";

            Choices.clear();
        }

        void Event(Party::Base &party)
        {
            RestPrice = -1;
            CanRecharge = false;
            Controls = Story::Controls::STANDARD;

            PreText = "The Cold River Inn is a large building built on sticks to protect it from flooding. The rooms are separated by stretched fabrics of many different colours, and the tavern is a virtual maze of woven corridors, from which the low voices of residents and drinkers alike can be heard behind the frescos and tapestries that separate you from them.";

            if (!Engine::VERIFY_CODES_ANY(party, {Codes::A(6), Codes::C(6)}))
            {
                RestPrice = 5;
                CanRecharge = true;
                Controls = Story::Controls::INN;

                PreText += "\n\nYou may stay at the inn and recover your strength. For every 5 silver coins you spend, each party member can recover 1 Health point. Spell casters can also spend silver here to recharge their spells, purchasing components in the nearby marketplace and going into meditation in the privacy of their rooms.\n\nDuring your stay meet a frustrated archaeologist, fresh from his digs at the Tumblestones just north of Lhasbreath. \"First we were constantly exploited by barbarians from the south, and then our trenches are refilled from the blasted sandstorms as quickly as we could dig them,\" he grumbles. \"I'm certain there are amazing discoveries to be made, but I'll be blown if it's worth all the hassle of finding them!\"";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES_ANY(party, {Codes::A(6), Codes::C(6)}))
            {
                return {Book::Type::BOOK1, 562};
            }
            else
            {
                return {Book::Type::BOOK1, 614};
            }
        }
    };

    class Story285 : public Story::Base
    {
    public:
        Story285()
        {
            BookID = Book::Type::BOOK1;

            ID = 285;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You turn a corner to see Tommul, one of the thugs you bullied in the dungeon on your very first day. He is accompanied by another muscular man, armed with a club. \"I told you I would get even with you, scum!\" he snarls, advancing menacingly towards you.";

            Choices.clear();
            Choices.push_back(Choice::Base("Run for it", {Book::Type::BOOK1, 544}));
            Choices.push_back(Choice::Base("Try to talk Tommul down", {Book::Type::BOOK1, 649}));
            Choices.push_back(Choice::Base("Raise your fists", {Book::Type::BOOK1, 239}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story286 : public Story::Base
    {
    public:
        Story286()
        {
            BookID = Book::Type::BOOK1;

            ID = 286;

            Text = "You believe you have already found this man... stretched out on a rack in an orcish prison. Tears form in the old man's eyes. \"Oh! Return his body -- I beg you!\" he pleads. \"My son's spirit cannot rest unless he is buried with his ancestors.\" The thought of dragging a six-foot barbarian across the desert does not exactly appeal, but you say you will do what you can.\n\nNote: You gained the code A67.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(67)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story287 : public Story::Base
    {
    public:
        Story287()
        {
            BookID = Book::Type::BOOK1;

            ID = 287;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "Honnu has nothing more to say to you.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::SILVER_IDOL}))
            {
                return {Book::Type::BOOK1, 675};
            }
            else if (Engine::HAS_STATUS(party, Character::Status::ENLIGHTENED))
            {
                return {Book::Type::BOOK1, 241};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story288 : public Story::Base
    {
    public:
        Story288()
        {
            BookID = Book::Type::BOOK1;

            ID = 288;

            Text = "The symbols on the calendar are rather representational. Perhaps you can infer their meaning?";

            Choices.clear();
            Choices.push_back(Choice::Base("Translate the calendar (Team check: Lore 5+, Successes: 4)", {Book::Type::BOOK1, 50}, {Book::Type::BOOK1, 585}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 5, 4));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            Bye = NULL;

            if (!outcome)
            {
                Bye = "You are unable to work out the meaning. Apologising, you get some sleep whilst you wait out the storm.";
            }
        }
    };

    class Story289 : public Story::Base
    {
    public:
        Story289()
        {
            BookID = Book::Type::BOOK1;

            ID = 289;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You return to the treasure chamber in the hopes of finding some more treasure. Alas, a full search reveals nothing more. Disappointed, you return to the corridor.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 165}; }
    };

    class Story290 : public Story::Base
    {
    public:
        Story290()
        {
            BookID = Book::Type::BOOK1;

            ID = 290;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The sister bows as you present her with the letter, and immediately escorts you into the chamber of the God King. The king takes the letter, glancing over it with a casual eye. Long before he could have finished reading it, he stands.\n\n\"Yes, this is the Everchild as I remember her,\" nods the God King. \"I officially place the armies of Chalice at her disposal. My kensai warriors shall attend her, a full five hundred men. An additional six hundred archers shall provide her with support. Once she is queen, we shall defer our city to her policies as they relate to all international affairs.\"\n\nYou are dumbstruck. Could the God King really have changed his mind from a quick glance at a letter? Or has he received council since your last meeting and was going to back the Everchild no matter what? You suppose you shall never know.\n\nYou thank the God King for his support, leaving the chamber in amazement at your success.\n\nYou may add the following soldiers to the Luutanesh barracks:\n\n[Kensai Warriors]: Strength 4, Morale 4\n[Chalice Archers]: Strength 2, Morale 3\n\nGaining the God King's support has been quite an endeavour.\n\nNote: You gained the code A20.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Charisma", {Book::Type::BOOK1, 450}, Choice::Type::ROLL_FOR_ATTRIBUTE_INCREASE, {Attribute::Type::CHARISMA}, 1, 2, 0));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::BEAUTIFUL_LETTER});

            auto location = Location::Type::LUUTANESH;

            if (Engine::VERIFY_CODES(party, {Codes::Type::QUEEN_IN_SALTDAD}))
            {
                location = Location::Type::SALTDAD;
            }

            Army = {
                Army::Base("Kensai Warriors", Army::Type::KENSAI_WARRIORS, location, 4, 4),
                Army::Base("Chalice Archers", Army::Type::CHALICE_ARCHERS, location, 2, 3)};

            Engine::GET_CODES(party, {Codes::A(20)});
        }
    };

    class Story291 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story291()
        {
            BookID = Book::Type::BOOK1;

            ID = 291;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            party.CurrentCharacter = Engine::FIND_SOLO(party);

            auto target = -1;

            if (Engine::IS_ACTIVE(party, party.CurrentCharacter))
            {
                target = party.CurrentCharacter;
            }
            else if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                target = party.LastSelected;
            }

            PreText = "Tommul replies with a punch to your jaw, which sends you crashing to the ground. This is followed by savage kicks from his companion.\n\n";

            if (target >= 0 && target < party.Members.size())
            {
                PreText += std::string(party.Members[target].Name) + " loses 3 Health points.";

                Engine::GAIN_HEALTH(party.Members[target], -3);

                if (Engine::SCORE(party.Members[target], Attribute::Type::HEALTH) > 0)
                {
                    Bye = "You nurse your wounds grudgingly, muttering words of revenge under your breath.";
                }
            }
            else
            {
                PreText += "You lose 3 Health points.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 157}; }
    };

    class Story292 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story292()
        {
            BookID = Book::Type::BOOK1;

            ID = 292;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Type = Story::Type::NORMAL;

            PreText = "The remaining members of your party are in grief at the loss of their comrades.";

            if (Engine::COUNT(party) > 1)
            {
                PreText += " You must make another attempt to get the weapons.";
            }
            else
            {
                Type = Story::Type::DOOM;

                PreText += " They shall die a slave in this foul arena.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 191}; }
    };

    class Story293 : public Story::Base
    {
    public:
        Story293()
        {
            BookID = Book::Type::BOOK1;

            ID = 293;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You utter the word 'amora' and there is a great clunk from the vault. Suddenly it swings smoothly open. You elate -- the treasures of Unbraaki are all yours!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 416}; }
    };

    class Story294 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story294()
        {
            BookID = Book::Type::BOOK1;

            ID = 294;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            party.CurrentCharacter = Engine::FIND_SOLO(party);

            auto target = -1;

            if (Engine::IS_ACTIVE(party, party.CurrentCharacter))
            {
                target = party.CurrentCharacter;
            }
            else if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                target = party.LastSelected;
            }

            PreText = "The rest of the party think you mad, but you are resolved that this peasant should not suffer because of you. The man is released, desperately pleading his thanks, before fleeing from the hall.\n\nLothor is a sadistic man and makes you suffer. ";

            if (target >= 0 && target < party.Members.size())
            {
                PreText += std::string(party.Members[target].Name) + " loses";

                Engine::GAIN_HEALTH(party.Members[target], -2);

                Engine::GAIN_STATUS(party.Members[target], Character::Status::LOST_FINGERNAILS);
            }
            else
            {
                PreText += "You lose";
            }

            PreText += " 2 points of Health and 1 point of Fighting skill, as wielding a weapon without fingernails is agony. After removing five nails Lothor seems pleased with himself, and graciously lets you keep the nails on the other hand.\n\nYou stagger, wincing from the hall, your companions holding you up. The peasant you saved is nowhere to be found. Perhaps you will get your reward in paradise?\n\nNote: You gained the code A34.";

            Engine::GET_CODES(party, {Codes::A(34)});

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story295 : public Story::Base
    {
    public:
        Story295()
        {
            BookID = Book::Type::BOOK1;

            ID = 295;

            Text = "\"Nah, I won't tell you nothin',\" says the ogre. \"In fact -- I think I'll bash your heads in, just to be on the safe side.\" It seems diplomacy is over ...";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 117}; }
    };

    class Story296 : public Story::Base
    {
    public:
        Story296()
        {
            BookID = Book::Type::BOOK1;

            ID = 296;

            Location = Location::Type::SALT_MINES;

            Text = "Long before you reach their lair the troglodytes intercept you. There are five of them... fierce odds, given the accuracy of their snatching claws. You gird yourselves for battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            Take.clear();

            Limit = 0;

            Monsters = {
                Monster::Base("Troglodyte", 4, 3, 4, 8, 0),
                Monster::Base("Troglodyte", 2, 3, 4, 4, 0),
                Monster::Base("Troglodyte", 3, 3, 4, 3, 0),
                Monster::Base("Troglodyte", 3, 3, 4, 3, 0),
                Monster::Base("Troglodyte", 2, 3, 4, 5, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 135}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Take = {Equipment::TROGLODYTE_HEAD, Equipment::TROGLODYTE_HEAD, Equipment::TROGLODYTE_HEAD, Equipment::TROGLODYTE_HEAD, Equipment::TROGLODYTE_HEAD, Equipment::SHIELD2, Equipment::INCENSE};

                Limit = 7;

                Engine::GAIN_MONEY(party, 40);

                Engine::GET_CODES(party, {Codes::A(26)});

                Bye = "Pleased with yourselves you leave the fourteenth level.\n\nNote: You gained the code A26.";
            }
        }
    };

    class Story297 : public Story::Base
    {
    public:
        Story297()
        {
            BookID = Book::Type::BOOK1;

            ID = 297;

            Text = "You are attacking at a distance and the barbarians have no bows.\n\nNote: Your spellcasters can make an extra attack in the first round of combat, as long as that attack is used to cast some sort of spell. After the extra attacks, resolve the battle as normal.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            Take.clear();

            Limit = 0;

            Monsters = {
                Monster::Base("Lhasbreath Barbarians", 9, 5, 3, 16, 0),
                Monster::Base("Barbarian Leader", 4, 4, 4, 7, 0)};

            for (auto i = 0; i < party.Members.size(); i++)
            {
                if (party.Members[i].SpellCaster && Engine::SCORE(party.Members[i], Attribute::Type::HEALTH) > 0)
                {
                    Engine::GAIN_STATUS(party.Members[i], Character::Status::EXTRA_MAGIC_ROUND0);
                }
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 135}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Engine::GAIN_MONEY(party, 20);
            }
        }
    };

    class Story298 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story298()
        {
            BookID = Book::Type::BOOK1;

            ID = 298;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "It is only several minutes after the last blow is struck that you can be sure that the battle has finally ended. Finally, you sheathe your weapons and attempt to claim as much treasure from the magically darkened chamber as you can.";

            if (Engine::SPELLCASTERS(party) < 1)
            {
                PreText += "\n\nYou manage to grasp 15 silver coins before groping your way to the chamber exit and making your way further into the temple.";

                Engine::GAIN_MONEY(party, 15);
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::SPELLCASTERS(party) > 0)
            {
                return {Book::Type::BOOK1, 810};
            }
            else
            {
                return {Book::Type::BOOK1, 93};
            }
        }
    };

    class Story299 : public Story::Base
    {
    public:
        Story299()
        {
            BookID = Book::Type::BOOK1;

            ID = 299;

            Text = "You follow the scholars and Emlyn Pass-Ross up the steps of the pyramid. They are astonished by their discovery, chattering to themselves excitedly about the interesting blooms and fragrances. It all happens so fast... secret doors in the sides of the pyramids open, and terrible snakemen come slithering through. Most your party manage to intercept them, but one scholar has her head cut clean off before you can leap to her defence.";

            Bye = "Pushing the remaining scholars behind you, you draw your weapons and prepare to hold off the attack.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Book1::LOST_SCHOLAR(party);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 150}; }
    };

    class Story300 : public Story::Base
    {
    public:
        Story300()
        {
            BookID = Book::Type::BOOK1;

            ID = 300;

            Text = "You are about to fight in a Mass Combat. This involves hundreds of soldiers clashing on the field of battle. Each unit represents around five hundred soldiers. In any given battle you can bring a maximum of six units from your barracks. It will probably help if you record the location of your units, and those of your enemy, on the Battlefield section on your adventure sheet.\n\nTo win a Mass Combat you must control two out of three combat zones. The zones are called Left Flank, Centre and Right Flank. You control a zone when you have units in it, but your opponent does not. As soon as either you or the enemy general controls two zones the battle immediately ends. Any enemy units in the remaining zone will rout and flee as soon as it becomes obvious that one side has won.\n\nUnits have two attributes -- Strength and Morale. Strength shows how good the unit is at fighting, and Morale demonstrates how well a unit can cope with upsets such as casualties and enemy magic. Before the battle you must arrange your units on the battlefield. You can put a maximum of two units into each zone (Left Flank, Centre and Right Flank). One unit is put at the Front -- preferably a unit with a high Strength score -- and the second unit is put behind in Support. The Support unit is there to take over the fight if the unit at the Front routs (runs away!). You can see where the enemy have deployed their units, so try to match or beat the Strength score of the enemy unit at the Front in each zone.\n\nOnce you have assigned your units the battle will begin. You will fight in each zone, starting in the Left Flank, moving to the Centre, and then fighting on the Right Flank. If you have any spellcasters who can cast Mass Combat spells, each caster can cast a single spell just before the combat starts. If you have any spells left over, you can cast again each time you are about to fight on the Left Flank.\n\nStarting with the enemy unit at the Front on the Left Flank, roll a die and add that unit's Strength score to the result. This is the unit's battle score. Now do the same for your own unit at the front. If your battle score is higher than the enemy's, the enemy must make a morale check. If the enemy's score is higher, you must make a morale check. If the results are equal the fight is inconclusive -- move onto the next zone.\n\nTo make a morale check, roll a die and compare it to the defeated unit's Morale score. If the result is higher, that unit immediately routs. Cross it off the battlefield! If the result is equal or lower than the unit's Morale score the unit does not rout -- but it does lose a point of Morale. The more often a unit checks morale, the lower its morale becomes.\n\nIf a unit routs, the unit behind it in support can immediately take its place. If there is no unit in support, then the zone is lost.\n\nKeep fighting, moving from zone to zone, until either you or your opponent controls two zones. Units in Support do not fight until the unit at the Front has routed -- at that point the unit in Support moves to the Front. As soon someone controls two zones the battle is over.";

            Choices.clear();

            Controls = Story::Controls::NONE;
        }
    };

    class Story301 : public Story::Base
    {
    public:
        Story301()
        {
            BookID = Book::Type::BOOK1;

            ID = 301;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::COUNT(party, Team::Type::EVERCHILD_SECURITY) > 0)
            {
                return {Book::Type::BOOK1, 648};
            }
            else
            {
                return {Book::Type::BOOK1, 591};
            }
        }
    };

    class Story302 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story302()
        {
            BookID = Book::Type::BOOK1;

            ID = 302;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            party.CurrentCharacter = Engine::FIND_SOLO(party);

            auto target = -1;

            if (Engine::IS_ACTIVE(party, party.CurrentCharacter))
            {
                target = party.CurrentCharacter;
            }
            else if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                target = party.LastSelected;
            }

            PreText = "You are grabbed and pulled to the floor. Tommul and his brutish friend beat you with clubs until the shouts of the guards chase them away.\n\n";

            if (target >= 0 && target < party.Members.size())
            {
                PreText += std::string(party.Members[target].Name) + " loses 3 Health points.";

                Engine::GAIN_HEALTH(party.Members[target], -3);

                if (Engine::SCORE(party.Members[target], Attribute::Type::HEALTH) > 0)
                {
                    Bye = "You nurse your wounds grudgingly, muttering words of revenge under your breath.";
                }
            }
            else
            {
                PreText += "You lose 3 Health points.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 157}; }
    };

    class Story303 : public Story::Base
    {
    public:
        Story303()
        {
            BookID = Book::Type::BOOK1;

            ID = 303;

            Text = "You climb back out of the pit on the far side. Why risk crossing a rickety plank when a little caution can keep life and limb intact? You smartly continue down the tunnel.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 686}; }
    };

    class Story304 : public Story::Base
    {
    public:
        Story304()
        {
            BookID = Book::Type::BOOK1;

            ID = 304;

            Text = "It will be no easy matter to sneak into the palace. Unbraaki is well-guarded and probably protects himself with powerful sorcery. You wait until nightfall to give you cover. The palace is dark except for a single light in the library. Now is your chance, and you scamper through the garden, ducking behind bushes and fountains on your way to the palace.";

            Choices.clear();
            Choices.push_back(Choice::Base("Sneak through the garden (Team check: Stealth 4+, Successes: 5)", {Book::Type::BOOK1, 871}, {Book::Type::BOOK1, 632}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::STEALTH}, 4, 5));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story305 : public Story::Base
    {
    public:
        Story305()
        {
            BookID = Book::Type::BOOK1;

            ID = 305;

            Text = "With a low clunk the window pops open. You crawl inside, opening the other window using the latch. Brekken and his gang are soon inside.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 116}; }
    };

    class Story306 : public Story::Base
    {
    public:
        std::string PreText = "";

        Engine::Destination destination = {};

        Story306()
        {
            BookID = Book::Type::BOOK1;

            ID = 306;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            Limit = 0;

            Monsters.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(65)}))
            {
                PreText = "The room beyond is different from the others. It is a rough chamber, cut from the living rock, rather than a flagstone and brick room. Inside you can see, piled up, many crudely manufactured crates. These appear to be the orc's supplies, shipped all the way from the Savage Lands. Before them a pack of savage hounds have been left on guard, attached to long chains that will not let them leave the room, but gives them free reign to attack intruders. They bark and snarl at you, but with their masters dead you have little to fear from the noise. If you want the supplies you will have to deal with the hounds...\n\nNote: You can cast any number of spells before combat starts, as the chained hounds cannot reach you through the door.";

                CanFlee = true;

                Monsters = {
                    Monster::Base("Warhound", 4, 4, 4, 5, 0),
                    Monster::Base("Warhound", 3, 4, 4, 4, 0),
                    Monster::Base("Warhound", 4, 4, 4, 6, 0)};

                for (auto i = 0; i < party.Members.size(); i++)
                {
                    if (party.Members[i].SpellCaster && Engine::SCORE(party.Members[i], Attribute::Type::HEALTH) > 0)
                    {
                        Engine::GAIN_STATUS(party.Members[i], Character::Status::UNLIMITED_MAGIC_ROUND0);
                    }
                }
            }
            else
            {
                PreText = "This chamber is empty.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                destination = {Book::Type::BOOK1, 816};
            }
            else if (result == Engine::Combat::FLEE)
            {
                destination = {Book::Type::BOOK1, 736};
            }
        }
    };

    class Story307 : public Story::Base
    {
    public:
        Story307()
        {
            BookID = Book::Type::BOOK1;

            ID = 307;

            Text = "Finally, after days of wandering you collapse, helpless into the dry sands. You fear death will take you. What happens later is scarcely much better. A patrol of guards from Clifftop come across your nearly dead bodies. Seeing the opportunity to make a quick coin, they decide to sell you into slavery.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 55}; }
    };

    class Story308 : public Story::Base
    {
    public:
        Story308()
        {
            BookID = Book::Type::BOOK1;

            ID = 308;

            Text = "The door opens and you get to your feet, expecting to see the king and his councillors. Instead, five burly barbarians enter the room with weapons drawn. They quietly close the door behind them. \"Sorry, foreigners,\" apologises the tallest. \"But we've been paid three hundred silver coins to ensure you come to a sticky end. No offence. It's just business.\"\n\n\"None taken,\" you snarl, drawing your own weapons.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            Limit = 0;

            Monsters = {
                Monster::Base("Lhasbreath Barbarians", 6, 4, 3, 15, 0),
                Monster::Base("Barbarian Leader", 4, 4, 3, 8, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Take = {Equipment::IRON_GREATAXE2};

                Limit = 1;

                Engine::GAIN_MONEY(party, 300);
            }
        }
    };

    class Story309 : public Story::Base
    {
    public:
        Story309()
        {
            BookID = Book::Type::BOOK1;

            ID = 309;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Image = "images/book1/victory_over_ironking.png";

            Text = "With a mighty blow you cleave the Iron King's head from his shoulders. A mighty clang fills the hall as his heavy metal crown crashes to the floor. Standing outside the palace holding the bloody crown aloft you cry victory for the Everchild. In an instant the remaining forces of the old king disperse and surrender, and a great cheer goes up from your army. The day is won!\n\nThe Everchild is led into the palace in a great parade, tears of joy flowing from the oppressed citizens of Saltdad. She is merciful towards her defeated foes, sparing all but the worst offenders of the old regime. You have accomplished an action long predicted in legend. The Everchild once again sits on the throne of Saltdad. She could not have hoped to accomplish such a feat without you.\n\nThere follows a great celebration, the fat stores of the Iron King are broken open to hold a massive feast for the people. An elegant diadem upon her head, the Everchild finally looks the part of queen. Wine and food are consumed in great amounts, and songs are sung across the city. Your party's health scores are restored to maximum.\n\nNote: You gained the code A1.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose two party members and increase their maximum, unwounded Health score by 1 point", {Book::Type::BOOK1, 280}, Choice::Type::TEAM_MAX_HEALTH, 2, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::REST(party);

            Engine::GET_CODES(party, {Codes::A(1)});

            Engine::LOSE_CODES(party, {Codes::A(6), Codes::A(7)});

            if (Engine::IN_PARTY(party, Character::Type::AMELIA_PASS_DAYNE))
            {
                Choices[0].Destination = {Book::Type::BOOK1, 181};
            }
            else
            {
                Choices[0].Destination = {Book::Type::BOOK1, 280};
            }
        }
    };

    class Story310 : public Story::Base
    {
    public:
        Story310()
        {
            BookID = Book::Type::BOOK1;

            ID = 310;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You have reached a crossroads, with the corridor splitting off into four directions. To the north you make out a door in the eastern wall. The western branch of the corridor has a door in the north wall. The tunnels leads off into darkness to the south and east.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go through the door in the north tunnel", {Book::Type::BOOK1, 361}));
            Choices.push_back(Choice::Base("Go north, past the door, down the tunnel", {Book::Type::BOOK1, 634}));
            Choices.push_back(Choice::Base("Go through the door in the west tunnel", {Book::Type::BOOK1, 247}));
            Choices.push_back(Choice::Base("Go south", {Book::Type::BOOK1, 196}));
            Choices.push_back(Choice::Base("Go east", {Book::Type::BOOK1, 23}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story311 : public Story::Base
    {
    public:
        Story311()
        {
            BookID = Book::Type::BOOK1;

            ID = 311;

            Text = "Imopposh gives an unearthly howl before collapsing into piles of dust. You are relieved that the foul sorcerer has finally met his end.\n\nYour rewards are considerable. A MASTERWORK BLADE (Fighting +3) and some CHAIN ARMOUR (Armour +2) are stuffed into an urn, along with 900 silver coins. In an ancient wooden box stuffed underneath rotten funeral garbs you discover a GLITTERING NECKLACE (Charisma +2). You may also take a MAGICAL WEAVE from Imopposh's funeral bandages.\n\nNote: You gained the code A39.";

            Bye = "When you have finished your looting, you return to the desert.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(39)});

            Take = {Equipment::MASTERWORK_BLADE3, Equipment::CHAIN_ARMOUR2, Equipment::GLITTERING_NECKLACE2, Equipment::MAGICAL_WEAVE};

            Limit = 4;

            Engine::GAIN_MONEY(party, 900);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 115}; }
    };

    class Story312 : public Story::Base
    {
    public:
        Story312()
        {
            BookID = Book::Type::BOOK1;

            ID = 312;

            Text = "You quickly show the High Zealot your ring, before he can summon the guards. The zealot snarls and sits back down. \"I find it distasteful that the patriarch sees fit to employ such godless servants -- but his will be done. You may leave.\"";

            Bye = "You don't need to be told twice.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 574}; }
    };

    class Story313 : public Story::Base
    {
    public:
        Story313()
        {
            BookID = Book::Type::BOOK1;

            ID = 313;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "You stumble through the busy streets of Saltdad, pushed hither and thither by the bustling crowds. By accident you crash into a merchant carrying a box of nails and bolts, spilling his inventory across the dusty ground. Fortunately, he is a merry fellow and laughs the incident off. His name is Hammon, and once you have finished scrabbling in the dirt to retrieve his spilt goods, he insists you join him for a coffee at a local parlour to show there are no hard feelings.\n\nDrinking down the oddly bitter liquid you ask if there is any opportunity to earn money in the valley. \"Why, Saltdad itself is a city of boundless adventure and opportunity!\" exclaims Hammon. \"Try exploring the many streets and alleys of the city. There are plenty of people who need help these days. I've heard that the master of the salt mines to the north-east is looking for muscular sorts to help him with a few problems, so you might consider heading east if you'd like to avoid the city. If you're after a real adventure, I've heard tell that some crazy foreigners have set-up an Expeditionary Guild in the city of Lhasbreath. Apparently, they are searching the jungle for something, although what could be found in that green hell I cannot imagine!\"";

            Bye = "It is getting late. You thank Hammon for his courtesy and head into the centre of the city.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story314 : public Story::Base
    {
    public:
        Story314()
        {
            BookID = Book::Type::BOOK1;

            ID = 314;

            Text = "You utter your spell. In an instant the beetle swarm keels over and dies, destroyed utterly by your spell. Feeling overmighty, you stroll into the room, crushing the dead beetles underfoot as you go.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 251}; }
    };

    class Story315 : public Story::Base
    {
    public:
        Story315()
        {
            BookID = Book::Type::BOOK1;

            ID = 315;

            Location = Location::Type::BLACKWALL;

            Text = "You walk along the featureless black stone wall, your reflections on the mirror-bright surface following you. The wall seems endless, ahead and behind, and you feel as if you have been walking for days.";

            Choices.clear();
            Choices.push_back(Choice::Base("Keep following the wall", {Book::Type::BOOK1, 259}));
            Choices.push_back(Choice::Base("Break off from the wall and head north", {Book::Type::BOOK1, 858}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story316 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story316()
        {
            BookID = Book::Type::BOOK1;

            ID = 316;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "With a war cry, your forces overwhelm the Cursites, who flee into their city of black tombs. Alas, your battle is only half won. Now the fight must be carried into the city itself.\n\nNote: Your units do not get the chance to recover any lost morale points; they keep their current Morale values the same until the city is taken. Any units which have fled are not available for this battle.";

            Engine::REMOVE_ROUTED(party);

            Choices.clear();

            if (Engine::VERIFY_CODES(party, {Codes::Type::EVERCHILD_POISONED}))
            {
                PreText += "\n\nYou are relieved to see her emerge from her campaign tent, unscathed. She has apparently managed to cure herself, and her presence on the battlefield reassures many men.";

                Choices.push_back(Choice::Base("Choose a unit of your choice and raise its Morale by 1 point", {Book::Type::BOOK1, -316}, Choice::Type::GAIN_MORALE, Location::Type::SALTDAD, 1, 1));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, -316}; }
    };

    class Event316 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Event316()
        {
            BookID = Book::Type::BOOK1;

            ID = -316;

            DisplayID = 316;

            Text = "Now you fight again. You can choose up to six units from the Saltdad garrison. These can be units you used before, or fresh troops, or a combination of both. Descantos, if he is still alive, can cast no more spells -- so at least that is in your favour.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            EnemyArmy.clear();

            BattleLocation = Location::Type::SALTDAD;

            if (Engine::VERIFY_CODES(party, {Codes::A(96)}))
            {
                EnemyArmy.push_back(Army::Base("Cursite Citizens", Army::Type::CURSITE_CITIZENS, Location::Type::SALTDAD, Location::BattleField::LEFT_FLANK_FRONT, 2, 3, false));

                if (!Engine::VERIFY_CODES(party, {Codes::A(40)}))
                {
                    EnemyArmy.push_back(Army::Base("Cursite Zealots", Army::Type::CURSITE_ZEALOTS, Location::Type::SALTDAD, Location::BattleField::RIGHT_FLANK_FRONT, 4, 5, false));
                }
            }
            else
            {
                EnemyArmy.push_back(Army::Base("Mercenary Men-at-Arms", Army::Type::MERCENARY_MEN_AT_ARMS, Location::Type::SALTDAD, Location::BattleField::LEFT_FLANK_FRONT, 4, 2, false));
                EnemyArmy.push_back(Army::Base("Cursite Citizens", Army::Type::CURSITE_CITIZENS, Location::Type::SALTDAD, Location::BattleField::LEFT_FLANK_SUPPORT, 2, 3, false));

                if (!Engine::VERIFY_CODES(party, {Codes::A(40)}))
                {
                    EnemyArmy.push_back(Army::Base("Cursite Zealots", Army::Type::CURSITE_ZEALOTS, Location::Type::SALTDAD, Location::BattleField::RIGHT_FLANK_FRONT, 4, 5, false));
                    EnemyArmy.push_back(Army::Base("Mercenary Crossbows", Army::Type::MERCENARY_CROSSBOWS, Location::Type::SALTDAD, Location::BattleField::RIGHT_FLANK_SUPPORT, 2, 2, false));
                }
                else
                {
                    EnemyArmy.push_back(Army::Base("Mercenary Crossbows", Army::Type::MERCENARY_CROSSBOWS, Location::Type::SALTDAD, Location::BattleField::RIGHT_FLANK_FRONT, 2, 2, false));
                }
            }

            EnemyArmy.push_back(Army::Base("Temple Guard", Army::Type::TEMPLE_GUARD, Location::Type::SALTDAD, Location::BattleField::CENTER_FRONT, 5, 4, false));
            EnemyArmy.push_back(Army::Base("Citizen Archers", Army::Type::CITIZEN_ARCHERS, Location::Type::SALTDAD, Location::BattleField::CENTER_SUPPORT, 2, 4, false));
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                destination = {Book::Type::BOOK1, 363};
            }
            else
            {
                destination = {Book::Type::BOOK1, 220};
            }
        }
    };

    class Story317 : public Story::Base
    {
    public:
        Story317()
        {
            BookID = Book::Type::BOOK1;

            ID = 317;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Image = "images/book1/water_filled_archways.png";

            Text = "Time is of the essence. You quickly regroup with your companions and make your way down darkened tunnels to the dig-site. A tiny crawlspace has been painstakingly carved out of the wall, concealed by a few broken barrels. The Everchild, Che Long, and three other conspirators are here, delighted to see you as you come bearing armfuls of weapons. They have not been idle, securing torches and packs stuffed with waterskins and food supplies.\n\n\"What follows will not be easy,\" she warns. \"The tunnels are far from safe, but with your help we might just stand a chance.\"\n\nAt a nod from the Everchild, Che Long descends into the tunnel first, with you following tight behind. The flames from your torches lick the low roof of the hand-dug tunnel, and the space is claustrophobic in the extreme. To your delight the tunnel eventually breaks through into an ancient chamber, half-flooded, with two arched exits. The walls are painted in old flecks of colour, displaying an ancient city dominated by a tall palace.\n\n\"The palace of my ancestor still stands,\" notes the Everchild as she examines the decaying mural with you. \"Much of the rest of the city is little better than mud-brick hovels now. There is much work to be done.\"\n\nYou examine the exits from the chamber, one at the back of the water-logged chamber, which seems to descend down into yet more murky water.\n\n\"The dry exit looks the most logical -- but I wonder where the water-filled one leads?\" muses the Everchild.";

            Choices.clear();
            Choices.push_back(Choice::Base("Offer to scout out the watery arch", {Book::Type::BOOK1, 438}, Choice::Type::CHOOSE_PARTY_MEMBER));
            Choices.push_back(Choice::Base("Suggest you head through the safer, dryer archway", {Book::Type::BOOK1, 523}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story318 : public Story::Base
    {
    public:
        Story318()
        {
            BookID = Book::Type::BOOK1;

            ID = 318;

            Text = "You have returned to the door you forced open earlier.";

            Choices.clear();
            Choices.push_back(Choice::Base("Head north into the room beyond", {Book::Type::BOOK1, 494}));
            Choices.push_back(Choice::Base("Head south to the junction", {Book::Type::BOOK1, 350}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story319 : public Story::Base
    {
    public:
        Story319()
        {
            BookID = Book::Type::BOOK1;

            ID = 319;

            Text = "Milagros wails but does not weep as she is beaten, the guard stopping short as he sees the angry gazes of the other slaves. Departing in a hail of foul language, he leaves the bloodied and defiant child. You feel ungallant for not interfering, but strangely proud of Milagros for her bravery.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 700}; }
    };

    class Story320 : public Story::Base
    {
    public:
        Story320()
        {
            BookID = Book::Type::BOOK1;

            ID = 320;

            Text = "You emerge from the tent the next morning to a sad scene. Akihiro, your friend, lies dead in the sands -- his sword across his chest. You were unable, with raw terror, to leave the tent and assist him. You can only pray that he has found his peace at last. After burying him in the sands you move on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::KILL(party, Character::Type::AKIHIRO_OF_CHALICE);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 840}; }
    };

    class Story321 : public Story::Base
    {
    public:
        Story321()
        {
            BookID = Book::Type::BOOK1;

            ID = 321;

            Text = "You coldly sheathe your weapon, your companions bleeding into the flagstones and crumbling books around you. You push aside their bodies, sit and begin to read. You continue to read, unmoving, until death takes you.";

            Type = Story::Type::DOOM;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story322 : public Story::Base
    {
    public:
        Story322()
        {
            BookID = Book::Type::BOOK1;

            ID = 322;

            Text = "You approach the door carefully, examining the mystic runes carved around its edge.\n\nNote: Only those party members assigned to the door may contribute to this check.";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine the runes (Team check: Lore 4+, Successes: 4)", {Book::Type::BOOK1, 420}, {Book::Type::BOOK1, 464}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::MAGICAL_DOOR, {Attribute::Type::LORE}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story323 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story323()
        {
            BookID = Book::Type::BOOK1;

            ID = 323;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The keeper of the holy purse is in charge of tax administration, specifically the religious tithes paid by other cities. He is a fat, wealthy priest, who eyes you lazily as you enter.";

            if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::IRON_SCEPTRE}))
            {
                PreText += "\n\nThe keeper has no time for you, and has you pushed out of his office.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::IRON_SCEPTRE}))
            {
                return {Book::Type::BOOK1, 153};
            }
            else
            {
                return {Book::Type::BOOK1, 574};
            }
        }
    };

    class Story324 : public Story::Base
    {
    public:
        Story324()
        {
            BookID = Book::Type::BOOK1;

            ID = 324;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "The textureless sands swirl like dust on your boots. You feel cold and drained.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 1 Health", {Book::Type::BOOK1, -324}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event324 : public Story::Base
    {
    public:
        Event324()
        {
            BookID = Book::Type::BOOK1;

            ID = -324;

            DisplayID = 324;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "Where will you go?";

            Choices.clear();
            Choices.push_back(Choice::Base("North", {Book::Type::BOOK1, 692}));
            Choices.push_back(Choice::Base("West", {Book::Type::BOOK1, 73}));
            Choices.push_back(Choice::Base("South", {Book::Type::BOOK1, 273}));
            Choices.push_back(Choice::Base("East", {Book::Type::BOOK1, 886}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story325 : public Story::Base
    {
    public:
        Story325()
        {
            BookID = Book::Type::BOOK1;

            ID = 325;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You have entered the orc leader's war room. His body, and those of his followers, are still here.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go through the west door", {Book::Type::BOOK1, 736}));
            Choices.push_back(Choice::Base("Go through the south door", {Book::Type::BOOK1, 566}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story326 : public Story::Base
    {
    public:
        Story326()
        {
            BookID = Book::Type::BOOK1;

            ID = 326;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "The Saltdad slave markets sell flesh from all across the valley. Some are unfortunates who have crossed the jealous desert kings, others have been plucked, dying from dehydration, from the waterless wastes. Most are miserable-looking specimens in rags and heavy chains, but every so often a promising candidate will show up.\n\nNote: If you have fewer than four party members in your team, you may recruit some more from the slave market. It costs 200 silver coins to buy another party member, and they start with no equipment. A party member without a weapon has their Fighting score reduced by 1 point in combat.";

            Choices.clear();

            Controls = Story::Controls::RECRUIT;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story327 : public Story::Base
    {
    public:
        Story327()
        {
            BookID = Book::Type::BOOK1;

            ID = 327;

            Text = "You cannot expect to rob the patriarch twice and get away with it! As soon as your party have made it down the stairs you are pounced upon by dozens of guards in hiding. Those who dash up the stairs are cut off by another troop. You have been captured!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 55}; }
    };

    class Story328 : public Story::Base
    {
    public:
        Story328()
        {
            BookID = Book::Type::BOOK1;

            ID = 328;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The aftermath of the battle is bloody indeed. A dozen thieves, as well as one of the Everchild's men, lie dead. Reasoning that you might as well take the thieves' ill-gotten gains, you open the chests and crates to examine what kind of goods they had stolen. You count 75 silver coins, a REFERENCE BOOK (Lore +1), an ENGAGEMENT RING, as well as large amounts of clothes. Thinking quickly, you strip off your slave rags and change into more common garb, the Everchild and her followers doing the same.\n\nYou slip out of the thieves' hideaway and into the storm drains beneath the city.";

            Bye = "After an hour's wandering you eventually come to a ladder, leading up to a drain cover. You cautiously make your way upwards.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::REFERENCE_BOOK1, Equipment::ENGAGEMENT_RING};

            Limit = 2;

            Engine::GAIN_MONEY(party, 75);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 41}; }
    };

    class Story329 : public Story::Base
    {
    public:
        Story329()
        {
            BookID = Book::Type::BOOK1;

            ID = 329;

            Text = "The bridge creaks alarmingly as you put your weight on it. Nearby rice farmers shake their heads sadly before returning to their work.";

            Choices.clear();
            Choices.push_back(Choice::Base("Back out of crossing", {Book::Type::BOOK1, 442}));
            Choices.push_back(Choice::Base("Carefully cross", {Book::Type::BOOK1, 85}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story330 : public Story::Base
    {
    public:
        Story330()
        {
            BookID = Book::Type::BOOK1;

            ID = 330;

            Location = Location::Type::LUUTANESH;

            Text = "You present the Everchild with CALLIGRAPHY INK and ask her to write a letter to the God King of Chalice. She spends a full day working on her note, pleading for aid in a beautiful hand. The resultant BEAUTIFUL LETTER from the Everchild is a work of art.\n\n\"Let us hope that he likes what he sees,\" muses the Everchild. \"Thank you for pursuing this matter. I shall pray for your success.\"";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::CALLIGRAPHY_INK});

            Take = {Equipment::BEAUTIFUL_LETTER};

            Limit = 1;

            Engine::LOSE_CODES(party, {Codes::A(28)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 263}; }
    };

    class Story331 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story331()
        {
            BookID = Book::Type::BOOK1;

            ID = 331;

            Location = Location::Type::LHASBREATH;

            IsCity = true;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You pass by a number of Lhasbreath drinking halls, where the barbarians sing and dance to the sound of drums and flutes. A Lhasbreath maiden puts a garland of flowers around your neck, winking lewdly at you as you pass. The folk of this city seem to have no cares in the world!";

            if (!Engine::VERIFY_CODES(party, {Codes::A(1)}) || Engine::VERIFY_CODES(party, {Codes::A(90)}))
            {
                PreText += "\n\nYou stroll on past the merriment.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(1)}) && !Engine::VERIFY_CODES(party, {Codes::A(90)}))
            {
                return {Book::Type::BOOK1, 394};
            }
            else
            {
                return {Book::Type::BOOK1, 775};
            }
        }
    };

    class Story332 : public Story::Base
    {
    public:
        Story332()
        {
            BookID = Book::Type::BOOK1;

            ID = 332;

            Text = "You launch yourself through the window and tackle the thief to the ground, just before he reaches the rope. He kicks you away and begins to dash out of the door. The second party member who climbed the rope has now joined you in the room.";

            Choices.clear();
            Choices.push_back(Choice::Base("Chase the thief", {Book::Type::BOOK1, 573}));
            Choices.push_back(Choice::Base("Rifle through the bag left by the thief", {Book::Type::BOOK1, 868}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story333 : public Story::Base
    {
    public:
        Story333()
        {
            BookID = Book::Type::BOOK1;

            ID = 333;

            Text = "The guards grunt and uncross their spears. \"Go through, but we'll be watching you...\" they snarl. Nodding, you pass through into the cool palace.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 868}; }
    };

    class Story334 : public Story::Base
    {
    public:
        Story334()
        {
            BookID = Book::Type::BOOK1;

            ID = 334;

            Text = "Fastilon falls to the ground, quite dead, his glowing sword vanishing in his hand. He appears to be wearing nothing of value on his person, despite the power he summoned to fight you. Checking that the MADSHARDs are still in your possession, you return to the surface. Your workers have gone, scared away by the sounds of battle, leaving you alone amongst the ruins.\n\nNote: You gained the code A81.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            Limit = 0;

            if (Engine::COUNT_EQUIPMENT(party, {Equipment::Type::MADSHARD}) < 1)
            {
                Take.push_back(Equipment::MADSHARD);
            }

            if (Engine::COUNT_EQUIPMENT(party, {Equipment::Type::MADSHARD}) < 2)
            {
                Take.push_back(Equipment::MADSHARD);
            }

            Limit = Take.size();

            Engine::GET_CODES(party, {Codes::A(81)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 515}; }
    };

    class Story335 : public Story::Base
    {
    public:
        Story335()
        {
            BookID = Book::Type::BOOK1;

            ID = 335;

            Text = "Akihiro draws his sword and hurls it at the thrown dagger. There is a clang of steel as the sword knocks the dagger off target. Brash snatches Akihiro's sword as it deflects off the dagger, throwing it smoothly back to Akihiro who catches it by the hilt.\n\nBrash will not forget this.\n\nNote: Brash has gained a heart for Akihiro. Akihiro also gains a heart for Brash.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEARTS(party, Character::Type::BRASH, Character::Type::AKIHIRO_OF_CHALICE, 1);
            Engine::GAIN_HEARTS(party, Character::Type::AKIHIRO_OF_CHALICE, Character::Type::BRASH, 1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 60}; }
    };

    class Story336 : public Story::Base
    {
    public:
        Story336()
        {
            BookID = Book::Type::BOOK1;

            ID = 336;

            Text = "There is only room for one person in the team to make this attempt... careful now!";

            Choices.clear();
            Choices.push_back(Choice::Base("Assassinate the wizard (Individual check: Stealth 4+, Successes: 4)", {Book::Type::BOOK1, 655}, {Book::Type::BOOK1, 877}, Team::Type::ASSASSINATION_DESCANTOS, {Attribute::Type::STEALTH}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story337 : public Story::Base
    {
    public:
        Story337()
        {
            BookID = Book::Type::BOOK1;

            ID = 337;

            Location = Location::Type::LHASBREATH_RAPIDS;

            Text = "You punt hard to avoid some oncoming rocks, but overcompensate, sending the raft splintering onto a jagged rock just beyond. You leap aside into the frothy waters, gasping and splashing as you attempt to gain purchase. You watch in horror as one of the scholars is pulled under the water and does not emerge. It takes all your strength just to pull yourselves onto the heavily forested bank.\n\nYou have lost a scholar. Each party member loses 1 Health point.";

            Bye = "Bedraggled, you stagger into the thick jungle. You'll be on foot from here!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Book1::LOST_SCHOLAR(party);

            Engine::GAIN_HEALTH(party, -1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 501}; }
    };

    class Story338 : public Story::Base
    {
    public:
        Story338()
        {
            BookID = Book::Type::BOOK1;

            ID = 338;

            Text = "The ghastly screams of the man echo in your head long after his eyes have been torn from his skull. Lothor congratulates you for your choice of punishments, gifting you a purse of 20 silver coins, but you shall pay a hefty price spiritually. The gods despise a torturer -- from now on you cannot receive any blessings from any priest in the world.\n\nNote: You gained the code A34.";

            Bye = "Feeling dead inside, you depart.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 20);

            Engine::GET_CODES(party, {Codes::A(34)});
            Engine::GET_CODES(party, {Codes::Type::NO_BLESSINGS_FOREVER});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story339 : public Story::Base
    {
    public:
        Story339()
        {
            BookID = Book::Type::BOOK1;

            ID = 339;

            Location = Location::Type::BANDO_VILLAGE;

            Text = "The Bando are more sophisticated than they appear. You make a small exchange of gifts, a few coils of rope and a pair of hammers, and you are presented with flowery wreaths in exchange. The tribe holler their acceptance of you, and soon a kind of impromptu party begins, with wild dancing and sweet, fermented fruit drinks. As evening descends you are brought before the shaman.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 381}; }
    };

    class Story340 : public Story::Base
    {
    public:
        Story340()
        {
            BookID = Book::Type::BOOK1;

            ID = 340;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Image = "images/book1/city_of_cursus.png";

            Text = "The city of Cursus is a dominated by thirteen flat-topped step pyramids made of black stone. It is the spiritual and cultural centre of valley, the domain of the millennia-spanning worship of the god of judgement. Priests and worshipers, dressed in long black robes, are commonplace. Only those inducted into the church can have a profession or own property in the city, so displays of sombre piety are everywhere. Slaves and the faithless toil in the fields around the rushing Cold River, which feeds into a magnificent harbour. Sadly, for the city, all too few merchant vessels stop here. Cursus may be rich by the standards of the valley, but it has few trade goods to share with the outside world, and Clifftop tends to dominate the salt trade, being closer to the trade routes of Royce.\n\nDominating the centre of the city is the Grand Ziggurat, the political and financial centre of the city. From here the priests of Cursus calculate their taxes and work to expunge all other faiths in the valley.";

            Choices.clear();
            Choices.push_back(Choice::Base("Find an inn", {Book::Type::BOOK1, 201}));
            Choices.push_back(Choice::Base("Go to the marketplace", {Book::Type::BOOK1, 375}));
            Choices.push_back(Choice::Base("Go to the slave market", {Book::Type::BOOK1, 595}));
            Choices.push_back(Choice::Base("Visit the Grand Ziggurat", {Book::Type::BOOK1, 110}));
            Choices.push_back(Choice::Base("Visit a small temple of Cursus", {Book::Type::BOOK1, 272}));
            Choices.push_back(Choice::Base("Go to the harbour", {Book::Type::BOOK1, 33}));
            Choices.push_back(Choice::Base("Explore the city", {Book::Type::BOOK1, 369}));
            Choices.push_back(Choice::Base("Follow the Northroad out of the city", {Book::Type::BOOK1, 822}));
            Choices.push_back(Choice::Base("Go northeast, following the eastern bank of the river", {Book::Type::BOOK1, 625}));
            Choices.push_back(Choice::Base("Go west, into the desert", {Book::Type::BOOK1, 657}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            party.CurrentShip = -1;
        }
    };

    class Story341 : public Story::Base
    {
    public:
        Story341()
        {
            BookID = Book::Type::BOOK1;

            ID = 341;

            Text = "You sheathe your weapons and search through the coffin, somewhat gingerly given the amount of oozing fluid puddling in the bottom.\n\nYou manage to stomach extracting 240 silver coins and an AMULET OF DEFENCE (Armour +1). You also discover the FAIRBROTHER FAMILY CREST, which was tucked into corner covered in ooze-soaked cloth.\n\nTake what you wish.\n\nNote: You gained the code A58.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 240);

            Take = {Equipment::AMULET_OF_DEFENSE1, Equipment::FAIRBROTHER_FAMILY_CREST};

            Limit = 2;

            Engine::GET_CODES(party, {Codes::A(58)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 211}; }
    };

    class Story342 : public Story::Base
    {
    public:
        Story342()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::CLIFFTOP;

            ID = 342;

            Text = "King Lothor's forces collapse in disorder. There is a general rout, and a terrible crush at the bridge as the tyrant's forces all attempt to cross it at once. Your army closes in against the defenceless foe, caught between the river and destruction. Lothor is singled out and cut down by a common infantryman even as he attempts escape. Soon, the enemy have surrendered en-masse. The Everchild is victorious.\n\nNote: You gained the code A33.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(33)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 626}; }
    };

    class Story343 : public Story::Base
    {
    public:
        Story343()
        {
            BookID = Book::Type::BOOK1;

            ID = 343;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "You didn't think you went so far into the jungle... but when you tried to find your way out, you realised you had no idea where you were. You've become disorientated, and your supplies are getting low.";

            Choices.clear();
            Choices.push_back(Choice::Base("Find your way out of the jungle (Team check: Survival 4+, Successes: 4)", {Book::Type::BOOK1, 618}, {Book::Type::BOOK1, -343}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (outcome)
            {
                Bye = "You manage to reach the treeline.";
            }
            else
            {
                Bye = "Each party member loses 1 Health point.";

                Engine::GAIN_HEALTH(party, -1);
            }
        }
    };

    class Event343 : public Story::Base
    {
    public:
        Event343()
        {
            BookID = Book::Type::BOOK1;

            ID = -343;

            DisplayID = 343;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 343}; }
    };

    class Story344 : public Story::Base
    {
    public:
        Story344()
        {
            BookID = Book::Type::BOOK1;

            ID = 344;

            Location = Location::Type::SALT_MINES;

            Text = "You have returned to the dragon's lair, now long since looted. The tunnel the dragon made into the lands of Drakehallow is still here.";

            Choices.clear();
            Choices.push_back(Choice::Base("(Drakehallow) Follow the tunnel", {Book::Type::BOOK6, 33}));
            Choices.push_back(Choice::Base("Go back to the lift", {Book::Type::BOOK1, 135}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story345 : public Story::Base
    {
    public:
        Story345()
        {
            BookID = Book::Type::BOOK1;

            ID = 345;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The final skeleton shatters into pieces. With the bodies so damaged it will be impossible to animate them again using the book. Musing on the inconsistent nature of necromantic magic, you return to the crossroads.\n\nNote: You gained the code A75.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(75)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 310}; }
    };

    class Story346 : public Story::Base
    {
    public:
        Story346()
        {
            BookID = Book::Type::BOOK1;

            ID = 346;

            Location = Location::Type::CAVES_OF_URANU;

            Image = "images/book1/caves_of_uranu.png";

            Text = "You are on the eastern bank of the Cold River, a wide, life-giving waterway. To the north lies the beautiful city of Chalice. Abutting against the side of the river come a series of steep desert hills, riddled with caves said to contain hordes of vicious monsters.\n\nThese are the infamous Caves of Uranu, named after the valley-god of the underworld.";

            Choices.clear();
            Choices.push_back(Choice::Base("Explore the caves", {Book::Type::BOOK1, 493}));
            Choices.push_back(Choice::Base("Skirt around the caves and move on", {Book::Type::BOOK1, 445}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story347 : public Story::Base
    {
    public:
        Story347()
        {
            BookID = Book::Type::BOOK1;

            ID = 347;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You emerge into a tunnel that soon splits in two. One route leads down slightly, the other slopes up. Ancient writing crosses the walls, and the Everchild calls for more light as she examines it. \"The downward slope led to an old armoury,\" she comments. \"Upwards was a changing room. There is no indication which route leads out, however.\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Head down towards the armoury", {Book::Type::BOOK1, 242}));
            Choices.push_back(Choice::Base("Head upwards towards the changing room", {Book::Type::BOOK1, 883}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story348 : public Story::Base
    {
    public:
        Story348()
        {
            BookID = Book::Type::BOOK1;

            ID = 348;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "The vault door is wide open, its contents looted. There is nothing more to be found here.";

            Choices.clear();
            Choices.push_back(Choice::Base("Check out the room to the south", {Book::Type::BOOK1, 484}));
            Choices.push_back(Choice::Base("Leave the palace", {Book::Type::BOOK1, 265}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story349 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story349()
        {
            BookID = Book::Type::BOOK1;

            ID = 349;

            Location = Location::Type::LHASBREATH_OASIS;

            Image = "images/book1/bathe_in_oasis.png";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "For modesty's sake you divide yourselves into male and female groups, a bank of reeds providing cover between you, before stripping off and plunging into the cool waters. This has been your first bath since coming to valley, and the water feels glorious on your skin.";

            if (!Engine::IN_PARTY(party, Character::Type::TASHA))
            {
                PreText += "\n\nAfter scrubbing yourselves clean you emerge from the oasis refreshed and ready to continue your journey.";
            }

            PreText += "\n\nNote: Each party member recovers 2 Health points. You gained the code A44.";

            Engine::GET_CODES(party, {Codes::A(44)});

            Engine::GAIN_HEALTH(party, 2);

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::IN_PARTY(party, Character::Type::TASHA))
            {
                return {Book::Type::BOOK1, 802};
            }
            else
            {
                return {Book::Type::BOOK1, 51};
            }
        }
    };

    class Story350 : public Story::Base
    {
    public:
        Story350()
        {
            BookID = Book::Type::BOOK1;

            ID = 350;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You are in a short, well-trodden corridor with an open door in the west wall. A little beyond the door, the corridor splits, branching to the west and north. The north end of the corridor ends in a strong looking door with a red 'x' upon it. To the south, stairs lead up into brilliant daylight.";

            Choices.clear();
            Choices.push_back(Choice::Base("Exit the dungeon by going south, up the stairs", {Book::Type::BOOK1, 515}));
            Choices.push_back(Choice::Base("Check out the open door in the west wall", {Book::Type::BOOK1, 654}));
            Choices.push_back(Choice::Base("Head down the corridor west", {Book::Type::BOOK1, 566}));
            Choices.push_back(Choice::Base("Check out the door to the north", {Book::Type::BOOK1, 31}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story351 : public Story::Base
    {
    public:
        Story351()
        {
            BookID = Book::Type::BOOK1;

            ID = 351;

            Text = "You invoke the shadow door, and soon enough a dark portal opens up in the west wall. The chamber beyond looks as empty as the first, with no exits except for the shadow door you just conjured. A circular tunnel, about three feet wide, is raised four feet from the ground on the far wall. It seems to turn sharply upwards. Strange.";

            Choices.clear();
            Choices.push_back(Choice::Base("Close the shadow door", {Book::Type::BOOK1, 717}));
            Choices.push_back(Choice::Base("Examine the curved tunnel", {Book::Type::BOOK1, 224}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(60)}))
            {
                return {Book::Type::BOOK1, 527};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::CAST_SPELL(party, Team::Type::NONE, Spells::Type::SHADOW_DOOR);
        }
    };

    class Story352 : public Story::Base
    {
    public:
        Story352()
        {
            BookID = Book::Type::BOOK1;

            ID = 352;

            Text = "Heaving with steady progress, you eventually pull the great cogwheel from the sea and roll it into the boat. Your jollyboat floats low in the water, and you waste no time rowing it to shore. There is a great cheer from the harbour crew as you moor up. The harbourmaster gratefully presents you with a purse of 300 silver coins. Soon the cogwheel is cleaned up and reinstalled into the crane.\n\nNote: You gained the code A31.";

            Bye = "Waving the harbour crew goodbye you return to your ship.";

            Choices.clear();
            Choices.push_back(Choice::Base("Gain 1 point of Survival", {Book::Type::BOOK1, 82}, Choice::Type::ROLL_ATTRIBUTE_WITH_STATUS, {Character::Status::FOUND_COGWHEEL}, {Attribute::Type::SURVIVAL}, 1, 2, 0));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 300);

            Engine::LOSE_CODES(party, {Codes::A(32)});

            Engine::GET_CODES(party, {Codes::A(31)});
        }
    };

    class Story353 : public Story::Base
    {
    public:
        Story353()
        {
            BookID = Book::Type::BOOK1;

            ID = 353;

            Text = "The armoury is quiet at this time of night. A cluster of spears line the far wall, but it is the complete suit of BRONZE ARMOUR (Armour +4) that catches your eye. The rumours about its incredible durability are true, the magical armour is indeed stronger than the steel plate of Royce and weighs only half as much. Take it, if you wish.\n\nNote: You gained the code A9.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(9)}))
            {
                return {Book::Type::BOOK1, 427};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(9)});

            Take = {Equipment::BRONZE_ARMOUR4};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 424}; }
    };

    class Story354 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story354()
        {
            BookID = Book::Type::BOOK1;

            ID = 354;

            Location = Location::Type::CLIFFTOP;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "Clifftop was not built for sightseers. There are no monuments or grand constructions, bar the cliff-side crane that is designed to haul goods from the harbour below.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(35)}))
            {
                PreText += "\n\nYou come upon a young woman in a field being beaten by a pack of overseers. They idly kick her as she attempts to stand, and jeer at her for being lazy and worthless.\n\nNote: You gained the code A35.";

                Engine::GET_CODES(party, {Codes::A(35)});

                Choices.push_back(Choice::Base("Intervene", {Book::Type::BOOK1, 417}));
                Choices.push_back(Choice::Base("Leave the locals to their sport", {Book::Type::BOOK1, 19}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 581}; }
    };

    class Story355 : public Story::Base
    {
    public:
        Story355()
        {
            BookID = Book::Type::BOOK1;

            ID = 355;

            Text = "The mood is quiet and professional in the king's hall today. King Scarrenden acknowledges your arrival with a curt nod as he finishes his business with another councillor and asks your business in the hall.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::VERIFY_CODES_ANY(party, {Codes::A(1), Codes::A(7)}))
            {
                Choices.push_back(Choice::Base("Talk politics with the king", {Book::Type::BOOK1, 826}));
            }

            Choices.push_back(Choice::Base("Ask the king for a boon", {Book::Type::BOOK1, 834}));
            Choices.push_back(Choice::Base("Thank the king for his time and leave the hall", {Book::Type::BOOK1, 775}));
        }
    };

    class Story356 : public Story::Base
    {
    public:
        Story356()
        {
            BookID = Book::Type::BOOK1;

            ID = 356;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You enter a stale smelling cave with a heavy overhang, which plunges the tunnel beyond into darkness. Lighting your lanterns, you illuminate a pack of giant sand lizards shielding themselves from the noonday sun. With alien speed they bolt at you, eager for a good meal.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            Limit = 0;

            Monsters = {
                Monster::Base("Sand Lizard", 6, 3, 4, 8, 0),
                Monster::Base("Sand Lizard", 4, 3, 4, 9, 0),
                Monster::Base("Sand Lizard", 5, 3, 4, 10, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 395}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Take = {Equipment::LIZARD_HIDE};

                Limit = 1;
            }
        }
    };

    class Story357 : public Story::Base
    {
    public:
        Story357()
        {
            BookID = Book::Type::BOOK1;

            ID = 357;

            Text = "The old father is tearful with gratitude. \"I have no money to give you, obviously,\" he says. \"But I insist you have this. In my youth I travelled the world, and made a pilgrimage to Pendrilor, where St. Elias, the holiest man in the world, blessed this humble wooden talisman for me. It kept me safe from the grasp of undead horrors, but it's powers only work here in the Valley. Please, take it with my thanks.\"\n\nHe presses the TALISMAN of St. Elias into your hands. It is little more than a humble wooden pendant.\n\nTake it if you wish.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::TALISMAN_OF_ST_ELIAS};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story358 : public Story::Base
    {
    public:
        Story358()
        {
            BookID = Book::Type::BOOK1;

            ID = 358;

            Text = "You must climb the rope one at a time.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose what order you want your party to climb the rope, from first to last", {Book::Type::BOOK1, 255}, Choice::Type::SET_PARTY_ORDER));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story359 : public Story::Base
    {
    public:
        Story359()
        {
            BookID = Book::Type::BOOK1;

            ID = 359;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "Your trek through the jungle continues, moisture dripping from the long-leafed and hairy trees around you. Peering at her water-logged map, Emlyn Pass-Ross leads the way through the chittering rainforest. Eventually you become aware of movement above you. As you gaze upwards you see hundreds of small monkeys, each less than a foot high, leaping and howling through the treetops.\n\n\"Uh oh... trouble,\" mutters Emlyn as she beholds them.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::HAS_SPELL(party, {Spells::Type::ANIMAL_SPEECH}))
            {
                Choices.push_back(Choice::Base("Cast Animal Speech", {Book::Type::BOOK1, 496}));
            }

            Choices.push_back(Choice::Base("Hold up your hands and show the monkeys you mean them no harm", {Book::Type::BOOK1, 671}));
            Choices.push_back(Choice::Base("Make a run for it", {Book::Type::BOOK1, 879}));
        }
    };

    class Story360 : public Story::Base
    {
    public:
        Story360()
        {
            BookID = Book::Type::BOOK1;

            ID = 360;

            Location = Location::Type::LUUTANESH;

            Text = "You travel a few miles outside the village before coming to the Everchild's training grounds. Her soldiers are divided into two types. The guards of Luutanesh are easily the best, well-provisioned and equipped with hide armour and long spears. They are disciplined and well trained. The other half of her army are less impressive, peasants and freed slaves armed with crude weapons, and only a few with shields. They are eager, and evidently their morale is quite good. Still, you wouldn't want to use them in battle as anything except reserve troops.\n\n\"As they say in Royce, from small seeds mighty trees grow,\" quotes the Everchild. \"Still, I am eager for more soldiers. I will even accept foreign mercenaries if you have access to them. However, Lhasbreath and Chalice are your best bets in the short term.\"\n\nShe cocks her head thoughtfully. \"I find that I trust you well,\" she says. \"I am happy to launch the attack on Saltdad as soon as you think we have enough soldiers, and the Iron King is suitably diminished in power. We shall only have one chance, so choose our moment well.\"\n\nNote: You can note the following soldiers in your Army:\n\n[Luutanesh Spears]: Strength 3, Morale 3\n[Faithful Irregulars]: Strength 1, Morale 4\n\nThese forces are currently in Luutanesh garrison. You cannot transfer troops from the Luutanesh barracks without permission from the Everchild. Because the Everchild does not yet own a port city, you also cannot transfer troops you might own in other barracks to the Luutanesh barracks.";

            Bye = "At that she kisses you on your cheeks and departs for her chambers at the Cold River Inn.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Army = {
                Army::Base("Kensai Warriors", Army::Type::LUUTANESH_SPEARS, Location::Type::LUUTANESH, 3, 3),
                Army::Base("Chalice Archers", Army::Type::FAITHFUL_IRREGULARS, Location::Type::LUUTANESH, 1, 4)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 263}; }
    };

    class Story361 : public Story::Base
    {
    public:
        Story361()
        {
            BookID = Book::Type::BOOK1;

            ID = 361;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You open the door to discover a dark room with the bodies of four complete skeletons lying stretched out on long tables. At the back of the room is a large book, wide open, displaying a page full of strange chants and diagrams of skeletal bodies. The whole place gives you the creeps. There are no other exits from this room.";

            Choices.clear();
            Choices.push_back(Choice::Base("Smash the skeletons to pieces", {Book::Type::BOOK1, 97}));
            Choices.push_back(Choice::Base("Examine the book", {Book::Type::BOOK1, 8}));
            Choices.push_back(Choice::Base("Return to the crossroads", {Book::Type::BOOK1, 310}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(75)}))
            {
                return {Book::Type::BOOK1, 845};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story362 : public Story::Base
    {
    public:
        Story362()
        {
            BookID = Book::Type::BOOK1;

            ID = 362;

            Location = Location::Type::LUUTANESH;

            Text = "A senior priest steps forward and puts a hand on the shoulder of the taxman. \"Are you deranged?\" he asks. \"Can you not see that these are the agents of the queen?\"";

            Bye = "Grumbling his apologies, the taxman allows you to pass.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 458}; }
    };

    class Story363 : public Story::Base
    {
    public:
        Story363()
        {
            BookID = Book::Type::BOOK1;

            ID = 363;

            Location = Location::Type::CURSUS;

            Text = "With a final despairing cry, the Cursite forces surrender. There is nowhere left for them to run. They wail and weep at the loss of their city and their power, recoiling before the Everchild as if she was a burning brand.\n\nWasting no time, you accompany the Everchild into the Grand Ziggurat, your best soldiers by your side. You fully expect a bitter final showdown between the patriarch and the queen. You are almost disappointed as you enter the ceremonial chamber, to find the patriarch and his high priests dead by their own hands. Only a single priest remains alive, the dagger hovering uncertainly by his belly.\n\n\"These are sad findings, and not what I wished,\" says the Everchild, shaking her head. \"As for you, fellow, put down your knife. The war is done, and you have nothing to fear from me.\"\n\n\"I... cannot bear to watch you pull down the holy temples!\" he weeps.\n\n\"I shall do no such thing, to this or any other temple,\" says the Everchild firmly. \"Men may worship what gods they wish, from this day, old or new. And temples need priests. Will you abandon your god when he needs you the most?\"\n\nThe priest swallows and drops the dagger. The Everchild's handmaidens attend him as she walks towards the sacred throne. She nods to Che Long, who pushes the body of the patriarch from it. She seats herself with a satisfied smile, gazing across the halls that have oppressed the people for so long. Halls, which now, like every hall in the valley, she rules as absolute monarch.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 400}; }
    };

    class Story364 : public Story::Base
    {
    public:
        Story364()
        {
            BookID = Book::Type::BOOK1;

            ID = 364;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The eager guards take your distraction team away to a more private location. Hopefully this should give the other team enough time to carry out their task!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 456}; }
    };

    class Story365 : public Story::Base
    {
    public:
        Story365()
        {
            BookID = Book::Type::BOOK1;

            ID = 365;

            Location = Location::Type::CURSUS;

            Text = "You prowl silently through the night, unseen, past the many soldiers of Cursus. Soon you arrive at a dark green tent with glowing sigils woven into it. This must be it. You approach cautiously -- wizards are famed for using magical defences about their sleeping places.";

            Choices.clear();
            Choices.push_back(Choice::Base("Disenchant the wizard's tent (Team check: Lore 4+, Successes: 5)", {Book::Type::BOOK1, 32}, {Book::Type::BOOK1, 687}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::ASSASSINATION_DESCANTOS, {Attribute::Type::LORE}, 4, 5));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story366 : public Story::Base
    {
    public:
        Story366()
        {
            BookID = Book::Type::BOOK1;

            ID = 366;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You find yourselves in a long corridor that runs east-west. Three doors present themselves as ways onwards.";

            Choices.clear();
            Choices.push_back(Choice::Base("Take the door in the southern wall at the far eastern end of the corridor", {Book::Type::BOOK1, 717}));
            Choices.push_back(Choice::Base("Open the door in the middle corridor, also in the south wall, from which pleasant smells emerge", {Book::Type::BOOK1, 551}));
            Choices.push_back(Choice::Base("Open the door in the far west end of the corridor", {Book::Type::BOOK1, 821}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story367 : public Story::Base
    {
    public:
        Story367()
        {
            BookID = Book::Type::BOOK1;

            ID = 367;

            Text = "You draw your weapons. \"We will not let you harm grieving people,\" you say sharply. The kensai bow to you and draw their swords as one. This will be a tough fight.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {
                Monster::Base("Kensai", 6, 4, 4, 9, 0),
                Monster::Base("Kensai", 7, 4, 4, 8, 0),
                Monster::Base("Kensai", 6, 4, 4, 10, 0),
                Monster::Base("Kensai", 6, 4, 4, 9, 0),
                Monster::Base("Kensai Master", 8, 3, 5, 11, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 874}; }
    };

    class Story368 : public Story::Base
    {
    public:
        Story368()
        {
            BookID = Book::Type::BOOK1;

            ID = 368;

            Location = Location::Type::TUMBLESTONES;

            Text = "The stone blocks are so withered and aged it is impossible to get an exact fit between the blocks. After several failed attempts you give up, the inscribed spell making no sense to you. Perhaps you could try again later, when your magical knowledge has increased?";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 453}; }
    };

    class Story369 : public Story::Base
    {
    public:
        Story369()
        {
            BookID = Book::Type::BOOK1;

            ID = 369;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "You are walking through the Streel, a marketplace in Cursus that sells the most exclusive ornaments and clothing for the well-to-do. One stall is particularly impressive, stacked top to bottom with exotic birds in cages. Though you have no business in buying a bird, you cannot help but examine some of the fascinating (and noisy) specimens on sale. The seller, named Haatchi, is generous with his time, explaining where each creature came from and the lengths he had to go to acquire them.\n\n\"You look adventurous sorts,\" he grins. \"Perhaps you can help me resolve a commission? I've been trying to acquire a crier bird, a relatively rare specimen that lives in the Lhasbreath jungles. It is not much to look at, but its voice is so uncanny it almost sounds human. If you can retrieve one for me, there is 100 silver in it for you.\"";

            Choices.clear();
            Choices.push_back(Choice::Base("You have a CRIER BIRD", {Book::Type::BOOK1, 441}, {Equipment::CRIER_BIRD}));
            Choices.push_back(Choice::Base("promise to keep a look out for the bird, should you ever head out that way", {Book::Type::BOOK1, 340}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story370 : public Story::Base
    {
    public:
        Story370()
        {
            BookID = Book::Type::BOOK1;

            ID = 370;

            Location = Location::Type::LHASBREATH;

            Image = "images/book1/lhasbreath_jungle.png";

            Text = "You have come to the outskirts of a thick jungle that lies just to the west of Lhasbreath. It is too difficult to traverse far into the jungle without a proper expedition, but perhaps you might discover something interesting with a quick look.";

            Choices.clear();
            Choices.push_back(Choice::Base("See what you discover", {{4, NULL, {Book::Type::BOOK1, 701}}, {6, NULL, {Book::Type::BOOK1, 343}}, {7, NULL, {Book::Type::BOOK1, 598}}, {9, NULL, {Book::Type::BOOK1, 449}}, {12, NULL, {Book::Type::BOOK1, 547}}}, 2));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story371 : public Story::Base
    {
    public:
        Story371()
        {
            BookID = Book::Type::BOOK1;

            ID = 371;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You look around the chamber, attempting to puzzle out what the orcs were doing here. The tunnels they have cut lead in all directions, but end in disappointing dead ends. It has the feel of an expedition that was sure it was in the right place but didn't know exactly which way to go once they got here. Shrugging your shoulders, you make your way out of the cavern and back up the stairs.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 634}; }
    };

    class Story372 : public Story::Base
    {
    public:
        Story372()
        {
            BookID = Book::Type::BOOK1;

            ID = 372;

            Location = Location::Type::SALT_MINES;

            Text = "You step off the lift onto the top floor of the mine.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(1)}))
            {
                Choices.push_back(Choice::Base("Sell some TROGLODYTE HEADs to Clavod", {Book::Type::BOOK1, 233}, {Equipment::TROGLODYTE_HEAD}));
                Choices.push_back(Choice::Base("Make your way onwards", {Book::Type::BOOK1, 722}));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 722}; }
    };

    class Story373 : public Story::Base
    {
    public:
        Story373()
        {
            BookID = Book::Type::BOOK1;

            ID = 373;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Text = "You have returned to the sinister chamber where you found the SILVER SKULL. However, that grim artefact is now missing from its pedestal. There is nothing more to be found here, so you make your way back to the crossroads.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 46}; }
    };

    class Story374 : public Story::Base
    {
    public:
        Story374()
        {
            BookID = Book::Type::BOOK1;

            ID = 374;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The slaves merely laugh at you and push you away. Demoralised, you are forced to wait for your food like everyone else.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 118}; }
    };

    class Story375 : public Story::Base
    {
    public:
        Story375()
        {
            BookID = Book::Type::BOOK1;

            ID = 375;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "The marketplace of Cursus is strictly organised. The same family of food sellers have occupied the same stall locations for hundreds of years, and the more modern the good the further to the exterior of the market can be found the stall. Priests of Cursus occupy each stall, each uttering a solemn praise to their god before welcoming you curtly.";

            Choices.clear();

            Controls = Story::Controls::SHOP;
        }

        void Event(Party::Base &party)
        {
            Shop = {
                {Equipment::CRUDE_BLADE, 25, 10, -1, {}},
                {Equipment::MAUL, 50, 25, -1, {}},
                {Equipment::IRON_SHORTSWORD1, 200, 100, -1, {}},
                {Equipment::IRON_GREATAXE2, -1, 150, -1, {}},
                {Equipment::STEEL_LONGSWORD2, -1, 400, -1, {}},
                {Equipment::STEEL_GREATSWORD3, -1, 450, -1, {}},
                {Equipment::SHIELD2, 50, 25, -1, {}},
                {Equipment::HIDE_ARMOUR1, 70, 35, -1, {}},
                {Equipment::BONE_ARMOUR2, -1, 150, -1, {}},
                {Equipment::BRONZE_ARMOUR4, -1, 2000, -1, {}},
                {Equipment::SOFT_BOOTS1, 500, 250, -1, {}},
                {Equipment::REFERENCE_BOOK1, 500, 250, -1, {}},
                {Equipment::WARM_CLOAK1, -1, 250, -1, {}},
                {Equipment::HANDSOME_BROOCH1, -1, 250, -1, {}},
                {Equipment::PRYBAR, 100, 50, -1, {}},
                {Equipment::INCENSE, -1, 90, -1, {}},
                {Equipment::CALLIGRAPHY_INK, 2000, 1000, -1, {}},
                {Equipment::SILVER_IDOL, -1, 50, -1, {}},
                {Equipment::VIAL_OF_POISON, -1, 50, -1, {}},
                {Equipment::DRAGONYAK_HORN, -1, 35, -1, {}},
                {Equipment::LIZARD_HIDE, -1, 25, -1, {}}};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 340}; }
    };

    class Story376 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story376()
        {
            BookID = Book::Type::BOOK1;

            ID = 376;

            Location = Location::Type::LUUTANESH;

            Text = "You feel that you have done all you can to prepare the Everchild's forces for battle. You go into council with her and convince the queen to commit her soldiers. \"Very well,\" she says solemnly. \"May St. Elias guide our blades. Good luck, my generals.\"\n\nMustering your soldiers from the Luutanesh barracks, you begin your march across the Great Westroad to Saltdad, the sun hanging low in the sky. Soon enough the Iron King's forces intercept you, the ramshackle palace of Saltdad visible in the distance. The coward king himself has not deigned to take the field and has left governorship of his army in the hands of his generals.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            EnemyArmy.clear();

            BattleLocation = Location::Type::LUUTANESH;

            if (Engine::VERIFY_CODES(party, {Codes::A(8)}))
            {
                EnemyArmy.push_back(Army::Base("Peasant Levies", Army::Type::CURSITE_INFANTRY, Location::Type::LUUTANESH, Location::BattleField::CENTER_FRONT, 1, 1, false));
            }
            else
            {
                EnemyArmy.push_back(Army::Base("Bronzeguard", Army::Type::BRONZEGUARD, Location::Type::LUUTANESH, Location::BattleField::CENTER_FRONT, 5, 5, true));
                EnemyArmy.push_back(Army::Base("Peasant Levies", Army::Type::CURSITE_INFANTRY, Location::Type::LUUTANESH, Location::BattleField::CENTER_SUPPORT, 1, 1, false));
            }

            EnemyArmy.push_back(Army::Base("Spearmen of Saltdad", Army::Type::SPEARMEN_OF_SALTDAD, Location::Type::LUUTANESH, Location::BattleField::LEFT_FLANK_FRONT, 2, 2, false));
            EnemyArmy.push_back(Army::Base("Mercenary Swords", Army::Type::MERCENARY_SWORDS, Location::Type::LUUTANESH, Location::BattleField::RIGHT_FLANK_FRONT, 3, 2, false));
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                destination = {Book::Type::BOOK1, 214};
            }
            else
            {
                destination = {Book::Type::BOOK1, 670};
            }
        }
    };

    class Story377 : public Story::Base
    {
    public:
        Story377()
        {
            BookID = Book::Type::BOOK1;

            ID = 377;

            Text = "The thief reluctantly hands over 100 silver coins. When the rest of your party climb through the window, he also decides to throw in a HANDSOME BROOCH (Charisma +1) to discourage any further extortion.";

            Bye = "You slip away into the streets together, the thief soon vanishing from sight.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::HANDSOME_BROOCH1};

            Limit = 1;

            Engine::GAIN_MONEY(party, 100);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story378 : public Story::Base
    {
    public:
        Story378()
        {
            BookID = Book::Type::BOOK1;

            ID = 378;

            Text = "Kopu is astounded you have learned this forbidden language. \"You keep divine company, for the only man I know who understands the Drear tongue is St. Elias himself. He would not have taught you such a language unless the world itself was at stake.\"\n\nKopu waves his hands and a magical cabinet made of purple wood appears, floating in the air. From the cabinet he retrieves a CLOAK OF WONDER (all skills +3). \"Take it!\" he insists. \"And banish the darkness from our land once and for all!\" You vow to do so.\n\nNote: In addition, all injured party members are restored to full Health, as you spend many days resting in the tower whilst you teach the language to Kopu.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::Type::TAUGHT_KOPU_DREAR}))
            {
                return {Book::Type::BOOK1, 539};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::CLOAK_OF_WONDER3};

            Limit = 1;

            Engine::GET_CODES(party, {Codes::Type::TAUGHT_KOPU_DREAR});

            Engine::REST(party);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 539}; }
    };

    class Story379 : public Story::Base
    {
    public:
        Story379()
        {
            BookID = Book::Type::BOOK1;

            ID = 379;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You make your way down the pitch-black tunnel, relying on touching the damp walls to guide you. You emerge into a small cell, through which light streams weakly from a tiny arch high in the wall. In the cell you can see Che Long, your trainer, and several other gladiator slaves.\n\n\"Welcome, my students,\" bows Che Long. He indicates Milagros. \"You come in good company, I see.\"\n\n\"I believe we can trust these warriors,\" announces Milagros. \"Tell them the plan, Che Long.\"\n\n\"Do they know what they are letting themselves in for... who they fight for?\"\n\n\"We are all slaves here,\" you assure them. \"We fight for our freedom.\"\n\n\"That, and so much more,\" says Che Long, smiling. \"This is no mere slave girl. Standing before you is the reincarnation of the Everchild. The Queen of the Valley. The supreme sorceress herself.\"\n\nYou look down at the dirty blonde waif. She speaks well, but could she really be a queen? The Everchild is a figure of legend, a story told to squires and children. Milagros sees the doubt in your eyes and places a finger in the soul bowl. She withdraws it, and paints the walls with the thick soup, drawing strange symbols and wards which begin to pulse and move as if under their own power. To your astonishment she has drawn a spell upon the walls, filled with arcane power.\n\nWith a wave of her hands Milagros bathes your bodies in healing energies. Your party's Health scores are restored to full. Any of your characters that lost limbs, tongues or other organs, are restored. Any diseases or curses you are affected by are also removed.\n\nThere can be no doubt. This young slave girl is, if not the Everchild, certainly a sorceress of great power.\n\nNote: You can learn the following spell:\n\nSoothing Touch (Adventure or Combat)\n\nYour hands glow with divine energy. Choose one of your party members; they can restore 5 Health points.\n\nRecharge: 50 silver";

            Choices.clear();
            Choices.push_back(Choice::Base("Ask her how she came to be enslaved", {Book::Type::BOOK1, 629}));
            Choices.push_back(Choice::Base("Ask her about the escape plan", {Book::Type::BOOK1, 743}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Spells = {Spells::SOOTHING_TOUCH};

            //TODO: Cure lost limbs, diseases
            Engine::REST(party);

            Engine::REMOVE_STATUS(party, Character::Status::LOST_FINGERNAILS);
            Engine::REMOVE_STATUS(party, Character::Status::LOST_TONGUE);
        }
    };

    class Story380 : public Story::Base
    {
    public:
        Story380()
        {
            BookID = Book::Type::BOOK1;

            ID = 380;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "The door is unlocked and leads to a priest's sanctum. There is a small altar with a block of INCENSE and 15 silver coins on it. The place is tidy, but there are no comfortable bits of furniture such as chairs or tables here.";

            Bye = "With no other exits available, you make your way to the archway.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::INCENSE};

            Limit = 1;

            Engine::GAIN_MONEY(party, 15);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 806}; }
    };

    class Story381 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story381()
        {
            BookID = Book::Type::BOOK1;

            ID = 381;

            Location = Location::Type::BANDO_VILLAGE;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You sit before the shaman, a ghostly looking man with silver hair and skull-like white makeup, in the company of what looks like the chief and his most loyal warriors. Your packs are searched whilst the shaman casts strange incense into the firepit.";

            if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::MAGICAL_WEAVE}))
            {
                PreText += "\n\nAfter a full search of your packs the shaman shrugs and you are escorted back to your ship. You get the impression your audience with the Bando has come to an end.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::MAGICAL_WEAVE}))
            {
                return {Book::Type::BOOK1, 767};
            }
            else
            {
                return {Book::Type::BOOK1, 144};
            }
        }
    };

    class Story382 : public Story::Base
    {
    public:
        Story382()
        {
            BookID = Book::Type::BOOK1;

            ID = 382;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "The Temple of Kalu is nothing more than a pile of rubble. The religion has been decreed heresy by the patriarch of Cursus, and the temple has been torn down.";

            Bye = "Mystified at this barbaric zealotry, you return to the city centre.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(1)}))
            {
                return {Book::Type::BOOK1, 128};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story383 : public Story::Base
    {
    public:
        Story383()
        {
            BookID = Book::Type::BOOK1;

            ID = 383;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "Choose a party member to perform this stealthy manoeuvre. You drop down to your belly and wriggle through the open door as quietly as possible.";

            Choices.clear();
            Choices.push_back(Choice::Base("Sneak up on the orcs (Individual check: Stealth 5+, Successes: 2)", {Book::Type::BOOK1, 2}, {Book::Type::BOOK1, 2}, {Attribute::Type::STEALTH}, 5, 2));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            Bye = NULL;

            if (outcome)
            {
                if (Engine::IS_ACTIVE(party, party.LastSelected))
                {
                    temp_string = "Note: " + std::string(party.Members[party.LastSelected].Name) + " may attack the first orc twice in the first round.";

                    Bye = temp_string.c_str();

                    Engine::GAIN_STATUS(party.Members[party.LastSelected], Character::Status::ATTACK2_ENEMY0_ROUND0);
                }
                else
                {
                    Bye = "Note: Your stealthy character may attack the first orc twice in the first round.";
                }
            }
            else
            {
                Bye = "Note: The 1st Orc gets a free attack at the beginning of the battle on the party member who failed the stealth check.";

                Engine::GET_CODES(party, {Codes::Type::ENEMY1_FREEATTACK_ROUND0});
            }
        }
    };

    class Story384 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story384()
        {
            BookID = Book::Type::BOOK1;

            ID = 384;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            PreText = "You make your way to Dulcimer's house, a red-roofed cubical block of stone and rough cement in the wealthiest part of the city. The house is well guarded and the family large in number, with aunts, uncles, nieces and nephews in ample numbers attending Dulcimer as he receives you in the family hall.\n\n\"That witch has damaged my honour and made me look a fool!\" rages Dulcimer as you explain the purpose of your visit. \"She is a thief and a harlot! My sister has volunteered personally to deal the killing blow to her.\"\n\nDulcimer's sister, a thin and sinister woman with sharp eyebrows, looks positively excited at the prospect.";

            Choices.clear();

            if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::ENGAGEMENT_RING}))
            {
                PreText += "\n\nThis will require delicate negotiations indeed.";

                Choices.push_back(Choice::Base("Calm Dulcimer's Rage (Team check: Charisma 5+, Successes: 4)", {Book::Type::BOOK1, 204}, {Book::Type::BOOK1, 155}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 5, 4));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 83}; }
    };

    class Story385 : public Story::Base
    {
    public:
        Story385()
        {
            BookID = Book::Type::BOOK1;

            ID = 385;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "Hardly daring to breathe, your party member manages to step carefully across the chamber, avoiding every pressure plate and hidden tripwire. You may take the BLACK PRISM from the pedestal. You only hope it was worth the danger retrieving it!\n\nRetracing your steps with a heart-thumping precision, you manage to make it out of the chamber to the warm congratulations of your colleagues.\n\nNote: You gained the code A80.";

            Choices.clear();
            Choices.push_back(Choice::Base("Gain 1 point of Survival", {Book::Type::BOOK1, 310}, Choice::Type::LASTCHARACTER_ROLLS_FOR_ATTRIBUTEINCREASE, {Attribute::Type::SURVIVAL}, 1, 2, 0));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::BLACK_PRISM};

            Limit = 1;

            Engine::GET_CODES(party, {Codes::A(80)});
        }
    };

    class Story386 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Team::Type previousTeam = Team::Type::NONE;

        int character = -1;

        Story386()
        {
            BookID = Book::Type::BOOK1;

            ID = 386;

            Image = "images/book1/akihiro_battles_monk.png";

            Text = "You inform your companions to stand aside.\n\nGazing directly into the eyes of the opposing monks you strip away your weapon belt and throw it to the side. Armed only with your fists you approach, the monks adopting fighting stances.\n\nNote: Because you have no weapon for this fight, you cannot add any Fighting bonus a weapon can give you. However, because you are familiar with the unarmed combat style of the monks, you do not lose a point of Fighting for having no weapon.\n\nNote: Only Akihiro may engage in this battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::AKIHIRO_OF_CHALICE;

            character = Engine::FIND_CHARACTER(party, Character::Type::AKIHIRO_OF_CHALICE);

            if (Engine::IS_ACTIVE(party, character))
            {
                previousTeam = party.Members[character].Team;

                Engine::SET_TEAM(party.Members[character]);

                Monsters = {Monster::Base("Monks", 5, 4, 4, 8, 0)};

                Engine::GAIN_STATUS(party.Members[character], Character::Status::UNARMED_COMBAT);
            }
            else
            {
                Monsters.clear();
            }
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                if (Engine::IS_ACTIVE(party, character))
                {
                    Engine::SET_TEAM(party.Members[character], previousTeam);
                }

                destination = {Book::Type::BOOK1, 9};
            }
            else
            {
                if (character >= 0 && character < party.Members.size())
                {
                    party.Members[character].Health = 1;
                }

                destination = {Book::Type::BOOK1, 596};
            }
        }
    };

    class Story387 : public Story::Base
    {
    public:
        Story387()
        {
            BookID = Book::Type::BOOK1;

            ID = 387;

            Text = "As soon as you show the ring, the guards become humble. \"Forgive us, great ones, we did not know!\" they whisper. \"Naturally, you may pass!\"";

            Bye = "Hoping your cover will not be blown, your party makes its way inside.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 574}; }
    };

    class Story388 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story388()
        {
            BookID = Book::Type::BOOK1;

            ID = 388;

            Location = Location::Type::SALT_MINES;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The mine lift creaks loudly as you reach the thirteenth floor.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(25)}))
            {
                PreText += "\n\nYou speak to the miners, asking them about recent attacks. They confirm that there have been a few, but that the troglodytes have been hiding in the deep tunnels to avoid the attention of the guards. Clearly you will have to flush them out!";

                Choices.push_back(Choice::Base("Explore the thirteenth level (Team check: Survival 4+, Successes: 5)", {Book::Type::BOOK1, 446}, {Book::Type::BOOK1, -388}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 5));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 817}; }
    };

    class Event388 : public Story::Base
    {
    public:
        Event388()
        {
            BookID = Book::Type::BOOK1;

            ID = -388;

            DisplayID = 388;

            Text = "You only manage to bang your head on one of the low walls.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose the party member to lose 1 Health", {Book::Type::BOOK1, 135}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story389 : public Story::Base
    {
    public:
        Story389()
        {
            BookID = Book::Type::BOOK1;

            ID = 389;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You curse as three of the goblins bolt past you out of the south door. The other three goblins bear their teeth and lunge at you.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {
                Monster::Base("Goblin", 2, 4, 4, 3, 0),
                Monster::Base("Goblin", 3, 4, 4, 5, 0),
                Monster::Base("Goblin", 2, 4, 4, 4, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 650}; }
    };

    class Story390 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story390()
        {
            BookID = Book::Type::BOOK1;

            ID = 390;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The Bronzeguard live in a large, low compound with reinforced walls, just adjacent to the palace.\n\nGuards are everywhere, though servants flow through the gates, delivering food, water and other materials into the building.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(7)}) || Engine::VERIFY_CODES(party, {Codes::A(8)}))
            {
                PreText += "\n\nYou have no business here and depart once the guards start glowering at you across the street.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(7)}) && !Engine::VERIFY_CODES(party, {Codes::A(8)}))
            {
                return {Book::Type::BOOK1, 684};
            }
            else
            {
                return {Book::Type::BOOK1, 75};
            }
        }
    };

    class Story391 : public Story::Base
    {
    public:
        Story391()
        {
            BookID = Book::Type::BOOK1;

            ID = 391;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The thief lies dead at your feet. You may take his IRON SHORTSWORD (Fighting +1), his LEATHER ARMOUR (Armour +1) and a pair of SOFT BOOTS (Stealth +1). He also carries 30 silver coins. Eventually the city guards arrive and you inform them what has just happened. Fortunately, they have been looking for this thief for some time and so believe your story.\n\nThe thief's victim, a local magistrate, is delighted with your kindness. He promises to put in a good word with the authorities whilst you are in Chalice.\n\nNote: From now on, any time you have to make a Charisma skill check in the city of Chalice, you may pass it automatically.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::IRON_SHORTSWORD1, Equipment::LEATHER_ARMOUR1, Equipment::SOFT_BOOTS1};

            Limit = 3;

            Engine::GAIN_MONEY(party, 30);

            Engine::GET_CODES(party, {Codes::Type::CHARISMA_SUCCESS_CHALICE});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story392 : public Story::Base
    {
    public:
        Story392()
        {
            BookID = Book::Type::BOOK1;

            ID = 392;

            Text = "You make your way to the king's hall, a vast timber and stone structure which displays the heads and horns of terrible beasts. The hall is the living space of the King Scarrenden and his most trusted berserkers, and you are rudely shoved about by passing housecarls and beer wenches in the crowded space. The king himself is peering over the edge of a pit, where one of his warriors is being mauled to death by an angry sand bear. The king toasts the bear's victory with a flagon of frothy beer, much to the laughter of the assembled barbarians.\n\n\"What was his crime?\" you ask a passing wench.\n\n\"No crime, we don't feed criminals to bears,\" she laughs. \"He chose to fight the bear to impress the king. You can petition the king for aid if you display a great feat of strength.\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Offer to wrestle the bear", {Book::Type::BOOK1, 425}, Choice::Type::CHOOSE_PARTY_MEMBER));
            Choices.push_back(Choice::Base("Attempt to woo one of the king's most trusted councillors", {Book::Type::BOOK1, 86}));
            Choices.push_back(Choice::Base("Leave these savages to their amusement", {Book::Type::BOOK1, 775}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(82)}))
            {
                return {Book::Type::BOOK1, 355};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story393 : public Story::Base
    {
    public:
        Story393()
        {
            BookID = Book::Type::BOOK1;

            ID = 393;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The overseer is not present, but guards and servants walk by the door frequently. You need to be in and out as quickly as possible.\n\nNote: Multiple people might be spotted, so only one party member in the weapon stealing team can be chosen for this task.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::VERIFY_CODES(party, {Codes::Type::WEAPON_AND_DISTRACTION}))
            {
                Choices.push_back(Choice::Base("Steal the key (Individual check: Stealth 4+, Successes: 2)", {Book::Type::BOOK1, 147}, {Book::Type::BOOK1, 483}, {Attribute::Type::STEALTH}, 4, 2));
            }
            else
            {
                Choices.push_back(Choice::Base("Steal the key (Individual check: Stealth 4+, Successes: 2)", {Book::Type::BOOK1, 147}, {Book::Type::BOOK1, 483}, Team::Type::WEAPONS, {Attribute::Type::STEALTH}, 4, 2));
            }
        }
    };

    class Story394 : public Story::Base
    {
    public:
        Story394()
        {
            BookID = Book::Type::BOOK1;

            ID = 394;

            Text = "A surly group of barbarians begin pushing you, spoiling for a fight. In the background a weaselly looking man with a long knife observes the horseplay, his finger pressing to the top of his dagger meaningfully.";

            Choices.clear();
            Choices.push_back(Choice::Base("Push the barbarians back", {Book::Type::BOOK1, 435}));
            Choices.push_back(Choice::Base("Try to diffuse the situation", {Book::Type::BOOK1, 472}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story395 : public Story::Base
    {
    public:
        Story395()
        {
            BookID = Book::Type::BOOK1;

            ID = 395;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You are leaving the Caves of Uranu behind. Where will you go?";

            Choices.clear();
            Choices.push_back(Choice::Base("North, towards Chalice", {Book::Type::BOOK1, 450}));
            Choices.push_back(Choice::Base("South, towards Cursus", {Book::Type::BOOK1, 625}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story396 : public Story::Base
    {
    public:
        Story396()
        {
            BookID = Book::Type::BOOK1;

            ID = 396;

            Location = Location::Type::WEST_ROAD;

            Text = "There is no shelter and the storm lashes you cruelly.";

            Choices.clear();
            Choices.push_back(Choice::Base("Survive the Sandstorm (Team check: Survival 4+, Successes: 4)", {Book::Type::BOOK1, 569}, {Book::Type::BOOK1, 569}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (!outcome)
            {
                Bye = "Each party member loses 2 Health pointS.";

                Engine::GAIN_HEALTH(party, -2);
            }
            else
            {
                Bye = "You manage to bury yourselves in the sand until the storm abates.";
            }
        }
    };

    class Story397 : public Story::Base
    {
    public:
        Story397()
        {
            BookID = Book::Type::BOOK1;

            ID = 397;

            Location = Location::Type::WEST_ROAD;

            Text = "A great caravan of salt merchants, enroute to Clifftop, offer you their services. Their merchants have various odds and ends you might find useful. All prices are in silver coins.\n\nIf you have a ship docked in Clifftop, you can also buy up to three cargo units of Salt from the merchants for 500 silver coins each. They will deliver this cargo straight to your ship provided there is room for it.";

            Choices.clear();
            Choices.push_back(Choice::Base("Buy one cargo unit of SALT", {Book::Type::BOOK1, -397}, Choice::Type::DELIVER, {Cargo::Type::SALT}, Location::Type::CLIFFTOP, 500));
            Choices.push_back(Choice::Base("Buy two cargo units of SALT", {Book::Type::BOOK1, -397}, Choice::Type::DELIVER, {Cargo::Type::SALT, Cargo::Type::SALT}, Location::Type::CLIFFTOP, 1000));
            Choices.push_back(Choice::Base("Buy three cargo units of SALT", {Book::Type::BOOK1, -397}, Choice::Type::DELIVER, {Cargo::Type::SALT, Cargo::Type::SALT, Cargo::Type::SALT}, Location::Type::CLIFFTOP, 1500));
            Choices.push_back(Choice::Base("You have finished your trading", {Book::Type::BOOK1, 569}, Choice::Type::RESET_SHOP));

            Controls = Story::Controls::SHOP;

            ResetShop = true;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(21)}) && ResetShop)
            {
                return {Book::Type::BOOK1, 89};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            if (ResetShop)
            {
                Shop = {
                    {Equipment::CRUDE_BLADE, 25, 10, -1, {}},
                    {Equipment::MAUL, 50, 25, -1, {}},
                    {Equipment::SHIELD2, 50, 25, -1, {}},
                    {Equipment::INCENSE, 500, 90, 1, {Codes::A(21)}},
                    {Equipment::BLUESTONE, 400, 45, 1, {Codes::A(21)}},
                    {Equipment::TALISMAN_OF_ST_ELIAS, -1, 150, -1, {}}};

                ResetShop = false;
            }
        }
    };

    class Event397 : public Story::Base
    {
    public:
        Event397()
        {
            BookID = Book::Type::BOOK1;

            ID = -397;

            DisplayID = 397;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party) { return {Book::Type::BOOK1, 397}; }
    };

    class Story398 : public Story::Base
    {
    public:
        Story398()
        {
            BookID = Book::Type::BOOK1;

            ID = 398;

            Text = "Water gushes in through the ripped hole in your vessel. Your crew give a great cry and abandon ship, leaping into the frothing waves with a wail. You have scant seconds to prepare yourself to dive into the ocean.\n\nThere is nowhere to swim but the harbour.\n\nNote: Any character wearing or carrying a suit of armour or robes must discard it. In addition, you can carry no more than four items each before leaping into the sea -- any remaining items are lost (there is no time to conjure a magic cabinet). Each party member loses 2 Health points.";

            Bye = "After an exhausting swim, you manage to pull yourself onto the harbourside. Of your ship crew there is no sign.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::NO_VAULT_ACCESS});

            Engine::LOSE_ALL(party, Equipment::Class::ARMOUR);

            Engine::LOSE_ALL(party, Equipment::Class::ROBE);

            Engine::GAIN_HEALTH(party, -2);

            Engine::SINK_SHIP(party);

            Choices.clear();

            if (!Engine::VERIFY_EQUIPMENT_LIMIT(party, 4))
            {
                Choices.push_back(Choice::Base("Drop number of items down to 4", {Book::Type::BOOK1, 662}, Choice::Type::LIMIT_EQUIPMENT, 4));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 662}; }
    };

    class Story399 : public Story::Base
    {
    public:
        Story399()
        {
            BookID = Book::Type::BOOK1;

            ID = 399;

            Location = Location::Type::DESERT;

            Text = "\"Bless you strangers,\" murmurs the monkey. \"I knew there was kindness in human-folk. Alas, I have seen all too little of it. I was a slave of the devious sorcerer Unbraaki. He took me from my home and made me his apprentice. I longed to return to my family, but Unbraaki swore he would find me and slay my kin if I ever escaped. I fled into the desert, rather than endanger them, but the land could not sustain me.\"\n\n\"A sad tale,\" you say. \"We will avenge you if we can.\"\n\n\"He is a covetous man, but powerful,\" sighs the monkey. \"Avenge me by taking what was his. I alone know the password to enter his secret vault. It is 'amora'. Say that word, and the doors shall open. Goodbye friends...\"\n\nAt this the monkey closes his eyes and dies in your arms.\n\nNote: You gained the code A43.";

            Bye = "Burying the monkey in the desert, you make your way onwards.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::CAST_SPELL(party, Team::Type::NONE, Spells::Type::ANIMAL_SPEECH);

            Engine::GET_CODES(party, {Codes::A(43)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 125}; }
    };

    class Story400 : public Story::Base
    {
    public:
        Story400()
        {
            BookID = Book::Type::BOOK1;

            ID = 400;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "The plaza in the temple district is full. Soldiers and diplomats from across the valley fill it, from sweaty Lhasbreath Barbarians to dignified Chalice scholars. Ayleta the Traveller leads a delegation from Clifftop, sun-bronzed peasants and sailors from that poorest of cities following in her wake. King Scarrenden of Lhasbreath grins widely, missing teeth on show, his housecarls and berserkers drinking deeply and cheering. The innkeep from Luutanesh engages Che Long in animated discussion. Priests of Cursus, grumbling under their breath, kneel before the throne.\n\nJoining the Everchild on the raised stage comes the God King of Chalice, elegant, eternally young and fit. The lord of that city kneels and bows before the small child who ascends a throne made of wood and bronze -- the final homage that acknowledges to all who the ruler of the valley truly is.\n\nThe Everchild sits and motions with her hand. A silence falls. \"The scholars tell us that there is no such thing as victory,\" she says, her voice amplifying by some sorcerous means. \"There are battles to be won and wars to be fought. But no vision of even the humblest ruler is ever truly realised. But there is such a thing as change. The Valley of Bones is now mine. Every city and every living being within them is my subject. From today we are no longer competitors, but brothers and sisters, driven not to exceed or dominate the others, but to strive to make our family strong. I see a vision of flourishing cities; I see the casting down of whips. I see a time when Royce and Drakehallow shall look with envy on our shores and say, 'if only our lands were as fair as those in the valley'. And well they might. No people are as vigorous or determined as ours. We shall be the crucible of new learning. Our many cultures shall create a land of beauty and flowers, and in time, the sun itself shall cease its scorching, and instead caress a land of meadows and rivers. I am the Everchild. And I shall be your ruler forever!\"\n\nThere is a mighty cheer, which resounds across the city and its dark mausoleums. A new day has come, and the Everchild is finally secure on her throne.\n\nNote: You have achieved a mighty feat in restoring the valley to the authority of the Everchild. Each party member increases their Health scores by 1 point.\n\nAny troops that were not routed returns to the Saltdad barracks. Their Morale and Strength scores to maximum.\n\nYou gained the code A100.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            // TODO: Rescue captured party members?

            Engine::RAISE_HEALTH(party, 1);

            Engine::GET_CODES(party, {Codes::A(100)});

            Engine::REMOVE_ROUTED(party);

            Engine::RESTORE_MORALE(party, Location::Type::SALTDAD);

            Engine::RESTORE_STRENGTH(party, Location::Type::SALTDAD);

            Choices.clear();

            if (Engine::VERIFY_CODES(party, {Codes::A(16), Codes::A(20), Codes::A(37), Codes::A(89)}))
            {
                Choices.push_back(Choice::Base("Each of your characters raises one skill by one point", {Book::Type::BOOK1, -400}, Choice::Type::PARTY_RAISE_ATTRIBUTE, 1));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, -400}; }
    };

    class Event400 : public Story::Base
    {
    public:
        Event400()
        {
            BookID = Book::Type::BOOK1;

            ID = -400;

            DisplayID = 400;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "The Everchild is generous and awards you 2000 silver coins.";

            Choices.clear();
            Choices.push_back(Choice::Base("Escort her back to Saltdad", {Book::Type::BOOK1, 75}));
            Choices.push_back(Choice::Base("Remain a while in Cursus", {Book::Type::BOOK1, 340}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 2000);
        }
    };

    class Story401 : public Story::Base
    {
    public:
        Story401()
        {
            BookID = Book::Type::BOOK1;

            ID = 401;

            Text = "Sar Jessica has a lingering strain in her arm from her last battle and is struggling to wash her back. Tasha volunteers to help, perhaps a little too eagerly. The knight is beautiful, noble-born with strong limbs and an air of authority. Tasha has often glanced at her across an inn room, when deep in her cups, with admiration and desire. Now Tasha is washing her, she cannot resist cradling her against her body, feeling her flesh against hers. Jessica acts as if nothing is going on, but surely she cannot be so blind to Tasha's affections?\n\nNote: Tasha has gained a heart for Sar Jessica. Sar Jessica also gains a heart for Tasha.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            Engine::GAIN_HEARTS(party, Character::Type::TASHA, Character::Type::SAR_JESSICA_DAYNE, 1);
            Engine::GAIN_HEARTS(party, Character::Type::SAR_JESSICA_DAYNE, Character::Type::TASHA, 1);
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::IN_PARTY(party, Character::Type::AMELIA_PASS_DAYNE) && Engine::HEARTS(party, Character::Type::AMELIA_PASS_DAYNE, Character::Type::TASHA) > 0)
            {
                return {Book::Type::BOOK1, 888};
            }
            else if (Engine::HEARTS(party, Character::Type::TASHA, Character::Type::SAR_JESSICA_DAYNE) >= 2 && Engine::HEARTS(party, Character::Type::SAR_JESSICA_DAYNE, Character::Type::TASHA) >= 2)
            {
                return {Book::Type::BOOK1, 726};
            }
            else
            {
                Bye = "The sound of the men on the other side of the reed bank getting out of the water ends this quiet moment and you blushingly emerge yourselves.";

                return {Book::Type::BOOK1, 51};
            }
        }
    };

    class Story402 : public Story::Base
    {
    public:
        Story402()
        {
            BookID = Book::Type::BOOK1;

            ID = 402;

            Text = "Throwing caution to the wind you pluck some flowers, keeping some in your pack, and perhaps wearing some in your hair. A little colour for your bleak desert trips. They are slightly magical, and it takes years for them to decay.";

            Bye = "Feeling slightly prettier you move on.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::HYGLIPH_FLOWER};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 618}; }
    };

    class Story403 : public Story::Base
    {
    public:
        Story403()
        {
            BookID = Book::Type::BOOK1;

            ID = 403;

            Location = Location::Type::CLIFFTOP;

            Text = "With the cargo crane in operation you can buy goods in Cargo Units from Clifftop. These goods are too large for your characters to carry, but they can be loaded onto any ship you have in Clifftop harbour. You cannot buy more cargo units than you can store in your ship (for instance, a Cog can carry 2 Cargo Units). You can also sell any goods you are carrying in your ships for the same price as well:\n\nSALT: 550 silver coins\nCROPS: 600 silver coins\nSTEEL: 3000 silver coins\nSPICES: 3200 silver coins\nWINE: 2000 silver coins\nSLAVES: 700 silver coins";

            Choices.clear();

            Controls = Story::Controls::HARBOUR;
        }

        void Event(Party::Base &party)
        {
            Ships.clear();

            Cargo = {
                {Cargo::Type::SALT, 550, 550},
                {Cargo::Type::CROPS, 600, 600},
                {Cargo::Type::STEEL, 3000, 3000},
                {Cargo::Type::SPICES, 3200, 3200},
                {Cargo::Type::WINE, 2000, 2000},
                {Cargo::Type::SLAVES, 7000, 700}

            };

            ShipRepairPrice = -1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 703}; }
    };

    class Story404 : public Story::Base
    {
    public:
        Story404()
        {
            BookID = Book::Type::BOOK1;

            ID = 404;

            Text = "Something isn't right here. You don't know a lot about growing flowers, but something must be tending those blooms. And until you find out what that is, those scholars are going to stay out of sight! Stepping cautiously into the gloom your worst fears are confirmed. Dreadful snakemen, their curved swords already drawn, come hissing into the gateway to intercept you.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 150}; }
    };

    class Story405 : public Story::Base
    {
    public:
        Story405()
        {
            BookID = Book::Type::BOOK1;

            ID = 405;

            Text = "The work is hot, smelly and dirty, and the piles of junk in the cave seem endless.\n\nNote: Each party member loses 1 Health point as they heave the heavy trash outside the cave.";

            Bye = "After a number of hours you still haven't found anything of value and decide to call it quits.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 395}; }
    };

    class Story406 : public Story::Base
    {
    public:
        Story406()
        {
            BookID = Book::Type::BOOK1;

            ID = 406;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Picking up a nearby bench you attempt to ram the gatehouse door.\n\nNote: Only members of the weapon stealing team may help in this test.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::VERIFY_CODES(party, {Codes::Type::WEAPON_AND_DISTRACTION}))
            {
                Choices.push_back(Choice::Base("Bashing open the door (Team check: Fighting 5+, Successes: 3)", {Book::Type::BOOK1, 611}, {Book::Type::BOOK1, -406}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::FIGHTING}, 5, 3, false));
            }
            else
            {
                Choices.push_back(Choice::Base("Bashing open the door (Team check: Fighting 5+, Successes: 3)", {Book::Type::BOOK1, 611}, {Book::Type::BOOK1, -406}, Choice::Type::TEAM_ATTRIBUTES, Team::Type::WEAPONS, {Attribute::Type::FIGHTING}, 5, 3, false));
            }
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            Bye = NULL;

            if (outcome)
            {
                Bye = "You succeed: the door flies open after a few attempts.";
            }
        }
    };

    class Event406 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Event406()
        {
            BookID = Book::Type::BOOK1;

            ID = -406;

            DisplayID = 406;

            Text = "You fail but you still manage to force open the door, but not before a pair of guards, attracted by the noise, interrupt you!\n\nNote: Only members of the weapon stealing team may help in this combat.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::WEAPONS;

            Monsters = {
                Monster::Base("Guard", 4, 4, 4, 8, 0, {Equipment::IRON_SHORTSWORD1}),
                Monster::Base("Guard", 3, 4, 4, 7, 0, {Equipment::IRON_SHORTSWORD1})};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                destination = {Book::Type::BOOK1, 611};
            }
            else
            {
                destination = {Book::Type::BOOK1, 292};
            }
        }
    };

    class Story407 : public Story::Base
    {
    public:
        Story407()
        {
            BookID = Book::Type::BOOK1;

            ID = 407;

            Text = "The power of St. Elias should be effective against intelligent undead, even these slavering lunatics. You brandish the talisman, the ghouls hissing in pain as you present it. You can actually see their flesh begin to wither and disintegrate in the holy glow that pours from the artefact. Soon you have boxed the ghouls into a corner, their bodies withering before the talisman. In moments they have become little more than bleached bones, cleansed entirely by the power of the holy man who crafted the talisman.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 651}; }
    };

    class Story408 : public Story::Base
    {
    public:
        Story408()
        {
            BookID = Book::Type::BOOK1;

            ID = 408;

            Text = "\"Oh! Please, your majesty, don't take my fingernails! I need my hands to work!\" begs the fellow.\n\n\"Well, unless anyone else would like to volunteer to have their nails removed in your place, I'm going to do it,\" grins the king.\n\nWould anyone in the party be noble enough to suffer such a torment for a lowly peasant?";

            Choices.clear();
            Choices.push_back(Choice::Base("Volunteer someone from your party", {Book::Type::BOOK1, 294}, Choice::Type::CHOOSE_PARTY_MEMBER));
            Choices.push_back(Choice::Base("Do not volunteer", {Book::Type::BOOK1, -408}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event408 : public Story::Base
    {
    public:
        Event408()
        {
            BookID = Book::Type::BOOK1;

            ID = -408;

            DisplayID = 408;

            Text = "The peasant howls in agony as the nails are torn from his hands with rusty pliers. You are forced to withdraw from the court, the bile building in your mouths, at the ghastly inhumanity of it all.\n\nNote: You gained the code A34.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(34)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story409 : public Story::Base
    {
    public:
        Story409()
        {
            BookID = Book::Type::BOOK1;

            ID = 409;

            Text = "With almost every ounce of energy spent, you finally manage to haul yourselves up onto the edge of the cliffside. Slumping against the base of a tree, the chirp of insects and caws of birds lull you to sleep.\n\nNote: Each party member loses 3 Health points.";

            Bye = "In the morning you rise, your stomach's growling. You must start your lives again with what you have.\n\nFirst, though, you must brave the perils of the jungle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -3);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 370}; }
    };

    class Story410 : public Story::Base
    {
    public:
        Story410()
        {
            BookID = Book::Type::BOOK1;

            ID = 410;

            Location = Location::Type::SHADED_GATE;

            Text = "You step through the Shaded Gate, becoming engulfed in cool shadow. The land here is different, and you cannot make out the Granite Hills that should lie beyond the wall. The chill nags at you, but you resolve to carry on.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::WAYFINDER_ROD}))
            {
                Choices.push_back(Choice::Base("Go south", {Book::Type::BOOK1, 886}));
                Choices.push_back(Choice::Base("Go west", {Book::Type::BOOK1, 676}));
                Choices.push_back(Choice::Base("Go east", {Book::Type::BOOK1, 589}));
                Choices.push_back(Choice::Base("Go north through the Shaded Gate", {Book::Type::BOOK1, 140}));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 481}; }
    };

    class Story411 : public Story::Base
    {
    public:
        Story411()
        {
            BookID = Book::Type::BOOK1;

            ID = 411;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The Tower of Oneness is not the tallest structure in Chalice, but it is the grandest. Intricately carved from the living rock, and decorated in flecked red and gold paint, the tower stands out amidst a sea of grand temples.\n\nThe mercifully cool insides are open to all, but there are few visitors in this sacred place. The halls of the God King are closed off to most, and the libraries are only useful to those who can read; a rare skill in the Valley of Bones.\n\nAn elderly sister, in long orange robes, asks how she can be of assistance.";

            Choices.clear();
            Choices.push_back(Choice::Base("Visit the library", {Book::Type::BOOK1, 680}));
            Choices.push_back(Choice::Base("Ask to see the God King", {Book::Type::BOOK1, 628}));
            Choices.push_back(Choice::Base("Make your apologies and leave", {Book::Type::BOOK1, 450}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story412 : public Story::Base
    {
    public:
        Story412()
        {
            BookID = Book::Type::BOOK1;

            ID = 412;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "The monkeys paw over the item you give them, hauling it up into the trees. One monkey snatches it from another, and soon the entire pack storm through the trees, howling after the thief, shaking down a rain of leaves as they scramble away.\n\n\"Let's get out of here while we still can!\" smiles Emlyn, urging you down the path.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 740}; }
    };

    class Story413 : public Story::Base
    {
    public:
        Story413()
        {
            BookID = Book::Type::BOOK1;

            ID = 413;

            Text = "You carefully shuffle along the ledge, unaware how weak it is. Midway, a large portion of the ledge collapses, sending you tumbling into the pit, crushing spider eggs as you go. Immediately, swarms of tiny, biting spiders begin to emerge from the broken eggs. Suddenly the giant spiders move as one, descending upon your companions and the Everchild's followers. Eggs crack as careless feet release more baby spiders.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 237}; }
    };

    class Story414 : public Story::Base
    {
    public:
        Story414()
        {
            BookID = Book::Type::BOOK1;

            ID = 414;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The coffin is made of stone, and its lid looks heavy. There are scrape marks on the lip of the lid that makes it look like it was opened quite recently. It has a name: 'Sar Wilmot Fairbrother'.";

            Choices.clear();
            Choices.push_back(Choice::Base("Open the coffin", {Book::Type::BOOK1, 660}));
            Choices.push_back(Choice::Base("Explore elsewhere", {Book::Type::BOOK1, 494}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story415 : public Story::Base
    {
    public:
        Story415()
        {
            BookID = Book::Type::BOOK1;

            ID = 415;

            Location = Location::Type::CAVES_OF_URANU;

            Image = "images/book1/yu_yuan.png";

            Text = "\"And you are?\" she asks.\n\n\"Akihiro of Chalice, and you?\"\n\n\"Yu Yan,\" she says, offering the smallest of bows in return. She sheathes her sword. \"I take it you are here treasure hunting?\"\n\n\"In a fashion -- I seek a SILVER IDOL for my master, Honnu,\" you admit.\n\n\"That could be a problem,\" says Yu Yan. \"I am not used to sharing. And I am here to treasure hunt.\"\n\nYou frown. You do not seek conflict with this woman, but nor can you just leave without the statue.";

            Choices.clear();
            Choices.push_back(Choice::Base("Offer to work together with Yu Yan", {Book::Type::BOOK1, 454}));
            Choices.push_back(Choice::Base("Insist on searching her bags", {Book::Type::BOOK1, 506}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story416 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story416()
        {
            BookID = Book::Type::BOOK1;

            ID = 416;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Choices.clear();
            Choices.push_back(Choice::Base("Leave the palace", {Book::Type::BOOK1, 265}));
            Choices.push_back(Choice::Base("Go to the room in the south", {Book::Type::BOOK1, 484}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You rub your hands together with glee as you behold the stores of treasure. It's time to get looting!\n\nThe following items are in the vault:\n\n1500 silver pieces\nA bar GOLD BULLION\nA MAGICAL WEAVE\nA pile of REGISTRY PAPERS\nA GLITTERING NECKLACE (Charisma +2)\nA TOME OF KNOWLEDGE (Lore +2)\nA SILVER IDOL\n\nWhat will you do now?\n\nNote: You may take what you wish.";

            Take = {
                Equipment::Base("1500 silver pieces", "1500 silver pieces", Equipment::Class::NORMAL, Equipment::Type::SILVER_COINS, Attribute::Type::NONE, 0, 0, 1500, false),
                Equipment::GOLD_BULLION,
                Equipment::REGISTRY_PAPERS,
                Equipment::GLITTERING_NECKLACE2,
                Equipment::TOME_OF_KNOWLEDGE2,
                Equipment::SILVER_IDOL};

            Limit = Take.size();

            if (Engine::VERIFY_CODES(party, {Codes::Type::BANDITS_GET3}))
            {
                PreText += " The bandits get three of these treasures.";

                Limit -= 3;
            }

            Text = PreText.c_str();
        }
    };

    class Story417 : public Story::Base
    {
    public:
        Story417()
        {
            BookID = Book::Type::BOOK1;

            ID = 417;

            Text = "The overseers have no intention of messing with armed warriors, and quickly leave their sport. The woman staggers to her feet, blood flowing from her face.\n\n\"Barbarians!\" she spits. \"They beat me because I am down on my luck. My family used to own half the land in Clifftop, but my grandfather was forced off his land by the vile sorcerer Unbraaki who stole his land documents. You look like adventurous sorts. If you find me the REGISTRY PAPERS from Unbraaki's vault, I'll reward you!\"\n\n\"And you are?\" you ask.\n\n\"They call me Damned Suzanna,\" she shrugs. \"At least, that's what I'm called when people see me. Find those REGISTRY PAPERS and I'll split the land value with you.\"\n\nIt might be worth looking out for.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story418 : public Story::Base
    {
    public:
        Story418()
        {
            BookID = Book::Type::BOOK1;

            ID = 418;

            Text = "Your defeat of the kensai in single combat has proven the strength of your convictions. The sister defers and asks you to maintain a respectful tone as she escorts you to Hall of the King.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 638}; }
    };

    class Story419 : public Story::Base
    {
    public:
        Story419()
        {
            BookID = Book::Type::BOOK1;

            ID = 419;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You attempt to invoke the power of the book, hoping your pronunciations and somatic gestures are correct.";

            Choices.clear();
            Choices.push_back(Choice::Base("Animate the Skeletons (Team check: Lore 4+, Successes: 6)", {Book::Type::BOOK1, 232}, {Book::Type::BOOK1, 457}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 4, 6));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story420 : public Story::Base
    {
    public:
        Story420()
        {
            BookID = Book::Type::BOOK1;

            ID = 420;

            Text = "You carefully mar the strange symbols around the door, being careful not to trigger the effect early. Eventually the runes are ruined and lose their power. To your delight the door merely clicks open; there is not so much as a conventional lock upon them!\n\nYou step into a darkened hallway. A magnificent flight of carpeted steps leads up to the top floor. Rows of books line the walls in antique cases. Nearby, a solid gold candlestick looks a tempting grab.";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine the bookcase", {Book::Type::BOOK1, 320}));
            Choices.push_back(Choice::Base("Snatch the golden candlestick", {Book::Type::BOOK1, 644}));
            Choices.push_back(Choice::Base("Head upstairs to help the climbing team", {Book::Type::BOOK1, 92}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story421 : public Story::Base
    {
    public:
        Story421()
        {
            BookID = Book::Type::BOOK1;

            ID = 421;

            Text = "\"You have done all I have asked -- all I can ever ask,\" smiles the Everchild as she greets you into her presence. \"As a boon I am willing to provide soldiers to you, should you ever need the services of an army. Provided you own a barracks elsewhere, you have my permission to transfer soldiers to that barracks from Saltdad. Please leave me with a few units, though... you never know when the valley might need them.\"";

            Bye = "You spend several hours with the Everchild, reflecting on your adventures. Eventually it is time to leave, the Everchild kissing you goodbye.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 620}; }
    };

    class Story422 : public Story::Base
    {
    public:
        Story422()
        {
            BookID = Book::Type::BOOK1;

            ID = 422;

            Location = Location::Type::WITHERED_STEPPES;

            Text = "You are not successful in your search for the nomads, but you do find trouble. Vicious Sand Drakes, tawny-brown reptilian horrors that stand some ten feet high on two scally legs, take an interest in you. You have little option but to fend them off.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {
                Monster::Base("Sand Drake", 6, 5, 4, 12, 0),
                Monster::Base("Sand Drake", 5, 5, 4, 11, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 115}; }
    };

    class Story423 : public Story::Base
    {
    public:
        Story423()
        {
            BookID = Book::Type::BOOK1;

            ID = 423;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You have returned to the goblin kitchen. The goblins greet you with friendly chitters and offer you some food.\n\nNote: Any party members on less than 4 Health restore themselves to 4 Health points by eating here.";

            Bye = "You thank the goblins and move on.";

            Choices.clear();
            Choices.push_back(Choice::Base("Leave the kitchen through the north door", {Book::Type::BOOK1, 366}));
            Choices.push_back(Choice::Base("Leave the kitchen through the south door", {Book::Type::BOOK1, 736}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::RESTORE_HEALTH(party, 4);
        }
    };

    class Story424 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story424()
        {
            BookID = Book::Type::BOOK1;

            ID = 424;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You prowl into the kitchen, ducking behind the counters and peering over. The evening meal is being prepared, and chefs and servants scurry from one place to the other, putting the final herbs and spices into the stew that boils away in an enormous cauldron.";

            if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::VIAL_OF_POISON}))
            {
                PreText += "\n\nThere is nothing you can do finish off the Bronzeguard with the ingredients at hand. You quickly flee the compound before you are spotted.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::VIAL_OF_POISON}))
            {
                return {Book::Type::BOOK1, 565};
            }
            else
            {
                return {Book::Type::BOOK1, 75};
            }
        }
    };

    class Story425 : public Story::Base
    {
    public:
        Story425()
        {
            BookID = Book::Type::BOOK1;

            ID = 425;

            Text = "You step forward and loudly declare your challenge. There is a great cheer from the audience, including the king. Someone gives you a hearty shove, and you are hurled into the pit. The sand bear snarls at you, showing its teeth.\n\nNote: You cannot use any bonuses from your weapon with this check.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::IS_ACTIVE(party, party.LastSelected) && Engine::HAS_SPELL(party.Members[party.LastSelected], {Spells::Type::ANIMAL_SPEECH}))
            {
                Choices.push_back(Choice::Base("Cast Animal Speech", {Book::Type::BOOK1, 615}));
            }

            Choices.push_back(Choice::Base("Wrestle the Bear (Individual check: Fighting 5+, Successes: 2)", {Book::Type::BOOK1, 677}, {Book::Type::BOOK1, 742}, Choice::Type::LAST_INDIVIDUAL_CHECK, {Attribute::Type::FIGHTING}, 5, 2, false));
        }
    };

    class Story426 : public Story::Base
    {
    public:
        Story426()
        {
            BookID = Book::Type::BOOK1;

            ID = 426;

            Location = Location::Type::CROSSROADS;

            Text = "It's time to move on. Where will you go from here?";

            Choices.clear();
            Choices.push_back(Choice::Base("Go northwest, to the Blackwall", {Book::Type::BOOK1, 691}));
            Choices.push_back(Choice::Base("Go north, towards Saltdad", {Book::Type::BOOK1, 858}));
            Choices.push_back(Choice::Base("Go northeast into the Withered Steppes", {Book::Type::BOOK1, 115}));
            Choices.push_back(Choice::Base("Go southeast, into desert", {Book::Type::BOOK1, 202}));
            Choices.push_back(Choice::Base("Go south towards Lhasbreath Oasis", {Book::Type::BOOK1, 590}));
            Choices.push_back(Choice::Base("Go southwest towards Lhasbreath", {Book::Type::BOOK1, 752}));
            Choices.push_back(Choice::Base("Go west to the Tumblestones", {Book::Type::BOOK1, 137}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story427 : public Story::Base
    {
    public:
        Story427()
        {
            BookID = Book::Type::BOOK1;

            ID = 427;

            Text = "You had hoped you might be able to take another suit of bronze armour here, but alas no spare suits appear to be present. Cursing your luck, you sneak onwards towards the kitchen.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 424}; }
    };

    class Story428 : public Story::Base
    {
    public:
        Story428()
        {
            BookID = Book::Type::BOOK1;

            ID = 428;

            Text = "Quiet as a mouse you manage to step across the floor of broken bones without so much as raising a dust cloud. Nothing stirs, and you manage to reach the chest quite safely.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 3}; }
    };

    class Story429 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story429()
        {
            BookID = Book::Type::BOOK1;

            ID = 429;

            Location = Location::Type::CAPE_PORTA;

            Text = "Just as you feared a dreadful pirate pinnace comes swooping around the bay. They seem keen on plundering your ship and crew.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            EnemyFleet = {Ship::Base("PIRATE PINNACE", Ship::Type::PIRATE_PINNACE, Location::Type::NONE, 5, 6, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                destination = {Book::Type::BOOK1, 690};
            }
            else
            {
                destination = {Book::Type::BOOK1, 741};
            }
        }
    };

    class Story430 : public Story::Base
    {
    public:
        Story430()
        {
            BookID = Book::Type::BOOK1;

            ID = 430;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You convince the thieves that you are not dangerous, nor are you agents of the Iron King. Your slave garb assures them you are speaking the truth, and instead you are even offered some decent hospitality in the form of beer and bread. The thief's leader, Brekken, reveals that they are downtrodden citizens of Saltdad, and that they only prey on the merchants and nobles who support the king's rule. \"But slaves have nothing to fear from us,\" he assures you. \"If you wish, we can provide you with some spare clothing to help conceal your identity in the city.\"\n\n\"That would be most kind, thank you, Brekken,\" nods the Everchild. \"You show greater civility than your monarch.\"\n\n\"A plague-ridden dragonyak shows more grace than our king,\" laughs Brekken. \"But thank you, girl, for the compliment.\"\n\nYou can see that the Everchild would dearly love to share her secret with Brekken, but wisely holds her tongue, instead asking if the thieves could show you all a safe route out of the ruined tunnels. Brekken agrees, escorting you into the old storm drains that lie beneath the city, and to a drain cover that leads to an isolated alleyway.\n\nYou have gained a useful ally.\n\nNote: Each party member recovers 2 Health points.  You gained the code A5.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(5)});

            Engine::GAIN_HEALTH(party, 2);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 41}; }
    };

    class Story431 : public Story::Base
    {
    public:
        Story431()
        {
            BookID = Book::Type::BOOK1;

            ID = 431;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You find 123 silver coins and a RUSTY KEY on the bodies.\n\nNote: If you paid any bribes to an ogre, you can recover that money as well.\n\nNote: You gained the code A76.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(76)});

            Engine::GAIN_MONEY(party, 123);

            Take = {Equipment::RUSTY_KEY};

            Limit = 1;

            // TODO: Recover bribes to orcs
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 310}; }
    };

    class Story432 : public Story::Base
    {
    public:
        Story432()
        {
            BookID = Book::Type::BOOK1;

            ID = 432;

            Location = Location::Type::MORDAIN;

            Text = "The temples of Mordain lie in crumbled ruins, like the rest of the city. Listing above a wrecked tower in a temple of Kalu, a lone bell peals in the sea breeze. You shudder involuntarily at the sudden cold. There is nothing for you here.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 515}; }
    };

    class Story433 : public Story::Base
    {
    public:
        Story433()
        {
            BookID = Book::Type::BOOK1;

            ID = 433;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You chase after her but stumble up the steps as you run. The stairs lead out onto the side of the hilltop, but by the time you emerge you have lost sight of her. You curse loudly. It is unlikely she will be found now. Perhaps there is some other way of finding a SILVER IDOL? Musing on your failure, you return to Chalice.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story434 : public Story::Base
    {
    public:
        Story434()
        {
            BookID = Book::Type::BOOK1;

            ID = 434;

            Text = "You hold aloft the talisman and Imopposh screams. He casts a bolt of roaring fire that would surely incinerate you, but the impact merely makes you stagger back towards the daylight. Imopposh cannot oppose the power of the living saint himself, for in times past the two of them were rivals -- but neither can you gain ground against him. Imopposh draws the fragments of his casket around him, returning to his rest. The shadow door slams shut in front of you.";

            Bye = "Without even pausing to catch your breath, you bolt from the canyon.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 115}; }
    };

    class Story435 : public Story::Base
    {
    public:
        Story435()
        {
            BookID = Book::Type::BOOK1;

            ID = 435;

            Text = "The barbarians laugh as you shove them in return. You put up your fists to show you mean business and are alarmed as your opponents heft their axes in return. This isn't a merry brawl... it's a fight to the death!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 587}; }
    };

    class Story436 : public Story::Base
    {
    public:
        Story436()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::SALT_PLAINS;

            ID = 436;

            Text = "You spot the trail of sand frogs in the crystal earth of the desert. These hardy amphibians can go without water for days, but even they do not stray far from a water source. Following the trails, you come to a rocky place. Lifting some of the stones you discover hidden pools, the hatcheries of the sand frogs. Batting away the harmless frogs you drink deeply to get your strength back and refill your waterskins.\n\nYou gaze across the desert, getting your bearings.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(18)}))
            {
                return {Book::Type::BOOK1, 711};
            }
            else
            {
                return {Book::Type::BOOK1, 731};
            }
        }
    };

    class Story437 : public Story::Base
    {
    public:
        Story437()
        {
            BookID = Book::Type::BOOK1;

            ID = 437;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You climb up the stairs a good distance, reaching another tunnel which appears to be blocked by a crude but well-made barricade. Large wooden struts hold up a barrier of rock and timber. With sufficient strength you might be able to pull down the barricade, if you wished.";

            Choices.clear();
            Choices.push_back(Choice::Base("Pull down the barricade", {Book::Type::BOOK1, 541}));
            Choices.push_back(Choice::Base("Go back down the stairs to the west", {Book::Type::BOOK1, 23}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(72)}))
            {
                return {Book::Type::BOOK1, 180};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story438 : public Story::Base
    {
    public:
        Story438()
        {
            BookID = Book::Type::BOOK1;

            ID = 438;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                return {Book::Type::BOOK1, 678};
            }
            else
            {
                return {Book::Type::BOOK1, 317};
            }
        }
    };

    class Story439 : public Story::Base
    {
    public:
        Story439()
        {
            BookID = Book::Type::BOOK1;

            ID = 439;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The steps lead down until you arrive at a huge cavern, ringing with the sounds of picks on rocks. Half the chamber is filled with rock detritus, chiselled from the walls by dozens of human slaves. The slaves themselves seem to be locals from the valley, a combination of slim-bodied Cursites and heavy-set men and women from Lhasbreath. Around them, half a dozen orcs whip and cajole the slaves, ordering them to work faster. One orc is dressed in heavy chainmail armour and looks to be the leader. He is roaring loudly at a terrified young woman, putting his great-tusked jaws less than an inch from her face. In the corner, several dead humans lie rotting, presumably dead from their injuries.\n\nYou are able to dive behind the rock detritus before the orcs see you. How will you proceed?";

            Choices.clear();
            Choices.push_back(Choice::Base("Draw your weapons and charge to the attack", {Book::Type::BOOK1, 213}));
            Choices.push_back(Choice::Base("Wait until the work stops and then attempt to rescue the prisoners", {Book::Type::BOOK1, 783}));
            Choices.push_back(Choice::Base("Sneak out of the chamber", {Book::Type::BOOK1, 11}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(69)}))
            {
                return {Book::Type::BOOK1, 209};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story440 : public Story::Base
    {
    public:
        Story440()
        {
            BookID = Book::Type::BOOK1;

            ID = 440;

            Text = "You lunge for the wizard's throat, but he dives aside at the last moment, yelling for aid. You are not given another chance. Between the wizard's magic which forces you away and the dozens of guards that swarm you your capture is inevitable. The assassination team have been captured. What happens to them now is up to you. If you capture the city of Cursus you can free them from prison. If your army is defeated, the party members will be executed. Either way, the captured party members can take no further part in the battle until rescued.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            for (auto i = 0; i < party.Members.size(); i++)
            {
                if (Engine::SCORE(party.Members[i], Attribute::Type::HEALTH) > 0 && party.Members[i].Team == Team::Type::ASSASSINATION_DESCANTOS)
                {
                    Engine::GAIN_STATUS(party.Members[i], Character::Status::CAPTURED);
                }
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 96}; }
    };

    class Story441 : public Story::Base
    {
    public:
        Story441()
        {
            BookID = Book::Type::BOOK1;

            ID = 441;

            Text = "Haatchi is delighted as you produce the CRIER BIRD for him. He quickly hangs it in pride of place in his collection, the bird singing a mournful but sweet tune. True to his word, Haatchi hands over a purse of 100 silver coins. \"If you find any others, just bring them to me,\" he insists.";

            Bye = "Wishing him a good day, you stroll on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::CRIER_BIRD});

            Engine::GAIN_MONEY(party, 100);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 340}; }
    };

    class Story442 : public Story::Base
    {
    public:
        Story442()
        {
            BookID = Book::Type::BOOK1;

            ID = 442;

            Text = "You have come to the banks of a wide river that separates the city of Chalice from the rest of the valley. The Cold River pours from the craggy mountain tops of the Stonewalls and bisects the desert like a sword blade. Spanning this river is an ancient bridge, built shortly after the demon lord Abraxas destroyed the elder civilisation. Originally built as an act of faith to restart society, its designers could not hold back the wave of savagery left in the demon's wake as the fine cities of the elders were brought to ruin.\n\nThe bridge, however, still stands, wide and strong. Dozens of heavy wagons ply its ancient length and without it the city of Chalice would be entirely cut off. A fee of 40 silver coins is required to cross it, a steep price normally paid only by merchants. You notice that slimmer, flimsier bridges made of rope and wood also cross the river, through few people seem willing to use them. There is no toll for their use.";

            Choices.clear();
            Choices.push_back(Choice::Base("Pay 40 silver coins and cross the stone bridge", {Book::Type::BOOK1, 450}, Choice::Type::GAIN_MONEY, -40));
            Choices.push_back(Choice::Base("Cross the river using one of the rope bridges", {Book::Type::BOOK1, 329}));
            Choices.push_back(Choice::Base("Head back to Luutanesh", {Book::Type::BOOK1, 614}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story443 : public Story::Base
    {
    public:
        Story443()
        {
            BookID = Book::Type::BOOK1;

            ID = 443;

            Text = "The window proves impossible to open and smashing it would create too much noise. Reluctantly you abandon your attempt on the house, dropping back down to the street. Soon Brekken joins you, his gang looking rueful. \"Well -- it was worth an attempt,\" he shrugs. You comfort yourselves with a quick commiseration drink at a local tavern. \"We are usually better than this,\" he assures you. \"If you come across any likely heists you think we could help with, don't forget to pay us a visit.\"";

            Bye = "Assuring Brekken that you will keep him in mind, you depart the tavern at first light.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story444 : public Story::Base
    {
    public:
        Story444()
        {
            BookID = Book::Type::BOOK1;

            ID = 444;

            Text = "Kopu is impressed with your learnedness. \"Few people live long enough amongst orcs to grasp their language,\" admits Kopu. \"This requires a significant reward.\"\n\nHe rummages through his notes until he finds some SCROLLS OF LORE (Lore +3). \"These magical scrolls contain vast amounts of knowledge, practically an entire library's worth. I was looking for someone worthy to pass them on to. Consider them yours.\"\n\nNote: In addition, all injured party members are restored to full Health, as you spend many days resting in the tower whilst you teach the language to Kopu.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::Type::TAUGHT_KOPU_ORCISH}))
            {
                return {Book::Type::BOOK1, 539};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::SCROLLS_OF_LORE3};

            Limit = 1;

            Engine::GET_CODES(party, {Codes::Type::TAUGHT_KOPU_ORCISH});

            Engine::REST(party);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 539}; }
    };

    class Story445 : public Story::Base
    {
    public:
        Story445()
        {
            BookID = Book::Type::BOOK1;

            ID = 445;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "It is not so easy to escape unmolested past the Caves of Uranu. There is a reason people use the Northroad rather than trudge through the desert.";

            Choices.clear();
            Choices.push_back(Choice::Base("Avoid monsters (Team check: Survival 4+, Successes: 7)", {Book::Type::BOOK1, 395}, {Book::Type::BOOK1, 846}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 7));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story446 : public Story::Base
    {
    public:
        Story446()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::SALT_MINES;

            ID = 446;

            Text = "It was not easy to find them, but finally you discover a band of troglodytes in their lair. They hiss at you and leap to the attack.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            Take.clear();

            Limit = 0;

            Monsters = {
                Monster::Base("Troglodyte", 3, 3, 4, 5, 0),
                Monster::Base("Troglodyte", 2, 3, 4, 3, 0),
                Monster::Base("Troglodyte", 2, 3, 4, 3, 0),
                Monster::Base("Troglodyte", 3, 3, 4, 4, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 135}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Take = {Equipment::TROGLODYTE_HEAD, Equipment::TROGLODYTE_HEAD, Equipment::TROGLODYTE_HEAD, Equipment::TROGLODYTE_HEAD, Equipment::HANDSOME_BROOCH1, Equipment::GREY_TALISMAN};

                Limit = 6;

                Engine::GAIN_MONEY(party, 10);

                Engine::GET_CODES(party, {Codes::A(25)});

                Bye = "\n\nNote: You gained the code A25.";
            }
        }
    };

    class Story447 : public Story::Base
    {
    public:
        Story447()
        {
            BookID = Book::Type::BOOK1;

            ID = 447;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "Realising your peril, you raise the talisman high in front of you. The green skeletons let out a terrible screech as blue light burns away the scummy slime from their bones, causing them to collapse in a heap. Skallos, roars with hatred, unleashing a great blast of energy from his mouth. The light from the amulet dims for a moment, before shining back into pure radiance. The undead knight cannot stand against its power, igniting into white flames. Soon his body and possessions have turned to dust, all that is left is his sword and a whispered cry for vengeance.\n\nYou may take the SKALLOS RUNEBLADE (Fighting +3, Lore +2) if you wish. Whatever else the black knight might have possessed is now naught but ash.\n\nNote: You gained the code A79.";

            Bye = "There are no additional exits from this room, so you return to the corridor outside.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::SKALLOS_RUNEBLADE};

            Limit = 1;

            Engine::GET_CODES(party, {Codes::A(79)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 165}; }
    };

    class Story448 : public Story::Base
    {
    public:
        Story448()
        {
            BookID = Book::Type::BOOK1;

            ID = 448;

            Text = "The oasis is packed with herd beasts and nomads, sharing the waterhole like brothers. You have heard savage stories about the nomads, but they seem friendly enough. Indeed, one informs you that violence is forbidden at an oasis, though he does so with one hand on his scimitar, as if to suggest that he is willing to wink at that rule if provoked. You peacefully refill your waterskins and continue with your journey.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 51}; }
    };

    class Story449 : public Story::Base
    {
    public:
        Story449()
        {
            BookID = Book::Type::BOOK1;

            ID = 449;

            Text = "Tromping through the jungle you have attracted attention to yourselves. A pair of jungle panthers have been stalking you. They leap upon you, quite unexpectedly.\n\nNote: The panthers have ambushed you! They get the first turn.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            Monsters = {
                Monster::Base("Panther", 5, 4, 4, 6, 0),
                Monster::Base("Panther", 4, 4, 4, 7, 0)};

            Engine::GET_CODES(party, {Codes::Type::LAST_IN_COMBAT});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 618}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Bye = "You quickly make your way out of the dangerous jungle.";
            }
        }
    };

    class Story450 : public Story::Base
    {
    public:
        Story450()
        {
            BookID = Book::Type::BOOK1;

            ID = 450;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Image = "images/book1/city_of_chalice.png";

            Text = "Chalice is a city of tall, decorated towers cut from the mesas of rock that dot the landscape. Between the towers high-topped houses with red roofs cram together to produce neighbourhoods and boroughs, interspersed with painted temples decorated with bells and chimes. The nearby Cold River floods the plains between the rocks to create the most fertile place in the valley. Huge rice fields are tended to by hundreds of farmers in pyramidal hats. Unlike some cities in the valley there are no burly taskmasters savagely beating their workforce into submission. Instead the obedient folk of Chalice labour willingly for their God King, who resides in the Tower of Oneness in the heart of the city. It is an orderly place, quiet and subdued compared with other cities, but also less savage and uncivilised.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::IN_PARTY(party, Character::Type::AKIHIRO_OF_CHALICE))
            {
                Choices.push_back(Choice::Base("Visit Akihiro's house", {Book::Type::BOOK1, 897}));
            }

            Choices.push_back(Choice::Base("Visit the marketplace", {Book::Type::BOOK1, 142}));
            Choices.push_back(Choice::Base("Find an inn in the foreign quarter", {Book::Type::BOOK1, 665}));
            Choices.push_back(Choice::Base("Explore the city", {Book::Type::BOOK1, 270}));
            Choices.push_back(Choice::Base("Leave the city west, over the bridge (you do not need to pay on this side)", {Book::Type::BOOK1, 614}));
            Choices.push_back(Choice::Base("Leave the city south, along the Cold River", {Book::Type::BOOK1, 346}));
        }
    };

    class Story451 : public Story::Base
    {
    public:
        Story451()
        {
            BookID = Book::Type::BOOK1;

            ID = 451;

            Location = Location::Type::NORTH_ROAD;

            Text = "The caravan guards sense the uncertainty in your voice as the nomads crash upon them. The line breaks and soon there is chaos. In the fighting and looting that follows you are captured and clad in chains. Because you are such healthy specimens the nomads decide to sell you as slaves.";

            Choices.clear();
            Choices.push_back(Choice::Base("See where you are eventually sold", {{2, "You are sold to the Saltdad Arena", {Book::Type::BOOK1, 631}}, {4, "You are sold to the taskmasters of Clifftop", {Book::Type::BOOK1, 866}}, {6, "You are sold to the priests of Cursus", {Book::Type::BOOK1, 531}}}, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            party.Money = 0;

            Engine::LOSE_ALL(party);
        }
    };

    class Story452 : public Story::Base
    {
    public:
        Story452()
        {
            BookID = Book::Type::BOOK1;

            ID = 452;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The Everchild was the immortal ruler of the valley before the desolation of Abraxas. She ruled from the magnificent city of Saltdad in a fantastic palace which was said to hold many wonders of the world. She was eternally young in appearance, although exactly how young is subject to debate.\n\nSome records put her at only seven summers, others twelve, a few even suggest fifteen or eighteen. She possessed powerful magical abilities, so mighty that she had need of very few soldiers, since her magic could annihilate armies and disperse crowds.\n\nMost stories present her as a benevolent but single-minded ruler, who would be inflexible in her judgements once she had made up her mind.\n\nExactly how she died is unclear, but most tales assume that she was slain by Abraxas when the demon lord walked the valley.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 680}; }
    };

    class Story453 : public Story::Base
    {
    public:
        Story453()
        {
            BookID = Book::Type::BOOK1;

            ID = 453;

            Location = Location::Type::TUMBLESTONES;

            Text = "You are leaving The Tumblestones.\n\nWhere will you travel now?";

            Choices.clear();
            Choices.push_back(Choice::Base("Northeast, towards Saltdad", {Book::Type::BOOK1, 511}));
            Choices.push_back(Choice::Base("East, towards the Blackwall", {Book::Type::BOOK1, 691}));
            Choices.push_back(Choice::Base("Southeast, into the desert", {Book::Type::BOOK1, 752}));
            Choices.push_back(Choice::Base("South, to the city of Lhasbreath", {Book::Type::BOOK1, 775}));
            Choices.push_back(Choice::Base("West, to the Palace of Unbraaki", {Book::Type::BOOK1, 890}));
            Choices.push_back(Choice::Base("Northwest, towards Clifftop", {Book::Type::BOOK1, 12}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story454 : public Story::Base
    {
    public:
        Story454()
        {
            BookID = Book::Type::BOOK1;

            ID = 454;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "\"What if we worked together?\" you offer. \"In exchange you may have all the treasure we find, except for the silver idol. It is all I am interested in.\"\n\nShe looks you up and down, as if judging you. \"So be it, Akihiro of Chalice,\" she says, smiling. \"This place is quite dangerous, and you look like you can handle yourself. There is nothing to be found in the passage I have just explored. Our only way onwards is up the west side steps. Shall we go together?\"";

            Bye = "You nod cautiously and follow her up the stairwell.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 279}; }
    };

    class Story455 : public Story::Base
    {
    public:
        Story455()
        {
            BookID = Book::Type::BOOK1;

            ID = 455;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You ask if you can consult Unbraaki on magical matters, since you have heard of his great reputation as a sorcerer. The guard shakes his head. \"My master is no public oracle, and his palace is not a school like Animus Mast. Get you gone, curs.\" Two dozen soldiers lower their spears in preparation for your defiance, with another company advancing up the road to support them.";

            Bye = "Realising that these are not men to be trifled with you politely depart.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 265}; }
    };

    class Story456 : public Story::Base
    {
    public:
        Story456()
        {
            BookID = Book::Type::BOOK1;

            ID = 456;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The door to the gatehouse is now unguarded, and your weapon-stealing team can now approach. The only obstacle is the gate-house door, which is locked at all times.";

            Choices.clear();
            Choices.push_back(Choice::Base("Steal the key from the overseer's office", {Book::Type::BOOK1, 393}));
            Choices.push_back(Choice::Base("Attempt to force the door", {Book::Type::BOOK1, 406}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story457 : public Story::Base
    {
    public:
        Story457()
        {
            BookID = Book::Type::BOOK1;

            ID = 457;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "Something goes wrong with the invocation. The skeleton's animate, but you are unable to bind them to your control. They seem to resent being awoken from their rest and make their feelings clear as they try to gouge your eyes out with their bony claws. You must fight!\n\nNote: The skeletons will attack twice each round. You must assign the damage of the second attack to a different character from the first.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {Monster::Base("Skeletons", 5, 5, 4, 24, 0, 0, 2)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 345}; }
    };

    class Story458 : public Story::Base
    {
    public:
        Story458()
        {
            BookID = Book::Type::BOOK1;

            ID = 458;

            Text = "Where will you travel now?";

            Choices.clear();
            Choices.push_back(Choice::Base("Go north, up the road", {Book::Type::BOOK1, 113}));
            Choices.push_back(Choice::Base("Go west, to the Temple of the Unbroken", {Book::Type::BOOK1, 535}));
            Choices.push_back(Choice::Base("Go south, into the city of Cursus", {Book::Type::BOOK1, 340}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story459 : public Story::Base
    {
    public:
        Story459()
        {
            BookID = Book::Type::BOOK1;

            ID = 459;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You open the door to the massive library and jolt in shock. Looking up to see you in a velvet armchair is Unbraaki himself, book in hand, a small pack of monkeys reading on the floor alongside him. \"Visitors,\" smiles Unbraaki. \"And unbidden ones! Kill them.\"";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 564}; }
    };

    class Story460 : public Story::Base
    {
    public:
        Story460()
        {
            BookID = Book::Type::BOOK1;

            ID = 460;

            Location = Location::Type::SALT_PLAINS;

            Image = "images/book1/driest_place.png";

            Text = "You have entered the driest place in the Valley of Bones.\n\nThe still, brown-yellow sands glitter with salt crystals, and within an hour your throats are as dry as parchment. Your skin and eyes begin to sting, even as you rapidly drain your water supplies.";

            Choices.clear();
            Choices.push_back(Choice::Base("Survive the Salt Plains (Team check: Survival 4+, Successes: 6)", {Book::Type::BOOK1, 436}, {Book::Type::BOOK1, 864}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 6));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story461 : public Story::Base
    {
    public:
        Story461()
        {
            BookID = Book::Type::BOOK1;

            ID = 461;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The spiders seem unsure about attacking such large, fire-wielding prey, especially those that are respecting the integrity of their nests. Heart in your mouth, you move around the egg clusters carefully, not breaking a single one, before clambering out of the crevice along a rubble-scattered ramp. Another chamber beckons on the other side.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 347}; }
    };

    class Story462 : public Story::Base
    {
    public:
        Story462()
        {
            BookID = Book::Type::BOOK1;

            ID = 462;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "You become dreadfully lost, wandering through the jungle aimlessly, trying to find a familiar landmark. Suddenly, behind you, you hear a terrible cry. You spin around to see that one of the scholars has fallen into a hidden pit. Dashing to the edge of the pit you move to help but see that the poor woman has been impaled on sharpened stakes which have been hammered into the bottom. This was clearly no accident!\n\nYou have lost one scholar. Emlyn refrains from cursing you out loud, but you see the disappointment and fear in her eyes.";

            Bye = "After several hours more fruitless wandering you eventually emerge back onto the path, now clear of water.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Book1::LOST_SCHOLAR(party);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 359}; }
    };

    class Story463 : public Story::Base
    {
    public:
        Story463()
        {
            BookID = Book::Type::BOOK1;

            ID = 463;

            Text = "You are not quite in position to save Brash. He immediately loses 3 Health points. You continue the pursuit.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                if (party.Members[party.LastSelected].Type == Character::Type::AMELIA_PASS_DAYNE)
                {
                    return {Book::Type::BOOK1, 831};
                }
                else if (party.Members[party.LastSelected].Type == Character::Type::AKIHIRO_OF_CHALICE)
                {
                    return {Book::Type::BOOK1, 335};
                }
                else
                {
                    return {Book::Type::NONE, -1};
                }
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            auto brash = Engine::FIND_CHARACTER(party, Character::Type::BRASH);

            if (Engine::IS_ACTIVE(party, brash))
            {
                Engine::GAIN_HEALTH(party.Members[brash], -3);
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 60}; }
    };

    class Story464 : public Story::Base
    {
    public:
        Story464()
        {
            BookID = Book::Type::BOOK1;

            ID = 464;

            Text = "You cannot determine how the runes might be deactivated. In fact, you are beginning to suspect that the runes might not be magical at all.";

            Choices.clear();
            Choices.push_back(Choice::Base("Open the door regardless", {Book::Type::BOOK1, 673}));
            Choices.push_back(Choice::Base("Leave the rest of the mission to the climbing team", {Book::Type::BOOK1, 728}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story465 : public Story::Base
    {
    public:
        Story465()
        {
            BookID = Book::Type::BOOK1;

            ID = 465;

            Text = "You look in vain for your foe. Clearly Montague has outmatched you again! Cursing under your breath, you return to the city centre.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 340}; }
    };

    class Story466 : public Story::Base
    {
    public:
        Story466()
        {
            BookID = Book::Type::BOOK1;

            Location = Location::Type::WEST_ROAD;

            ID = 466;

            Text = "Sandstorms are common here, the wind whipping up sand that feels like stinging hornets on your flesh.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::HAS_SPELL(party, {Spells::Type::NATURE_WARD}))
            {
                Choices.push_back(Choice::Base("Cast Nature Ward", {Book::Type::BOOK1, 784}));
                Choices.push_back(Choice::Base("Brave the sandstorm", {Book::Type::BOOK1, -466}));
            }
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(19)}))
            {
                return {Book::Type::BOOK1, 396};
            }
            else
            {
                return {Book::Type::BOOK1, -466};
            }
        }
    };

    class Event466 : public Story::Base
    {
    public:
        Event466()
        {
            BookID = Book::Type::BOOK1;

            ID = -466;

            DisplayID = 466;

            Text = "The storm is becoming unbearable. Fortunately, you espy a good-sized tent through the storm, made of blue canvass. Desperate, you duck into the tent to avoid the storm. Inside is a priest, wearing embroidered blue robes. He is initially startled but begins to relax when you assure him you mean him no harm. His name is Kopu, and he is a priest of Kalu, the god of time and harvest. He offers you shelter, and bids his slaves provide you with wine and food.\n\n\"It is rare to encounter civilised people in these parts,\" admits Kopu. \"The worship of Kalu has been banned by the patriarch of Cursus, and since then we priests have lived the lives of nomads, waiting for a more tolerant ruler to let us rebuild our temples. I wonder if you might be able to help me with a problem?\"\n\n\"It depends what it is,\" you shrug.\n\n\"I am attempting to translate the calendar of the Bando people into the common tongue,\" he explains. \"Calendars are sacred to Kalu, you see. It is the hope of the priesthood that we can gather calendars of all the peoples of the world to create the Great Calendar. From this we could divine the ultimate truths of the universe and predict the future.\"\n\n\"Well... if that is what you believe...\" you say uncertainly.\n\n\"Sadly I have hit a snag,\" he says. \"This translation book I have acquired is a fake. Evidently the author had never come across a speaker of Bando in his life! I need someone skilled in Bando to translate the symbols on this calendar I have acquired.\"\n\nNote: Your entire party regain 1 Healh point from eating and drinking.";

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(19)}))
            {
                return {Book::Type::BOOK1, 396};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, 1);

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::Type::SPEAK_BANDO}))
            {
                Choices.push_back(Choice::Base("Attempt the translation yourself", {Book::Type::BOOK1, 288}));
                Choices.push_back(Choice::Base("Decline to help the strange priest", {Book::Type::BOOK1, 585}));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 50}; }
    };

    class Story467 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story467()
        {
            BookID = Book::Type::BOOK1;

            ID = 467;

            Choices.clear();
            Choices.push_back(Choice::Base("Pass through the door in the western wall", {Book::Type::BOOK1, 256}));
            Choices.push_back(Choice::Base("Return to the corridor through the east door", {Book::Type::BOOK1, 755}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "Something has clearly gone wrong. As you heat the mixture it explodes violently, shattering the delicate equipment and scorching you.";

            Engine::GAIN_HEALTH(party, -2);

            if (Engine::COUNT(party) > 0)
            {
                PreText += " Nursing your injuries, you decide to make your way on.\n\nNote: Each party member loses 2 Health points. You gained the code A73.";

                Engine::GET_CODES(party, {Codes::A(73)});
            }
            else
            {
                PreText += "\n\nNote: Each party member loses 2 Health points.";
            }

            Text = PreText.c_str();
        }
    };

    class Story468 : public Story::Base
    {
    public:
        Story468()
        {
            BookID = Book::Type::BOOK1;

            ID = 468;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "You return empty-handed to Akini, apologising for your failure. Akini thanks you for your efforts but is resigned to a grisly death at the hands of her lover. You cannot stay to watch, and leave, despairing at the savagery of the Saltdad court.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story469 : public Story::Base
    {
    public:
        Story469()
        {
            BookID = Book::Type::BOOK1;

            ID = 469;

            Text = "Quick as a flash you dash across the room and come amongst the slaves. You rip the restraining bolts from their manacles, freeing their hands, as your companions prepare to jump from their hiding places. Eventually the orcs spot you, but not before the majority of the slaves are freed.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::SLAVES_DAMAGE_FOR2});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 213}; }
    };

    class Story470 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story470()
        {
            BookID = Book::Type::BOOK1;

            ID = 470;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(52)}))
            {
                return {Book::Type::BOOK1, 613};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            PreText = "You emerge alone from your tent, screwing your courage to the sticking place. You gaze into the light and see it. A skeletal figure, composed of light and hate, a curved longsword in its hands. It is a revenant, a ghost of a dishonoured sword saint. It seeks those undertaking the trial of the kensai to test them.";

            if (!Engine::VERIFY_CODES(party, {Codes::A(51)}))
            {
                PreText += "\n\n\"Akihiro of Chalice,\" intones the revenant. \"Now you know where I dwell. Know that I am for you, and at my hands you shall face your final death. But not now. You are as a child to me. Return to me when you are worthy.\"\n\nYou snarl, your hand dropping to your weapon, but the spirit is already gone, dissolving into the cold wind like scattered rice paper. In sombre quiet, you return to the tent.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(51)}))
            {
                return {Book::Type::BOOK1, 500};
            }
            else
            {
                return {Book::Type::BOOK1, 840};
            }
        }
    };

    class Story471 : public Story::Base
    {
    public:
        Story471()
        {
            BookID = Book::Type::BOOK1;

            ID = 471;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Image = "images/book1/pitiful_waif.png";

            Text = "You walk the streets of Saltdad, watching the bronzed, ragged people and avoiding the sinister Bronzeguard patrols where you can. Eventually you come upon a peasant girl, less than twenty summers old, seated upon an upturned barrel and weeping pitifully. The heartless folk of Saltdad ignore her, some going so far as to cross to the other side of street to avoid her.\n\nNote: You gained the code A14.";

            Choices.clear();
            Choices.push_back(Choice::Base("Ask her what is wrong", {Book::Type::BOOK1, 829}));
            Choices.push_back(Choice::Base("Ignore the pitiful waif", {Book::Type::BOOK1, 75}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(1)}))
            {
                return {Book::Type::BOOK1, 64};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(7)}) && !Engine::VERIFY_CODES(party, {Codes::A(13)}))
            {
                return {Book::Type::BOOK1, 520};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(14)}))
            {
                return {Book::Type::BOOK1, 668};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(14)});
        }
    };

    class Story472 : public Story::Base
    {
    public:
        Story472()
        {
            BookID = Book::Type::BOOK1;

            ID = 472;

            Text = "You raise your hands to show there is no hard feelings. In response, one of your party members is punched in the mouth with the haft of an axe and loses 1 Health point. Weapons are drawn... how did this get so violent so quickly?";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 1 Health", {Book::Type::BOOK1, 587}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IN_PARTY(party, Character::Type::BRASH))
            {
                return {Book::Type::BOOK1, 513};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story473 : public Story::Base
    {
    public:
        Story473()
        {
            BookID = Book::Type::BOOK1;

            ID = 473;

            Location = Location::Type::WITHERED_STEPPES;

            Text = "It takes great patience and skill to find the nomad camp. Little wonder, since they are despised by all the kings of the valley. They are an ancient people, who lived as desert wanderers even before the desolation of Abraxas. They greet you with some confidence, for you are in their homeland, and each nomad is a skilled warrior who can best the toughest soldier.";

            Choices.clear();
            Choices.push_back(Choice::Base("See the nomad chief", {Book::Type::BOOK1, 30}));
            Choices.push_back(Choice::Base("Trade with the nomads", {Book::Type::BOOK1, 768}));
            Choices.push_back(Choice::Base("Bid them farewell and return to the desert", {Book::Type::BOOK1, 115}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story474 : public Story::Base
    {
    public:
        Story474()
        {
            BookID = Book::Type::BOOK1;

            ID = 474;

            Text = "You have re-entered the ruined library. A dead orc lies here, decaying amongst the ruined pages.";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine the black book he was reading", {Book::Type::BOOK1, 119}));
            Choices.push_back(Choice::Base("Close the door and go somewhere else", {Book::Type::BOOK1, 821}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story475 : public Story::Base
    {
    public:
        Story475()
        {
            BookID = Book::Type::BOOK1;

            ID = 475;

            Text = "The guards suspect you are assassins and traitors. One calls out, and suddenly dozens of heavily armed Bronzeguard begin to clank towards you. There are too many to fight, you must flee!";

            Choices.clear();
            Choices.push_back(Choice::Base("Escape the Bronzeguard (Team check: Stealth 4+, Successes: 7)", {Book::Type::BOOK1, 75}, {Book::Type::BOOK1, 55}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::STEALTH}, 4, 7));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (outcome)
            {
                Bye = "You manage to lose them in the warren of alleyways in the city.";
            }
            else
            {
                Bye = "You are overwhelmed and arrested";
            }
        }
    };

    class Story476 : public Story::Base
    {
    public:
        Story476()
        {
            BookID = Book::Type::BOOK1;

            ID = 476;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "Mannus understands what you are driving at. He looks very pleased at the thought of accepting the Iron King's bribes and quickly pens an official document. Soon you have a very favourable TITHE REPORT that greatly reduces the amount Saltdad is required to pay.";

            Bye = "Thanking each other for your time, you depart.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::TITHE_REPORT};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 574}; }
    };

    class Story477 : public Story::Base
    {
    public:
        Story477()
        {
            BookID = Book::Type::BOOK1;

            ID = 477;

            Location = Location::Type::NORTH_ROAD;

            Text = "Where will you travel now?";

            Choices.clear();
            Choices.push_back(Choice::Base("North, to Luutanesh", {Book::Type::BOOK1, 614}));
            Choices.push_back(Choice::Base("West, to the Withered Steppes", {Book::Type::BOOK1, 115}));
            Choices.push_back(Choice::Base("South, towards Cursus", {Book::Type::BOOK1, 822}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story478 : public Story::Base
    {
    public:
        Story478()
        {
            BookID = Book::Type::BOOK1;

            ID = 478;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "With the orcs defeated you quickly search their guard room. In total 20 silver coins lies scattered across the table. You can take either orc's CRUDE BLADE (Fighting +0) if you are short on weapons. The first orc also carried a shield (Armour +2).\n\nNote: You gained the code A56.";

            Bye = "You return to the corridor outside.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 20);

            Engine::GET_CODES(party, {Codes::A(56)});

            Take = {Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE};

            Limit = 2;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 350}; }
    };

    class Story479 : public Story::Base
    {
    public:
        Story479()
        {
            BookID = Book::Type::BOOK1;

            ID = 479;

            Text = "After days of wandering you reach the outskirts of a ramshackle city which stands in the shadow of a ruined palace. Some peasant girls take pity on you, feeding you with precious water. Thanking them you make your way into the city centre.\n\nYou lose 5 silver coins, if you have them.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, -5);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story480 : public Story::Base
    {
    public:
        Story480()
        {
            BookID = Book::Type::BOOK1;

            ID = 480;

            Text = "Since this is the first time you have taught this language Kopu is delighted. He offers you a BLUESTONE in exchange.\n\nNote: In addition, any injured party members are restored to full Health, as you spend many days resting in the tower whilst you teach the language to Kopu.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::Type::TAUGHT_KOPU_BANDO}))
            {
                return {Book::Type::BOOK1, 539};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::BLUESTONE};

            Limit = 1;

            Engine::GET_CODES(party, {Codes::Type::TAUGHT_KOPU_BANDO});

            Engine::REST(party);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 539}; }
    };

    class Story481 : public Story::Base
    {
    public:
        Story481()
        {
            BookID = Book::Type::BOOK1;

            ID = 481;

            Location = Location::Type::SHADED_GATE;

            Text = "The WAYFINDER ROD seems to hum and vibrate in your pack. Pulling it out you see that the strength of the vibrations lead in a south-easterly direction. You follow it for some time, every so often the rod bidding you to change direction, and you walk through the strange, cool, sunless desert for many hours.\n\nFinally, you arrive at an obelisk, carved with mystic runes. The WAYFINDER ROD crumbles away in your hands. Examining the obelisk you find a strange spell carved into its surface.\n\nOddly, the Shaded Gate has appeared again, the rich colour of the real world blazing through the aperture\n\nNote: You can learn the following spell:\n\nShadow Door (Adventure)\n\nYou can detect the secret doors installed by the penumbral lords when they ruled the land.\n\nRecharge: 50 silver";

            Choices.clear();
            Choices.push_back(Choice::Base("Go through the Shaded Gate", {Book::Type::BOOK1, 140}));
            Choices.push_back(Choice::Base("Head south, instead", {Book::Type::BOOK1, 537}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::WAYFINDER_ROD});

            Spells = {Spells::SHADOW_DOOR};
        }
    };

    class Story482 : public Story::Base
    {
    public:
        Story482()
        {
            BookID = Book::Type::BOOK1;

            ID = 482;

            Text = "You consult the instructions and check the ingredients. This should be possible, but you can see why a less talented alchemist might struggle to complete the potions.";

            Choices.clear();
            Choices.push_back(Choice::Base("Brew the potions (Team check: Lore 4+, Successes: 4)", {Book::Type::BOOK1, 136}, {Book::Type::BOOK1, 467}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story483 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story483()
        {
            BookID = Book::Type::BOOK1;

            ID = 483;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You emerge with key in hand and must stifle a cry of shock as you stroll right in front of a pair of armed guards.\n\nNote: Any party members in the weapon stealing team can leap to your defence.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Guard", 4, 4, 4, 8, 0, {Equipment::IRON_SHORTSWORD1}),
                Monster::Base("Guard", 3, 4, 4, 7, 0, {Equipment::IRON_SHORTSWORD1})};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                if (Engine::COUNT(party, Team::Type::WEAPONS) <= 0)
                {
                    destination = {Book::Type::BOOK1, 292};
                }
                else
                {
                    destination = {Book::Type::BOOK1, 611};
                }
            }
            else
            {
                destination = {Book::Type::BOOK1, 292};
            }
        }
    };

    class Story484 : public Story::Base
    {
    public:
        Story484()
        {
            BookID = Book::Type::BOOK1;

            ID = 484;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You have arrived at Unbraaki's teleport circle, deep inside his palace.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::HAS_SPELL(party, {Spells::Type::TELEPORT_CIRCLE}))
            {
                Choices.push_back(Choice::Base("Cast Teleport Circle", {Book::Type::BOOK1, 859}));
            }

            Choices.push_back(Choice::Base("There is nothing you can do here but leave through the only exit.", {Book::Type::BOOK1, 67}));
        }
    };

    class Story485 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story485()
        {
            BookID = Book::Type::BOOK1;

            ID = 485;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                if (party.Members[party.LastSelected].Type == Character::Type::TASHA)
                {
                    return {Book::Type::BOOK1, 37};
                }
                else if (party.Members[party.LastSelected].Type == Character::Type::AKIHIRO_OF_CHALICE)
                {
                    return {Book::Type::BOOK1, 735};
                }
                else
                {
                    return {Book::Type::NONE, -1};
                }
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            PreText = "You dash to Jessica's defence, but alas, you are too far out of position. The axe lands with a sickening thud. Sar Jessica loses 3 Health points. You manage to impale the barbarian from behind, kicking his dying body away from the knight.";

            auto jessica = Engine::FIND_CHARACTER(party, Character::Type::SAR_JESSICA_DAYNE);

            if (Engine::IS_ACTIVE(party, jessica))
            {
                Engine::GAIN_HEALTH(party.Members[jessica], -3);

                if (Engine::SCORE(party.Members[jessica], Attribute::Type::HEALTH) > 0)
                {
                    PreText += "\n\nYou haul Sar Jessica to her feet and spin around to face the rest of your opponents.";
                }
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 753}; }
    };

    class Story486 : public Story::Base
    {
    public:
        Story486()
        {
            BookID = Book::Type::BOOK1;

            ID = 486;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "It's kind of an old trick, but you suggest to the goblins that they might want to poison the orc leader's food with the handy vial of poison you have on you. The goblins eagerly agree, cackling wickedly as they sprinkle liberal drops of the venom across the orc's dinner. Several of the braver goblins vanish, dropping off their deadly meals, only to come scurrying back a few minutes later.\n\nThey are too cowardly to check the results of their poisoning. It looks like you will have to do that for them!\n\nThere's no more to do here. Where will you go now?\n\nNote: You gained the code A63.";

            Choices.clear();
            Choices.push_back(Choice::Base("Leave the kitchen through the north door", {Book::Type::BOOK1, 366}));
            Choices.push_back(Choice::Base("Leave the kitchen through the south door", {Book::Type::BOOK1, 736}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::VIAL_OF_POISON});

            Engine::GET_CODES(party, {Codes::A(63)});
        }
    };

    class Story487 : public Story::Base
    {
    public:
        Story487()
        {
            BookID = Book::Type::BOOK1;

            ID = 487;

            Text = "Quiet as a mouse you step towards the thief, drawing your weapon silently. The thief pauses in the middle of his rifling, and spins around. He is a man of Royce, handsome in a roguish kind of way. \"Well, you're a silent one,\" he grins. \"I'll split the takings in this house fifty-fifty with you if you promise not to make trouble.\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Accept his offer", {Book::Type::BOOK1, 377}));
            Choices.push_back(Choice::Base("Arrest him", {Book::Type::BOOK1, 573}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story488 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story488()
        {
            BookID = Book::Type::BOOK1;

            ID = 488;

            Bye = "You thank her for her time and leave.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::MAGIC_VAULT});

            PreText = "The Everchild nods to her generals, who reluctantly depart her company. She indicates for you to sit and joins you. \"What is on your mind?\" she asks.";

            if (!Engine::VERIFY_CODES(party, {Codes::A(37)}) || Engine::VERIFY_CODES(party, {Codes::A(94)}))
            {
                PreText += "\n\n\"Have you considered suing for peace with the patriarch of Cursus?\" you ask. \"Perhaps further bloodshed can be avoided?\"\n\n\"No,\" she says with certainty. \"The patriarch will never rest whilst I am queen. It is the foul beliefs of his god that have kept the valley in its barbaric state. We can never improve, never develop whilst his agents control all trade, progress and education.\n\nAt best, Saltdad would be a light in the darkness, waiting to be snuffed out. For now, we have sympathy from most of the city states. The other kings are tired of the patriarch's tyranny and wish to assert themselves. That won't last forever. A change of king, a bad harvest, a sudden surge amongst the faithful, would all topple my new regime. No. We must strike hard and fast, whilst the momentum is with us. I appreciate your calls for peace, but it would end as a call for bloodshed without end.\"\n\nThe Everchild rises and looks out the window upon her city. \"I need you to trust me just a little while longer,\" she says. \"I will not war forever. I promise.\"\n\nClearly the Everchild has made her mind up.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(37)}) && !Engine::VERIFY_CODES(party, {Codes::A(94)}))
            {
                return {Book::Type::BOOK1, 795};
            }
            else
            {
                return {Book::Type::NONE, 620};
            }
        }
    };

    class Story489 : public Story::Base
    {
    public:
        Story489()
        {
            BookID = Book::Type::BOOK1;

            ID = 489;

            Location = Location::Type::SALTDAD;

            Text = "You are not sure how it happened. Foul sorcery? Assassins from the House of Silence? Either way, a lone assassin managed to penetrate the defences around the Everchild and stab her with a poisoned dagger. By the time your team have returned you find her in a critical condition, unable to stand, her flesh looking as grey as stone. In her fevered delirium she insists on leading the troops into battle, but this is clearly impossible. You command her to concentrate on getting better, and to focus all her healing energies on herself.\n\nWord soon gets around about the Everchild's condition.\n\nNote: Each army unit in the Saltdad barracks must lose 1 point of Morale.";

            Bye = "You dread the coming of the dawn, but you realise you cannot escape now. You must face what comes with as much courage as you can muster.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MORALE(party, Location::Type::SALTDAD, -1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 162}; }
    };

    class Story490 : public Story::Base
    {
    public:
        Story490()
        {
            BookID = Book::Type::BOOK1;

            ID = 490;

            Text = "The dragonyak bull is delighted to see you again, and bids you join the herd at the waterside. You chat idly with the bull as he tells you the ancient stories of his clan.\n\n\"Once,\" he claims, \"the herd found itself lost in the shadowlands. Seeking shelter from the blistering sun they entered the Shaded Gate. Many cattle were lost. But then Ganch, the spirit bull, appeared, and led the herd west, then south, then west again. The Shaded Gate was found, and the herd emerged into the sun once more, weaker but wiser.\"";

            Bye = "Out of the mouths of bulls, eh? You thank the dragonyaks for their tale, and venture onwards.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 115}; }
    };

    class Story491 : public Story::Base
    {
    public:
        Story491()
        {
            BookID = Book::Type::BOOK1;

            ID = 491;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                if (party.Members[party.LastSelected].Type == Character::Type::AKIHIRO_OF_CHALICE)
                {
                    return {Book::Type::BOOK1, 470};
                }
                else if (party.Members[party.LastSelected].Type == Character::Type::AMELIA_PASS_DAYNE)
                {
                    return {Book::Type::BOOK1, 470};
                }
                else
                {
                    return {Book::Type::BOOK1, 613};
                }
            }
            else
            {
                return {Book::Type::BOOK1, 765};
            }
        }
    };

    class Story492 : public Story::Base
    {
    public:
        Story492()
        {
            BookID = Book::Type::BOOK1;

            ID = 492;

            Text = "You close your eyes and focus. You can feel them... madshards reverberating in the earth, beneath the temple. Extracting them won't be easy. You will need hundreds of diggers to tear up the unwilling earth. What you will find below... who knows?";

            Choices.clear();
            Choices.push_back(Choice::Base("Hire workers from Cursus to excavate the ruins for 5000 silver coins", {Book::Type::BOOK1, 571}, Choice::Type::GAIN_MONEY, -5000));
            Choices.push_back(Choice::Base("Leave the wretched fragments in their earthy tomb", {Book::Type::BOOK1, 515}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(81)}))
            {
                return {Book::Type::BOOK1, 887};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story493 : public Story::Base
    {
    public:
        Story493()
        {
            BookID = Book::Type::BOOK1;

            ID = 493;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "The area is seemingly pockmarked with caves. You decide to search one at random.";

            Choices.clear();
            Choices.push_back(Choice::Base("Search randomly", {{1, NULL, {Book::Type::BOOK1, 797}}, {2, NULL, {Book::Type::BOOK1, 580}}, {3, NULL, {Book::Type::BOOK1, 78}}, {4, NULL, {Book::Type::BOOK1, 855}}, {6, NULL, {Book::Type::BOOK1, 356}}}, 1));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(50)}) && Engine::IN_PARTY(party, Character::Type::AKIHIRO_OF_CHALICE))
            {
                return {Book::Type::BOOK1, 699};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story494 : public Story::Base
    {
    public:
        Story494()
        {
            BookID = Book::Type::BOOK1;

            ID = 494;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You are in a large, rectangular chamber which features a number of complete skeletons which have been carefully assembled and hung up on frames. The centre of the room is dominated by a large stone coffin, whose lid has been carved to resemble a knight.\n\nThere are three doors in the chamber, one in the north wall, a strong looking door in the south wall, and a flimsier looking door in the southwest corner.";

            Choices.clear();
            Choices.push_back(Choice::Base("Poke one of the skeletons", {Book::Type::BOOK1, 876}));
            Choices.push_back(Choice::Base("Examine the coffin", {Book::Type::BOOK1, 414}));
            Choices.push_back(Choice::Base("Go through the north door", {Book::Type::BOOK1, 717}));
            Choices.push_back(Choice::Base("Go through the south door", {Book::Type::BOOK1, 18}));
            Choices.push_back(Choice::Base("Go through the south-west door", {Book::Type::BOOK1, 127}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(58)}))
            {
                return {Book::Type::BOOK1, 211};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story495 : public Story::Base
    {
    public:
        Story495()
        {
            BookID = Book::Type::BOOK1;

            ID = 495;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "During your evening meal, one of your characters has wandered off.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose which character wandered off", {Book::Type::BOOK1, 285}, Choice::Type::CHOOSE_PARTY_MEMBER));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story496 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story496()
        {
            BookID = Book::Type::BOOK1;

            ID = 496;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::CAST_SPELL(party, Team::Type::NONE, Spells::Type::ANIMAL_SPEECH);

            Choices.clear();

            PreText = "You invoke the spell and call up to the monkeys. \"Ho there, groundlings!\" cries one of the monkeys. \"You bring exciting things into our home, do you? Glittering treasures and strange objects of metal and wood?\"\n\n\"What of it?\" you ask.\n\n\"Give us! Give us!\" chant the monkeys. \"Give us something! Or we take it all!\"";

            if (!Engine::VERIFY_CODES(party, {Codes::A(43)}))
            {
                PreText += "\n\nYou must decide what to do.";

                Choices.push_back(Choice::Base("Give the monkeys an item", {Book::Type::BOOK1, 412}, Choice::Type::LOSE_EQUIPMENT, 1));
                Choices.push_back(Choice::Base("Make a run for it", {Book::Type::BOOK1, 879}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 261}; }
    };

    class Story497 : public Story::Base
    {
    public:
        Story497()
        {
            BookID = Book::Type::BOOK1;

            ID = 497;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "You step through the archway, the chamber as black as pitch. You carefully shuffle your feet as you walk, nervous of stepping on anything unpleasant, such as trap. You join hands to keep track of where you are, eventually getting the idea of the shape of the room. The jingle of coins through your fingers as you come to a few flat surfaces suggest that something valuable is here. Sadly, you are not alone. Two snakemen are hiding, weapons drawn, in the corners of the room. Though they are blind like you, they can smell you with their tongues and feel an impression of your body heat. You cannot be certain of where the exit is and must fight to the death!\n\nNote: The snakemen strike first in this battle because they are ambushing you. If you have a HYGLIPH FLOWER the snakemen are put off by its pungent odour and require a 6+ on their attack rolls to inflict damage during this battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::LAST_IN_COMBAT});

            Monsters = {
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 4, 5, 6, 6, 0),
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 4, 5, 6, 5, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 298}; }
    };

    class Story498 : public Story::Base
    {
    public:
        Story498()
        {
            BookID = Book::Type::BOOK1;

            ID = 498;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "Straining every sinew, you scrape the door open inch by inch. To your anger you see that this door merely leads to the vault's antechamber, an even large vault door standing on the other side that would take a dozen men to open. Fortunately, the antechamber does contain some easily accessible treasure. You find 500 silver coins, an odd crystalline wand labelled as a wayfinder rod, a bar of GOLD BULLION and a block of INCENSE.\n\nThere are also a number of financial records, none of which look valuable at first. However, one book catches your eye. It is a ROYAL LEDGER, which bears the crest and authority of House Goldwell, the royal family of Royce. In it are detailed a number of transactions to purchase slaves from Cursus for the royal plantations in the Splintered Isles. The purchase of slaves is illegal in Royce... what is the king up to? Take the ledger, if you wish.\n\nBreaking into the patriarch's vault has been the heist of a lifetime.\n\nNote: You gained the code A83.";

            Bye = "You silently return to the ground floor of the pyramid.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Stealth", {Book::Type::BOOK1, 574}, Choice::Type::ROLL_FOR_ATTRIBUTE_INCREASE, Team::Type::ZIGGURAT, {Attribute::Type::STEALTH}, 1, 2, 0));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 500);

            Take = {Equipment::GOLD_BULLION, Equipment::INCENSE, Equipment::ROYAL_LEDGER};

            Limit = 3;

            Engine::GET_CODES(party, {Codes::A(83)});
        }
    };

    class Story499 : public Story::Base
    {
    public:
        Story499()
        {
            BookID = Book::Type::BOOK1;

            ID = 499;

            Location = Location::Type::CURSUS;

            Text = "You are sailing just south of the temple city of Cursus. Long war galleys patrol the coast, black-clad priests whipping the slave rowers in time to dreadful hymns. Traders are rare here, but so are pirates, with little opportunity and considerable danger facing any that dare to raid the coast.";

            Choices.clear();
            Choices.push_back(Choice::Base("Put into Cursus harbour", {Book::Type::BOOK1, 33}));
            Choices.push_back(Choice::Base("Sail west, along the coast", {Book::Type::BOOK1, 198}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story500 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Team::Type previousTeam = Team::Type::NONE;

        int character = -1;

        Story500()
        {
            BookID = Book::Type::BOOK1;

            ID = 500;

            Text = "\"I am for you Akihiro,\" says your father's spirit. \"You know me now, I think.\"\n\n\"There can be no forgiveness,\" you growl, drawing your blade. \"The stain on our family's honour must be expunged.\"\n\n\"No,\" says the spirit sadly. \"You shall fall as I did. As my grandfather slew me, I shall slay you. Have you children, Akihiro? I pray not. Let you be the last in our line to suffer this tragedy.\"\n\n\"I shall be the first,\" you vow. \"The first in a new dawn for our family. Face the blade of a true kensai, father.\"\n\nThe revenant draws his weapon, and so begins the ultimate duel between father and son.\n\nNote: Only Sar Akihiro may engage in this battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::AKIHIRO_OF_CHALICE;

            character = Engine::FIND_CHARACTER(party, Character::Type::AKIHIRO_OF_CHALICE);

            if (Engine::IS_ACTIVE(party, character))
            {
                previousTeam = party.Members[character].Team;

                Engine::SET_TEAM(party.Members[character]);

                if (Engine::HAS_STATUS(party.Members[character], Character::Status::ENLIGHTENED))
                {
                    Monsters = {Monster::Base("Revenant", 6, 4, 4, 8, 0)};
                }
                else
                {
                    Monsters = {Monster::Base("Revenant", 6, 3, 5, 8, 0)};
                }
            }
            else
            {
                Monsters.clear();
            }
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                if (Engine::IS_ACTIVE(party, character))
                {
                    Engine::SET_TEAM(party.Members[character], previousTeam);
                }

                destination = {Book::Type::BOOK1, 882};
            }
            else
            {
                destination = {Book::Type::BOOK1, 320};
            }
        }
    };

    class Story501 : public Story::Base
    {
    public:
        Story501()
        {
            BookID = Book::Type::BOOK1;

            ID = 501;

            Text = "Making your way through the jungle is tiring work. The area is particularly thick with vegetation, and you must hack and hew your way through the dense rainforest to make any progress at all.\n\nNote: Treat the jungle as if it were an opponent. The jungle does not attack, as such. Instead, each party member takes 1 point of Health damage each time they attack the jungle. This is from scrapes, exhaustion, etc, and you cannot use armour to save against this damage. A party member low on Health can skip their attack if you like, as long as at least one party member attacks each round.";

            Bye = "You hack your way through the jungle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {Monster::Base("Jungle", Monster::Type::JUNGLE, 0, 0, 4, 25, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 763}; }
    };

    class Story502 : public Story::Base
    {
    public:
        Story502()
        {
            BookID = Book::Type::BOOK1;

            ID = 502;

            Text = "You are shocked as the kensai beheads your companion in a smooth stroke with his sword. Somehow you assumed the kensai might show mercy, but it appears the kensai take their vows very seriously.\n\nOther kensai arrive to escort you firmly from the premises.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story503 : public Story::Base
    {
    public:
        Story503()
        {
            BookID = Book::Type::BOOK1;

            ID = 503;

            Text = "Holding your breath, you plunge into the cold water, swimming through the black tunnel. Eventually you spy the tiniest glimpse of light, and swim onwards, your lungs bursting. You emerge into a small but tall chamber, filled with half-submerged smashed pottery. Light streams through a tiny crack in the ceiling, and you can hear sounds of the city high above you.\n\nThe walls are unscalable, but searching the broken vases nets you 40 silver pieces and a HANDSOME BROOCH (Charisma +1).";

            Bye = "Pleased with your find, you swim back to the Everchild and make your report. Satisfied that the only way to go is through the dry arch, she beckons you onwards.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 40);

            Take.clear();

            Limit = 0;

            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                Engine::GET_EQUIPMENT(party.Members[party.LastSelected], {Equipment::HANDSOME_BROOCH1});
            }
            else
            {
                Take = {Equipment::HANDSOME_BROOCH1};

                Limit = 1;
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 523}; }
    };

    class Story504 : public Story::Base
    {
    public:
        Story504()
        {
            BookID = Book::Type::BOOK1;

            ID = 504;

            Text = "You have chosen a perilous course indeed! The waves crash against your vessel as you plough towards the rocks.\n\nChoose someone to steer the vessel.";

            Choices.clear();
            Choices.push_back(Choice::Base("Approach the wreck (Individual check: Survival 4+, Successes: Special)", {Book::Type::BOOK1, -504}, {Book::Type::BOOK1, -504}, {Attribute::Type::SURVIVAL}, 4, 0));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event504 : public Story::Base
    {
    public:
        std::string PreText = "";

        int damage = 0;

        Event504()
        {
            BookID = Book::Type::BOOK1;

            ID = -504;

            DisplayID = 504;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::SHIP_INTACT(party))
            {
                damage = 8 - party.RecentSuccesses;

                Engine::GAIN_HEALTH(party.Fleet[party.CurrentShip], -damage);

                if (party.Fleet[party.CurrentShip].Health > 0)
                {
                    return {Book::Type::NONE, -1};
                }
                else
                {
                    return {Book::Type::BOOK1, 87};
                }
            }
            else
            {
                return {Book::Type::BOOK1, 87};
            }
        }

        void Event(Party::Base &party)
        {
            PreText = "Your ship suffers " + std::to_string(damage) + " damage.\n\nDespite the collisions you manage to steer your ship adjacent to the wrecked vessel. You order some of your crew to swing aboard the vessel and loot it. They manage to recover a single cargo unit of Wine. Not wishing to push your luck, you sail away from the wreck as soon as your last crewman is aboard. Of the stranded sailor there is no longer any sign.";

            if (party.CurrentShip >= 0 && party.CurrentShip < party.Fleet.size() && party.Fleet[party.CurrentShip].Cargo.size() < party.Fleet[party.CurrentShip].MaximumCargo)
            {
                party.Fleet[party.CurrentShip].Cargo.push_back(Cargo::Type::WINE);
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 240}; }
    };

    class Story505 : public Story::Base
    {
    public:
        Story505()
        {
            BookID = Book::Type::BOOK1;

            ID = 505;

            Text = "A row of rowdy taverns stand on the wooden boardwalk built for the harbourside. The taverns are frequently flooded by the incoming tide, and no attempts have been made to sweep away the pooled saltwater that settles in their sunken floors. Frothy waves splash at the windows as you down a tankard of cheap grog at your table, and you wonder how the building manages to stay up.\n\nA nearby sailor sings a sad song about the Maiden of the Depths. She was a pure-hearted girl who was tossed over the side of a ship during one of the frequent storms in the Passage of Illikein around the Splintered Isles. The legend goes that those who present the Maiden with flowers receive rich rewards from sunken hulks beneath the waves.\n\nNote: You may stay at the tavern and recover your strength. For every 5 silver coins you spend, each party member can recover 1 Health point. Spell casters can also spend silver here to recharge their spells, purchasing components in the nearby marketplace and going into meditation in the privacy of their rooms. You gained the code A30.";

            RestPrice = 5;
            CanRecharge = true;

            Choices.clear();

            Controls = Story::Controls::INN;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(30)});

            party.CurrentShip = -1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story506 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Team::Type previousTeam = Team::Type::NONE;

        int character = -1;

        Story506()
        {
            BookID = Book::Type::BOOK1;

            ID = 506;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "\"No, Yu Yan,\" you say. \"I cannot allow that.\"\n\n\"A pity,\" she says. \"So be it.\" She draws a long green blade, and goes into a crouch, her sword held high.\n\nThe duel is on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::AKIHIRO_OF_CHALICE;

            character = Engine::FIND_CHARACTER(party, Character::Type::AKIHIRO_OF_CHALICE);

            if (Engine::IS_ACTIVE(party, character))
            {
                previousTeam = party.Members[character].Team;

                Engine::SET_TEAM(party.Members[character]);

                Monsters = {Monster::Base("Yu Yuan", 5, 4, 4, 9, 0)};
            }
            else
            {
                Monsters.clear();
            }
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                if (Engine::IS_ACTIVE(party, character))
                {
                    Engine::SET_TEAM(party.Members[character], previousTeam);
                }

                destination = {Book::Type::BOOK1, 184};
            }
            else
            {
                destination = {Book::Type::BOOK1, 450};
            }
        }
    };

    class Story507 : public Story::Base
    {
    public:
        Story507()
        {
            BookID = Book::Type::BOOK1;

            ID = 507;

            Text = "You open the door into a musty library, the air thick with dust and damp, rotting pages. The floor is covered in mouldering books. Around the walls are wooden shelves, some still packed with ruined books.\n\nSitting in the middle of the room, facing away from you, is a burly orc who appears to be reading a black- bound book. A glowing lantern is positioned next to him to enable him to see. He seems completely engrossed in his reading, and does not appear to have noticed your entrance.";

            Choices.clear();
            Choices.push_back(Choice::Base("Ask the orc what he is reading", {Book::Type::BOOK1, 664}));
            Choices.push_back(Choice::Base("Sneak up on the orc", {Book::Type::BOOK1, 414}));
            Choices.push_back(Choice::Base("Close the door and go somewhere", {Book::Type::BOOK1, 821}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(71)}))
            {
                return {Book::Type::BOOK1, 474};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story508 : public Story::Base
    {
    public:
        Story508()
        {
            BookID = Book::Type::BOOK1;

            ID = 508;

            Text = "You make your way to the training grounds, where you see the soldiers of the Everchild at practice. All the troops you have gathered for her can be found here, their armour and weapons glinting in the unforgiving sun.\n\n\"We can always use more soldiers,\" comments general Che Long. \"I know the Everchild has asked you to find some more from the leaders in the valley, but we can also muster more troops here if we can find the money.\"\n\n\"How much will it cost to levy more troops?\" you ask, checking your purse.\n\n\"More than any number of silver coins!\" laughs Che Long. \"We are talking about hundreds of soldiers, including weapons and supplies. You would need bars of GOLD BULLION to fully pay for the cost.\"\n\nYou ponder Che Long's request. \"If I found some, what kind of soldiers could we raise?\"\n\n\"For one bar of GOLD BULLION we could raise a decent troop of light infantry,\" says Che Long. \"But ideally, we would want two GOLD BULLION bars. With that we could retrain and equip the Bronzeguard. We still have their armour and equipment -- but teaching men to fight to that standard is a long and expensive process.\"\n\nIf you have any bars of GOLD BULLION you can purchase additional troops for the Everchild.";

            Choices.clear();
            Choices.push_back(Choice::Base("Spend one GOLD BULLION on some light infantry", {Book::Type::BOOK1, 900}, Choice::Type::PAY_WITH, {Equipment::GOLD_BULLION}, 1));
            Choices.push_back(Choice::Base("Spend two GOLD BULLION on restoring the Bronzeguard", {Book::Type::BOOK1, 143}, Choice::Type::PAY_WITH, {Equipment::GOLD_BULLION}, 2));
            Choices.push_back(Choice::Base("Leave the training ground", {Book::Type::BOOK1, 620}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            //TODO: Implement codes A33 and A100 troop transfers
            Engine::GET_CODES(party, {Codes::Type::MAGIC_VAULT});
        }
    };

    class Story509 : public Story::Base
    {
    public:
        Story509()
        {
            BookID = Book::Type::BOOK1;

            ID = 509;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "Unbraaki collapses to the ground, flames still pouring from his palms, igniting the palace. You only just have time to grasp his spellbook from his hands before crashing through the windows, away from the blaze.\n\nUnbraaki's guards cry in horror and amazement as they see the home of their master consumed in flames. Seeing no reason to remain, they scatter into the desert, leaving their master and his sorcerous monkeys to burn.\n\nAs the morning light spreads across the desert you see the extent of the devastation. The palace is a scorched ruin, though curiously a single entrance to the basement remains. Looking through Unbraaki's spellbook you see it contains many interesting notes on the nature of magic, as well as an interesting spell.\n\nNote: You gained the code A88. You can learn the following spell:\n\nSilver Tongue (Adventure)\n\nYour confidence grows as you summon this spell. Cast this spell when you fail a Charisma check. You gain an additional 3 automatic successes for this check only.\n\nRecharge: 75 silver\n\nIn addition, you may raise the Lore skill of one character by a single point for reading Unbraaki's fascinating theories on magic.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Lore", {Book::Type::BOOK1, -509}, Choice::Type::RAISE_ATTRIBUTE_SCORE, {Attribute::Type::LORE}, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(88)});

            Spells = {Spells::SILVER_TONGUE};
        }
    };

    class Event509 : public Story::Base
    {
    public:
        Event509()
        {
            BookID = Book::Type::BOOK1;

            ID = -509;

            DisplayID = 509;

            Text = "What will you do now?";

            Choices.clear();
            Choices.push_back(Choice::Base("Explore the basement of the palace", {Book::Type::BOOK1, 67}));
            Choices.push_back(Choice::Base("Leave the smouldering remains behind", {Book::Type::BOOK1, 265}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story510 : public Story::Base
    {
    public:
        Story510()
        {
            BookID = Book::Type::BOOK1;

            ID = 510;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You find you are unable to reach a state of deep mediation, your trials pressing upon your mind. It was this lack of clarity that caused you to fail in your first attempts at becoming kensai. Shaking your head at your own inadequacies, you decide to leave the matter to fate, you stroll towards the hill in front of you and enter the first cave you come across.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 24}; }
    };

    class Story511 : public Story::Base
    {
    public:
        Story511()
        {
            BookID = Book::Type::BOOK1;

            ID = 511;

            Location = Location::Type::WEST_ROAD;

            Text = "The sun crawls over the horizon, spreading a grey haze across the boundless desert. You are pleased to be raised above the sands on a built-up highway, even if the road itself is in dreadful condition. To the east the crowded city of Saltdad beckons, its decaying palace looming over it like a gnarled hag.";

            Choices.clear();
            Choices.push_back(Choice::Base("Random Event", {{2, NULL, {Book::Type::BOOK1, 666}}, {6, NULL, {Book::Type::BOOK1, 219}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story512 : public Story::Base
    {
    public:
        Story512()
        {
            BookID = Book::Type::BOOK1;

            ID = 512;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "You manage to persuade the crowd that the dead man has been honoured enough, and that the last thing he would want was violence with the state after working so selflessly for it. Reluctantly the crowd disperse, taking the casket for burial. The kensai thank you for your support and then carry on their way.\n\nThis was a sensitive situation which you have diffused.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Charisma", {Book::Type::BOOK1, 450}, Choice::Type::ROLL_FOR_ATTRIBUTE_INCREASE, {Attribute::Type::CHARISMA}, 1, 1, 0));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story513 : public Story::Base
    {
    public:
        Story513()
        {
            BookID = Book::Type::BOOK1;

            ID = 513;

            Text = "Thinking quickly, you point to the knife-wielding man and address the barbarians. \"Oh, dear! You're not working for Gareth the Snitch, are you? Poor fellows. He's always getting people to do his dirty work, and yet when it comes time for payment he uses clipped coins. Well... there's one born every minute, I suppose.\"\n\nThe barbarians turn angrily upon the small man. Your instinct was right. These are paid assassins, but they don't know their employer very well. The man with the knife panics and begins to flee into the crowd, pursued by the howling barbarians.\n\nNote: You gained the code A90.";

            Bye = "You take the opportunity to slip away.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(90)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story514 : public Story::Base
    {
    public:
        Story514()
        {
            BookID = Book::Type::BOOK1;

            ID = 514;

            Text = "The fighting is chaotic, and more slaves come to join the battle as the fight rages on. Sar Jessica is separated during the scrum. After slaying an opponent, she is suddenly bull-rushed to the ground by an enormous Lhasbreath barbarian, her weapon scattering from her grasp. The barbarian hefts his axe high above the helpless knight. You must rescue her!";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose another party member to come to her rescue", {Book::Type::BOOK1, 485}, Choice::Type::CHOOSE_CHARACTER_EXCEPT, Character::Type::SAR_JESSICA_DAYNE));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story515 : public Story::Base
    {
    public:
        Story515()
        {
            BookID = Book::Type::BOOK1;

            ID = 515;

            Location = Location::Type::MORDAIN;

            Image = "images/book1/city_of_mordain.png";

            Text = "You have arrived in the ruins of the city of Mordain, sacked over four hundred years ago by the priests of Cursus and the king of Lhasbreath. It is a place of ill-portent, shunned by the locals. No building fully stands in this coastal city, and even its walls are shattered and crumbling.";

            Choices.clear();
            Choices.push_back(Choice::Base("Explore the temple district", {Book::Type::BOOK1, 432}));
            Choices.push_back(Choice::Base("Explore the broken merchant quarter", {Book::Type::BOOK1, 79}));
            Choices.push_back(Choice::Base("Pick your way to the harbour", {Book::Type::BOOK1, 243}));
            Choices.push_back(Choice::Base("Head west, across the desert toward Lhasbreath", {Book::Type::BOOK1, 752}));
            Choices.push_back(Choice::Base("Head north, into the desert", {Book::Type::BOOK1, 202}));
            Choices.push_back(Choice::Base("Head east, across the desert towards Cursus", {Book::Type::BOOK1, 657}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story516 : public Story::Base
    {
    public:
        Story516()
        {
            BookID = Book::Type::BOOK1;

            ID = 516;

            Location = Location::Type::SOUTHCOAST_VALLEY_OF_BONES;

            Text = "The wind fills your sails as you glide in the straits between the shores of the valley and the jungle-filled island of Viaan.";

            Choices.clear();
            Choices.push_back(Choice::Base("Random Event", {{2, NULL, {Book::Type::BOOK1, 679}}, {6, NULL, {Book::Type::BOOK1, 144}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story517 : public Story::Base
    {
    public:
        Story517()
        {
            BookID = Book::Type::BOOK1;

            ID = 517;

            Text = "The Temple of the Unbroken collapses into a pile of broken stones behind you, great clouds of dust bursting from the shattered chambers. You think yourselves lucky to have survived.\n\nNote: You gained the code A41.";

            Bye = "After pausing to rest for a while you gather yourselves and prepare to move on.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member and increase their maximum, unwounded Health score by 1 point", {Book::Type::BOOK1, 860}, Choice::Type::ADD_MAX_HEALTH, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(41)});
        }
    };

    class Story518 : public Story::Base
    {
    public:
        Story518()
        {
            BookID = Book::Type::BOOK1;

            ID = 518;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "This will be an untypical battle. Whilst it is true you can crush dozens of beetles with each stamp you will be quickly swarmed. Their nasty, biting mandibles can sheer off flesh like tiny razors.\n\nYou cannot add the Fighting bonus from your weapons in this fight -- they are less effective than simply brushing off and standing on the beetles. The beetles will not roll for an attack. Instead each round they inflict 1 point of Health damage on each party member. Armour cannot help you against this damage.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {Monster::Base("Beetle Swarm", Monster::Type::BEETLE_SWARM, 0, 0, 3, 25, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 251}; }
    };

    class Story519 : public Story::Base
    {
    public:
        Story519()
        {
            BookID = Book::Type::BOOK1;

            ID = 519;

            Text = "The bridge holds, much to your relief, and you have soon crossed to the other side in safety.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story520 : public Story::Base
    {
    public:
        Story520()
        {
            BookID = Book::Type::BOOK1;

            ID = 520;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "You have been charged by the Everchild to attempt to destroy Malronac the Deathengine. This will be a fearsome task indeed.";

            Choices.clear();
            Choices.push_back(Choice::Base("Spy on the palace until you see him emerge", {Book::Type::BOOK1, 733}));
            Choices.push_back(Choice::Base("The Everchild's request is too much for you", {Book::Type::BOOK1, 75}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story521 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story521()
        {
            BookID = Book::Type::BOOK1;

            ID = 521;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Bye = "Once they have exhausted themselves you are thrown out of the ziggurat.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You babble an excuse about wishing to bathe in the beauty of their faith, but the zealots are having none of it. Soon guards arrive, and you are stripped to the waist and tied to the pillars in the grand hall. The zealots cruelly whip you.\n\nNote: Your party loses ";

            auto result = Engine::ROLL(1);

            Engine::GAIN_HEALTH(party, Team::Type::ZIGGURAT, -result);

            PreText += std::to_string(result) + " Health point";

            if (result > 1)
            {
                PreText += "s";
            }

            PreText += ".";

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 340}; }
    };

    class Story522 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story522()
        {
            BookID = Book::Type::BOOK1;

            ID = 522;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The common temples of Chalice are dedicated to their strange meditative religion. They are open structures without walls, although low wooden screens are used to separate the different orders of worshipers. You are surprised that no one here worships the God King, but merely pays reverence to his immortal insights into their faith. You cannot receive blessings here since there is no external god to bless you, instead all truth and beauty must be found from within through a process of long introspection.\n\nClearly, only a native of this land could master such intricacies.";

            if (!Engine::IN_PARTY(party, Character::Type::AKIHIRO_OF_CHALICE))
            {
                PreText += " Besides wondering at the strangeness of it all, you can gain no benefit here.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::IN_PARTY(party, Character::Type::AKIHIRO_OF_CHALICE))
            {
                return {Book::Type::BOOK1, 856};
            }
            else
            {
                return {Book::Type::BOOK1, 450};
            }
        }
    };

    class Story523 : public Story::Base
    {
    public:
        Story523()
        {
            BookID = Book::Type::BOOK1;

            ID = 523;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You emerge into a large chamber, filled with cobwebs which incinerate at the touch of your torches. The floor of this chamber has half collapsed, and in a small crevice you can make out the eggs of giant spiders, heaped upon one another. The adult spiders lurk in the ceiling corners of the chamber, waiting patiently for a chance to strike. You could make your way carefully through the crevice, since sloped rubble is piled up on either side of the drop -- but you would have to carefully navigate past the eggs. You also spy a narrow ledge around the crevice which might allow you to avoid the crevice completely, provided you could all make it across without falling. Or perhaps it would be wiser to attack the spiders whilst you are on firm ground, and get a battle out of the way?";

            Choices.clear();
            Choices.push_back(Choice::Base("Creep through the crevice", {Book::Type::BOOK1, 80}));
            Choices.push_back(Choice::Base("Sneak along the ledge", {Book::Type::BOOK1, 895}));
            Choices.push_back(Choice::Base("Provoke the spiders into battle", {Book::Type::BOOK1, 133}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story524 : public Story::Base
    {
    public:
        Story524()
        {
            BookID = Book::Type::BOOK1;

            ID = 524;

            Text = "In the dead of night you approach Dulcimer's house, in the rich quarter of the city. It is a red-roofed cubical block of stone and rough cement, with lacklustre guard patrols orbiting the estate at uneven intervals. You spy what looks to be the outdoor entrance to the basement; a large trapdoor wide enough to roll barrels into.\n\nWaiting for the right moment, you dash to the basement doors, some of you keeping watch whilst another attempts to break the padlock on the basement.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            Choices.clear();

            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::PRYBAR}))
            {
                Choices.push_back(Choice::Base("Break into the basement (Individual check: Fighting 4+, Successes: 2)", {Book::Type::BOOK1, 766}, {Book::Type::BOOK1, 468}, {Attribute::Type::FIGHTING}, 4, 2, false));
            }
            else
            {
                Choices.push_back(Choice::Base("Break into the basement (Individual check: Fighting 5+, Successes: 2)", {Book::Type::BOOK1, 766}, {Book::Type::BOOK1, 468}, {Attribute::Type::FIGHTING}, 5, 2, false));
            }
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            Bye = NULL;

            if (!outcome)
            {
                Bye = "You are still struggling with the padlock when the guards arrive. You are chased away.";
            }
        }
    };

    class Story525 : public Story::Base
    {
    public:
        Story525()
        {
            BookID = Book::Type::BOOK1;

            ID = 525;

            Text = "This is harder than it looks. Sand is tricky stuff and it is easy to accidentally leave a limb uncovered.";

            Choices.clear();
            Choices.push_back(Choice::Base("Hide from the barbarians (Team check: Stealth 5+, Successes: 4)", {Book::Type::BOOK1, 840}, {Book::Type::BOOK1, 238}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::STEALTH}, 5, 4));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            Bye = NULL;

            if (!outcome)
            {
                Bye = "The barbarians spot you, and begin to wheel towards you, weapons drawn.";
            }
        }
    };

    class Story526 : public Story::Base
    {
    public:
        Story526()
        {
            BookID = Book::Type::BOOK1;

            ID = 526;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Your physical strength and martial technique intimidate the slaves, who grumble and back down, allowing you to rip the choicest and best-cooked flesh off the goat first. One of the slaves, a fellow called Tommul, mutters dark warnings about revenge. Snarling at him, you retreat to a corner to finish your food.\n\nNote: You gained the code A2.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(2)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 865}; }
    };

    class Story527 : public Story::Base
    {
    public:
        Story527()
        {
            BookID = Book::Type::BOOK1;

            ID = 527;

            Text = "You cast the spell, but the shadow door is blocked on the other side by a huge stone slab. The weird magics of the shadow door make getting a grip on the stone block impossible. Eventually you are forced to give up.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 717}; }
    };

    class Story528 : public Story::Base
    {
    public:
        Story528()
        {
            BookID = Book::Type::BOOK1;

            ID = 528;

            Text = "You are not quick enough. You are still hanging onto the rope when the thief cuts it, sending your whole party into a heap on the ground. You dust yourselves off and consider attempting a pursuit, but the thief has made good his escape, and the only way to chase him would be to break into the house.\n\nNote: Each party member loses 1 Health point.";

            Bye = "Shaking your head at his audacity you make your way into town.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story529 : public Story::Base
    {
    public:
        Story529()
        {
            BookID = Book::Type::BOOK1;

            ID = 529;

            Text = "The heist began well, with you being able to snatch a GOLD PORTRAIT and a BRONZE SCORPION.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::WALL_CLIMBING;

            Take = {Equipment::GOLD_PORTRAIT, Equipment::BRONZE_SCORPION};

            Limit = 2;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, -529}; }
    };

    class Event529 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Event529()
        {
            BookID = Book::Type::BOOK1;

            ID = -529;

            DisplayID = 529;

            Text = "As you are rifling through a chest of drawers you disturb a mirror, which crashes to the floor with an almighty smash! Soon, the house guards from the ground floor come swarming up upon you. You draw your swords and, back to back with Brekken's team, you prepare to fight to the death to defend your loot.\n\nNote: Only members of the wall-climbing team may help in this fight.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::Type::WALL_CLIMBING_AND_DOOR}))
            {
                Team = Team::Type::NONE;
            }
            else
            {
                Team = Team::Type::WALL_CLIMBING;
            }

            Monsters = {
                Monster::Base("Guard", 4, 4, 4, 7, 0),
                Monster::Base("Guard", 4, 4, 3, 9, 0),
                Monster::Base("Guard", 5, 5, 4, 11, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            Bye = NULL;

            if (result == Engine::Combat::VICTORY)
            {
                if (Engine::VERIFY_CODES(party, {Codes::Type::WALL_CLIMBING_AND_DOOR}))
                {
                    destination = {Book::Type::BOOK1, 833};
                }
                else
                {
                    if (Engine::COUNT(party, Team::Type::WALL_CLIMBING) <= 0)
                    {
                        Bye = "All members of the wall-climbing team are dead.";

                        Engine::LOSE_ALL(party, Team::Type::WALL_CLIMBING);

                        destination = {Book::Type::BOOK1, 75};
                    }
                    else
                    {
                        destination = {Book::Type::BOOK1, 833};
                    }
                }
            }
            else
            {
                Bye = "All members of the wall-climbing team are dead.";

                Engine::LOSE_ALL(party, Team::Type::WALL_CLIMBING);

                destination = {Book::Type::BOOK1, 75};
            }
        }
    };

    class Story530 : public Story::Base
    {
    public:
        Story530()
        {
            BookID = Book::Type::BOOK1;

            ID = 530;

            Location = Location::Type::CHALICE;

            Text = "\"Now it is time to demonstrate your bladecraft,\" nods Honnu. \"And it must be against a foe that can test you spiritually as well as physically. It is known that somewhere in the central deserts of the valley dwells a revenant -- the undead spirit of a man who failed his kensai trials so disastrously he is doomed to walk the earth forever. You must find this spirit and defeat it in single combat.\"\n\nYou feel no fear. \"I shall,\" you vow. \n\n\"This task will not be easy,\" says Honnu. \"Get yourself a good sword, and train yourself to the highest standard before you track down your foe. It will be the duel that defines your family's fate forever. When you have slain it, return to me.\"\n\nNote: You gained the code A51.";

            Bye = "You stand and bow, pondering where to begin your search.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_CODES(party, {Codes::A(50)});

            Engine::GET_CODES(party, {Codes::A(51)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story531 : public Story::Base
    {
    public:
        Story531()
        {
            BookID = Book::Type::BOOK1;

            ID = 531;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "You have been sold to a rice farmer in the city of Cursus, and work knee-deep in muck along the Cold River. Your surroundings are suitably dramatic; huge black step pyramids dominate the landscape, the holy temples of Cursus from which chants and deep choral hymns echo at all times of day. Your owner is a pious man, and surprisingly gentle for a slave owner. Whipping is rare, although the threat of execution hangs over anyone who does not work hard enough.\n\nYour thoughts soon turn to escape. There seem two likely methods. You will be helping to construct a granary next week, and builders are freed from their chains so they can move around more freely. It would involve a bit of a dramatic breakout, but it might be possible.\n\nOtherwise you might be able to persuade priest who owns you to free you, if you express enough devotion to his god.\n\nNote: Your party members to are restored full Health as they carry out their labours.";

            Choices.clear();
            Choices.push_back(Choice::Base("Attempt a breakout", {Book::Type::BOOK1, 785}));
            Choices.push_back(Choice::Base("Try and charm your way out", {Book::Type::BOOK1, 570}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::REST(party);
        }
    };

    class Story532 : public Story::Base
    {
    public:
        Story532()
        {
            BookID = Book::Type::BOOK1;

            ID = 532;

            Text = "Clavod is not happy to see you. \"Since your political machinations we have been forced to free our miners and pay them a wage. Many of our warehouses now contain sleeping quarters rather than salt. Why, the place is barely worth keeping anymore,\" he moans.\n\n\"The wages of sin are high,\" you say dryly. \"You've lived off fat profits for long enough.\"\n\nClavod merely sniffs with contempt. \"I'm no longer paying bounties for troglodytes,\" he says airily. \"The queen can look to the protection of free men. I suppose I can still sell you salt, I'll take money even from the most sanctimonious wretch.\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Demand entrance to the mines as representatives of the queen", {Book::Type::BOOK1, 227}));
            Choices.push_back(Choice::Base("Express interest in buying salt for your ships", {Book::Type::BOOK1, 575}));
            Choices.push_back(Choice::Base("Leave with distaste", {Book::Type::BOOK1, 722}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story533 : public Story::Base
    {
    public:
        Story533()
        {
            BookID = Book::Type::BOOK1;

            ID = 533;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Text = "You have already looted this chamber of its funeral goods. It would serve no point to disturb the dead further.";

            Bye = "You return to the crossroads.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 46}; }
    };

    class Story534 : public Story::Base
    {
    public:
        Story534()
        {
            BookID = Book::Type::BOOK1;

            ID = 534;

            Text = "Although the desert nights are cold, the temperature tonight is particularly freezing. You pitch up your tents and huddle together for warmth. Outside the tents you suddenly perceive a light, like the flame of a lantern, only brighter. Something stalks around your tent menacingly, the crunch of bootprints on the sand. A sudden fear grips you, and it is difficult to leave the safety of your tent. You briefly decide together who should check out this frightening phenomenon.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose someone to look outside", {Book::Type::BOOK1, 765}, Choice::Type::CHOOSE_PARTY_MEMBER));
            Choices.push_back(Choice::Base("Decide to all go out together, although this feels dangerous", {Book::Type::BOOK1, 613}));
            Choices.push_back(Choice::Base("Stay safely inside the tent", {Book::Type::BOOK1, 584}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story535 : public Story::Base
    {
    public:
        Story535()
        {
            BookID = Book::Type::BOOK1;

            ID = 535;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Image = "images/book1/shattered_ziggurat.png";

            Text = "You travel through the desert for many days, the desolation and quiet of the sands absolute and still. On the fourth day you cross over a dune to see a colossal wreck before you. It is a shattered ziggurat of black stone, somewhat similar in design to the slab-like temples in the city of Cursus. This structure has been blasphemously left to disintegrate with age. You wonder why the zealous priests of Cursus would allow such a thing to happen?";

            Choices.clear();
            Choices.push_back(Choice::Base("Investigate the temple", {Book::Type::BOOK1, 708}));
            Choices.push_back(Choice::Base("Go north, into the Withered Steppes", {Book::Type::BOOK1, 115}));
            Choices.push_back(Choice::Base("West, into the desert", {Book::Type::BOOK1, 202}));
            Choices.push_back(Choice::Base("South, towards the coast", {Book::Type::BOOK1, 657}));
            Choices.push_back(Choice::Base("East, towards the Northroad", {Book::Type::BOOK1, 822}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story536 : public Story::Base
    {
    public:
        Story536()
        {
            BookID = Book::Type::BOOK1;

            ID = 536;

            Text = "As you sail along the coast you come upon the sight of a colossal wreck. A Drakehallow greatship, a four-master from the looks of her, has dashed herself on the rocks. Powerful winds buffet the cliff face, and you are already on half sails to ride out the winds. A little way off the wreck, on a tall rock against the cliffside, you can see a lone figure desperately clinging on for life. The spray and powerful waves threaten to engulf him at any moment.\n\nNote: You gained the code A99.";

            Choices.clear();
            Choices.push_back(Choice::Base("Launch a lifeboat and try to rescue the man", {Book::Type::BOOK1, 667}));
            Choices.push_back(Choice::Base("Ignore the man and try to loot the wreck", {Book::Type::BOOK1, 504}));
            Choices.push_back(Choice::Base("Refuse to risk your ship and sail onwards", {Book::Type::BOOK1, 240}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(99)}))
            {
                return {Book::Type::BOOK1, 186};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(99)});
        }
    };

    class Story537 : public Story::Base
    {
    public:
        Story537()
        {
            BookID = Book::Type::BOOK1;

            ID = 537;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "There is not even a breath of wind in this silent hell. There is nothing to see for miles around. Your limbs ache.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 1 Health", {Book::Type::BOOK1, -537}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event537 : public Story::Base
    {
    public:
        Event537()
        {
            BookID = Book::Type::BOOK1;

            ID = -537;

            DisplayID = 537;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "Where will you go?";

            Choices.clear();
            Choices.push_back(Choice::Base("North", {Book::Type::BOOK1, 589}));
            Choices.push_back(Choice::Base("West", {Book::Type::BOOK1, 692}));
            Choices.push_back(Choice::Base("South", {Book::Type::BOOK1, 273}));
            Choices.push_back(Choice::Base("East", {Book::Type::BOOK1, 886}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story538 : public Story::Base
    {
    public:
        Story538()
        {
            BookID = Book::Type::BOOK1;

            ID = 538;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "The tunnel emerges into a larger temple room, in which snakemen appear to be at worship by a flat-black altar. They hiss in alarm as you enter, reaching for their wickedly curved swords. You narrow your eyes in concentration as their swaying bodies slither towards you.\n\nNote: If you have a HYGLIPH FLOWER the snakemen are put off by its pungent odour and require a 5+ on their attack rolls to inflict damage during this battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 4, 4, 3, 5, 0),
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 4, 4, 3, 8, 0),
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 4, 4, 3, 4, 0),
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 3, 4, 3, 6, 0),
                Monster::Base("Snakeman Champion", Monster::Type::SNAKEMAN, 6, 4, 3, 12, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 748}; }
    };

    class Story539 : public Story::Base
    {
    public:
        Story539()
        {
            BookID = Book::Type::BOOK1;

            ID = 539;

            Text = "Kopu is delighted to see you again and beckons you inside his comfortably furnished tower. Open books are spread across his table, and he beckons his slaves to remove them as he fetches some wine. Kopu is interested in all kinds of languages. If you have been taught any of the languages below, you can teach him the rudiments.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::VERIFY_CODES_ANY(party, {Codes::Type::SPEAK_BANDO}))
            {
                Choices.push_back(Choice::Base("Teach Kopu the Bando language", {Book::Type::BOOK1, 480}));
            }

            if (Engine::VERIFY_CODES_ANY(party, {Codes::Type::SPEAK_ORCISH}))
            {
                Choices.push_back(Choice::Base("Teach Kopu the Orc language", {Book::Type::BOOK1, 444}));
            }

            if (Engine::VERIFY_CODES_ANY(party, {Codes::Type::SPEAK_DREAR}))
            {
                Choices.push_back(Choice::Base("Teach Kopu the Drear language", {Book::Type::BOOK1, 378}));
            }

            Choices.push_back(Choice::Base("Bid Kopu farewell", {Book::Type::BOOK1, 775}));
        }
    };

    class Story540 : public Story::Base
    {
    public:
        Story540()
        {
            BookID = Book::Type::BOOK1;

            ID = 540;

            Text = "Representatives from all the settlements in the valley, bar Cursus, now fill the Everchild's war room. A map of the valley, carved onto the wall behind the throne, illuminates the Everchild's many lands and legions. A hush descends as the girl queen enters the chamber and climbs the platform which raises her seat above all others. She clicks her fingers, and Che Long, her guardian, presents her with a long, steel sword. She points it at the map, right above Cursus.\n\n\"There is now only one obstacle that stands between us and the unity of the valley,\" says the Everchild boldly. \"Cursus has not been idle. The patriarch has hired mercenaries from Royce and Thalsia to bolster his armies of fanatics. Despite sorcery being forbidden in their religion, they have employed the dark wizard Descantos to fortify their defences. The Cursites have skilled warriors. The Cursites have loyal warriors. But they do not have warriors who are both skilled and loyal. Something must give, and it is this miss-match between their forces that I intend to exploit.\"\n\n\"To bolster our chances,\" she continues, returning the sword to Che Long, \"I intend to rob the patriarch of some of these advantages. My agents will either dispose of Descantos or pay-off the mercenaries to abandon the patriarch's cause. I believe that without either of these advantages, the patriarch cannot hold against us.\"\n\n\"What of your safety, majesty?\" prompts one of her generals. \"The attempts against your life have increased in intensity since you took Clifftop. We have reason to believe another attempt will be made on the eve of battle.\"\n\n\"My personal security is peerless, and my followers loyal, do not fear for me,\" rebuts the Everchild. \"All I require of you is that you look to your legions.\"\n\nShe turns to you with expectation. \"And you, my friends, tell me: Is now the time to make the attack?\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Launch the attack now", {Book::Type::BOOK1, 268}));
            Choices.push_back(Choice::Base("Wait until you are ready", {Book::Type::BOOK1, 620}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story541 : public Story::Base
    {
    public:
        Story541()
        {
            BookID = Book::Type::BOOK1;

            ID = 541;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You get to work attempting to rip the barricade down.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::PRYBAR}))
            {
                Choices.push_back(Choice::Base("Pull down the barricade (Team check: Fighting 4+, Successes: 3)", {Book::Type::BOOK1, 630}, {Book::Type::BOOK1, -541}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::FIGHTING}, 4, 3, false));
            }
            else
            {
                Choices.push_back(Choice::Base("Open the vault (Team check: Fighting 5+, Successes: 3)", {Book::Type::BOOK1, 630}, {Book::Type::BOOK1, -541}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::FIGHTING}, 5, 3, false));
            }

            Choices.push_back(Choice::Base("Make your way back down the stairs", {Book::Type::BOOK1, 23}));
        }
    };

    class Event541 : public Story::Base
    {
    public:
        Event541()
        {
            BookID = Book::Type::BOOK1;

            ID = -541;

            DisplayID = 541;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You strain yourselves.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 1 Health", {Book::Type::BOOK1, 541}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story542 : public Story::Base
    {
    public:
        Story542()
        {
            BookID = Book::Type::BOOK1;

            ID = 542;

            Location = Location::Type::NORTH_ROAD;

            Text = "Your marshal tone cannot be denied. You form an impenetrable thicket of soldiers against the cavalry charge. Your archers pepper the hesitating nomads with arrows. Realising that their shock tactics have failed, the nomads flee back into the desert rather than face a long, bloody combat for a few barrels of salt.\n\nA great cheer goes up from the caravan guards. The merchants, delighted with your brave actions, reward you with 100 silver coins.";

            Bye = "After a brief rest you continue on your way.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 100);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 477}; }
    };

    class Story543 : public Story::Base
    {
    public:
        Story543()
        {
            BookID = Book::Type::BOOK1;

            ID = 543;

            Text = "The palace of Saltdad has vast underground chambers which are still in the process of being unearthed. In one of the vaults the Iron King discovered the weapons and armour for his Bronzeguard. In another was found Malronac the Deathengine. Who knows what still awaits to be found within the cold earth?\n\nYou spend some time exploring the ancient arcades and hallways, looking for secret passages or forgotten routes.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::MAGIC_VAULT});

            Bye = NULL;

            Choices.clear();

            if (Engine::HAS_SPELL(party, {Spells::Type::SHADOW_DOOR}))
            {
                Choices.push_back(Choice::Base("Cast Shadow Door", {Book::Type::BOOK1, 637}));
                Choices.push_back(Choice::Base("Give up searching", {Book::Type::BOOK1, 620}));
            }
            else
            {
                Bye = "After a considerable search you find nothing new.";
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 620}; }
    };

    class Story544 : public Story::Base
    {
    public:
        Story544()
        {
            BookID = Book::Type::BOOK1;

            ID = 544;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Discretion is the better part of valour. You attempt to bolt, Tommul diving to make a grab for you. You must use the Stealth ability of the character you have chosen.";

            Choices.clear();
            Choices.push_back(Choice::Base("Escape from Tommul (Individual check: Stealth 4+, Successes: 2)", {Book::Type::BOOK1, 193}, {Book::Type::BOOK1, 302}, Choice::Type::LAST_INDIVIDUAL_CHECK, {Attribute::Type::STEALTH}, 4, 2));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story545 : public Story::Base
    {
    public:
        Story545()
        {
            BookID = Book::Type::BOOK1;

            ID = 545;

            Text = "Some of the Everchild's agents are skilled negotiators... still, they might lack the authority needed to get the mercenaries to co-operate.";

            Choices.clear();
            Choices.push_back(Choice::Base("Negotiate with the mercenaries", {{4, "The agents fail in their task, and you will have to face the full might of the patriarch's forces.", {Book::Type::BOOK1, 301}}, {6, NULL, {Book::Type::BOOK1, -545}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event545 : public Story::Base
    {
    public:
        Event545()
        {
            BookID = Book::Type::BOOK1;

            ID = -545;

            DisplayID = 545;

            Text = "The agents are successful and convince some of the mercenaries to abandon the patriarch.\n\nNote: You gained the code A96.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(96)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 301}; }
    };

    class Story546 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story546()
        {
            BookID = Book::Type::BOOK1;

            ID = 546;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You are so busy examining the coffer that you fail to spot the raised stone step in front of you. As soon as you step on the trap a stone block descends down upon your head.";

            auto first = Engine::FIRST(party, Character::Status::FRONT);

            if (Engine::IS_ACTIVE(party, first))
            {
                Engine::GAIN_HEALTH(party, Character::Status::FRONT, -5);

                PreText += std::string(party.Members[first].Name) + " loses 5 Health.";

                if (!Engine::IS_ACTIVE(party, first))
                {
                    PreText += " The stone slab is too heavy to move and all of " + std::string(party.Members[first].Name) + "'s gear is lost.";

                    party.Members[first].Equipment.clear();
                }
                else
                {
                    PreText += std::string(party.Members[first].Name) + " manages to dive aside before the block completely crushes them.";
                }
            }

            PreText += "\n\nThe slab does not block off the way onwards, and you are able to crawl over the slab and towards the coffer.";

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 277}; }
    };

    class Story547 : public Story::Base
    {
    public:
        Story547()
        {
            BookID = Book::Type::BOOK1;

            ID = 547;

            Text = "You come upon a patch of bright yellow flowers. They have a pleasing scent and your first thought is to gather some up. You pause, though... you are unsure if it is safe to pluck these blooms. They might be poisonous.";

            Choices.clear();
            Choices.push_back(Choice::Base("Pick some anyway", {Book::Type::BOOK1, 402}));
            Choices.push_back(Choice::Base("Avoid the flowers and move on", {Book::Type::BOOK1, 618}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story548 : public Story::Base
    {
    public:
        Story548()
        {
            BookID = Book::Type::BOOK1;

            ID = 548;

            Text = "You recite every blessing and counterspell you know. You are not sure which incantation was the correct one, but suddenly the spell breaks, and the skull stops its infernal murmuring.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 132}; }
    };

    class Story549 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story549()
        {
            BookID = Book::Type::BOOK1;

            ID = 549;

            Location = Location::Type::CLIFFTOP;

            Choices.clear();
            Choices.push_back(Choice::Base("Make another attempt", {Book::Type::BOOK1, 583}));
            Choices.push_back(Choice::Base("Abandon the attempt for the moment.", {Book::Type::BOOK1, 82}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You are caught in a sudden current and dashed against the cliffside.";

            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                auto result = Engine::ROLL(1);

                Engine::GAIN_HEALTH(party.Members[party.LastSelected], -result);

                PreText += "\n\n" + std::string(party.Members[party.LastSelected].Name) + " loses " + std::to_string(result) + " Health point";

                if (result > 1)
                {
                    PreText += "s";
                }

                PreText += ".";
            }

            PreText += "The rest of the party quickly come to your rescue, hauling you back into the jollyboat.";

            Text = PreText.c_str();
        }
    };

    class Story550 : public Story::Base
    {
    public:
        std::string PreText = "";

        Engine::Destination destination = {};

        Story550()
        {
            BookID = Book::Type::BOOK1;

            ID = 550;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "There is no point in provoking anything. You would rather deal with wounded and exhausted opponents than arena champions. You cast your eyes warily across the exterior of the battle.";

            if (!Engine::VERIFY_CODES(party, {Codes::A(3)}))
            {
                PreText += "\n\nAn arrow thudding into the ground near you, launched from one the arena guards, spurs you back into action. Clearly you must fight hard or be executed. Hurriedly you engage with the dregs of the fight to keep busy.";

                Monsters = {Monster::Base("Slaves", 6, 5, 3, 20, 0)};

                destination = {Book::Type::BOOK1, 71};
            }
            else
            {
                Monsters.clear();

                destination = {Book::Type::BOOK1, 718};
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }
    };

    class Story551 : public Story::Base
    {
    public:
        Story551()
        {
            BookID = Book::Type::BOOK1;

            ID = 551;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You open the door into a busy looking kitchen. Goblins, slaves by the look of their garb, are busy cooking a surprisingly decent looking broth in a large cauldron. Even through the thick clouds of steam they spot you, mouths open in surprise.";

            Choices.clear();
            Choices.push_back(Choice::Base("Try to speak to them", {Book::Type::BOOK1, 57}));
            Choices.push_back(Choice::Base("Rush to an attack", {Book::Type::BOOK1, 389}));
            Choices.push_back(Choice::Base("Wait to see what they will do", {Book::Type::BOOK1, 99}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(61)}))
            {
                return {Book::Type::BOOK1, 809};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(62)}))
            {
                return {Book::Type::BOOK1, 423};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story552 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story552()
        {
            BookID = Book::Type::BOOK1;

            ID = 552;

            Location = Location::Type::DESERT;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The poor monkey is dying, but your water eases its suffering somewhat, and it cradles itself lovingly in your arms.";

            Choices.clear();

            if (Engine::HAS_SPELL(party, {Spells::Type::ANIMAL_SPEECH}))
            {
                Choices.push_back(Choice::Base("Cast Animal Speech", {Book::Type::BOOK1, 399}));
                Choices.push_back(Choice::Base("Comfort the monkey until its life fades away", {Book::Type::BOOK1, 125}));
            }
            else
            {
                PreText += "\n\nYou comfort the monkey until its life fades away, wondering what could bring such tragedy to a harmless creature.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 125}; }
    };

    class Story553 : public Story::Base
    {
    public:
        Story553()
        {
            BookID = Book::Type::BOOK1;

            ID = 553;

            Text = "A lone assassin does make an attempt on the Everchild's life, but her alert agents manage to foil the attack. The Everchild looks unflustered and calm as the morning sun illuminates the horizon, and her presence on the field, astride a nomad steed, causes your army to cheer wildly. Confidence is high. Now it is time to see if your preparations for the coming battle have been enough.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 162}; }
    };

    class Story554 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story554()
        {
            BookID = Book::Type::BOOK1;

            ID = 554;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "\"Death to the Iron King!\" you snarl, drawing your weapons. The soldiers look horrified to see such disciplined warriors before them.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            CanFlee = true;

            Monsters = {
                Monster::Base("Soldier", 3, 4, 4, 6, 0),
                Monster::Base("Soldier", 3, 4, 3, 7, 0),
                Monster::Base("Soldier", 4, 4, 3, 9, 0),
                Monster::Base("Soldier", 3, 4, 4, 8, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::FLEE)
            {
                destination = {Book::Type::BOOK1, 75};
            }
            else
            {
                destination = {Book::Type::BOOK1, 357};
            }
        }
    };

    class Story555 : public Story::Base
    {
    public:
        Story555()
        {
            BookID = Book::Type::BOOK1;

            ID = 555;

            Text = "This battle has taught you much about combat strategy.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of FIGHTING", {Book::Type::BOOK1, 3}, Choice::Type::ROLL_FOR_ATTRIBUTE_INCREASE, {Attribute::Type::FIGHTING}, 1, 1, 0));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story556 : public Story::Base
    {
    public:
        Story556()
        {
            BookID = Book::Type::BOOK1;

            ID = 556;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You inform the soldier that you are agents of the Everchild and have come to plead for Unbraaki's support in her cause. The soldier nods and asks you to wait in the garden until his return. Slave girls deliver iced fruit juices to you as you sit upon a bench in the shade. Eventually the soldier returns.\n\n\"Unbraaki sends his greetings to you,\" says the soldier formally. \"Alas, he is not interested in supporting a rebel leader in her cause at this time. Should the Everchild ever become a serious political figure, he would be delighted to meet with you. Until that time, Unbraaki has no intention of disrupting the order of the valley.\"\n\n\"I see,\" you nod. \"Perhaps if we met, we might be able to persuade your master...\"\n\n\"You may go,\" interrupts the soldier, firmly. A dozen additional soldiers arrive to reinforce his suggestion.";

            Bye = "Thanking the slaves for their refreshment you depart.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 265}; }
    };

    class Story557 : public Story::Base
    {
    public:
        Story557()
        {
            BookID = Book::Type::BOOK1;

            ID = 557;

            Text = "You enter the hall of Lothor the Ugly, brutal king of Clifftop. He is currently in the process of torturing one of his servants, his lords urging him on to greater acts of cruelty. The hideous, scarred king looks up at you as you enter. \"What's this?\" he gargles. \"More petitioners for my favour? If you would be my friend, tell me what kind of punishment I should inflict on this man? Don't be too lenient, or you will share his fate!\"\n\nDozens of guards close in around you as you consider your answer.";

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(33)}))
            {
                return {Book::Type::BOOK1, 126};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(34)}))
            {
                return {Book::Type::BOOK1, 642};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (!Engine::IN_PARTY(party, Character::Type::LORD_TIQUON))
            {
                Choices.push_back(Choice::Base("Have the man whipped", {Book::Type::BOOK1, 658}));
                Choices.push_back(Choice::Base("Pull out his fingernails", {Book::Type::BOOK1, 408}));
                Choices.push_back(Choice::Base("Gouge out his eyes", {Book::Type::BOOK1, 338}));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 10}; }
    };

    class Story558 : public Story::Base
    {
    public:
        Story558()
        {
            BookID = Book::Type::BOOK1;

            ID = 558;

            Text = "You browse the selection, with many interesting tomes on philosophy, war and architecture on display. Disturbingly, you also come across the bodies of two orcs, lying dead on the floor. They seem to have been bludgeoned to death. Your eyes flick to a blood-stained tome that seems to be pulling itself off the shelves. To your horror it is joined by a veritable swarm of books. They fly off the shelves, bashing into the sides of your faces, flapping their heavy leather and wooden pages like aggressive pigeons before your startled eyes.\n\nYou attempt to hold your ground for a few moments, but as more and more books fly off the shelf, you realise your task is hopeless. You must fight your way to the exit!\n\nNote:  Each party member loses 1 Health point.";

            Choices.clear();
            Choices.push_back(Choice::Base("Fight your way out of the library (Team check: Fighting 4+, Successes: 4)", {Book::Type::BOOK1, 203}, {Book::Type::BOOK1, -558}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::FIGHTING}, 4, 4, false));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -1);
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (!outcome)
            {
                Bye = "Each party member loses 1 Health point.";

                Engine::GAIN_HEALTH(party, -1);
            }
        }
    };

    class Event558 : public Story::Base
    {
    public:
        Event558()
        {
            BookID = Book::Type::BOOK1;

            ID = -558;

            DisplayID = 558;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 558}; }
    };

    class Story559 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story559()
        {
            BookID = Book::Type::BOOK1;

            ID = 559;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Image = "images/book1/unbraaki.png";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            PreText = "You inform the soldier that you are agents of the queen of Saltdad and have come to plead for Unbraaki's support in her cause. The soldier nods and asks you to wait in the garden until his return. Slave girls deliver iced fruit juices to you as you sit upon a bench in the shade. Eventually the soldier returns.\n\n\"Please, come with me,\" he says. \"Unbraaki will see you now.\"\n\nYou follow the soldier into the gorgeous palace, quite the equal of any manorial estate in Royce or Drakehallow. You are led into a private study where you meet Unbraaki himself. He is an elegant, though rather short man, with a long, thin oiled moustache. His robes are a dazzle of colours that seem to shift before your eyes. On his desk sits a small monkey, oddly wearing a tiny wizard's hat. It looks at you with penetrating, intelligent eyes. Unbraaki bids you to sit, seating himself on a throne-like chair cunningly designed to make him look taller.\n\n\"I am pleased you came to see me,\" smiles Unbraaki. \"I have been following your progress, and that of your queen, with great interest. I am now satisfied that the wind is changing in the valley, and that the Everchild is both a promising and likely leader.\"\n\n\"You will support her, then?\" you press.\n\n\"Perhaps,\" says Unbraaki suddenly cold. \"My soldiers are some of the best in the land, and their loyalty comes with a cost.\"\n\n\"I'm sure the Everchild can provide you with the necessary compensation,\" you say breezily.\n\n\"The Everchild does not have what I want,\" Unbraaki says.\n\n\"And what do you want, eminence?\" you ask.\n\nUnbraaki rises and walks to a bookcase. He snaps his fingers, and the monkey on the desk scales the tall shelves, pulling down an ancient tome and passing it to his master.\n\nUnbraaki opens the book at a particular page and shows you a picture. It appears to be a triangular object, grey or black in colour, with light streaming through it. \"The black prism,\" says Unbraaki. \"It holds the secrets of light itself. Long I've sought it, in this world and the world of shadow, but to no avail. I have consulted an oracle in Drakehallow who told me that only the agents of the queen of Saltdad can find the prism. Of course, there has been no queen in Saltdad for a thousand years. You have just made that happen. I want you to find me the black prism, and in exchange I will provide my soldiers to the Everchild's cause.\"";

            Choices.clear();

            if (!Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::BLACK_PRISM}))
            {
                PreText += "\n\n\"Where can I find it?\" you ask.\n\n\"I only know that it was hidden on the south coast of the valley,\" says Unbraaki. \"Perhaps the patriarch has it hidden in his vault? Or maybe it lies in the dread city of Mordain? You are fated to find it, so I doubt you will struggle hard to locate it.\"\n\nWell, the directions are vague, but it's something to go on.";

                Bye = "You thank Unbraaki for his time and promise to return with the prism. You are escorted out of the palace.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::BLACK_PRISM}))
            {
                return {Book::Type::BOOK1, 818};
            }
            else
            {
                return {Book::Type::BOOK1, 265};
            }
        }
    };

    class Story560 : public Story::Base
    {
    public:
        Story560()
        {
            BookID = Book::Type::BOOK1;

            ID = 560;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "Mannus is clearly troubled at the brazen way you are attempting to bribe him. Suspecting that you might be a plant from one of his opponents he calls the guards and has you arrested. Here, in the heart of the temple, you have no chance of escape.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 55}; }
    };

    class Story561 : public Story::Base
    {
    public:
        Story561()
        {
            BookID = Book::Type::BOOK1;

            ID = 561;

            Location = Location::Type::MORDAIN;

            Text = "You have returned to the orc guard room. Except for a pair of dead orcs there is nothing to see here. You return to the corridor.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 350}; }
    };

    class Story562 : public Story::Base
    {
    public:
        Story562()
        {
            BookID = Book::Type::BOOK1;

            ID = 562;

            Location = Location::Type::LUUTANESH;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(7)}))
            {
                return {Book::Type::BOOK1, 263};
            }
            else
            {
                return {Book::Type::BOOK1, 750};
            }
        }
    };

    class Story563 : public Story::Base
    {
    public:
        Story563()
        {
            BookID = Book::Type::BOOK1;

            ID = 563;

            Text = "This unnatural monster cannot be allowed to live. Drawing your weapons with a grimace, you advance.\n\nNote: Imopposh, instead of attacking, will cast the following spells each turn, as long as he is still alive:\n\n1st turn: Imopposh casts a Thunderbolt spell. He makes two Fighting: 10 attacks.\n\n2nd turn: Imopposh casts an Orb of Annihilation spell. He makes a single Fighting: 13 attack.\n\n3rd turn: Imopposh casts a Sandstorm spell. He makes a Fighting: 3 attack on each party member.\n\n4th turn onwards: Imopposh makes a standard attack.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {Monster::Base("Imopposh the Mad", Monster::Type::IMOPPOSH_THE_MAD, 3, 4, 4, 30, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 311}; }
    };

    class Story564 : public Story::Base
    {
    public:
        Story564()
        {
            BookID = Book::Type::BOOK1;

            ID = 564;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You are about to battle the foremost wizard of the Valley of Bones. His colourful robe blazes with light, making him hard to see as he commands his monkeys to attack. To your horror the monkeys do not attack with teeth and nails, but with blasts of magic. You are not just fighting one sorcerer -- but a whole pack of them!\n\nNote: Unbraaki fights with blasts of black flames from his hands. These flames leech your life into his. For every Health point you lose, Unbraaki gains a Health point, even if this takes him over his starting Health. The monkeys do not attack physically, but each will cast a spell from the following list:\n\nIce Bolt: Make a Fighting: 8 attack at 4+ difficulty\n\nUnfailing Strike: Inflict 3 damage on one party member\n\nPoison Stream: Make two Fighting: 5 attacks at 4+ difficulty";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {
                Monster::Base("Unbraaki", Monster::Type::UNBRAAKI, 8, 3, 6, 11, 0),
                Monster::Base("Monkey", Monster::Type::MONKEY_WITH_SPELLS, 0, 0, 5, 3, 0),
                Monster::Base("Monkey", Monster::Type::MONKEY_WITH_SPELLS, 0, 0, 5, 4, 0),
                Monster::Base("Monkey", Monster::Type::MONKEY_WITH_SPELLS, 0, 0, 5, 3, 0),
                Monster::Base("Monkey", Monster::Type::MONKEY_WITH_SPELLS, 0, 0, 5, 5, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 509}; }
    };

    class Story565 : public Story::Base
    {
    public:
        Story565()
        {
            BookID = Book::Type::BOOK1;

            ID = 565;

            Text = "There is no chance that you will all be able to sneak up to the cauldron as a team without raising the alarm. Nominate a party member to sneak up to cauldron with the vial of poison.";

            Choices.clear();
            Choices.push_back(Choice::Base("Poison the Cauldron (Individual check: Stealth 4+, Successes: 3)", {Book::Type::BOOK1, 661}, {Book::Type::BOOK1, 58}, {Attribute::Type::STEALTH}, 4, 3));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story566 : public Story::Base
    {
    public:
        Story566()
        {
            BookID = Book::Type::BOOK1;

            ID = 566;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You have reached a crossroads, with tunnels going off in all directions. The corridors are short to the south and west, and each contains a door. To the east the corridor stretches into darkness, though you can make out a door in the north wall. Going north you think you can make out another pair of doors, but you will have to get closer to find out.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go north", {Book::Type::BOOK1, 736}));
            Choices.push_back(Choice::Base("Go east, down the corridor", {Book::Type::BOOK1, 350}));
            Choices.push_back(Choice::Base("Go east, and through the door in the north wall", {Book::Type::BOOK1, 723}));
            Choices.push_back(Choice::Base("Go through the door in the south tunnel", {Book::Type::BOOK1, 857}));
            Choices.push_back(Choice::Base("Go through the door in the west tunnel", {Book::Type::BOOK1, 151}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story567 : public Story::Base
    {
    public:
        Story567()
        {
            BookID = Book::Type::BOOK1;

            ID = 567;

            Text = "With your missions assigned the Everchild wishes you good luck as you vanish under the cover of night.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::COUNT(party, Team::Type::ASSASSINATION_DESCANTOS) > 0)
            {
                return {Book::Type::BOOK1, 880};
            }
            else
            {
                return {Book::Type::BOOK1, 639};
            }
        }
    };

    class Story568 : public Story::Base
    {
    public:
        Story568()
        {
            BookID = Book::Type::BOOK1;

            ID = 568;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You have returned to the chamber of Skallos, the dark knight. This champion of evil has been destroyed, and you have no wish to remain in his haunted chamber any longer than you need to.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 165}; }
    };

    class Story569 : public Story::Base
    {
    public:
        Story569()
        {
            BookID = Book::Type::BOOK1;

            ID = 569;

            Location = Location::Type::WEST_ROAD;

            Text = "You are on the Westroad, somewhat near to Clifftop. Where will you travel now?";

            Choices.clear();
            Choices.push_back(Choice::Base("West, to Clifftop", {Book::Type::BOOK1, 19}));
            Choices.push_back(Choice::Base("Southwest, into the desert", {Book::Type::BOOK1, 350}));
            Choices.push_back(Choice::Base("South, to the Tumblestones", {Book::Type::BOOK1, 137}));
            Choices.push_back(Choice::Base("East, along the road to Saltdad", {Book::Type::BOOK1, 511}));
            Choices.push_back(Choice::Base("North, to the Salt Plains", {Book::Type::BOOK1, 460}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story570 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story570()
        {
            BookID = Book::Type::BOOK1;

            ID = 570;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IN_PARTY(party, Character::Type::BRASH))
            {
                return {Book::Type::BOOK1, 627};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            PreText = "You attend prayer with your master every day until he remarks upon your devotion to the faith. When the time is right you ask him free you, as fellow worshipers of Cursus. \"If souls can be brought to the light of reason, I would be willing to sacrifice my wealth by freeing you,\" says the priest, benevolently. \"However, I would have to be sure of your devotion. If you each agreed to receive ritual scarring to honour Cursus, I would have no hesitation in freeing you.\"";

            Choices.clear();

            if (Engine::COUNT(party, Character::Status::RITUAL_SCARRING_CURSUS) < Engine::COUNT(party))
            {
                PreText += "\n\nNote: If you agree to the priest's terms he will put the dreadful scars on your bodies. It is an extremely painful experience which will lower the maximum Health score of each party member by 1 point. Each party member will have Ritual Scarring (Cursus).";

                Choices.push_back(Choice::Base("Agree to the priest's terms", {Book::Type::BOOK1, -570}));
                Choices.push_back(Choice::Base("Try and break out", {Book::Type::BOOK1, 785}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 713}; }
    };

    class Event570 : public Story::Base
    {
    public:
        Event570()
        {
            BookID = Book::Type::BOOK1;

            ID = -570;

            DisplayID = 570;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            for (auto i = 0; i < party.Members.size(); i++)
            {
                if (Engine::IS_ACTIVE(party, i))
                {
                    if (!Engine::HAS_STATUS(party.Members[i], Character::Status::RITUAL_SCARRING_CURSUS))
                    {
                        party.Members[i].MaximumHealth -= 1;

                        if (party.Members[i].Health > party.Members[i].MaximumHealth)
                        {
                            party.Members[i].Health = party.Members[i].MaximumHealth;
                        }

                        Engine::GAIN_STATUS(party.Members[i], Character::Status::RITUAL_SCARRING_CURSUS);
                    }
                }
            }

            return {Book::Type::BOOK1, 713};
        }
    };

    class Story571 : public Story::Base
    {
    public:
        Story571()
        {
            BookID = Book::Type::BOOK1;

            ID = 571;

            Text = "For weeks your diggers clear away rubble and hack at the ground. The very stones seem to recoil as you dig deeper and deeper into the earth. Above your workforce, black clouds gather, and fierce rainstorms attempt to sweep away your encampments. Your workers are terrified and want to abandon their dig.";

            Choices.clear();
            Choices.push_back(Choice::Base("Convince the workers (Team check: Charisma 4+, Successes: 10)", {Book::Type::BOOK1, 702}, {Book::Type::BOOK1, 515}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 4, 10));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (!outcome)
            {
                Bye = "The workers down their tools and flee into the desert.";
            }
        }
    };

    class Story572 : public Story::Base
    {
    public:
        Story572()
        {
            BookID = Book::Type::BOOK1;

            ID = 572;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Neither side is willing to back down, and soon the hall dissolves into a violent scrum. Fists fly and blood is spilt as people fight like animals for a sliver of cooked flesh.\n\nNote: Health points of all Party Members are reduced by 2 points.";

            Bye = "You have managed to feed, but are a mass of bruises.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -2);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 865}; }
    };

    class Story573 : public Story::Base
    {
    public:
        Story573()
        {
            BookID = Book::Type::BOOK1;

            ID = 573;

            Text = "The thief bolts from the room and you follow in hot pursuit. He dashes into another bedroom on the far side of the house and leaps from an open window, onto the rooftops of a lower house.\n\nNote: If you think a party member won't be able to give chase (Survival score is 2 or less) you can have them hang back instead, although that means they will not be able to assist in the rest of the chase.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose which party members will chase the thief", {Book::Type::BOOK1, -573001}, Choice::Type::ASSIGN_TEAMS, {{Team::Type::CHASE, 0, 4}}, 0));

            Controls = Story::Controls::STANDARD;
        }
    };

    class E573_001 : public Story::Base
    {
    public:
        E573_001()
        {
            BookID = Book::Type::BOOK1;

            ID = -573001;

            DisplayID = 573;

            Text = "Each party member chasing the thief must make an individual skill check to see if they can continue.";

            Choices.clear();
            Choices.push_back(Choice::Base("Chase the thief (Individual check: Survival 4+, Successes: 2)", {Book::Type::BOOK1, -573002}, Choice::Type::EVERYONE_SKILL_CHECKS, Team::Type::CHASE, {Attribute::Type::SURVIVAL}, 0, 4, 2));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::COUNT(party, Team::Type::CHASE) > 0)
            {
                return {Book::Type::NONE, -1};
            }
            else
            {
                return {Book::Type::BOOK1, 29};
            }
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            temp_string = "";
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (!outcome)
            {
                if (selection.size() > 0)
                {
                    if (Engine::IS_ACTIVE(party, selection[0]))
                    {
                        if (temp_string.length() > 0)
                        {
                            temp_string += "\n";
                        }

                        temp_string += std::string(party.Members[selection[0]].Name) + " takes a hard fall, loses 2 health and is out of the chase.";

                        Engine::GAIN_HEALTH(party.Members[selection[0]], -2);

                        party.Members[selection[0]].Team = Team::Type::NONE;

                        Bye = temp_string.c_str();
                    }
                }
            }
        }
    };

    class E573_002 : public Story::Base
    {
    public:
        E573_002()
        {
            BookID = Book::Type::BOOK1;

            ID = -573002;

            DisplayID = 573;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::COUNT(party, Team::Type::CHASE) > 0)
            {
                return {Book::Type::BOOK1, 789};
            }
            else
            {
                return {Book::Type::BOOK1, 29};
            }
        }
    };

    class Story574 : public Story::Base
    {
    public:
        Story574()
        {
            BookID = Book::Type::BOOK1;

            ID = 574;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "The inside of the ziggurat is not what you expected. Although there is a single, ceremonial religious hall for important funerals, the majority of the chambers are dedicated to running the government. Tax offices, religious regulators and financial departments are scattered across the temple, with dozens of black-robed orderlies running messages between them. Of course... the vault lies just beneath your feet as well.";

            Choices.clear();
            Choices.push_back(Choice::Base("Visit the keeper of the holy purse", {Book::Type::BOOK1, 323}));
            Choices.push_back(Choice::Base("Visit the zealotry commission", {Book::Type::BOOK1, 867}));
            Choices.push_back(Choice::Base("Attempt to rob the vault", {Book::Type::BOOK1, 281}));
            Choices.push_back(Choice::Base("Leave the Great Ziggurat", {Book::Type::BOOK1, 340}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::CONSOLIDATE(party);

            for (auto i = 0; i < party.Members.size(); i++)
            {
                if (Engine::HAS_STATUS(party.Members[i], Character::Status::RITUAL_SCARRING_CURSUS))
                {
                    party.Members[i].Team = Team::Type::ZIGGURAT;
                }
            }
        }
    };

    class Story575 : public Story::Base
    {
    public:
        Story575()
        {
            BookID = Book::Type::BOOK1;

            ID = 575;

            Location = Location::Type::SALT_MINES;

            Text = "You can buy salt in bulk for any ships you have moored in Cursus or Clifftop. Each cargo unit costs 450 silver pieces, and will be transported to your ships for free. Your ships must have room in their cargo holds in order for you to buy salt here.";

            // TODO: There has to be smarter way to do this!
            Choices.clear();
            Choices.push_back(Choice::Base("Buy one cargo unit of SALT for your ship in Cursus", {Book::Type::BOOK1, -575}, Choice::Type::DELIVER, {Cargo::Type::SALT}, Location::Type::CURSUS, 450));
            Choices.push_back(Choice::Base("Buy two cargo units of SALT for your ship in Cursus", {Book::Type::BOOK1, -575}, Choice::Type::DELIVER, {Cargo::Type::SALT}, Location::Type::CURSUS, 900));
            Choices.push_back(Choice::Base("Buy three cargo units of SALT for your ship in Cursus", {Book::Type::BOOK1, -575}, Choice::Type::DELIVER, {Cargo::Type::SALT}, Location::Type::CURSUS, 1350));
            Choices.push_back(Choice::Base("Buy one cargo unit of SALT for your ship in Clifftop", {Book::Type::BOOK1, -575}, Choice::Type::DELIVER, {Cargo::Type::SALT}, Location::Type::CLIFFTOP, 450));
            Choices.push_back(Choice::Base("Buy two cargo units of SALT for your ship in Clifftop", {Book::Type::BOOK1, -575}, Choice::Type::DELIVER, {Cargo::Type::SALT}, Location::Type::CLIFFTOP, 900));
            Choices.push_back(Choice::Base("Buy three cargo units of SALT for your ship in Clifftop", {Book::Type::BOOK1, -575}, Choice::Type::DELIVER, {Cargo::Type::SALT}, Location::Type::CLIFFTOP, 1350));
            Choices.push_back(Choice::Base("You have finished your business", {Book::Type::BOOK1, 722}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event575 : public Story::Base
    {
    public:
        Event575()
        {
            BookID = Book::Type::BOOK1;

            ID = -575;

            DisplayID = 575;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party) { return {Book::Type::BOOK1, 575}; }
    };

    class Story576 : public Story::Base
    {
    public:
        Story576()
        {
            BookID = Book::Type::BOOK1;

            ID = 576;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "\"You couldn't afford me!\" laughs the ogre.\n\n\"How much?\" you press.\n\n\"Eight hundred silver,\" grins the ogre. \"I'd charge a thousand, but I'll give you a discount since I've been stuck in this hole for months.\"";

            // TODO: Keep track of 800 paid to the ogre
            Choices.clear();
            Choices.push_back(Choice::Base("Pay the ogre 800 silver coins", {Book::Type::BOOK1, 245}, Choice::Type::GAIN_MONEY, -800));
            Choices.push_back(Choice::Base("Kill the ogre", {Book::Type::BOOK1, 117}));
            Choices.push_back(Choice::Base("Leave the ogre in peace", {Book::Type::BOOK1, 310}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story577 : public Story::Base
    {
    public:
        Story577()
        {
            BookID = Book::Type::BOOK1;

            ID = 577;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The city of Mordain was a coastal port on the southern end of the Valley of Bones. Although it was rebuilt after the desolation of Abraxas, it fell prey to the infighting amongst the cities of the valley. About four hundred years ago it was entirely torn down when the cities of Cursus and Lhasbreath joined forces against it. Before that time it was a relatively prosperous place, but the religious freedoms it granted its citizens were abhorrent to the clergy in Cursus. It was said to have a grand museum which stored all kinds of artefacts from ancient times, although it is doubtful that anything remains there now.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 680}; }
    };

    class Story578 : public Story::Base
    {
    public:
        Story578()
        {
            BookID = Book::Type::BOOK1;

            ID = 578;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Image = "images/book1/nightmare_room.png";

            Text = "The door opens into a room out of your worst nightmares. Bright silver sawblades are suspended on long, mechanical arms which jut from the side of the walls. Spear holes cover the floor at uneven intervals. You can see the dismembered bodies of orcs, literally chopped to pieces, scattered across the ground.\n\nOne orc has been impaled from his seat to his neck, and is still suspended in the air, dripping blood.\n\nAt the far end of the room you can see a pedestal, on which sits a BLACK PRISM of some kind.";

            Choices.clear();
            Choices.push_back(Choice::Base("Close the door on this room of horrors", {Book::Type::BOOK1, 310}));
            Choices.push_back(Choice::Base("Have someone attempt to navigate the room", {Book::Type::BOOK1, 44}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(80)}))
            {
                return {Book::Type::BOOK1, 729};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story579 : public Story::Base
    {
    public:
        Story579()
        {
            BookID = Book::Type::BOOK1;

            ID = 579;

            Text = "In the aftermath of the battle you enter the step pyramid to see if any more horrors lurk within. Fortunately the pyramid is not large, and you seem to have cleared away all the snakemen. You help yourself to 200 silver coins worth of jewels and artefacts before returning to the scholars.\n\nNow the area is safe Emlyn begins to take samples of the exotic plants growing on the temple. It is impossible to take them all, so only the most likely candidates should be picked. She asks your advice on what should be taken, also getting guidance from her fellow scholars.\n\nNote: The difficulty of this skill check depends on how many scholars died on the trip through the jungle. If no scholars died, the difficulty is 3+. If one died it is 4+, if two died it is 5+, and if three died it is 6+.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 200);

            Choices.clear();

            if (Engine::VERIFY_CODES(party, {Codes::Type::LOST_SCHOLAR3}))
            {
                Choices.push_back(Choice::Base("Examine plant samples (Team check: Lore 6+, Successes: 4)", {Book::Type::BOOK1, 49}, {Book::Type::BOOK1, 90}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 6, 4));
            }
            else if (Engine::VERIFY_CODES(party, {Codes::Type::LOST_SCHOLAR2}))
            {
                Choices.push_back(Choice::Base("Examine plant samples (Team check: Lore 5+, Successes: 4)", {Book::Type::BOOK1, 49}, {Book::Type::BOOK1, 90}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 5, 4));
            }
            else if (Engine::VERIFY_CODES(party, {Codes::Type::LOST_SCHOLAR1}))
            {
                Choices.push_back(Choice::Base("Examine plant samples (Team check: Lore 4+, Successes: 4)", {Book::Type::BOOK1, 49}, {Book::Type::BOOK1, 90}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 4, 4));
            }
            else
            {
                Choices.push_back(Choice::Base("Examine plant samples (Team check: Lore 3+, Successes: 4)", {Book::Type::BOOK1, 49}, {Book::Type::BOOK1, 90}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 3, 4));
            }
        }
    };

    class Story580 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story580()
        {
            BookID = Book::Type::BOOK1;

            ID = 580;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You have entered the cave of a terrible naga, a spirit snake of fearsome magical power. The ghastly creature splits itself into six identical copies before lunging for you.\n\nNote: You cannot make any armour saves in this battle. You can flee from the naga at the start of a combat round, but the naga will make an attack upon you before you escape.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            CanFlee = true;

            Monsters = {Monster::Base("Naga", Monster::Type::NAGA, 5, 3, 6, 10, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::FLEE)
            {
                Bye = "The naga attacks your party as you flee!";

                destination = {Book::Type::BOOK1, -580};
            }
            else
            {
                destination = {Book::Type::BOOK1, 773};
            }
        }
    };

    class Event580 : public Story::Base
    {
    public:
        std::string PreText = "";

        Event580()
        {
            BookID = Book::Type::BOOK1;

            ID = -580;

            DisplayID = 580;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            auto result = Engine::COUNT(5, 3);

            Choices.clear();

            if (result > 0)
            {
                PreText = "The naga attacks your party and deals " + std::to_string(result) + " damage to the party!";

                Choices.push_back(Choice::Base("Assign damage to a party member", {Book::Type::BOOK1, 395}, Choice::Type::GAIN_HEALTH, -result));
            }
            else
            {
                PreText = "The naga's attack was ineffective!";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 395}; }
    };

    class Story581 : public Story::Base
    {
    public:
        Story581()
        {
            BookID = Book::Type::BOOK1;

            ID = 581;

            Text = "You meet a foreigner from the county of Longport Bay, now ploughing the fields as a humble farmworker. He has many bruises across his face from the cruel whips of his overseers. \"The ironic thing is I fled from the town of Joria-by-Long because I couldn't stand the beatings from my masters in House Bailey,\" he says bitterly. \"Now I am a broke tenant farmer in Clifftop and the overseers here are even crueller. It seems the gods have it in for me.\"\n\n\"The grass is always greener on the other side,\" you say wistfully.\n\n\"Not here, it isn't,\" he grumbles.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::REGISTRY_PAPERS}))
            {
                return {Book::Type::BOOK1, 70};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -4);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story582 : public Story::Base
    {
    public:
        Story582()
        {
            BookID = Book::Type::BOOK1;

            ID = 582;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You know this brutal place well by now. The guards welcome you back with a stout beating and promise that this time you will only be leaving the arena on a corpse cart.\n\nNote: Each party member loses 2 Health points.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -2);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 223}; }
    };

    class Story583 : public Story::Base
    {
    public:
        Story583()
        {
            BookID = Book::Type::BOOK1;

            ID = 583;

            Location = Location::Type::CLIFFTOP;

            Text = "The seas are too dangerous to risk your ship, so you will have to perform this task in the jollyboat. To get the cogwheel someone will have to dive into the rough seas around Clifftop, find and then tie a rope around the wheel. The remaining team will have to haul the heavy bronze cogwheel up. Decide who will perform the dive.";

            Choices.clear();
            Choices.push_back(Choice::Base("Find the cogwheel (Individual check: Lore 4+, Successes: 2)", {Book::Type::BOOK1, 129}, {Book::Type::BOOK1, 549}, {Attribute::Type::LORE}, 4, 2));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story584 : public Story::Base
    {
    public:
        Story584()
        {
            BookID = Book::Type::BOOK1;

            ID = 584;

            Text = "The light circles around the tent several times in the night before eventually departing. In the morning you cannot find so much as a footprint in the sand. Shivering, despite the rising heat, you pack up camp and move on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 840}; }
    };

    class Story585 : public Story::Base
    {
    public:
        Story585()
        {
            BookID = Book::Type::BOOK1;

            ID = 585;

            Location = Location::Type::WEST_ROAD;

            Text = "In the cool hours of the early morning you awake, thanking Kopu and his slaves for their hospitality. \"Look for me in Lhasbreath,\" he says. \"I have a house there when I am not out travelling. I am always looking for exotic new languages! Seek me out if you find any!\"\n\nNote: You gained the code A19.";

            Bye = "You promise to pay him a visit, and then depart into the cool desert morning.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(19)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 569}; }
    };

    class Story586 : public Story::Base
    {
    public:
        Story586()
        {
            BookID = Book::Type::BOOK1;

            ID = 586;

            Text = "Casting a rope to your stranded teammate you heave against the ghastly magical force sucking them into the earth. You strain every sinew as your friend is pulled deeper and deeper into the sands. Suddenly the unfeeling desert loses its strength, and your teammate bursts from the sands in a shower of grit. ";

            Bye = "Coughing and gasping you stagger from the cave, vowing to never return.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(19)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 395}; }
    };

    class Story587 : public Story::Base
    {
    public:
        Story587()
        {
            BookID = Book::Type::BOOK1;

            ID = 587;

            Text = "The barbarians square up to you. Behind you, the knife-wielding assassin prepares to strike.\n\nNote: In any round where the Cursite Assassin is not injured he will backstab a party member. When backstabbing the Assassin does not need to roll to hit but inflicts 4 points of damage.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {

            Monsters = {
                Monster::Base("Berserker", 7, 4, 3, 12, 0),
                Monster::Base("Cursite Assassin", Monster::Type::CURSITE_ASSASSIN, 4, 3, 5, 7, 0),
                Monster::Base("Barbarian", 4, 4, 3, 9, 0),
                Monster::Base("Barbarian", 3, 4, 3, 8, 0),
                Monster::Base("Barbarian", 4, 4, 3, 8, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 606}; }
    };

    class Story588 : public Story::Base
    {
    public:
        Story588()
        {
            BookID = Book::Type::BOOK1;

            ID = 588;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Perhaps your long incarceration has ruined your looks, or perhaps you are just not the guard's type? Your offer is rudely rejected, and is accompanied by a cruel beating.\n\nNote: Each member of the distraction team loses 2 Health points.";

            Bye = "You must choose something else.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, Team::Type::DISTRACTION, -2);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 169}; }
    };

    class Story589 : public Story::Base
    {
    public:
        Story589()
        {
            BookID = Book::Type::BOOK1;

            ID = 589;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "You are walking through a dreary land, without people or landmarks. The chill penetrates your bones.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 1 Health", {Book::Type::BOOK1, -589}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event589 : public Story::Base
    {
    public:
        Event589()
        {
            BookID = Book::Type::BOOK1;

            ID = -589;

            DisplayID = 589;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "Where will you go?";

            Choices.clear();
            Choices.push_back(Choice::Base("North", {Book::Type::BOOK1, 692}));
            Choices.push_back(Choice::Base("West", {Book::Type::BOOK1, 273}));
            Choices.push_back(Choice::Base("South", {Book::Type::BOOK1, 886}));
            Choices.push_back(Choice::Base("East", {Book::Type::BOOK1, 537}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story590 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story590()
        {
            BookID = Book::Type::BOOK1;

            ID = 590;

            Location = Location::Type::LHASBREATH_OASIS;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The sweat is thick in your clothes and across your bodies as you slog on through the desert. However, there comes a sight to reward even the most jaded nomad's eyes. A shining pool of water, almost the size of a lake, comes shimmering into view as you cross the dunes. A splash of vegetation surrounds it, a riot of green amongst a tyranny of yellow sand.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(44)}))
            {
                PreText += "\n\nAstonishingly there are no caravaners, nomads or even herds of beasts here. Only flocks of brightly coloured birds flitter in and out of the bushes and trees ringing the oasis, taking sips of water and strutting before each other in curious mating dances. You are sore and smelly from your long desert travel.\n\nIf you would like the bathe in the oasis, you can do so. Otherwise, you can refill your waterskins and decide on your next destination.";

                Choices.push_back(Choice::Base("Bathe in the oasis", {Book::Type::BOOK1, 349}));
                Choices.push_back(Choice::Base("Go North, to the Granite Hills", {Book::Type::BOOK1, 275}));
                Choices.push_back(Choice::Base("East, into the desert", {Book::Type::BOOK1, 202}));
                Choices.push_back(Choice::Base("Go South, to the Mordain ruins", {Book::Type::BOOK1, 515}));
                Choices.push_back(Choice::Base("Travel West, across the desert towards Lhasbreath", {Book::Type::BOOK1, 752}));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 448}; }
    };

    class Story591 : public Story::Base
    {
    public:
        Story591()
        {
            BookID = Book::Type::BOOK1;

            ID = 591;

            Text = "The Everchild's camp is on high alert, and her followers will give their lives to protect her. Chances are good that she will be alright even without your help.";

            Choices.clear();
            Choices.push_back(Choice::Base("Random Event", {{1, NULL, {Book::Type::BOOK1, 489}}, {6, NULL, {Book::Type::BOOK1, 553}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story592 : public Story::Base
    {
    public:
        Story592()
        {
            BookID = Book::Type::BOOK1;

            ID = 592;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You are quickly recognised as the queen's champions by the cruel arena master. Grovelling obsequiously, he apologises for your detention, and even offers you 100 silver coins by way of apology. You may also take up to four CRUDE BLADES (Fighting +0) from the armoury to replace your lost weapons.";

            Bye = "Banishing the arena master with a cuff to his ear, you march smartly into the city.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE};

            Limit = 4;

            Engine::GAIN_MONEY(party, 100);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story593 : public Story::Base
    {
    public:
        Story593()
        {
            BookID = Book::Type::BOOK1;

            ID = 593;

            Text = "This tunnel has been well built, with flagstone flooring and brick walls. At first you think it must have been a cargo store of some kind -- but it opens up into a bigger complex. Much bigger.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            party.CurrentShip = -1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 755}; }
    };

    class Story594 : public Story::Base
    {
    public:
        Story594()
        {
            BookID = Book::Type::BOOK1;

            ID = 594;

            Text = "After all you've been through Amelia deserves a chance to cut loose, and you watch idly as she walks away with some soldiers. She doesn't speak about what happened the next morning, but she is missing a fair quantity of money.\n\nNote: You lost 35 silver coins.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, -35);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 280}; }
    };

    class Story595 : public Story::Base
    {
    public:
        Story595()
        {
            BookID = Book::Type::BOOK1;

            ID = 595;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "Slaves are expensive in Cursus, and do not remain unsold for long. The auction platforms have long stood in the shadow of a lesser temple and are fortified against theft. Only strong and healthy slaves can be found here... the god of judgement will not tolerate those who cannot work.\n\nNote: If you have less than four party members in your team you may recruit some more from the slave market.\n\nIt costs 200 silver coins to buy another party member, and they start with no equipment. A party member without a weapon has their Fighting score reduced by 1 point in combat.";

            Choices.clear();

            Controls = Story::Controls::RECRUIT;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 340}; }
    };

    class Story596 : public Story::Base
    {
    public:
        Story596()
        {
            BookID = Book::Type::BOOK1;

            ID = 596;

            Text = "You have been beaten down, but the monks are not savages and do not deal a killing blow. \"Your dishonour has made you weak,Akihiro!\" barks one of the monks. \"Never return to this place.\"\n\n\"I shall face you all again... and win!\" you vow, but the monks merely laugh at you and walk away. Red-faced with shame you limp away from the temple.\n\nNote: Akihiro is down to 1 Health point.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GO_SOLO(party, Character::Type::AKIHIRO_OF_CHALICE);

            party.CurrentCharacter = Engine::FIND_SOLO(party);

            if (Engine::IS_ACTIVE(party, party.CurrentCharacter))
            {
                party.Members[party.CurrentCharacter].Health = 1;
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story597 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story597()
        {
            BookID = Book::Type::BOOK1;

            ID = 597;

            Location = Location::Type::SALT_MINES;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The lift shudders and comes to a halt on the fourteenth floor.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(26)}))
            {
                PreText += "\n\nThe ground here is muddy, with ground water leaking through parts of the tunnel to create a salty marsh. Relatively few miners work here as so much of the salt has been dissolved, but there are a few dry parts of the level that still yield crystals. Troglodyte footprints are everywhere. It should be a simple matter of tracking the footprints back to their lair.";

                Choices.push_back(Choice::Base("Follow the troglodyte prints (Team check: Stealth 3+, Successes: 6)", {Book::Type::BOOK1, 296}, {Book::Type::BOOK1, -597}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::STEALTH}, 3, 6));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 817}; }
    };

    class Event597 : public Story::Base
    {
    public:
        Event597()
        {
            BookID = Book::Type::BOOK1;

            ID = -597;

            DisplayID = 597;

            Text = "You get lost in the mines, the terrible atmosphere slowly robbing you of strength.";

            Bye = "You give up your search and decide to look elsewhere.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 1 Health", {Book::Type::BOOK1, 135}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story598 : public Story::Base
    {
    public:
        Story598()
        {
            BookID = Book::Type::BOOK1;

            ID = 598;

            Text = "You encounter a group of loggers from Lhasbreath, chopping trees and skinning branches. Jungle woods make poor building materials, but the jungle nonetheless provides the majority of the lumber in the dry valley.\n\nOne of the loggers is clearly not a native of the city but is instead a wiry fellow from Chalice. You ask how he fell into this work. \"I've always been a labourer,\" he admits. \"For a time I worked as a miner for the God King of Chalice. We attempted to find metals in the Caves of Uranu -- but that place is packed full of terrible monsters. Take my advice; don't venture near the caves unless you are loaded down with weapons and armour. Even amongst barbarians, it's much safer here by the jungle.\"";

            Bye = "You thank the logger for his advice and move on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 618}; }
    };

    class Story599 : public Story::Base
    {
    public:
        Story599()
        {
            BookID = Book::Type::BOOK1;

            ID = 599;

            Text = "One of the stone slabs on the floor ahead of you sticks out curiously. Crouching down with your lantern you can see the glimmer of a small lever under the slab, a trigger for some kind of vile trap, no doubt. You inform the rest of the party to avoid the slab, and cautiously step over it towards the chest.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 277}; }
    };

    class Story600 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story600()
        {
            BookID = Book::Type::BOOK1;

            ID = 600;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::CONSOLIDATE(party);

            PreText = "As you make your way to the steps of the temple you can see monks lining up on both sides. Many of the God King's kensai bow deeply as you pass, recognising you as one of their own. You can see your family is also gathered here, including your mother and sister, looking so proud they are fit to burst.\n\nHonnu, now dressed in the shell-blue robes of a kensai, greets you with a bow. He takes you aside behind a screen, where you are presented with high-collared KENSAI ROBES (Armour +3) to change into. You emerge to cheers, the great and the good of Chalice turning out to applaud you.\n\n";

            Choices.clear();

            if (Engine::IN_PARTY(party, Character::Type::SAR_JESSICA_DAYNE) && Engine::IN_PARTY(party, Character::Type::BRASH))
            {
                PreText += "Both Sar Jessica and Brash gain a heart for Akihiro. He";

                Choices.push_back(Choice::Base("Akihiro gains a heart for Sar Jessica", {Book::Type::BOOK1, 450}, Choice::Type::GAIN_HEART, Character::Type::AKIHIRO_OF_CHALICE, Character::Type::SAR_JESSICA_DAYNE, 1));
                Choices.push_back(Choice::Base("Akihiro gains a heart for Brash", {Book::Type::BOOK1, 450}, Choice::Type::GAIN_HEART, Character::Type::AKIHIRO_OF_CHALICE, Character::Type::BRASH, 1));
                Choices.push_back(Choice::Base("Go back to the city centre", {Book::Type::BOOK1, 450}));

                Engine::GAIN_HEARTS(party, Character::Type::SAR_JESSICA_DAYNE, Character::Type::AKIHIRO_OF_CHALICE, 1);
                Engine::GAIN_HEARTS(party, Character::Type::BRASH, Character::Type::AKIHIRO_OF_CHALICE, 1);
            }
            else if (Engine::IN_PARTY(party, Character::Type::SAR_JESSICA_DAYNE))
            {
                PreText += "Sar Jessica gains a heart for Akihiro. He";

                Engine::GAIN_HEARTS(party, Character::Type::SAR_JESSICA_DAYNE, Character::Type::AKIHIRO_OF_CHALICE, 1);

                Choices.push_back(Choice::Base("Akihiro gains a heart for Sar Jessica", {Book::Type::BOOK1, 450}, Choice::Type::GAIN_HEART, Character::Type::AKIHIRO_OF_CHALICE, Character::Type::SAR_JESSICA_DAYNE, 1));
                Choices.push_back(Choice::Base("Go back to the city centre", {Book::Type::BOOK1, 450}));
            }
            else if (Engine::IN_PARTY(party, Character::Type::BRASH))
            {
                PreText += "Brash gains a heart for Akihiro. He";

                Engine::GAIN_HEARTS(party, Character::Type::BRASH, Character::Type::AKIHIRO_OF_CHALICE, 1);

                Choices.push_back(Choice::Base("Akihiro gains a heart for Brash", {Book::Type::BOOK1, 450}, Choice::Type::GAIN_HEART, Character::Type::AKIHIRO_OF_CHALICE, Character::Type::BRASH, 1));
                Choices.push_back(Choice::Base("Go back to the city centre", {Book::Type::BOOK1, 450}));
            }
            else
            {
                PreText += "Akihiro";
            }

            PreText += " looks particularly handsome in his fine KENSAI ROBES, and the loving praise being heaped upon him makes him seem even more attractive.\n\nThe family curse is broken, Akihiro is at last at peace.\n\nNote: Akihiro's Charisma score increases by 1 point.\n\nNote: You gained the code A53.";

            Engine::GET_EQUIPMENT(party, Character::Type::AKIHIRO_OF_CHALICE, {Equipment::KENSAI_ROBES3});

            Engine::GAIN_SCORE(party, Character::Type::AKIHIRO_OF_CHALICE, Attribute::Type::CHARISMA, 1);

            Engine::GET_CODES(party, {Codes::A(53)});

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story601 : public Story::Base
    {
    public:
        Story601()
        {
            BookID = Book::Type::BOOK1;

            ID = 601;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IN_TEAM(party, Character::Type::BRASH, Team::Type::CHASE))
            {
                return {Book::Type::BOOK1, 819};
            }
            else
            {
                return {Book::Type::BOOK1, 60};
            }
        }
    };

    class Story602 : public Story::Base
    {
    public:
        Story602()
        {
            BookID = Book::Type::BOOK1;

            ID = 602;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You stroll down the gorgeous avenue towards the palace gates, allowing Unbraaki's soldiers to intercept you. \"What business do you have here?\" grunts the guard, through a helmet made of a sand lizard's skull.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(89)}))
            {
                return {Book::Type::BOOK1, 74};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(1)}))
            {
                return {Book::Type::BOOK1, 559};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(7)}))
            {
                return {Book::Type::BOOK1, 556};
            }
            else
            {
                return {Book::Type::BOOK1, 455};
            }
        }
    };

    class Story603 : public Story::Base
    {
    public:
        Story603()
        {
            BookID = Book::Type::BOOK1;

            ID = 603;

            Location = Location::Type::TUMBLESTONES;

            Text = "To your delight you manage to find all the relevant pieces of the mural and reassemble them together. Inscribed into the stone is a most useful spell.\n\nNote: Any of your spellcasters can add this spell to their spellbooks if they wish but remember that you cannot have more than six spells in a single spellbook at any given time:\n\nSandstorm (Combat)\n\nYou whip up a blast of glassy sand to shred all your foes at once. Make an immediate attack with a Fighting score of 3 against each opponent.\n\nRecharge: 50 silver";

            Bye = "The heat is overbearing you in this desolate place, so you decide to move on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Spells = {Spells::SANDSTORM};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 453}; }
    };

    class Story604 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story604()
        {
            BookID = Book::Type::BOOK1;

            ID = 604;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You have entered a comfortable looking room with a large fireplace, a table scattered with ancient art objects, and a number of straw pallets. You are just getting comfortable when the door opposite you opens and five burly looking orcs emerge. They do not hesitate to give a great roar and leap to the attack.\n\nNote: You can only escape if you have a ship in Mordain harbour.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(74)}))
            {
                return {Book::Type::BOOK1, 861};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            if (Engine::HAS_SHIP(party, Location::Type::MORDAIN))
            {
                CanFlee = true;
            }

            Monsters = {
                Monster::Base("Orc", 5, 4, 4, 8, 0),
                Monster::Base("Orc", 5, 4, 4, 9, 0),
                Monster::Base("Orc", 4, 4, 4, 11, 0),
                Monster::Base("Orc", 6, 5, 3, 10, 0),
                Monster::Base("Orc", 4, 4, 4, 7, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::FLEE)
            {
                Bye = "You flee back to the harbour, get aboard your ship, and sail off. Your crew gives you covering arrow fire.";

                destination = {Book::Type::BOOK1, 851};
            }
            else
            {
                destination = {Book::Type::BOOK1, 734};
            }
        }
    };

    class Story605 : public Story::Base
    {
    public:
        Story605()
        {
            BookID = Book::Type::BOOK1;

            ID = 605;

            Text = "You descend into a mighty canyon, different coloured bands of earth clearly visible along the tall walls of the cleft. Water pools in some places, with patches of lush vegetation clogging parts of the valley. A herd of wild dragonyaks, like scaled buffalo, cluster around the oasis, munching contentedly. A dragonyak bull, appalled at your intervention, stamps his clawed hoof and utters a roar of challenge. He is clearly unwilling to yield the water to you.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            Choices.push_back(Choice::Base("Back away, out of the canyon", {Book::Type::BOOK1, 115}));
            Choices.push_back(Choice::Base("Hold your ground", {Book::Type::BOOK1, 149}));

            if (Engine::HAS_SPELL(party, {Spells::Type::ANIMAL_SPEECH}))
            {
                Choices.push_back(Choice::Base("Cast Animal Speech", {Book::Type::BOOK1, 248}));
            }
        }
    };

    class Story606 : public Story::Base
    {
    public:
        Story606()
        {
            BookID = Book::Type::BOOK1;

            ID = 606;

            Text = "You quickly examine the bodies before the housecarls arrive on the scene. You find a little money, 20 silver coins. Most damningly you find a RING OF THE PATRIARCH. These rings are only given out to the most loyal servants of Cursus. Clearly your allegiance to the Everchild will mean you shall be hounded by these fanatics until the end of your days! Shaking your head, you quickly flee the scene.\n\nNote: You gained the code A90.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::RING_OF_THE_PATRIARCH};

            Limit = 1;

            Engine::GAIN_MONEY(party, 20);

            Engine::GET_CODES(party, {Codes::A(90)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story607 : public Story::Base
    {
    public:
        Story607()
        {
            BookID = Book::Type::BOOK1;

            ID = 607;

            Text = "That night, you stroll along the terrace, the night a canopy of stars, reflected in the watery rice paddies that surround the house. Sar Jessica is with you, and in the tradition of Royce you hold her arm as you stroll.\n\n\"You are a fine man, Akihiro,\" says Sar Jessica. \"Honourable, yet not proud. Willing to forgive insult, but not bear it. And handsome too.\"\n\nYou shrug. \"No more than any other man,\" you say.\n\n\"Much more than most,\" corrects Sar Jessica. She gazes into your eyes. \"My father intends me to marry Sir Anthony Ross. He is a kind man, but crude. I am not sure I can marry him now I know what true manhood is. Delicate but strong, wise but not insufferable. How could I settle for less, now I have seen what the true flower of chivalry is?\"\n\n\"Your father would never approve of me, Sar Jessica,\" you say darkly. \"Your people would never accept me. I am foreign. You shall be a baroness...\"\n\nSuddenly her lips are pressing against yours. It seems that the knight will not be denied. Her kind words and your feeling of triumph combine, and you kiss her back, unable to restrain yourself.\n\n\"Oh! Forgive me!\" you hear a familiar voice cry. Breaking off you can see Yuko, your sister, her hand to her mouth at the scandal she has witnessed. She quickly scampers away.\n\n\"Privacy is rarer than gold,\" you muse, turning back to Jessica. \"Come, let us go in before gossip overtakes us.\"\n\nNote: Akihiro has gained a heart for Sar Jessica Dayne. Sar Jessica Dayne also gains a heart for Akihiro. You gained the code A98.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEARTS(party, Character::Type::AKIHIRO_OF_CHALICE, Character::Type::SAR_JESSICA_DAYNE, 1);
            Engine::GAIN_HEARTS(party, Character::Type::SAR_JESSICA_DAYNE, Character::Type::AKIHIRO_OF_CHALICE, 1);

            Engine::GET_CODES(party, {Codes::A(98)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story608 : public Story::Base
    {
    public:
        Story608()
        {
            BookID = Book::Type::BOOK1;

            ID = 608;

            Location = Location::Type::SALTDAD_ARENA;

            Text = "Because some of your party members used magic spells while in the arena, they are taken away by the guards to a small room where their tongues are cut out and then sealed with branding irons.\n\nNote: Each magic-using character loses 3 Health and cannot cast spells unless they can find a way to regrow their tongues!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (!Engine::HAS_STATUS(party, Character::Status::USED_MAGIC_INARENA))
            {
                return {Book::Type::BOOK1, 792};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            for (auto i = 0; i < party.Members.size(); i++)
            {
                if (Engine::HAS_STATUS(party.Members[i], Character::Status::USED_MAGIC_INARENA))
                {
                    Engine::GAIN_HEALTH(party.Members[i], -3);

                    Engine::GAIN_STATUS(party.Members[i], Character::Status::LOST_TONGUE);

                    Engine::REMOVE_STATUS(party.Members[i], Character::Status::USED_MAGIC_INARENA);
                }
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 792}; }
    };

    class Story609 : public Story::Base
    {
    public:
        Story609()
        {
            BookID = Book::Type::BOOK1;

            ID = 609;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "You wade waist-deep through the cloudy, muddy water. Leeches latch onto your skin and the insanitary conditions take their toll on your health.\n\nNote: Each party member loses 2 Health points.";

            Bye = "However, by following the trail you have not gotten lost. Eventually the path leads to higher, drier grounds.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -2);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 359}; }
    };

    class Story610 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story610()
        {
            BookID = Book::Type::BOOK1;

            ID = 610;

            Location = Location::Type::SALTDAD;

            Image = "images/book1/march_to_clifftop.png";

            Text = "And so begins your march to Clifftop.\n\nThe Everchild's banners, a blazing sun on a field of azure, flutter in the desert wind as her armies troop onwards. After several days you meet the opposing army of Lothor the Ugly just beyond the river bridge.\n\n\"Why doesn't Lothor hold us at the bridge?\" the Everchild asks Che Long.\n\n\"He fears the quality of our troops,\" says Che Long. \"Lothor wishes to use his great numbers to overwhelm us.\"\n\n\"He is a fool, with the river to his back his troops have nowhere to run,\" you laugh.\n\n\"We must beat him first,\" cautions the Everchild. \"Assemble our formations. The battle will soon be upon us.\"\n\nNote: You may choose a maximum of six units from the Saltdad barracks to commit to this battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            BattleLocation = Location::Type::SALTDAD;

            EnemyArmy = {
                Army::Base("Landsmen Cavalry", Army::Type::LANDSMEN_CAVALRY, Location::Type::SALTDAD, Location::BattleField::LEFT_FLANK_FRONT, 4, 2, false),
                Army::Base("Field Overseers", Army::Type::FIELD_OVERSEERS, Location::Type::SALTDAD, Location::BattleField::LEFT_FLANK_SUPPORT, 2, 2, false),
                Army::Base("Cursite Fanatics", Army::Type::CURSITE_FANATICS, Location::Type::SALTDAD, Location::BattleField::CENTER_FRONT, 3, 5, false),
                Army::Base("Slave Levies", Army::Type::SLAVE_LEVIES, Location::Type::SALTDAD, Location::BattleField::CENTER_SUPPORT, 1, 1, false),
                Army::Base("Clifftop Infantry", Army::Type::CLIFFTOP_INFANTRY, Location::Type::SALTDAD, Location::BattleField::RIGHT_FLANK_FRONT, 3, 3, false),
                Army::Base("Thalsian Mercenaries", Army::Type::THALSIAN_MERCENARIES, Location::Type::SALTDAD, Location::BattleField::RIGHT_FLANK_SUPPORT, 2, 3, false)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                destination = {Book::Type::BOOK1, 342};
            }
            else
            {
                destination = {Book::Type::BOOK1, 48};
            }
        }
    };

    class Story611 : public Story::Base
    {
    public:
        Story611()
        {
            BookID = Book::Type::BOOK1;

            ID = 611;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The gatehouse's weapon store is open to you. You may take any of the following items:\n\nHIDE ARMOUR (Armour +1)\nSHIELD (Armour +2)\nMAUL* (Fighting +1)\nIRON SHORTSWORD (Fighting +1)\nCRUDE BLADE (Fighting +0) -- you may take up to four CRUDE BLADES.\n\nYou also grab a number of crude weapons for the Everchild and her followers, before fleeing the gatehouse, closing the door behind you.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::HIDE_ARMOUR1, Equipment::SHIELD2, Equipment::MAUL, Equipment::IRON_SHORTSWORD1, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE};

            Limit = 8;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 317}; }
    };

    class Story612 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story612()
        {
            BookID = Book::Type::BOOK1;

            ID = 612;

            Bye = "Saddened at this loss you order your crew to sail on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The waves tower above your flimsy vessel, blinding you as your little boat is tossed and turned in the storm. Long before you reach the sailor he is swept off the rock by a palace-sized wave. Your own vessel is overturned, and you only just manage to swim back to your ship.\n\nNote: ";

            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                Engine::GAIN_HEALTH(party.Members[party.LastSelected], -3);

                PreText += std::string(party.Members[party.LastSelected].Name) + " loses 3 Health points.";
            }
            else
            {
                PreText += "Your chosen party member loses 3 Health points.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 240}; }
    };

    class Story613 : public Story::Base
    {
    public:
        Story613()
        {
            BookID = Book::Type::BOOK1;

            ID = 613;

            Text = "You spy a merchant, blundering around your camp. \"I'm most dreadfully sorry for disturbing you,\" he mumbles. \"I was hoping to find some old bits of wood from your campfire. The night is absolutely freezing.\"\n\nYou breathe a sigh of relief and greet the old merchant. You spare what tinder you can and bid him a good evening.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 840}; }
    };

    class Story614 : public Story::Base
    {
    public:
        Story614()
        {
            BookID = Book::Type::BOOK1;

            ID = 614;

            Location = Location::Type::LUUTANESH;

            Text = "You have come to the small town of Luutanesh, positioned on the crossroads that lie between three great cities of the valley. The Cold River runs near on one side of the town, flooding the nearby rice plains which are tended by hundreds of workers in wide sunhats.\n\nThe village itself is poorer than it should be, with tax agents from Chalice, Saltdad and Cursus routinely stripping it of wealth. Security is strong here, with locals armed with long spears and dragonyak hide armour standing in guard huts positioned along the road.";

            Choices.clear();
            Choices.push_back(Choice::Base("Stop in at the Cold River Inn", {Book::Type::BOOK1, 284}));
            Choices.push_back(Choice::Base("Speak to the rice farmers", {Book::Type::BOOK1, 185}));
            Choices.push_back(Choice::Base("Leave Luutanesh", {Book::Type::BOOK1, 194}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story615 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story615()
        {
            BookID = Book::Type::BOOK1;

            ID = 615;

            Bye = "It seems you have no choice but to fight with the bear.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You cast your spell and address the bear, pleading with it to stand down. \"Do not be a puppet for these vile men,\" you say. \"Pretend to submit to me. There is no need to fight.\"\n\n\"I will never yield to humans!\" snarls the bear. \"Though you are an animal friend I shall never show weakness, come what may!\"\n\nThe bear lunges at you, swiping you to the floor with his heavy paw.\n\nNote: ";

            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                Engine::CAST_SPELL(party.Members[party.LastSelected], Spells::Type::ANIMAL_SPEECH);

                Engine::GAIN_HEALTH(party.Members[party.LastSelected], -3);

                PreText += std::string(party.Members[party.LastSelected].Name) + " loses 3 Health points.";
            }
            else
            {
                PreText += "Your chosen party member loses 3 Health points.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 425}; }
    };

    class Story616 : public Story::Base
    {
    public:
        Story616()
        {
            BookID = Book::Type::BOOK1;

            ID = 616;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "You know when to take a hint. You carefully back away. As you walk through an alleyway you hear the sounds of shouting and drawn swords. Blood is being spilt and the screams resonate through the city. It seems that even in Chalice the savagery of the Valley of Bones can take hold.";

            Bye = "Shaking your head sadly you move on.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story617 : public Story::Base
    {
    public:
        Story617()
        {
            BookID = Book::Type::BOOK1;

            ID = 617;

            Text = "That evening you gather in the wealthy area of the city, where taller buildings made of stone and wood stand in the shadow of the palace. Although the Bronzeguard do patrol this part of the city, most of the wealthier locals employ private guards to protect their valuables. Brekken's thieves have already dealt with the guard dogs that patrol the grounds around Chellar's house with poisoned meat. Now the way to the house is clearer.\n\n\"The front door is guarded with magical wards,\" says Brekken. \"Only Chellar or his steward can open it, unless you think you might be able to disenchant it? Otherwise there are the upper floor windows. I'll lead my team to scale the walls. You can join us, or handle the door... or maybe do both? It's up to you.\"\n\nNote: Decide how many of your party will deal with the magical door, and how many will help scaling the walls. You can assign everyone to one task or split your team between both tasks.\n\nYou gained the code A10.";

            Choices.clear();
            Choices.push_back(Choice::Base("Decide who will climb the walls and who deals with the front door", {Book::Type::BOOK1, -617}, Choice::Type::ASSIGN_TEAMS, {{Team::Type::MAGICAL_DOOR, 0, 4}, {Team::Type::WALL_CLIMBING, 1, 4}}, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(10)});
        }
    };

    class Event617 : public Story::Base
    {
    public:
        Event617()
        {
            BookID = Book::Type::BOOK1;

            ID = -617;

            DisplayID = 617;

            Choices.clear();

            Controls = Story::Controls::NONE;
        }

        Engine::Destination Background(Party::Base &party)
        {
            for (auto i = 0; i < party.Members.size(); i++)
            {
                if (Engine::IS_ACTIVE(party, i))
                {
                    if (party.Members[i].Team != Team::Type::MAGICAL_DOOR)
                    {
                        party.Members[i].Team = Team::Type::WALL_CLIMBING;
                    }
                }
            }

            if (Engine::COUNT(party, Team::Type::MAGICAL_DOOR) > 0)
            {
                return {Book::Type::BOOK1, 322};
            }
            else
            {
                return {Book::Type::BOOK1, 728};
            }
        }
    };

    class Story618 : public Story::Base
    {
    public:
        Story618()
        {
            BookID = Book::Type::BOOK1;

            ID = 618;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "You are leaving the Lhasbreath jungle, happy to be rid of the biting insects and draining humidity in that place. Where will you venture now?";

            Choices.clear();
            Choices.push_back(Choice::Base("North, to the Palace of Unbraaki", {Book::Type::BOOK1, 890}));
            Choices.push_back(Choice::Base("East, to the city of Lhasbreath", {Book::Type::BOOK1, 775}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story619 : public Story::Base
    {
    public:
        Story619()
        {
            BookID = Book::Type::BOOK1;

            ID = 619;

            Text = "The monstrous thing seems almost indestructible and sweat breaks out on your forehead. Suddenly there is a sharp slink! The statue's right foot has been sliced from its leg. The creature totters unsteadily and comes crashing to the ground, shattering into pieces. Standing behind the destruction is the young Drakehallow woman, a green longsword clutched in her hand. She looks upon you with a quizzical eyebrow.\n\n\"Thank you,\" you say, bowing. \"Your assistance is most appreciated.\"\n\n\"I'm sure it is,\" she says slyly.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 415}; }
    };

    class Story620 : public Story::Base
    {
    public:
        Story620()
        {
            BookID = Book::Type::BOOK1;

            ID = 620;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "The Everchild greets you warmly, and bids you stay in the palace as long as you wish. If you wish to help the Everchild in her campaign to reunite the Valley of Bones you should attend her war council.\n\nNote: Your party recovers all lost Health points. In addition, the Everchild will sponsor your spellcasters, allowing you to recharge your spells at half the usual cost.\n\nWhilst you are in the palace you have access to the Vault. You can store any number of items or amounts of money here for safe keeping. The Vault is magical and can transport things stored here from one place to another. If you gain access to the Vault anywhere, or through the magic cabinet spell, you can access all the items you have placed in the Vault whilst in the Valley of Bones.";

            Choices.clear();
            Choices.push_back(Choice::Base("Attend the Everchild's war council", {Book::Type::BOOK1, 189}));
            Choices.push_back(Choice::Base("Check on the garrison", {Book::Type::BOOK1, 508}));
            Choices.push_back(Choice::Base("Explore the palace ruins", {Book::Type::BOOK1, 543}));
            Choices.push_back(Choice::Base("Leave the palace", {Book::Type::BOOK1, 75}));

            RestPrice = 0;

            CanRecharge = true;

            Controls = Story::Controls::INN;
        }

        void Event(Party::Base &party)
        {
            Engine::REST(party);

            Engine::GET_CODES(party, {Codes::Type::MAGIC_VAULT, Codes::Type::RECHARGE_COSTS_HALF});
        }
    };

    class Story621 : public Story::Base
    {
    public:
        Story621()
        {
            BookID = Book::Type::BOOK1;

            ID = 621;

            Text = "You re-enter the study, eager to see what new spells Unbraaki has discovered. You almost jolt in surprise as you see the arch-sorcerer there, waiting for you, a gang of robed monkeys surrounding him. \"Thought I was in the library?\" smiles the sorcerer. \"Fool me once, shame on you. But you'll never fool me twice. Kill them.\"";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 564}; }
    };

    class Story622 : public Story::Base
    {
    public:
        Story622()
        {
            BookID = Book::Type::BOOK1;

            ID = 622;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The owner, a local magistrate, is delighted with your kindness. He promises to put in a good word with the authorities whilst you are in Chalice.\n\nNote: From now on, any time you have to make a Charisma skill check in the city of Chalice, you may pass it automatically.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::CHARISMA_SUCCESS_CHALICE});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story623 : public Story::Base
    {
    public:
        Story623()
        {
            BookID = Book::Type::BOOK1;

            ID = 623;

            Text = "The door behind you is almost in splinters as the Bronzeguard garrison attempts to break into the tower. Kicking open a nearby window you leap into the street beyond, panting with exhaustion. Alas, the Bronzeguard will never eat the stew now they know it is poisoned. But at least you escaped with your lives!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 75}; }
    };

    class Story624 : public Story::Base
    {
    public:
        Story624()
        {
            BookID = Book::Type::BOOK1;

            ID = 624;

            Text = "You lower yourself into the pit and check over the body, but do not uncover any additional treasure.";

            Choices.clear();
            Choices.push_back(Choice::Base("Climb up the far side of the pit", {Book::Type::BOOK1, 303}));
            Choices.push_back(Choice::Base("Climb back up the way you came", {Book::Type::BOOK1, 761}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story625 : public Story::Base
    {
    public:
        Story625()
        {
            BookID = Book::Type::BOOK1;

            ID = 625;

            Location = Location::Type::COLD_RIVER;

            Text = "You are on the eastern bank of the cold river, a few dozen miles from the religious city of Cursus. The heat is oppressive, but thanks to the ample water supply and obvious directional clues from the river, you can navigate this stretch of desert quite easily. River barges make their way lazily up and down the river, but they do so on the far side of the bank. The notorious Caves of Uranu lie to the north, and no trader will risk their stocks in that foul wasteland.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go north, to the Caves of Uranu", {Book::Type::BOOK1, 346}));
            Choices.push_back(Choice::Base("Go south, to the city of Cursus", {Book::Type::BOOK1, 340}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story626 : public Story::Base
    {
    public:
        Story626()
        {
            BookID = Book::Type::BOOK1;

            ID = 626;

            Location = Location::Type::CLIFFTOP;

            IsCity = true;

            Text = "The next morning the surviving landlords and masters of Clifftop fill the King's Hall to kneel before the Everchild. Resplendent in her yellow and blue silks and glittering silver crown, she immediately repeals the rights of the taskmasters to execute or mutilate their workers. Upstanding members of the revolution are awarded sweeping areas of land, the cruellest taskmasters are efficiently executed, and the Everchild goes amongst the workers to heal the lame and sick with her magic. Many fall in love with the queen that day, and soon her name is being chanted across city.\n\nThe Everchild award rulership of the city to Ayleta the Traveller, a mysterious mystic who has done good work in administrating the changes in Saltdad. You and your party are publicly honoured and presented with 1000 silver coins in compensation for your labours. Capturing this city has been a grand step forward for the Everchild's goals.\n\nNote: Any units that didn't rout can restore their Morale back to their starting value.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose two party members and raise their maximum, unwounded Health scores by 1 point.", {Book::Type::BOOK1, -626}, Choice::Type::TEAM_MAX_HEALTH, 2, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 1000);

            Engine::REMOVE_ROUTED(party);

            Engine::RESTORE_MORALE(party);
        }
    };

    class Event626 : public Story::Base
    {
    public:
        Event626()
        {
            BookID = Book::Type::BOOK1;

            ID = -626;

            DisplayID = 626;

            Text = "The Everchild offers to escort you back to Saltdad, if you wish, or you can remain in the captured city of Clifftop.";

            Choices.clear();
            Choices.push_back(Choice::Base("Return to Saltdad", {Book::Type::BOOK1, 75}));
            Choices.push_back(Choice::Base("Stay in Clifftop", {Book::Type::BOOK1, 19}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story627 : public Story::Base
    {
    public:
        Story627()
        {
            BookID = Book::Type::BOOK1;

            ID = 627;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "You've seen the priest's longing gazes at your body. Now all you have to do is turn that lust into love and you'll have him eating out of the palm of your hand. Soon you are engaged in many deep and meaningful chats in the dead of night, listening to the priest's worries, massaging his troubles away, whilst lamenting your own enslavement when you feel his pity upon you.\n\nOne morning the priest sends you away. He is on the verge of breaking his vows and can no longer bear to have such a beautiful creature working for him. You tell him that you will not leave without your friends, so he reluctantly frees them too.\n\nAs a parting gift he presents you with 120 silver coins and a HANDSOME BROOCH (Charisma +1) so you can always think of him in the future.";

            Bye = "Giving him a chaste but meaningful kiss goodbye, you quickly flee into the city centre before he can change his mind.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 120);

            Engine::REMOVE_STATUS(party, Character::Status::CAPTURED);

            Engine::GET_EQUIPMENT(party, Character::Type::BRASH, {Equipment::HANDSOME_BROOCH1});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 340}; }
    };

    class Story628 : public Story::Base
    {
    public:
        Story628()
        {
            BookID = Book::Type::BOOK1;

            ID = 628;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The sister plainly informs you that the God King is not available to be seen. The stern glare she fixes you wish suggests that it would not be easy to change her mind.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(20)}))
            {
                return {Book::Type::BOOK1, 641};
            }
            else if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::BEAUTIFUL_LETTER}))
            {
                return {Book::Type::BOOK1, 290};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(7)}) && !Engine::VERIFY_CODES(party, {Codes::A(28)}))
            {
                return {Book::Type::BOOK1, 176};
            }
            else
            {
                Bye = "It is clear that you will be unable to pay a visit and are escorted off the premises by armed kensai.";

                return {Book::Type::BOOK1, 450};
            }
        }
    };

    class Story629 : public Story::Base
    {
    public:
        Story629()
        {
            BookID = Book::Type::BOOK1;

            ID = 629;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "\"I am not yet at my full potency,\" admits the Everchild, running her hand through her filthy locks. \"In my eagerness to see the Iron King dethroned I sided with a certain group of revolutionaries. Sadly, we were ambushed by the king's men, and there was no opportunity for me to use my magic to turn the tide of the battle. I opted to keep my identity secret until a more appropriate juncture.\"\n\n\"But are you indeed the Everchild reborn, as the legends say?\" you insist.\n\n\"I believe so,\" she nods. \"I was born to common folk, and yet my mind is filled with memories, manners and skills from a past life. Even if I am not, I am determined to replace the Iron King's tyranny with even-handed justice. I am willing to take on the mantle of the Everchild, so why not take her name as well?\"\n\n\"Why do you not escape using your magic?\" you ask.\n\n\"It is not yet mighty enough for me to effect an escape... on my own,\" she explains. \"Besides, a queen needs followers, and mine are imprisoned here. We will leave together, or not at all.\" \n\n\"A noble sentiment,\" you admit. \"But how exactly do you plan to escape?\"";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 743}; }
    };

    class Story630 : public Story::Base
    {
    public:
        Story630()
        {
            BookID = Book::Type::BOOK1;

            ID = 630;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You prise out the supports of the barricade and soon the whole thing come crumbling down. You sweep the rubble onto one side of the tunnel to allow easy access.\n\nPast the ruins of the barricade the tunnel continues east for a while before ending at a wooden door.\n\nNote: You gained the code A72.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go east, through the door", {Book::Type::BOOK1, 821}));
            Choices.push_back(Choice::Base("Go west, back down the stairs", {Book::Type::BOOK1, 23}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(72)});
        }
    };

    class Story631 : public Story::Base
    {
    public:
        Story631()
        {
            BookID = Book::Type::BOOK1;

            ID = 631;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "The slavers have sold you to the dreaded Saltdad Arena, a grim place where the poor and criminals alike fight to the death for the savage entertainment of the crowd.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(1)}))
            {
                return {Book::Type::BOOK1, 592};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::C(17)}))
            {
                return {Book::Type::BOOK1, 582};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::Type::FIRSTTIME_SOLD_SALTDADARENA}))
            {
                return {Book::Type::BOOK1, 271};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::Type::FOUGHT_IN_ARENA}))
            {
                return {Book::Type::BOOK1, 582};
            }
            else
            {
                return {Book::Type::BOOK1, 271};
            }
        }
    };

    class Story632 : public Story::Base
    {
    public:
        Story632()
        {
            BookID = Book::Type::BOOK1;

            ID = 632;

            Text = "You are spotted as you dash across the grounds. The alarm is called and soon the grounds are heaving with hundreds of soldiers, some on horseback. Escape is impossible. You are seized by Unbraaki's guards.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 55}; }
    };

    class Story633 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story633()
        {
            BookID = Book::Type::BOOK1;

            ID = 633;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You approach the palace, the mighty structure almost half in ruins after a thousand years of wear.";

            Choices.clear();

            if (!Engine::VERIFY_CODES_ANY(party, {Codes::A(1), Codes::A(4), Codes::A(8)}))
            {
                PreText += "\n\nTwo strong Bronzeguard, the glittering armoured soldiers of the Iron King, cross spears as you attempt to gain entrance to the palace. \"What business have you here?\" they ask suspiciously. \"This place is not open to foreign slime such as you.\"\n\nYou can quickly apologize and back away if you wish or try to convince the guards to let you see the Iron King.";

                Choices.push_back(Choice::Base("Apologize", {Book::Type::BOOK1, 75}));
                Choices.push_back(Choice::Base("Convince the Bronzeguard (Team check: Charisma 4+, Successes: 5)", {Book::Type::BOOK1, 333}, {Book::Type::BOOK1, 475}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 4, 5));
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(1)}))
            {
                return {Book::Type::BOOK1, 620};
            }
            else
            {
                return {Book::Type::BOOK1, 868};
            }
        }
    };

    class Story634 : public Story::Base
    {
    public:
        Story634()
        {
            BookID = Book::Type::BOOK1;

            ID = 634;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You are in a long corridor that runs west to east, with a corridor that branches off the south somewhat in the middle. To the west the corridor ends in a set of stairs that lead downwards. To the east the corridor abruptly turns north. To the south lies the crossroads.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go west, down the stairs", {Book::Type::BOOK1, 439}));
            Choices.push_back(Choice::Base("Go east, and then north around the bend of the corridor", {Book::Type::BOOK1, 749}));
            Choices.push_back(Choice::Base("Go south, to the crossroads", {Book::Type::BOOK1, 310}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story635 : public Story::Base
    {
    public:
        Story635()
        {
            BookID = Book::Type::BOOK1;

            ID = 635;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You manage to slay the bulky creature, its thick blood leaking into the stones. Yu Yan nods to you. \"Impressive swordsmanship,\" she says. \"I'm pleased I made this partnership. Speaking of which, I have some treasure to gather.\"\n\nYou watch idly as she begins to pile the silver coins and jewellery into her sack. Curious, you look inside, only to see the SILVER IDOL you have been searching for peeking out of her sack. The devious looter has already found the object of your quest!\n\n\"Yu Yan! That silver idol is mine, by the terms of our agreement!\" you protest. \"Hand it over, now!\"\n\n\"I found it before we made that agreement, it's mine!\" she insists.\n\n\"Don't let this come to blows, Yu Yan,\" you threaten.\n\n\"The idol! Now!\"\n\nYu Yan looks crestfallen. She nods slowly, reaching into her bag. Suddenly a shower of silver coins are hurled into your face, sending you staggering back. Yu Yan giggles, and dashes up the stairs. Snarling, you go in pursuit.";

            Choices.clear();
            Choices.push_back(Choice::Base("Chase Yu Yan (Individual check: Survival 4+, Successes: 3)", {Book::Type::BOOK1, 899}, {Book::Type::BOOK1, 433}, {Attribute::Type::SURVIVAL}, 4, 3));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GO_SOLO(party, Character::Type::AKIHIRO_OF_CHALICE);
        }
    };

    class Story636 : public Story::Base
    {
    public:
        Story636()
        {
            BookID = Book::Type::BOOK1;

            ID = 636;

            Text = "In the depths of a freezing desert night your ears pick up the sound of crunching on the desert sands. Stirring your colleagues awake you scan the desert with your torch. Three warriors, stripped to the waist, bearing the ritual scars of Cursus, stand before you, their swords drawn. Behind them stands a tall priest of Cursus, the stench of sorcery about him. \"Heretics!\" he hisses. \"Your damned queen will never rule the hearts of the virtuous. Death to the Everchild and her apostate followers!\"\n\nA battle is inevitable.\n\nNote: The Sorcerer, instead of attacking, will cast the following spells each turn, as long as he is still alive:\n\n1st turn: The sorcerer casts an Ice Bolt spell. He makes an Fighting: 8 attack.\n\n2nd turn: The sorcerer casts a Dazing Lights spell. On the next combat round, each party member requires a 5+ to hit, rather than 4+\n\n3rd turn: The sorcerer casts a Sandstorm spell. The sorcerer makes a Fighting: 3 attack on each party member.\n\n4th turn onwards: The sorcerer makes a standard attack.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Zealot", 4, 4, 4, 6, 0),
                Monster::Base("Zealot", 5, 4, 4, 5, 0),
                Monster::Base("Zealot", 5, 4, 4, 5, 0),
                Monster::Base("Sorcerer", Monster::Type::ZEALOT_SORCERER, 3, 5, 4, 11, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 278}; }
    };

    class Story637 : public Story::Base
    {
    public:
        Story637()
        {
            BookID = Book::Type::BOOK1;

            ID = 637;

            Text = "You gain the sense of something obscured in the stonework. Casting your spell, a section of the wall dissolves into darkness. Shining your lanterns within reveals a circular room filled with sturdy shelves and boxes. Your heart hammers in excitement. This is a treasury room, probably one of the smaller treasuries built during the reign of the first Everchild.\n\nSadly, much of the money has already been taken, and many boxes are empty. Perhaps there was some sort of disaster in the waning years of the Everchild's reign? There is still some money to be found, however, including 600 silver coins and a bar of GOLD BULLION.\n\nNote: You gained the code A97.";

            Bye = "Stuffing your bags with coins, you depart.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(97)}))
            {
                return {Book::Type::BOOK1, 653};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::GOLD_BULLION};

            Limit = 1;

            Engine::GAIN_MONEY(party, 600);

            Engine::GET_CODES(party, {Codes::A(97)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 620}; }
    };

    class Story638 : public Story::Base
    {
    public:
        Story638()
        {
            BookID = Book::Type::BOOK1;

            ID = 638;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The sister escorts you into a fabulous hall lined with kensai warriors, the elite guards of the God King. The ruler himself comes gliding into the hall, dressed in long silks, a middle-aged man with a perfectly neutral expression. He sits upon a pile of cushions, and bids you to do the same.\n\n\"You would speak with me?\" he asks plainly, his black eyes inscrutable.\n\nYou tell him about your mission from the Everchild and ask if he would be willing to provide soldiers for her cause. He listens patiently to your request and does not interrupt until you have made your case.\n\n\"I remember the Everchild, of course,\" he says, his eyes taking on a distant look. \"She was a fellow immortal, but always the best of us. Once, six immortal kings sat upon the thrones of the Valley of Lilies, as it was called then. She ruled us with wisdom and patience. When Abraxas, the demon lord, rose from his pit she led an army of warriors and immortals against him. I was the only king to deny her call, as I foresaw combat against the beast of death was impossible. I was sanctioned, but when the dust settled it was she and her fellow kings who were dead, and her threat to end my rule came to nothing. Abraxas destroyed the valley, turning it into a nigh-lifeless desert. I have missed her, despite the harsh words of our final parting.\"\n\nThe God King turns to you, at last back in the present. \"Of course, that is assuming that the girl you represent really is the Everchild. Her return has been long predicted, but not by me. I will require proof before I risk the wrath of the patriarch of Cursus and side with her.\"\n\n\"Perhaps we can arrange a meeting?\" you suggest.\n\n\"Unnecessary,\" says the God King. \"All I require of her is her writing. Her calligraphy. You can tell from a person's hand whether they are honest or not. Tell her to write me a letter formally requesting my aid. If I find it well, she shall have all the aid I can give her.\"\n\nNote: You gained the code A28.";

            Bye = "The God King snaps his fingers, and kensai warriors immediately move to escort you out. It appears your audience is at an end.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(28)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story639 : public Story::Base
    {
    public:
        Story639()
        {
            BookID = Book::Type::BOOK1;

            ID = 639;

            Text = "Attempting to assassinate an archwizard is a task only the mightiest heroes could perform. The Everchild's agents have only a slim hope of completing it.";

            Choices.clear();
            Choices.push_back(Choice::Base("Check if the Everchild's agents were successful", {{5, "The assassins are caught and killed.", {Book::Type::BOOK1, 96}}, {6, NULL, {Book::Type::BOOK1, -639}}}, 1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event639 : public Story::Base
    {
    public:
        Event639()
        {
            BookID = Book::Type::BOOK1;

            ID = -639;

            DisplayID = 639;

            Text = "The Everchild's agents are successful, killing Descantos as he sleeps.\n\nNote: You gained the code A95.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(95)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 96}; }
    };

    class Story640 : public Story::Base
    {
    public:
        Story640()
        {
            BookID = Book::Type::BOOK1;

            ID = 640;

            Location = Location::Type::LHASBREATH;

            IsCity = true;

            Text = "You approach the stone tower of Kopu and knock upon the heavy timber door. Sometime later an apologetic slave opens the door, explaining that her master is currently travelling and is not in. \"I believe he was headed to the city of Clifftop, to study the dialect of the sea traders. I'm not sure when he will be back.\"";

            Bye = "You thank the slave for her time and go back to the city centre.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(19)}))
            {
                return {Book::Type::BOOK1, 539};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story641 : public Story::Base
    {
    public:
        Story641()
        {
            BookID = Book::Type::BOOK1;

            ID = 640;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "\"The God King has already pledged his forces and obedience to your mistress,\" says the sister, annoyed. \"There is nothing more he can provide for you. Please leave him to his meditations.\"";

            Bye = "The firmness of the sister's voice brooks no argument. You leave.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story642 : public Story::Base
    {
    public:
        Story642()
        {
            BookID = Book::Type::BOOK1;

            ID = 642;

            Location = Location::Type::CLIFFTOP;

            IsCity = true;

            Text = "You think twice before entering the hall of Lothor the Ugly. Last time you only narrowly escaped with your lives. You cannot bring yourself to enter, and return to the city centre.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 19}; }
    };

    class Story643 : public Story::Base
    {
    public:
        Story643()
        {
            BookID = Book::Type::BOOK1;

            ID = 643;

            Location = Location::Type::CLIFFTOP;

            Text = "You have been asked by the harbourmaster of Clifftop to retrieve the missing cogwheel from the cargo crane from the seabed.";

            Choices.clear();
            Choices.push_back(Choice::Base("You like to attend to this now", {Book::Type::BOOK1, 583}));
            Choices.push_back(Choice::Base("It too risky", {Book::Type::BOOK1, 82}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story644 : public Story::Base
    {
    public:
        Story644()
        {
            BookID = Book::Type::BOOK1;

            ID = 644;

            Location = Location::Type::SALT_MINES;

            Text = "The GOLDEN CANDLESTICK looks valuable, but ordinary. You can add it to your equipment.";

            Choices.clear();
            Choices.push_back(Choice::Base("Examine the bookcase", {Book::Type::BOOK1, 230}));
            Choices.push_back(Choice::Base("Head upstairs to help the climbing team", {Book::Type::BOOK1, 92}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Team = Team::Type::MAGICAL_DOOR;

            Take = {Equipment::GOLDEN_CANDLESTICK};

            Limit = 1;
        }
    };

    class Story645 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story645()
        {
            BookID = Book::Type::BOOK1;

            ID = 645;

            Location = Location::Type::MORDAIN;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You gaze out of the missing wall onto a terrific seascape. This dungeon room peeks out of the cliffside, with the ancient, ruined docks some fifty feet below.";

            Choices.clear();

            if (Engine::HAS_SHIP(party, Location::Type::MORDAIN))
            {
                PreText += "\n\nYou have a ship docked in Mordain harbour, you can see it here. It might be possible to climb down the cliff face and reach the harbour, though it is far from a risk-free climb.";

                Choices.push_back(Choice::Base("Climb down the cliffs to the harbour", {Book::Type::BOOK1, 188}));
            }

            Choices.push_back(Choice::Base("Examine the body on the rack", {Book::Type::BOOK1, 274}));
            Choices.push_back(Choice::Base("Leave the room and return to the crossroads", {Book::Type::BOOK1, 566}));

            Text = PreText.c_str();
        }
    };

    class Story646 : public Story::Base
    {
    public:
        Story646()
        {
            BookID = Book::Type::BOOK1;

            ID = 646;

            Text = "You grip onto your teammate's hand, heaving with all your might. But it is as if a demon was pulling at their legs. With a cry they are pulled from your grasp and sucked into the earth, never to be seen again. You stagger from the cave in horror, fearing the same fate might befall the rest of you.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                party.Members[party.LastSelected].Health = 0;
                party.Members[party.LastSelected].Equipment.clear();
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 395}; }
    };

    class Story647 : public Story::Base
    {
    public:
        Story647()
        {
            BookID = Book::Type::BOOK1;

            ID = 647;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Voices echo down the tunnel as you emerge onto the balcony of a large chamber. You wave the Everchild and her supporters down as you creep forwards to take a look. Peering over the balcony railing you see a dozen rough looking characters, armed with daggers, clubs and other simple weapons. Around them are various chests and crates, with the names of several different company brands upon them. It is clear that you have stumbled upon a thieves' hideout, their swarthy faces lit by the large central fire in the chamber.";

            Choices.clear();
            Choices.push_back(Choice::Base("Call out and approach them peacefully", {Book::Type::BOOK1, 187}));
            Choices.push_back(Choice::Base("Launch a surprise attack on the rogues", {Book::Type::BOOK1, 889}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story648 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story648()
        {
            BookID = Book::Type::BOOK1;

            ID = 648;

            Text = "You stick to the Everchild like glue all evening. With so much at stake the Everchild cannot sleep, and spends the entire night in preparation, touring the troops, and discussing plans. The assassination attempt is so subtle you might have missed it. During a practical discussion concerning which avenues to secure first in the attack on Cursus city, a servant approaches with a flask of wine. He is indecently close before you realise that you don't recognise his face. Acting with your gut instinct you shove the fellow away. He immediately draws a knife and tries to make for the queen.\n\nNote: The battle ends if at the end of any round you fail to inflict even a single point of damage on the Assassin.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {Monster::Base("Assassin", Monster::Type::EVERCHILD_ASSASSIN, 4, 4, 4, 7, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::FAILED_ATTACK)
            {
                destination = {Book::Type::BOOK1, 254};
            }
            else
            {
                destination = {Book::Type::BOOK1, 95};
            }
        }
    };

    class Story649 : public Story::Base
    {
    public:
        Story649()
        {
            BookID = Book::Type::BOOK1;

            ID = 649;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "It won't be easy to talk these brutes down.";

            Choices.clear();

            Choices.push_back(Choice::Base("Talk down Tommul (Individual check: Charisma 5+, Successes: 2)", {Book::Type::BOOK1, 815}, {Book::Type::BOOK1, 291}, Choice::Type::LAST_INDIVIDUAL_CHECK, {Attribute::Type::CHARISMA}, 5, 2));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                if (party.Members[party.LastSelected].Type == Character::Type::BRASH)
                {
                    return {Book::Type::BOOK1, 697};
                }
                else
                {
                    return {Book::Type::NONE, -1};
                }
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story650 : public Story::Base
    {
    public:
        Story650()
        {
            BookID = Book::Type::BOOK1;

            ID = 650;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The goblin kitchen slaves are dead. You make a search through the room, but there is nothing here of appreciable value. Shrugging, you make your way on.\n\nNote: You gained the code A61.";

            Choices.clear();
            Choices.push_back(Choice::Base("Leave the kitchen through the north door", {Book::Type::BOOK1, 366}));
            Choices.push_back(Choice::Base("Leave the kitchen through the south door", {Book::Type::BOOK1, 736}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(61)});
        }
    };

    class Story651 : public Story::Base
    {
    public:
        Story651()
        {
            BookID = Book::Type::BOOK1;

            ID = 651;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Text = "With the ghouls defeated you begin a grizzly search through the remains in the burial chamber. You find 125 silver coins and a strangely intact pair of SOFT BOOTS (Stealth +1).\n\nYou find a bronze tablet, set into the wall, upon which a powerful spell has been inscribed:\n\nWisdom (Adventure)\n\nYour mind awakens with ancient knowledge. Cast this spell when you have failed a Lore check. You gain 3 automatic successes for this check only.\n\nRecharge: 50 silver.\n\nNote: You gained the code A48.";

            Bye = "With nowhere else to go, you return to the crossroads.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 125);

            Engine::GET_CODES(party, {Codes::A(48)});

            Take = {Equipment::SOFT_BOOTS1};

            Limit = 1;

            Spells = {Spells::WISDOM};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 46}; }
    };

    class Story652 : public Story::Base
    {
    public:
        Story652()
        {
            BookID = Book::Type::BOOK1;

            ID = 652;

            Location = Location::Type::CLIFFTOP;

            Text = "It costs 50 silver coins to repair one Health point on any ship you have docked in Cursus harbour. You can repair a ship up to its maximum starting health.";

            Choices.clear();

            Controls = Story::Controls::HARBOUR;
        }

        void Event(Party::Base &party)
        {
            Ships.clear();

            Cargo.clear();

            ShipRepairPrice = 50;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 703}; }
    };

    class Story653 : public Story::Base
    {
    public:
        Story653()
        {
            BookID = Book::Type::BOOK1;

            ID = 653;

            Text = "You have returned to the old treasury room. It is filled with empty boxes. If you missed something the first time you looted it, the Everchild's agents would have taken the rest by now!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::MAGIC_VAULT});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 620}; }
    };

    class Story654 : public Story::Base
    {
    public:
        Story654()
        {
            BookID = Book::Type::BOOK1;

            ID = 654;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You peer through the door, to be presented with the sight of two foul looking orcs playing at cards together in a small room. A pile of silver pieces are scattered across the table, no doubt for the wagers in the game. They are quite taken with their game, but it would still be rather difficult to sneak up on them in such a tiny room.";

            Choices.clear();
            Choices.push_back(Choice::Base("Attack the orcs", {Book::Type::BOOK1, 2}));
            Choices.push_back(Choice::Base("Try to sneak up on one of them", {Book::Type::BOOK1, 383}));
            Choices.push_back(Choice::Base("Leave them to their game and move on", {Book::Type::BOOK1, 350}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(56)}))
            {
                return {Book::Type::BOOK1, 561};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story655 : public Story::Base
    {
    public:
        Story655()
        {
            BookID = Book::Type::BOOK1;

            ID = 655;

            Text = "You slit the wizard's throat. He silently drops to the ground, obligingly dead. Not wanting to delay and end up captured, you slip away, back to the command tent.\n\nNote: You gained the code A95.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(95)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 96}; }
    };

    class Story656 : public Story::Base
    {
    public:
        Story656()
        {
            BookID = Book::Type::BOOK1;

            ID = 656;

            Location = Location::Type::LHASBREATH;

            IsCity = true;

            Text = "The slave market of Lhasbreath contains many varied peoples from across the valley, seized in raids by the barbarian warriors that rule the town. Most will be here only temporarily; the best slaves are sold on to the richer cities of the valley for farm work, or to perish in the terrible arena in Saltdad.\n\nNote: If you have less than four party members in your team you may recruit some more from the slave market.\n\nIt costs 200 silver coins to buy another party member, and they start with no equipment. A party member without a weapon has their Fighting score reduced by 1 point in combat.";

            Choices.clear();

            Controls = Story::Controls::RECRUIT;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story657 : public Story::Base
    {
    public:
        Story657()
        {
            BookID = Book::Type::BOOK1;

            ID = 657;

            Location = Location::Type::DESERT;

            Text = "You are in a blazing equatorial desert, walking along the cliffside that looks across the Azure Deep to the south. You are midway, you think, between the city of Cursus and the crumbling ruins of Mordain. The heat is truly dreadful, and despite the cooling winds blowing across the sea, there is not a drop to drink except what you have brought with you.";

            Choices.clear();
            Choices.push_back(Choice::Base("Survive the Desert (Team check: Survival 4+, Successes: 4)", {Book::Type::BOOK1, -657}, {Book::Type::BOOK1, -657}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (!outcome)
            {
                temp_string = "Each party member loses 1 Health from the dreadful effects of the sun.";

                Engine::GAIN_HEALTH(party, -1);

                if (Engine::ROLL(1) < 3)
                {
                    temp_string += " You were harassed during your journey.";

                    Choices[0].DestinationFailed = {Book::Type::BOOK1, 28};
                }
                else
                {
                    Choices[0].DestinationFailed = {Book::Type::BOOK1, -657};
                }

                Bye = temp_string.c_str();
            }
            else
            {
                if (Engine::ROLL(1) < 3)
                {
                    Bye = "You were harassed during your journey.";

                    Choices[0].Destination = {Book::Type::BOOK1, 28};
                }
                else
                {
                    Bye = NULL;

                    Choices[0].Destination = {Book::Type::BOOK1, -657};
                }
            }
        }
    };

    class Event657 : public Story::Base
    {
    public:
        Event657()
        {
            BookID = Book::Type::BOOK1;

            ID = -657;

            DisplayID = 657;

            Location = Location::Type::DESERT;

            Text = "Where will you go now?";

            Choices.clear();
            Choices.push_back(Choice::Base("North, towards the Temple of the Unbroken", {Book::Type::BOOK1, 535}));
            Choices.push_back(Choice::Base("East, towards the city of Cursus", {Book::Type::BOOK1, 340}));
            Choices.push_back(Choice::Base("West, towards the Mordain Ruins", {Book::Type::BOOK1, 515}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story658 : public Story::Base
    {
    public:
        Story658()
        {
            BookID = Book::Type::BOOK1;

            ID = 658;

            Text = "\"Whipping is so dull!\" moans Lothor. \"Except when done en-mass!\"\n\nAt a nod from the king you are grasped by the guards and stripped. Soon King Lothor and his favourite lords are striping your backs with the whip, to the jeers of his court.\n\nEventually evening comes and Lothor tires of his sport. You are cast out of his court naked, to peels of laughter from his servants.\n\nNote: Each party member must lose 3 points of Health. Any characters wearing armour discards it, but the rest of your equipment is thrown after you. You gained the code A34.";

            Bye = "Vowing revenge you slink away to the marketplace to buy some new clothes.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, -3);

            Engine::LOSE_ALL(party, Equipment::Class::ARMOUR);

            Engine::GET_CODES(party, {Codes::A(34)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 759}; }
    };

    class Story659 : public Story::Base
    {
    public:
        Story659()
        {
            BookID = Book::Type::BOOK1;

            ID = 659;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You quietly prowl the corridors until you come to the open door of Unbraaki's study. Except for the occasional monkey, proudly strutting down the corridor in a tall hat, there is no one about. You peek inside the room. It is a treasure house of knowledge and spells, quills and ink. You may take some CALLIGRAPHY INK if you wish. You find books that contain all of the common spells of the world. Additionally, you find a very special spell indeed:\n\nClinging Dread (Mass Combat)\n\nDoubt and uncertainty fill the hearts of the enemy soldiers. Reduce the Morale score of an enemy unit by 1 point.\n\nRecharge: 50 silver.\n\nPleased with your findings you decide to quickly move on.\n\nNote: You can only cast this spell during Mass Combat (when entire armies clash). It has no effect on personal combat. You gained the code A91.";

            Choices.clear();
            Choices.push_back(Choice::Base("To the library", {Book::Type::BOOK1, 459}));
            Choices.push_back(Choice::Base("To the basement", {Book::Type::BOOK1, 67}));
            Choices.push_back(Choice::Base("Quietly leave the palace", {Book::Type::BOOK1, 265}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(91)}))
            {
                return {Book::Type::BOOK1, 621};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(91)});

            Take = {Equipment::CALLIGRAPHY_INK};

            Limit = 1;

            Spells = {Spells::ANIMAL_SPEECH, Spells::ARMOUR_OF_HEAVEN, Spells::ICE_BOLT, Spells::POISON_STREAM, Spells::UNFAILING_STRIKE, Spells::WOLF_SPIRIT, Spells::MAGIC_CABINET, Spells::CLINGING_DREAD};
        }
    };

    class Story660 : public Story::Base
    {
    public:
        Story660()
        {
            BookID = Book::Type::BOOK1;

            ID = 660;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "Since the lid is so heavy two of your party members attempt to shift it. Almost as soon as you touch it the coffin lid slides aside. Inside, it's skin rotten with putrefaction, is a zombie, so worm-eaten it is impossible to tell its gender. It hisses as it rises, a hideous grey tongue extending grotesquely from its mouth. All around you the inanimate skeletons suddenly snap to attention, drawing the poles they were hung upon to use as quarterstaffs. You are surrounded and must fight.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Zombie", 7, 4, 2, 20, 0),
                Monster::Base("Skeletons", 6, 5, 4, 12, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 341}; }
    };

    class Story661 : public Story::Base
    {
    public:
        Story661()
        {
            BookID = Book::Type::BOOK1;

            ID = 661;

            Text = "Almost casually you empty in the VIAL OF POISON as if it were nothing more than another herb or spice, before drifting away into the shadows. The cooks are blissfully unaware of your modifications, and soon begin to dish out the stew into hundreds of wooden bowls. There is nothing more you can do here, so you quietly slip away into the city.\n\nThe next morning the Bronzeguard compound is closed, and only regular guards appear to be patrolling the streets. The lack of enormous, armoured warriors is immediately obvious, and rumours and petty crime begin to sweep the city. There can be no doubt that the Bronzeguard, if not completely destroyed, have been dealt a dreadful blow.\n\nNote: You gained the code A8.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Stealth", {Book::Type::BOOK1, 75}, Choice::Type::ROLL_FOR_ATTRIBUTE_INCREASE, {Attribute::Type::STEALTH}, 1, 2, 0));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::VIAL_OF_POISON});

            Engine::GET_CODES(party, {Codes::A(8)});
        }
    };

    class Story662 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story662()
        {
            BookID = Book::Type::BOOK1;

            ID = 662;

            Location = Location::Type::MORDAIN;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You are in the magnificent ruins of Mordian harbour. Four hundred years of tidal forces have not yet eroded its stone dockyard, with the stone faces of Mordainian kings, carved from the cliff face, peering out to sea. Although the grand stairwell to the top of the cliff has long since collapsed, a great tunnel, carved to resemble the mouth of some gluttonous god, leads into the cliffside.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(68)}))
            {
                PreText += "\n\nBobbing shabbily in dock is large wooden ship, made of crudely hammered planks with sails made of animal skins. The decorations and savage glyphs on the side can mean only one thing. This is an orcish vessel. What has possessed those vile creatures to travel all the way to the Valley of Bones? The ship is abandoned but will require a crew. If you have a ship docked in Mordain harbour you may transfer your crew to the orc hulk. It has a large cargo bay, but little else to recommend its use as a sailing ship.";

                if (!Engine::VERIFY_CODES(party, {Codes::A(69)}))
                {
                    if (Engine::HAS_SHIP(party, Location::Type::MORDAIN))
                    {
                        Choices.push_back(Choice::Base("Transfer your crew to the orc hulk", {Book::Type::BOOK1, 894}));
                        Choices.push_back(Choice::Base("Board your ship", {Book::Type::BOOK1, 851}));
                    }

                    Choices.push_back(Choice::Base("Enter the wide tunnel", {Book::Type::BOOK1, 593}));
                }
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(68)}))
            {
                return {Book::Type::BOOK1, 13};
            }
            else
            {
                return {Book::Type::BOOK1, 738};
            }
        }
    };

    class Story663 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story663()
        {
            BookID = Book::Type::BOOK1;

            ID = 663;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "You chat with your old partner in crime about your many adventures.";

            if (!Engine::VERIFY_CODES(party, {Codes::A(11)}))
            {
                PreText += " After spending a splendid evening together, you retire back to the city.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(11)}))
            {
                return {Book::Type::BOOK1, 820};
            }
            else
            {
                return {Book::Type::BOOK1, 75};
            }
        }
    };

    class Story664 : public Story::Base
    {
    public:
        Story664()
        {
            BookID = Book::Type::BOOK1;

            ID = 664;

            Text = "You call out to the orc in the friendliest voice you can summon. The orc does not so much as blink, utterly transfixed by the book.";

            Choices.clear();
            Choices.push_back(Choice::Base("Throw a book at the orc", {Book::Type::BOOK1, 805}));
            Choices.push_back(Choice::Base("Sneak up on the orc", {Book::Type::BOOK1, 682}));
            Choices.push_back(Choice::Base("Close the door and go somewhere else", {Book::Type::BOOK1, 821}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story665 : public Story::Base
    {
    public:
        Story665()
        {
            BookID = Book::Type::BOOK1;

            ID = 665;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The foreign quarter is the place for merchants and travellers who do not follow the meditative teachings of the God King. It is noisier than the rest of Chalice, and the inn itself buzzes with activity from the traders and slaves who are tasked with shipping rice to the other starving cities of the valley. The inn you have found is typical of one in the foreign quarter, slightly shabby, with a mix of all races from dour Clifftop folk to the bone-clad barbarians of Lhasbreath.\n\nA chatty merchant advises you to avoid the Salt Plains, even if you are travelling on foot. \"It is the driest place in the valley and can suck the moisture from your gums quicker than the noonday sun,\" she says. \"It's not even a shortcut... the Westroad is a faster way to Clifftop. All you'll find in the Salt Plains are the bodies of the dead.\"\n\nNote: For every 5 silver coins you spend, each party member can recover 1 Health point. Spell casters can also spend silver here to recharge their spells, purchasing components in the nearby marketplace and going into meditation in the privacy of their rooms.";

            RestPrice = 5;
            CanRecharge = true;

            Choices.clear();

            Controls = Story::Controls::INN;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 450}; }
    };

    class Story666 : public Story::Base
    {
    public:
        std::string PreText = "";

        Engine::Destination destination = {};

        Story666()
        {
            BookID = Book::Type::BOOK1;

            ID = 666;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters.clear();

            PreText = "A pair of Lhasbreath barbarians come riding over the sands on dusty white horses.";

            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(16)}))
            {
                PreText += "  You are immediately accosted.";

                if (party.Money > 0)
                {
                    PreText += "You can hand over half your silver coins to appease them. Otherwise the barbarians will try to take your coins the old-fashioned way; through brute force!";

                    if (party.Money > 1)
                    {
                        auto coins = party.Money / 2;

                        temp_string = "Hand over " + std::to_string(coins) + " silver coin";

                        if (coins > 1)
                        {
                            temp_string += "s";
                        }

                        Choices.push_back(Choice::Base(temp_string.c_str(), {Book::Type::BOOK1, 219}, Choice::Type::GAIN_MONEY, -coins));
                    }
                    else
                    {
                        Choices.push_back(Choice::Base("Hand over 1 silver coin", {Book::Type::BOOK1, 219}, Choice::Type::GAIN_MONEY, -1));
                    }

                    Choices.push_back(Choice::Base("Refuse to hand over your silver", {Book::Type::BOOK1, -666}));
                }
                else
                {
                    Monsters = {
                        Monster::Base("Barbarian", 4, 4, 3, 9, 0),
                        Monster::Base("Barbarian", 3, 4, 3, 8, 0)};
                }
            }
            else
            {
                destination = {Book::Type::BOOK1, 130};
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Engine::GAIN_MONEY(party, 20);

                destination = {Book::Type::BOOK1, 219};
            }
        }
    };

    class Event666 : public Story::Base
    {
    public:
        Event666()
        {
            BookID = Book::Type::BOOK1;

            ID = -666;

            Text = "The barbarians will have to take it by brute force!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Barbarian", 4, 4, 3, 9, 0),
                Monster::Base("Barbarian", 3, 4, 3, 8, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 219}; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                Engine::GAIN_MONEY(party, 20);
            }
        }
    };

    class Story667 : public Story::Base
    {
    public:
        Story667()
        {
            BookID = Book::Type::BOOK1;

            ID = 667;

            Text = "There is no point is risking everyone on this dangerous escapade.";

            Choices.clear();
            Choices.push_back(Choice::Base("Rescue the Sailor (Individual check: Survival 5+, Successes: 2)", {Book::Type::BOOK1, 848}, {Book::Type::BOOK1, 612}, {Attribute::Type::SURVIVAL}, 5, 2));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story668 : public Story::Base
    {
    public:
        Story668()
        {
            BookID = Book::Type::BOOK1;

            ID = 668;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Image = "images/book1/soldiers_drag_family.png";

            Text = "As you are wandering the town, you hear screams from a nearby building. Running to investigate, you can see a band of the Iron King's thugs, not Bronzeguard, but regular soldiery, dragging a family from their home. The malicious sergeant informs the elderly father that his failure to pay his taxes means the entire family is to be sold into slavery. They struggle in their bonds and are beaten and kicked for their impertinence.\n\nNote: You gained the code A15.";

            Choices.clear();
            Choices.push_back(Choice::Base("Walk away; the laws of this city are not for you to interpret", {Book::Type::BOOK1, 75}));
            Choices.push_back(Choice::Base("Offer to pay the sergeant to release the family", {Book::Type::BOOK1, 808}));
            Choices.push_back(Choice::Base("Damn the Iron King! Attack the soldiers!", {Book::Type::BOOK1, 554}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(15)}))
            {
                return {Book::Type::BOOK1, 852};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(15)});
        }
    };

    class Story669 : public Story::Base
    {
    public:
        Story669()
        {
            BookID = Book::Type::BOOK1;

            ID = 669;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "With the orcs dead you move to loot the room and examine their wargear. The leader has a mighty IRON GREATAXE* (Fighting +2) and is wearing a fine suit of BONE ARMOUR (Armour +2). Three IRON SWORDS (Fighting +1) can be looted from the common warriors. Searching the room you find an iron key and a WARM CLOAK (Survival +1). Oddly, there are only 10 silver coins, not much for such a mighty leader. Where will you go now?\n\nNote: You gained the code 64.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go through the west door", {Book::Type::BOOK1, 736}));
            Choices.push_back(Choice::Base("Go through the south door", {Book::Type::BOOK1, 566}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(64)});

            Engine::GAIN_MONEY(party, 10);

            Take = {Equipment::IRON_GREATAXE2, Equipment::BONE_ARMOUR2, Equipment::IRON_SWORD1, Equipment::IRON_SWORD1, Equipment::IRON_SWORD1, Equipment::IRON_KEY, Equipment::WARM_CLOAK1};

            Limit = 7;
        }
    };

    class Story670 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story670()
        {
            BookID = Book::Type::BOOK1;

            ID = 670;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            auto loss = Engine::ROLL(1);

            Engine::GAIN_HEALTH(party, -loss);

            PreText = "You can only watch in horror as the Iron King's forces break the power of the Everchild's armies. You plead with the queen to retreat with you, but she refuses to yield even in the face of defeat. You stagger away, bloodied from the field. Each member of your party loses " + std::to_string(loss) + " health points.";

            if (Engine::COUNT(party) > 0)
            {
                PreText += "\n\nYou flee, turning from a distance to see the Everchild's command tent ransacked and burnt. What became of the Everchild herself you cannot say, but she is never seen in the Valley of Bones again.\n\nYou stagger away into the sands, dreams of freedom evaporating from your mind like water in the desert. The rest of the army likewise scatters to the four winds. Your men think you are dead, and your soldiers have dispersed.\n\nNote: You gained the code A4.";
            }

            for (auto i = 0; i < party.Army.size(); i++)
            {
                if (party.Army[i].Garrison == Location::Type::LUUTANESH)
                {
                    party.Army[i].Morale = 0;
                }
            }

            Engine::REMOVE_ROUTED(party);

            Engine::LOSE_CODES(party, {Codes::A(6), Codes::A(7)});

            Engine::GET_CODES(party, {Codes::A(4)});

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 858}; }
    };

    class Story671 : public Story::Base
    {
    public:
        Story671()
        {
            BookID = Book::Type::BOOK1;

            ID = 671;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "The monkeys mob you, their hands reaching into your pockets and packs, attempting to pull away items from you. \n\nThey eventually depart with their ill-gotten gains. Cursing the thieving monkeys, you make your way onwards.\n\nNote: Each character loses one item of equipment (not armour -- the monkeys aren't that good at stealing things!). In addition, you lose up to 170 silver coins. If you do not have that much, you lose all the silver coins you have.";
            Choices.clear();
            Choices.push_back(Choice::Base("Lose one item from each party member", {Book::Type::BOOK1, 740}, Choice::Type::EVERYONE_LOSES_EQUIPMENT, {Equipment::Class::ARMOUR}, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, -170);
        }
    };

    class Story672 : public Story::Base
    {
    public:
        Story672()
        {
            BookID = Book::Type::BOOK1;

            ID = 672;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "These people are going to get themselves killed if they oppose the fanatical kensai. You beg the mourners to let the matter drop before there is violence.";

            Choices.clear();
            Choices.push_back(Choice::Base("Persuade the crowd (Team check: Charisma 4+, Successes: 6)", {Book::Type::BOOK1, 512}, {Book::Type::BOOK1, 843}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 4, 6));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story673 : public Story::Base
    {
    public:
        Story673()
        {
            BookID = Book::Type::BOOK1;

            ID = 673;

            Text = "As soon as you touch the handle of the front door a great bolt of energy engulfs you. The lightning bolt has scarred your faces. Staggering back from the door you retire, hoping that the wall-climbing team may have better luck.\n\nNote: All members of the door-opening team lose 3 Health points and 1 point of Charisma.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, Team::Type::MAGICAL_DOOR, -3);

            for (auto i = 0; i < party.Members.size(); i++)
            {
                if (Engine::IS_ACTIVE(party, i) && Engine::IN_TEAM(party, party.Members[i].Type, Team::Type::MAGICAL_DOOR))
                {
                    Engine::GAIN_SCORE(party.Members[i], Attribute::Type::CHARISMA, -1);
                }
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 728}; }
    };

    class Story674 : public Story::Base
    {
    public:
        Story674()
        {
            BookID = Book::Type::BOOK1;

            ID = 674;

            Text = "You rise early the next morning to the sounds of cawing birds. You make good progress during the day and arrive at the checkpoint by early evening. The checkpoint is little more than a collection of empty huts built by the previous expedition, but it keeps the rain off your heads and the worst of the insects away. The way onwards is treacherous, so you leave the mules tethered here until your return.\n\n\"In the morning we'll head south,\" says Emlyn, pouring over her map. \"We built a raft in the last expedition to do just that, but my father came down with jungle fever before we could use it. It should still be moored by the riverbank. Alternatively, we could hack our way through the jungle, but there are no trails and the going will be hard. What do you suggest?\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Take the raft", {Book::Type::BOOK1, 105}));
            Choices.push_back(Choice::Base("Go overland", {Book::Type::BOOK1, 501}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story675 : public Story::Base
    {
    public:
        Story675()
        {
            BookID = Book::Type::BOOK1;

            ID = 675;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "Honnu nods as you hand over the SILVER IDOL. He looks at it briefly, and then tosses it to a nearby beggar in meditation. The astonished old beggar thanks the monk and dashes off to the marketplace to turn his donation into coins.\n\n\"Well, that's the tedious part of your tests complete,\" shrugs Honnu. The whole matter has been rather an anti-climax, but you seem to have passed.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::SILVER_IDOL});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 530}; }
    };

    class Story676 : public Story::Base
    {
    public:
        Story676()
        {
            BookID = Book::Type::BOOK1;

            ID = 676;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "You stroll through a featureless terrain of grey. The colour continues to fade from your companions.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 1 Health", {Book::Type::BOOK1, -676}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event676 : public Story::Base
    {
    public:
        Event676()
        {
            BookID = Book::Type::BOOK1;

            ID = -676;

            DisplayID = 676;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "Where will you go?";

            Choices.clear();
            Choices.push_back(Choice::Base("North", {Book::Type::BOOK1, 589}));
            Choices.push_back(Choice::Base("West", {Book::Type::BOOK1, 692}));
            Choices.push_back(Choice::Base("South", {Book::Type::BOOK1, 324}));
            Choices.push_back(Choice::Base("East", {Book::Type::BOOK1, 273}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story677 : public Story::Base
    {
    public:
        Story677()
        {
            BookID = Book::Type::BOOK1;

            ID = 677;

            Text = "You are quick and strong, and the bear cannot get a grasp on you. You even manage to pinion its head for a few moments before it shakes you away. The barbarians above you roar with delight as you demonstrate your mastery over the beast. Eventually the bear tires of fighting you. It grumbles loudly and lollops into a corner away from you, rolling onto its back. The barbarians cheer and throw you down a rope to climb up.\n\nThe king slaps you on the back and congratulates your skill. \"You've fought hard to get my attention,\" he smiles, several teeth missing from his wide grin. \"What brings you to my city, foreigner?\"\n\nNote: You gained the code A82.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(82)});

            Choices.clear();

            if (Engine::VERIFY_CODES_ANY(party, {Codes::A(1), Codes::A(7)}))
            {
                Choices.push_back(Choice::Base("Speak to the king about political matters", {Book::Type::BOOK1, 826}));
            }

            Choices.push_back(Choice::Base("Ask for a reward for your feat of strength", {Book::Type::BOOK1, 844}));
        }
    };

    class Story678 : public Story::Base
    {
    public:
        Story678()
        {
            BookID = Book::Type::BOOK1;

            ID = 678;

            Text = "You wade into the still, cold water, holding your torch aloft as you make your way down the slippery passageway. Eventually the water level gets too high. To proceed, you will have to dive into the water and swim down -- but who knows where the pitch-black tunnel will lead?";

            Choices.clear();
            Choices.push_back(Choice::Base("Swim down the tunnel (Individual check: Survival 4+, Successes: 2)", {Book::Type::BOOK1, 503}, {Book::Type::BOOK1, 825}, Choice::Type::LAST_INDIVIDUAL_CHECK, {Attribute::Type::SURVIVAL}, 4, 2));
            Choices.push_back(Choice::Base("You don't want to risk it: wade back to the Everchild and take the other tunnel", {Book::Type::BOOK1, 523}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story679 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story679()
        {
            BookID = Book::Type::BOOK1;

            ID = 679;

            Text = "You watch with mounting concern as dozens of small boats round the corner of Viaan Island and make their way directly towards you. They are war canoes, filled with tribal Bando warriors. Your crew man the ballista's (catapults are useless here against these small boats) and prepare to repel boarders.\n\nNote: Note: Because you cannot use all your ship's weapons you must lower the Fighting value of your ship by 1 point for this battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::Type::CANNOT_USE_SHIPWEAPONS});

            EnemyFleet = {Ship::Base("WAR CANOES", Ship::Type::WAR_CANOES, Location::Type::NONE, 3, 10, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                destination = {Book::Type::BOOK1, 774};
            }
            else
            {
                destination = {Book::Type::BOOK1, 52};
            }
        }
    };

    class Story680 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story680()
        {
            BookID = Book::Type::BOOK1;

            ID = 680;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "The library of Chalice has a grand marble f loor, decorated in unusual arcane patterns. Around the walls, so high they are accessible only by ladders, are numerous scrolls and even a few books. Whilst this library cannot compete with the shelves in Animus Mast, it is still an impressive store of knowledge.";

            Choices.clear();

            if (Engine::SPELLCASTERS(party) > 0)
            {
                PreText += "\n\nYou notice that the marble floor is a gigantic teleportation circle. If you had the means you could use this circle to transport your entire party to a different land.";

                if (Engine::HAS_SPELL(party, {Spells::Type::TELEPORT_CIRCLE}))
                {
                    Choices.push_back(Choice::Base("Cast Teleportation Circle spell", {Book::Type::BOOK1, 235}));
                }
            }

            PreText += "\n\nThere are many subjects you could research here.";

            Choices.push_back(Choice::Base("The Mordain Ruins", {Book::Type::BOOK1, 577}));
            Choices.push_back(Choice::Base("The Reign of the Everchild", {Book::Type::BOOK1, 452}));
            Choices.push_back(Choice::Base("Animus Mast", {Book::Type::BOOK1, 705}));
            Choices.push_back(Choice::Base("Longport Bay", {Book::Type::BOOK1, 81}));
            Choices.push_back(Choice::Base("Politics of the Splintered Isles", {Book::Type::BOOK1, 794}));
            Choices.push_back(Choice::Base("Saint Elias", {Book::Type::BOOK1, 262}));
            Choices.push_back(Choice::Base("Leave the library", {Book::Type::BOOK1, 560}));

            Text = PreText.c_str();
        }
    };

    class Story681 : public Story::Base
    {
    public:
        Story681()
        {
            BookID = Book::Type::BOOK1;

            ID = 681;

            Location = Location::Type::SALT_MINES;

            IsCity = true;

            Text = "You have entered the salt mines, a place of stygian hell where slaves work tirelessly under the lash to extract glittering salt rock from the chamber walls. The air itself is dry and salty, and seems to rob your mouth of moisture with each breath. Your way is lit miserly by a lamp you have borrowed from the overseer.\n\n\"The troglodyte infestation is on the twelfth, thirteenth and fourteenth levels,\" he advises. \"Avoid the lowest level, it's uninhabitable.\"\n\n\"Why shouldn't I search the lowest level?\" you ask.\n\n\"It sounds like a breeding ground for troglodytes.\"\n\nThe overseer grimaces. \"Dragon trouble,\" he says.\n\nWhich level of the mines will you explore?";

            Choices.clear();
            Choices.push_back(Choice::Base("The twelfth level", {Book::Type::BOOK1, 739}));
            Choices.push_back(Choice::Base("The thirteenth level", {Book::Type::BOOK1, 388}));
            Choices.push_back(Choice::Base("The fourteenth level", {Book::Type::BOOK1, 597}));
            Choices.push_back(Choice::Base("The lowest level", {Book::Type::BOOK1, 222}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story682 : public Story::Base
    {
    public:
        Story682()
        {
            BookID = Book::Type::BOOK1;

            ID = 682;

            Text = "You carefully sneak up on the orc, being as quiet as possible. You need not have tried so hard, the orc is entirely engrossed in his reading. You stand directly in front of him, and even prod him to get his attention. He does not move a muscle.";

            Choices.clear();
            Choices.push_back(Choice::Base("Kill the orc whilst he is reading", {Book::Type::BOOK1, 38}));
            Choices.push_back(Choice::Base("Snatch the black book from the orc's hands", {Book::Type::BOOK1, 160}));
            Choices.push_back(Choice::Base("Close the door and go somewhere else", {Book::Type::BOOK1, 821}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story683 : public Story::Base
    {
    public:
        Story683()
        {
            BookID = Book::Type::BOOK1;

            ID = 683;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "You attempt to clear your mind of all distractions and exist in a state of blessed emptiness. You remember your temple teachings when you were but a boy. \"The treasures of the mind outweigh any fortune of silver,\" you murmur.\n\nYou have relaxed completely. Your meditations have cleared your mind, but not given you specific inspiration as to where to go. Deciding to leave the matter to fate, you stroll towards the hill in front of you and enter the first cave you come across.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEALTH(party, Character::Type::AKIHIRO_OF_CHALICE, 1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 24}; }
    };

    class Story684 : public Story::Base
    {
    public:
        Story684()
        {
            BookID = Book::Type::BOOK1;

            ID = 684;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "The Everchild asked you to poison the Bronzeguard in their compound.";

            Choices.clear();
            Choices.push_back(Choice::Base("Do this now", {Book::Type::BOOK1, 847}));
            Choices.push_back(Choice::Base("You'd better be on your way", {Book::Type::BOOK1, 75}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story685 : public Story::Base
    {
    public:
        Story685()
        {
            BookID = Book::Type::BOOK1;

            ID = 685;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You have returned to the room with the magic circle. It will require quicksilver in order to operate.";

            Choices.clear();
            Choices.push_back(Choice::Base("Pour some QUICKSILVER into the circle", {Book::Type::BOOK1, 26}, {Equipment::QUICKSILVER}));
            Choices.push_back(Choice::Base("Return to the crossroads", {Book::Type::BOOK1, 566}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story686 : public Story::Base
    {
    public:
        Story686()
        {
            BookID = Book::Type::BOOK1;

            ID = 686;

            Location = Location::Type::UNDERGROUND_TUNNELS;

            Text = "The tunnel opens into a humble tomb, with a single stone sarcophagus in it. Above the sarcophagus is a silver skull, human sized, mounted on a pedestal. You cannot help but notice that the sarcophagus is open. You have an uneasy sense about the place, and your survival instincts are telling you to go back the way you came.";

            Choices.clear();
            Choices.push_back(Choice::Base("Enter the chamber", {Book::Type::BOOK1, 778}));
            Choices.push_back(Choice::Base("Go back to the crossroads", {Book::Type::BOOK1, 46}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(47)}))
            {
                return {Book::Type::BOOK1, 373};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story687 : public Story::Base
    {
    public:
        Story687()
        {
            BookID = Book::Type::BOOK1;

            ID = 687;

            Text = "The sigils fade as you complete your counterspell... but you have been tricked. The wards around the tent are still active, and a magical flash blinds you. You stagger back, light continuing to pour from the tent like a beacon. Soon the army of Cursus have captured the assassination team. What happens to them now is up to you. If you capture the city of Cursus you can free them from prison. If your army is defeated, the party members will be executed. Either way, the captured party members can take no further part in the battle until rescued.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            for (auto i = 0; i < party.Members.size(); i++)
            {
                if (Engine::SCORE(party.Members[i], Attribute::Type::HEALTH) > 0 && party.Members[i].Team == Team::Type::ASSASSINATION_DESCANTOS)
                {
                    Engine::GAIN_STATUS(party.Members[i], Character::Status::CAPTURED);
                }
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 96}; }
    };

    class Story688 : public Story::Base
    {
    public:
        Story688()
        {
            BookID = Book::Type::BOOK1;

            ID = 688;

            Location = Location::Type::GRANITE_HILLS;

            Text = "Perhaps the miners and sorcerers of old left something valuable in their wake? You begin to explore the hillsides for something of interest.";

            Choices.clear();
            Choices.push_back(Choice::Base("Explore the Granite Hills (Team check: Survival 4+, Successes: 5)", {Book::Type::BOOK1, 751}, {Book::Type::BOOK1, 426}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 5));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            Bye = NULL;

            if (!outcome)
            {
                Bye = "Each Party Member loses 2 Health.";

                Engine::GAIN_HEALTH(party, -2);
            }
        }
    };

    class Story689 : public Story::Base
    {
    public:
        Story689()
        {
            BookID = Book::Type::BOOK1;

            ID = 689;

            Location = Location::Type::WITHERED_STEPPES;

            Text = "There are innumerable cracks in the earth, small gullies in a broken land baked by the relentless sun. You wander a number of places, unsure of what you are looking for.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Bye = NULL;

            Choices.clear();

            if (Engine::HAS_SPELL(party, {Spells::Type::SHADOW_DOOR}))
            {
                Choices.push_back(Choice::Base("Cast Shadow Door", {Book::Type::BOOK1, 720}));
                Choices.push_back(Choice::Base("Give up", {Book::Type::BOOK1, 115}));
            }
            else
            {
                Bye = "You wander the area for days but discover nothing of interest.";
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 115}; }
    };

    class Story690 : public Story::Base
    {
    public:
        Story690()
        {
            BookID = Book::Type::BOOK1;

            ID = 690;

            Location = Location::Type::CAPE_PORTA;

            Text = "A ballista shot holes the pinnace below the waterline, and with a sudden jerk it begins its decent to the bottom of the sea. The pirate crew jump overboard, pleading for rescue. If you have space in your cargo hold you may take the pirates as one unit of Slaves, if you wish. Alternatively, you can let the knaves sink to the bottom of the ocean.";

            Choices.clear();
            Choices.push_back(Choice::Base("Take pirates as slaves", {Book::Type::BOOK1, -690}, Choice::Type::GAIN_CARGO, {Cargo::Type::SLAVES}));
            Choices.push_back(Choice::Base("Let the pirates sink with their ship", {Book::Type::BOOK1, -690}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event690 : public Story::Base
    {
    public:
        Event690()
        {
            BookID = Book::Type::BOOK1;

            ID = -690;

            DisplayID = 690;

            Location = Location::Type::CAPE_PORTA;

            Text = "You have decided it is time to sail on.";

            Choices.clear();
            Choices.push_back(Choice::Base("Sail north", {Book::Type::BOOK1, 82}));
            Choices.push_back(Choice::Base("Sail east", {Book::Type::BOOK1, 814}));
            Choices.push_back(Choice::Base("(Savage Lands) Sail west towards the Savage Lands", {Book::Type::BOOK5, 75}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story691 : public Story::Base
    {
    public:
        Story691()
        {
            BookID = Book::Type::BOOK1;

            ID = 691;

            Location = Location::Type::BLACKWALL;

            Image = "images/book1/blackwall.png";

            Text = "Emerging from the swimming haze ahead comes one of the most curious constructions in all the world. A long, unbroken wall of reflective black stone stretches for miles in an east-west direction. Beyond the wall lies the hard-stone Granite Hills -- and yet it is a trivial matter to simply walk around the side of the wall to reach them. What the wall guards, or why it was built, is a mystery, but many who have walked along it have not returned.";

            Choices.clear();
            Choices.push_back(Choice::Base("Walk along the length of the Blackwall", {Book::Type::BOOK1, 315}));
            Choices.push_back(Choice::Base("Go northeast, into the desert", {Book::Type::BOOK1, 858}));
            Choices.push_back(Choice::Base("Go around the wall to the Granite Hills", {Book::Type::BOOK1, 275}));
            Choices.push_back(Choice::Base("Go west to the Tumblestones", {Book::Type::BOOK1, 137}));
            Choices.push_back(Choice::Base("Go northwest, and join the Westroad", {Book::Type::BOOK1, 511}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story692 : public Story::Base
    {
    public:
        Story692()
        {
            BookID = Book::Type::BOOK1;

            ID = 692;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "You approach what looks like a building, but as you get closer you realise it is just a web of shadows cast from a lifeless tree. Your companions appear almost transparent.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to lose 1 Health", {Book::Type::BOOK1, -692}, Choice::Type::GAIN_HEALTH, -1));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event692 : public Story::Base
    {
    public:
        Event692()
        {
            BookID = Book::Type::BOOK1;

            ID = -692;

            DisplayID = 73;

            Location = Location::Type::BEYOND_SHADED_GATE;

            Text = "Where will you go?";

            Choices.clear();
            Choices.push_back(Choice::Base("North", {Book::Type::BOOK1, 273}));
            Choices.push_back(Choice::Base("West", {Book::Type::BOOK1, 886}));
            Choices.push_back(Choice::Base("South", {Book::Type::BOOK1, 537}));
            Choices.push_back(Choice::Base("East", {Book::Type::BOOK1, 589}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story693 : public Story::Base
    {
    public:
        Story693()
        {
            BookID = Book::Type::BOOK1;

            ID = 693;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "\"Morning,\" growls the foul ogre, to your greeting. \"What are you doing down here, then?\" \"Just looking around,\" you say airily. \"How about you?\"\n\n\"Eating,\" shrugs the ogre between mouthfuls. \"I'm supposed to be on guard, but I can't be bothered to do that.\"\n\n\"A fine work ethic,\" you nod. \"Do the orcs employ you?\"\n\n\"Yeah, but the pay is rubbish,\" he grumbles. \"So today's your lucky day. Don't let the door hit your bum on your way out.\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Ask what the orcs are doing here", {Book::Type::BOOK1, 776}));
            Choices.push_back(Choice::Base("Try to convince the ogre to change sides", {Book::Type::BOOK1, 576}));
            Choices.push_back(Choice::Base("Kill the ogre", {Book::Type::BOOK1, 117}));
            Choices.push_back(Choice::Base("Leave the ogre in peace", {Book::Type::BOOK1, 310}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story694 : public Story::Base
    {
    public:
        Story694()
        {
            BookID = Book::Type::BOOK1;

            ID = 694;

            Location = Location::Type::NORTH_ROAD;

            Text = "Nomad raiders come howling out of the Withered Steppes, brandishing their bright steel scimitars and thundering towards you on their horses. Around you the merchant caravans halt, their guards drawing bows and swords to make a desperate defence.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::A(37)}))
            {
                Choices.push_back(Choice::Base("Look to your own defences", {Book::Type::BOOK1, 901}));
                Choices.push_back(Choice::Base("Attempt to organise the defence of the caravans", {Book::Type::BOOK1, 39}));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 764}; }
    };

    class Story695 : public Story::Base
    {
    public:
        Story695()
        {
            BookID = Book::Type::BOOK1;

            ID = 695;

            Text = "With the curse broken, the black book lies on the floor, its back pages open. You notice that a spell has been inked there. It is the Unfailing Strike spell. Any of your spellcasters can add this spell to their spellbooks if they wish, but remember that you cannot have more than six spells in a single spellbook at any given time.:\n\nUnfailing Strike (Combat)\n\nA pillar of energy sizzles into a single foe. Choose an opponent to lose 3 Health.\n\nRecharge: 50 silver";

            Bye = "You return to the room outside.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Spells = {Spells::UNFAILING_STRIKE};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 821}; }
    };

    class Story696 : public Story::Base
    {
    public:
        Story696()
        {
            BookID = Book::Type::BOOK1;

            ID = 696;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "You stroll along the temple districts, expecting to find only peace and tranquillity. To your surprise you hear sounds of angry shouting. Moving to investigate you can see a crowd of mourners bearing a woven casket. They are arguing with a group of kensai, the sword-saint warriors of the God King, and protectors of the peace in Chalice.\n\nFrom what you can gather the mourners want to process the body past the temple towers, as the dead man was a great architect who maintained and repaired many of Chalice's mightiest structures. However, the kensai are firmly against this, claiming it is a violation of holy law to have more than one temple perform a funeral celebration. As far as they are concerned the procession violates this law, as the man has already received his funeral rites from the monks of the lower temples. What do you do?\n\nNote: You gained the code A55.";

            Choices.clear();
            Choices.push_back(Choice::Base("Intercede on the mourners behalf", {Book::Type::BOOK1, 730}));
            Choices.push_back(Choice::Base("Intercede on the kensai's behalf", {Book::Type::BOOK1, 672}));
            Choices.push_back(Choice::Base("Decline to get involved in such a delicate matter", {Book::Type::BOOK1, 450}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(55)}))
            {
                return {Book::Type::BOOK1, 225};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(55)});
        }
    };

    class Story697 : public Story::Base
    {
    public:
        Story697()
        {
            BookID = Book::Type::BOOK1;

            ID = 697;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You shake your head and agree with the slaves that your companions are uncultured brutes who do not understand the meaning of respect. You claim to be their well-beaten servant, bitter about your long service to them.\n\n\"The worst part about my companions is that they are all fully trained assassins from the House of Silence in Drakehallow,\" you say sadly. \"They have bitter and vengeful spirits. Indeed, those that slight them die in the most dreadful ways.\"\n\nTommul goes pale, and blathers that his threat to beat you was merely a poor jest. It is difficult to conceal your smirk as he slinks away.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 157}; }
    };

    class Story698 : public Story::Base
    {
    public:
        Story698()
        {
            BookID = Book::Type::BOOK1;

            ID = 698;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "Dashing into the narrow alleyways around a temple, you manage to pull some drying black priest robes from a washing line. Strolling nonchalantly into the city streets the guards rush right past you, failing to penetrate your disguise. Exhaling with relief you gaze about the city, wandering what you should do now you are penniless.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 340}; }
    };

    class Story699 : public Story::Base
    {
    public:
        Story699()
        {
            BookID = Book::Type::BOOK1;

            ID = 699;

            Location = Location::Type::CAVES_OF_URANU;

            Text = "Honnu of Chalice asked Akihiro to search for a silver idol in the Caves of Uranu. However, he has been instructed to search for the idol alone.";

            Choices.clear();
            Choices.push_back(Choice::Base("Let Akihiro undertake this quest now", {Book::Type::BOOK1, 154}));
            Choices.push_back(Choice::Base("You would rather stay together for the moment", {Book::Type::BOOK1, 493}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story700 : public Story::Base
    {
    public:
        Story700()
        {
            BookID = Book::Type::BOOK1;

            ID = 700;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You bend to help the injured Milagros, who tells you not to worry. \"I've had much worse, but you are gracious to help,\" she says, wincing as she smiles. \"Perhaps you would walk me to the kitchens? I fear my hands tremble too much to carry the soup.\"\n\nAssisting Milagros, you follow her down the poorly lit tunnel towards the kitchen. \"You are brave warriors, and you have kind hearts,\" she says. \"It is not right that you suffer and stultify here. There is... a plan, to abruptly shorten our sentence. If you would be free, follow me.\"\n\nMilagros makes an abrupt turn, down a narrow tunnel that plunges into darkness.";

            Choices.clear();
            Choices.push_back(Choice::Base("Follow her", {Book::Type::BOOK1, 379}));
            Choices.push_back(Choice::Base("Avoid trouble and return to your cells", {Book::Type::BOOK1, 223}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story701 : public Story::Base
    {
    public:
        Story701()
        {
            BookID = Book::Type::BOOK1;

            ID = 701;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Text = "As you wander the jungle you overhear a particularly mournful song coming through the trees. You come upon the sight of a crier bird in some distress. It has fallen into a small trap, a steel cage which has been hung up amongst the branches, no doubt left by some impoverished logger to earn a few extra coins. The poor bird warbles pitifully.";

            Choices.clear();
            Choices.push_back(Choice::Base("Take the bird with you", {Book::Type::BOOK1, 156}));
            Choices.push_back(Choice::Base("Free the bird from the cage", {Book::Type::BOOK1, 103}));
            Choices.push_back(Choice::Base("Leave the bird for the logger", {Book::Type::BOOK1, 618}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story702 : public Story::Base
    {
    public:
        Story702()
        {
            BookID = Book::Type::BOOK1;

            ID = 702;

            Text = "With a mixture of threats and promises you keep the workers digging. Finally, after weeks more effort, and plenty of supernatural terrors, the workers break into an antique chamber. Fear seems to almost radiate from the dreadful hall, and only one worker is brave enough to accompany you inside.\n\nIn the shrouded chamber you come upon a plinth, on which you find two madshards. You eagerly scoop them up, but as you turn you realise that something is wrong. The worker who accompanied you inside has changed. His peasant garb has become tight-fitting black robes, and in his hand he holds a blade composed of pure light.\n\n\"I am Fastilon, of the Silence,\" he declares. \"You have troubled the dark one long enough. This place will be a fitting tomb for you.\"\n\n\"He shall never rise!\" you swear, drawing your weapons.\n\nFastilon murmurs, and soon his form splits into six identical copies, which swirl about, constantly changing positions. You must defeat this master assassin.\n\nNote: The first person to damage Fastilon in a combat round is stunned by a magical bolt. That party member cannot attack in the next combat round. If Fastilon takes no damage in a combat round he will cast a spell instead of attacking (see his spells below). If Fastilon has been damaged, he will make two attacks in his turn. You must assign the damage of the second attack to a different character from the first.\nFastilon casts spells in the following order:\n\n1st) Fastilon casts Rune of Unmaking. One party member takes 6 points of damage.\n\n2nd) Fastilon casts Thunderbolt. Inflict 5 points of damage on two party members.\n\n3rd) Fastilon casts Healing Word. Fastilon recovers up to 8 Health points.\n\nAfter casting all his spells, Fastilon will fight as normal, with two attacks as mentioned above.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {Monster::Base("Fastilon", Monster::Type::FASTILON, 8, 2, 6, 40, 0, 2)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 334}; }
    };

    class Story703 : public Story::Base
    {
    public:
        Story703()
        {
            BookID = Book::Type::BOOK1;

            ID = 703;

            Location = Location::Type::CLIFFTOP;

            Text = "The journey to the harbour from the city is a fraught one, the thin path barely wide enough for a single person to traverse. Sometimes you have to give way to traffic coming up the trail on creaky wooden platforms that flex and bend under your weight. The harbour itself is a series of wooden piers hammered into the sides of the cliff face, barnacle encrusted beams peeping from the crashing waves. The ships must";

            Choices.clear();
            Choices.push_back(Choice::Base("Board your ship", {Book::Type::BOOK1, 82}, Choice::Type::SAIL, Location::Type::CLIFFTOP));
            Choices.push_back(Choice::Base("Get your ship repaired", {Book::Type::BOOK1, 652}, Choice::Type::SHIP, Location::Type::CLIFFTOP));
            Choices.push_back(Choice::Base("Buy or sell a ship", {Book::Type::BOOK1, 756}));
            Choices.push_back(Choice::Base("Organise a cargo delivery", {Book::Type::BOOK1, 855}));
            Choices.push_back(Choice::Base("Visit a local tavern", {Book::Type::BOOK1, 505}));
            Choices.push_back(Choice::Base("Return to the city centre", {Book::Type::BOOK1, 19}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story704 : public Story::Base
    {
    public:
        Story704()
        {
            BookID = Book::Type::BOOK1;

            ID = 704;

            Text = "\"A trade, for bringing me the weave,\" announces the shaman, brightly. \"I brew potions for the tribe. Choose one, and it shall be yours.\" The shaman offers you one of two potions.\n\nYou also ask for more information about the 'man with hatred in his heart' that the shaman spoke to you about before. He looks blankly at you, and then laughs. \"No doubt a piece of prophesy from my visions. Pay it no mind. My dreams are as insubstantial as air. But I do have one piece of advice for you. When the queen comes to take the bishop, bring gold to take the knights.\"\n\n\"Another one of your visions?\" you ask dryly.\n\nThe shaman shrugs. \"Take it or leave it,\" he says philosophically.\n\nNote:  The first is a HEALING POTION (restore 5 Health), which you can drink at any time, including during combat. The second is a POTION OF FLUENCY (3 Charisma successes), which you can drink during a Charisma skill check to automatically gain 3 extra successes. You can only choose one potion.";

            Bye = "Thanking him for his time, you return to your ship and weigh anchor.";

            Choices.clear();
            Choices.push_back(Choice::Base("Take the HEALING POTION", {Book::Type::BOOK1, 144}, Choice::Type::GET_EQUIPMENT, {Equipment::HEALING_POTION}));
            Choices.push_back(Choice::Base("Take the POTION OF FLUENCY (3 Charisma Successes)", {Book::Type::BOOK1, 144}, Choice::Type::GET_EQUIPMENT, {Equipment::POTION_OF_CHARISMA}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story705 : public Story::Base
    {
    public:
        Story705()
        {
            BookID = Book::Type::BOOK1;

            ID = 705;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "Animus Mast is the name of both a college of magic, and a literal magical tower in Drakehallow. It was built as part of the magical revival movement in that country some two hundred and fifty summers ago. It has a long running rivalry with Cassery Tower, another magical institution located only a few miles away. Animus Mast is an elitist organisation, accepting only proven mages into its fold. It is expensive to attend but is probably the superior college in terms of the learning facilities available. According to these scrolls, the most recent piece of research there is the rediscovery of golem construction. Golems are magical servants of stone and iron who built many of the monuments of the ancient world. Of course, these scrolls are forty summers old, so who knows what the wizards of Animus Mast are working on now!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 680}; }
    };

    class Story706 : public Story::Base
    {
    public:
        Engine::Destination destination = {};

        Story706()
        {
            BookID = Book::Type::BOOK1;

            ID = 706;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Text = "You'll not back down in front of a knave like Tommul. You must fight this battle alone.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            RoundLimit = 2;

            Monsters = {Monster::Base("Bronzeguard", Monster::Type::BRONZEGUARD, 8, 4, 5, 12, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::EXCEED_LIMIT)
            {
                destination = {Book::Type::BOOK1, 55};

                Bye = "You are still fighting when a horde of guardsmen burst through the doors. You are arrested on charges of conspiracy.";
            }
            else
            {
                destination = {Book::Type::BOOK1, 75};

                Bye = "You manage to escape.";
            }
        }
    };

    class Story707 : public Story::Base
    {
    public:
        Story707()
        {
            BookID = Book::Type::BOOK1;

            ID = 707;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The slaves give a mighty cheer as the last orc falls dead. They quickly take up the orc's weapons, though you may seize the CHAIN ARMOUR (Armour +2) from the orc leader, if you wish. The slaves heap glory upon you.\n\nYou ask the slaves what the orcs were digging for, but they can tell you little. The orcs would not reveal the object of their search, but they seemed frantic to find it, whatever it was. It is certainly unusual for orcs to travel so far, with so many supplies, and with such stealth into an enemy nation. You wonder what to make of it all.\n\nThe slaves thank you again, and let you know that they intend to find their own way out of the dungeon and to find a new life for themselves.\n\nNote: You gained the code A69.";

            Bye = "You wish them luck, and then turn your attention back to the cavern.";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to gain 1 point of Charisma", {Book::Type::BOOK1, 371}, Choice::Type::RAISE_ATTRIBUTE_SCORE, {Attribute::Type::CHARISMA}, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::CHAIN_ARMOUR2};

            Limit = 1;

            Engine::GET_CODES(party, {Codes::A(69)});
        }
    };

    class Story708 : public Story::Base
    {
    public:
        Story708()
        {
            BookID = Book::Type::BOOK1;

            ID = 708;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "You step cautiously through a crooked black stone archway and into a wide pillared chamber. You are just taking your bearings when you head a slam of rusted metal. Spinning around you can see that you have been cut off from the exit by a large portcullis. Worse, you can hear a savage hissing from all around the temple chamber. Drawing your weapons, you are startled to see a number of hideous snakemen, serpentine creatures with the arms of men and the bodies of a giant cobra. There is no escape, you must fight!\n\nNote: Note: If you have a HYGLIPH FLOWER the snakemen are put off by its pungent odour and require a 5+ on their attack rolls to inflict damage during this battle.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(41)}))
            {
                return {Book::Type::BOOK1, 827};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 5, 4, 3, 8, 0),
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 4, 4, 3, 8, 0),
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 3, 4, 3, 7, 0),
                Monster::Base("Snakeman", Monster::Type::SNAKEMAN, 3, 4, 3, 5, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 72}; }
    };

    class Story709 : public Story::Base
    {
    public:
        Story709()
        {
            BookID = Book::Type::BOOK1;

            ID = 709;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The strength of your convictions is obvious, and you can see the firmness of the sister faulter as you speak of the great hopes that the Everchild is inspiring in the downtrodden masses of Saltdad.\n\n\"Perhaps I was too hasty,\" she concedes. \"It seems clear that this is something the God King should know about. Come with me, please.\"";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 638}; }
    };

    class Story710 : public Story::Base
    {
    public:
        Story710()
        {
            BookID = Book::Type::BOOK1;

            ID = 710;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You have arrived at the ruined palace of Unbraaki. It is a charcoal wreck, thick with ash and forgotten sorcery. The soldiers that used to parade up and down its now weed-filled gardens haven long departed. Searching through the rubble you locate a set of stone steps leading down into a dimly lit gloom.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go down into the basement", {Book::Type::BOOK1, 67}));
            Choices.push_back(Choice::Base("Go north, towards Clifftop", {Book::Type::BOOK1, 725}));
            Choices.push_back(Choice::Base("Go west, to the Tumblestones", {Book::Type::BOOK1, 137}));
            Choices.push_back(Choice::Base("Go southeast, to Lhasbreath", {Book::Type::BOOK1, 775}));
            Choices.push_back(Choice::Base("Lhasbreath", {Book::Type::BOOK1, 775}));
            Choices.push_back(Choice::Base("Head south, into the jungle", {Book::Type::BOOK1, 370}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story711 : public Story::Base
    {
    public:
        Story711()
        {
            BookID = Book::Type::BOOK1;

            ID = 711;

            Location = Location::Type::SALT_PLAINS;

            Text = "It is time to leave the Salt Plains.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go southwest, toward Clifftop", {Book::Type::BOOK1, 12}));
            Choices.push_back(Choice::Base("Go southeast, towards Saltdad", {Book::Type::BOOK1, 511}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story712 : public Story::Base
    {
    public:
        Story712()
        {
            BookID = Book::Type::BOOK1;

            ID = 712;

            Text = "It is difficult to interpret what is really going on in the mural. Shrugging, you make your way further upwards.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 77}; }
    };

    class Story713 : public Story::Base
    {
    public:
        Story713()
        {
            BookID = Book::Type::BOOK1;

            ID = 713;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "The priest is delighted to be surrounded by such devout followers of the faith. In a grand ceremony in front of his other slaves he publicly releases you. In a warm gesture he even offers you 50 silver coins to help you get started in your new lives. Grovelling appropriately, you depart for the city centre.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_MONEY(party, 50);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 340}; }
    };

    class Story714 : public Story::Base
    {
    public:
        Story714()
        {
            BookID = Book::Type::BOOK1;

            ID = 714;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "You believe you have pieced together the mystery of this place. \"You are a priest of Cursus, then? The god of judgement?\"\n\n\"I am!\" he hisses. \"And I was high priest of all your kind once. When the demon lord came, we slithered from our underground dwellings from the cracks in the earth he smote with his sword. We took pity on you, took you as our slaves from your ruined cities. Gave you a home and pious work to perform, building temples in the name of Cursus. So cunning you were! Joined us in the worship of Cursus, your voices singing with ours... and then betrayal! You stole our god for your own! Escaped your chains and built your own temples without us. Your monuments were so magnificent that Cursus abandoned us for your kind.\"\n\n\"So Cursus was originally... a serpent god?\" you ask unsurely.\n\nThe priest seems angry. \"How can you doubt it?\" he snarls. \"Here! Look! The scrolls of Cursus, the original documents of our faith. Take them back to the foul priests in your monument-cluttered land! No human hand wrote this! This is the work of serpents...the true folk!\"\n\nHe thrusts the SCROLLS OF CURSUS into your hands. You gaze at them in wonder. If these documents were ever presented to the followers of Cursus it could cause untold damage to the faithful. Cursites have always been an intolerant folk. What would they make of the revelation that their faith was serpent-born?\n\nThe snakeman priest has slithered away, muttering dark words of sorcery. \"All is lost! My kin... too few in number to rebuild. The temple must not fall into human hands!\" Suddenly cracks begin forming in the walls, and a dreadful rumbling can be felt through the temple.\n\nYou have to get out of here!";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::SCROLLS_OF_CURSUS};

            Limit = 1;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 881}; }
    };

    class Story715 : public Story::Base
    {
    public:
        Story715()
        {
            BookID = Book::Type::BOOK1;

            ID = 715;

            Text = "\"We've met, haven't we, Emlyn?\" you ask unsurely.\n\n\"Eleven years ago, at Strongstone,\" she confirms. \"For the birth of my brother... my legitimate brother, Jeffery Ross. We were sat together at the low table with Montague Pass-Bailey. All the high lords in the county were there that night. I remember Count Spenser patting me on the head for bringing him a cup of mead, and being spat on and cuffed by your father for accidentally brushing past him.\"\n\n\"Sorry about that...\" you say guiltily.\n\n\"Why? You didn't do it,\" says Emlyn flatly.\n\n\"I think I'm always apologising for him,\" you add sheepishly. \"He's... very traditional, I suppose.\"\n\n\"It must have been tough growing up with Baron Baldwin Dayne as your father,\" she sympathises.\n\n\"I didn't grow up with him... I barely saw him,\" you mutter. \"Eighteen years I lived in Fosterly Castle. I spoke with him three times. He was ashamed of me. I don't know what it was about me that was so different from other bastard-born. Your father loves you and educated you as a scholar. Montague now serves his father as a spymaster. I scrubbed the castle floors and looked after the horses. I was treated like a peasant... and he called me such dreadful names, and never my own.\"\n\n\"Well, you're free of him now,\" says Emlyn.\n\nYou laugh. \"You're never free of your father.. not really.\"\n\nEmlyn pauses, and then searches her bag for a pair of cups in which she pours a little Almskirk wine. \"Let's do the old toast,\" she says, passing you a cup and raising hers. \"To the bastards of Strongstone!\"\n\n\"To the bastards of Strongstone,\" you smile, downing wine as bitter as your memories.\n\nNote: You gained the code A84.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(84)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 674}; }
    };

    class Story716 : public Story::Base
    {
    public:
        Story716()
        {
            BookID = Book::Type::BOOK1;

            ID = 716;

            Location = Location::Type::VIAAN_ISLAND;

            Text = "You steer your ship around Viaan Island until you come to the harbour of the Bando. The large village is a vista of brightly painted stick huts and boldly carved statues set against the wall of trees that is the Viaan Jungle. Tribes-folk swarm the edges of the harbour, pointing and chattering as your ship moors up. Immediately, blue and red painted tribesmen swarm up onto the deck, some armed, others merely curious. You get the impression that though they have certainly had visitors before, they are still making up their minds about you.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (!Engine::VERIFY_CODES(party, {Codes::Type::SPEAK_BANDO}))
            {
                Choices.push_back(Choice::Base("Reassure the Bando (Team check: Charisma 4+, Successes: 5)", {Book::Type::BOOK1, 339}, {Book::Type::BOOK1, 52}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::CHARISMA}, 6, 4));
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 206}; }
    };

    class Story717 : public Story::Base
    {
    public:
        Story717()
        {
            BookID = Book::Type::BOOK1;

            ID = 717;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "This plain looking room is empty. There is a door in the north and south wall.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::HAS_SPELL(party, {Spells::Type::SHADOW_DOOR}))
            {
                Choices.push_back(Choice::Base("Cast the shadow door spell", {Book::Type::BOOK1, 351}));
            }

            Choices.push_back(Choice::Base("Go north", {Book::Type::BOOK1, 366}));
            Choices.push_back(Choice::Base("Go south", {Book::Type::BOOK1, 494}));
        }
    };

    class Story718 : public Story::Base
    {
    public:
        Story718()
        {
            BookID = Book::Type::BOOK1;

            ID = 718;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "You spot the gang of slaves led by Tommul, who fought over the food supply in the dungeons. He seems happy to again join forces with you in order to increase his chances of survival. With a group of eight fighters you easily dominate the rest of the battle, ganging up and overwhelming any brave warriors that get in your way.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 71}; }
    };

    class Story719 : public Story::Base
    {
    public:
        Story719()
        {
            BookID = Book::Type::BOOK1;

            ID = 719;

            Text = "The door opens into a long corridor which ends in a formidable barricade. Blocks of stone, reinforced on the other side with heavy wooden beams, block the other side of the corridor. The barricade looks formidably strong.";

            Choices.clear();
            Choices.push_back(Choice::Base("Try and break the barricade", {Book::Type::BOOK1, 47}));
            Choices.push_back(Choice::Base("Return to the room you just came from", {Book::Type::BOOK1, 821}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(72)}))
            {
                return {Book::Type::BOOK1, 180};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story720 : public Story::Base
    {
    public:
        Story720()
        {
            BookID = Book::Type::BOOK1;

            ID = 720;

            Text = "The hairs on the back of your neck prick up. You sense a weakening in the fabric of the world in this place. Tracing mystic symbols in the air you see a patch of rock to your left fade away, revealing a small chamber containing funeral urns. A frail looking casket rests in the corner of the chamber, seeming to shudder in the feint breeze outside.";

            Choices.clear();
            Choices.push_back(Choice::Base("Enter the tomb", {Book::Type::BOOK1, 862}));
            Choices.push_back(Choice::Base("Quickly leave", {Book::Type::BOOK1, 115}));

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(39)}))
            {
                return {Book::Type::BOOK1, 167};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }
    };

    class Story721 : public Story::Base
    {
    public:
        Story721()
        {
            BookID = Book::Type::BOOK1;

            ID = 721;

            Location = Location::Type::AZURE_DEEP;

            Text = "Sailing around the bend comes a frightful looking vessel, so badly made you fear for the sailors who inhabit it. As it comes closer, for indeed it seems to be sailing directly towards you, you are astounded at what you see. It is an orcish vessel, its crude decorations across its hull and sails indicating it can be nothing else. Orcs are not native to the valley, their home hundreds of miles across the Azure Deep, in the Savage lands. What in the world are they doing all the way out here?\n\nThere is no time for questions.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(68)}))
            {
                return {Book::Type::BOOK1, 813};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            EnemyFleet = {Ship::Base("ORK HULK", Ship::Type::ORC_HULK, Location::Type::NONE, 3, 5, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 796}; }
    };

    class Story722 : public Story::Base
    {
    public:
        Story722()
        {
            BookID = Book::Type::BOOK1;

            ID = 722;

            Location = Location::Type::SALT_MINES;

            Text = "You are leaving the salt mines. The only way to go is in a southerly direction.";

            Choices.clear();
            Choices.push_back(Choice::Base("Southwest, towards Saltdad", {Book::Type::BOOK1, 177}));
            Choices.push_back(Choice::Base("Southeast, towards Luutanesh", {Book::Type::BOOK1, 614}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story723 : public Story::Base
    {
    public:
        Story723()
        {
            BookID = Book::Type::BOOK1;

            ID = 723;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You open the door to a gathering of large orc warriors, who turn to look at you sharply as you enter. The leader, a giant of an orc, gives a drooling snarl and commands his warriors to attack.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_CODES(party, {Codes::A(64)}))
            {
                return {Book::Type::BOOK1, 325};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(63)}))
            {
                return {Book::Type::BOOK1, 114};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(61)}))
            {
                return {Book::Type::BOOK1, 885};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Orc Leader", 7, 4, 4, 14, 0),
                Monster::Base("Orc", 5, 4, 4, 8, 0),
                Monster::Base("Orc", 5, 4, 4, 9, 0),
                Monster::Base("Orc", 4, 4, 4, 11, 0)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 669}; }
    };

    class Story724 : public Story::Base
    {
    public:
        Story724()
        {
            BookID = Book::Type::BOOK1;

            ID = 724;

            Text = "The thief turns his head at the sudden noise. As quick as a flash he dashes forwards, long dagger in hand, to cut the rope. You need to get through the window and stop him!\n\nNote: The party member at the top of the rope make following skill check.";

            Choices.clear();
            Choices.push_back(Choice::Base("Tackle the thief (Individual check: Fighting 5+, Successes: 4)", {Book::Type::BOOK1, 332}, {Book::Type::BOOK1, 528}, Choice::Type::ORDER_SKILL_CHECK, {Attribute::Type::FIGHTING}, 1, 5, 4, false));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story725 : public Story::Base
    {
    public:
        Story725()
        {
            BookID = Book::Type::BOOK1;

            ID = 725;

            Location = Location::Type::DESERT;

            Text = "You are wandering the desert, somewhat south of the dilapidated town of Clifftop. The searing heat is quite unbearable, and you struggle to ration your water carefully.";

            Choices.clear();
            Choices.push_back(Choice::Base("Manage your water (Team check: Survival 4+, Successes: 4)", {Book::Type::BOOK1, -725}, {Book::Type::BOOK1, -725}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::SURVIVAL}, 4, 4));

            Controls = Story::Controls::STANDARD;
        }

        void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection)
        {
            if (outcome)
            {
                Bye = "You manage to conserve water by travelling mostly at night and sheltering from the worst of the sun.";
            }
            else
            {
                Bye = "Each party member loses 1 Health from heatstroke.";

                Engine::GAIN_HEALTH(party, -1);
            }
        }
    };

    class Event725 : public Story::Base
    {
    public:
        Event725()
        {
            BookID = Book::Type::BOOK1;

            ID = -725;

            DisplayID = 725;

            Location = Location::Type::DESERT;

            Text = "Which direction will you head in?";

            Choices.clear();
            Choices.push_back(Choice::Base("South, to the palace of Unbraaki", {Book::Type::BOOK1, 890}));
            Choices.push_back(Choice::Base("East, to the Tumblestones", {Book::Type::BOOK1, 137}));
            Choices.push_back(Choice::Base("Northeast to the great Westroad", {Book::Type::BOOK1, 12}));
            Choices.push_back(Choice::Base("Northwest to Clifftop", {Book::Type::BOOK1, 19}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story726 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story726()
        {
            BookID = Book::Type::BOOK1;

            ID = 726;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "Sar Jessica turns to face Tasha, uncertainty in her eyes.";

            if (Engine::IN_PARTY(party, Character::Type::AMELIA_PASS_DAYNE))
            {
                PreText += " Amelia clears her throat and suggests it is time to move on.";
            }
            else
            {
                PreText += "\n\nThe sound of the men having a discussion beyond the reed bank provides the privacy she needs. Sar Jessica grasps Tasha's face and kisses her, as if releasing a long-withheld desire. She kisses her back, pleased to have secured the affections of the proud knight. The men, in their loud nattering, are none-the-wiser as they kiss.\n\nThe sound of the others getting out of the water breaks the moment and they hastily separate. Once everyone has dried themselves, you continue on your way.\n\nNote: Tasha has gained another heart for Sar Jessica. Sar Jessica also gains another heart for Tasha.";

                Engine::GAIN_HEARTS(party, Character::Type::TASHA, Character::Type::SAR_JESSICA_DAYNE, 1);
                Engine::GAIN_HEARTS(party, Character::Type::SAR_JESSICA_DAYNE, Character::Type::TASHA, 1);
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 51}; }
    };

    class Story727 : public Story::Base
    {
    public:
        Story727()
        {
            BookID = Book::Type::BOOK1;

            ID = 727;

            Location = Location::Type::CURSUS;

            IsCity = true;

            Text = "\"Forgive me, holy ones,\" you beg. \"But I found these sacred scrolls of Cursus in a long-abandoned ruin. I knew I had to bring them to you.\"\n\nThe High Zealot raises his eyebrows and takes the SCROLLS OF CURSUS. He scans over the sheets. \"They are written in the old hand! They are original works -- not translations! Praise be!\"\n\n\"Praise be!\" chant the other zealots, abasing themselves before the scrolls.\n\nAs the High Zealot reads his face contorts in confusion... and then horror. \"No! It cannot be!\" he cries. \"Cursus? A serpent god? A foul beast deity, with no more right to occupy heaven than a dog? We are deceived, brothers! Our faith is little more than a tool of spiritual slavery!\"\n\n\"No!\" cries another. \"These are lies!\"\n\n\"But they are written in the old hand, it cannot be lies!\" insists the High Zealot.\n\nYou discreetly leave the chamber as you hear the sounds of swords being drawn in anger. You have been forgotten, and there is much 'religious dialogue' to take place in your absence. Perhaps this is the beginning of the end of the Cursus religion, perhaps not. Either way, the zealots of Cursus will destroy each other.\n\nNote: You gained the code A40.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::LOSE_EQUIPMENT(party, {Equipment::Type::SCROLLS_OF_CURSUS});

            Engine::GET_CODES(party, {Codes::A(40)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 574}; }
    };

    class Story728 : public Story::Base
    {
    public:
        Story728()
        {
            BookID = Book::Type::BOOK1;

            ID = 728;

            Text = "Brekken has brought long grappling hooks which help you clamber up the walls with ease. However you soon hit a snag. The windows are proving difficult to open, with Brekken struggling to get a purchase on them. \"If only it was an exterior lock,\" he mumbles. \"I could get it open in a thrice.\"\n\nYou will have to wrench the window open with raw strength.\n\nNote: Choose a party member from the wall-climbing team to do this and make the following skill check.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::VERIFY_EQUIPMENT(party, Team::Type::WALL_CLIMBING, {Equipment::Type::PRYBAR}))
            {
                Choices.push_back(Choice::Base("Force open window (Individual check: Fighting 4+, Successes: 3)", {Book::Type::BOOK1, 305}, {Book::Type::BOOK1, 443}, Team::Type::WALL_CLIMBING, {Attribute::Type::FIGHTING}, 4, 3, false));
            }
            else
            {
                Choices.push_back(Choice::Base("Force open window (Individual check: Fighting 5+, Successes: 3)", {Book::Type::BOOK1, 305}, {Book::Type::BOOK1, 443}, Team::Type::WALL_CLIMBING, {Attribute::Type::FIGHTING}, 5, 3, false));
            }
        }
    };

    class Story729 : public Story::Base
    {
    public:
        Story729()
        {
            BookID = Book::Type::BOOK1;

            ID = 729;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You have returned to the room of traps, the deadly blades still dripping with blood. Having already looted the room you have no intention of ever returning. You go back to the crossroads.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 310}; }
    };

    class Story730 : public Story::Base
    {
    public:
        Story730()
        {
            BookID = Book::Type::BOOK1;

            ID = 730;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "You side with the mourners and attempt to persuade the kensai to let the matter drop. The kensai will only be persuaded by strong theological arguments.";

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Choices.clear();

            if (Engine::IN_PARTY(party, Character::Type::AKIHIRO_OF_CHALICE))
            {
                Choices.push_back(Choice::Base("Convince the kensai (Team check: Lore 4+, Successes: 6)", {Book::Type::BOOK1, 195}, {Book::Type::BOOK1, 843}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 4, 5));
            }
            else
            {
                Choices.push_back(Choice::Base("Convince the kensai (Team check: Lore 4+, Successes: 5)", {Book::Type::BOOK1, 195}, {Book::Type::BOOK1, 843}, Choice::Type::TEAM_ATTRIBUTES, {Attribute::Type::LORE}, 4, 6));
            }
        }
    };

    class Story731 : public Story::Base
    {
    public:
        Story731()
        {
            BookID = Book::Type::BOOK1;

            ID = 731;

            Location = Location::Type::SALT_PLAINS;

            Text = "You spy a body in the distance, little more than a pile of bones. Approaching you can see it is the remains of a Lhasbreath warrior, his grim BONE ARMOUR glistening in the waterless waste. The poor devil has no use for his things now. You can take his BONE ARMOUR (Armour +2), his IRON SHORTSWORD (Fighting +1) and 30 silver coins. Lamenting that he died so close to water, you look to leave the savage wasteland.\n\nNote: You gained the code A18.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::BONE_ARMOUR2, Equipment::IRON_SHORTSWORD1};

            Limit = 2;

            Engine::GET_CODES(party, {Codes::A(18)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 711}; }
    };

    class Story732 : public Story::Base
    {
    public:
        Story732()
        {
            BookID = Book::Type::BOOK1;

            ID = 732;

            Location = Location::Type::PALACE_OF_UNBRAAKI;

            Text = "You wait for another monkey to pass and cast your spell, the surprised looking ape gazing at you in wonder as you address it in its own tongue.\n\n\"My friend, can you help us through the window?\" you ask.\n\n\"Why do you want to come in?\" asks the monkey, scratching its behind.\n\nAnimals are honest creatures, and it is impossible to lie in their own language. \"We want to rob Unbraaki's palace,\" you say, appalled at your own frankness.\n\nThe monkey laughs. \"Sounds like fun!\" he chitters back. \"Hang on a moment.\"\n\nThe monkey sits upon the window ledge, and, to your amazement, scratches away the runes without activating their curse.\n\n\"How did you...?\" you ask.\n\n\"We're Unbraaki's apprentices,\" laughs the monkey.\n\n\"We are all sorcerers here! Still, Unbraaki can be mean sometimes, so I don't mind if you rob him. Have a good evening!\"";

            Bye = "The monkey scampers away, and you lose no time scrambling through the window into the attic.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 210}; }
    };

    class Story733 : public Story::Base
    {
    public:
        Story733()
        {
            BookID = Book::Type::BOOK1;

            ID = 733;

            Location = Location::Type::SALTDAD;

            IsCity = true;

            Image = "images/book1/malronac_the_deathengine.png";

            Text = "It is several days before you catch sight of the fearsome golem, but eventually the iron body of Malronac comes clanking out of the palace doors, its glittering steel greatsword gripped openly in hand. Malronac moves swiftly through the city streets, and you follow at a distance, eager to put as much distance between the city guards and him as possible.\n\nEventually the Deathengine stops outside the house of a beloved healer. He kicks in the door, loudly announcing his arrival. \"Garrick of Luutanesh! I am charged by the king to execute you under suspicion of conspiracy!\n\nThis is your moment. You follow Malronac into the house, just as he is gripping the throat of a helpless looking old man.\n\n\"Drop him, you metal cur!\" you snarl, drawing your weapons. Malronac raises a single metallic eyebrow, casting the old man into the corner. He grips his sword, eyes flashing with power.\n\n\"More traitors to execute!\" he growls. \"You merely save me time, fools!\"\n\nYou cannot flee from Malronac, he will chase you until the end of the world.\n\nNote: Malronac will attack twice each round. You must assign the damage of the second attack to a different character from the first.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Monsters = {Monster::Base("Malronac the Deathengine", 6, 3, 4, 30, 0, 0, 2)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 777}; }
    };

    class Story734 : public Story::Base
    {
    public:
        Story734()
        {
            BookID = Book::Type::BOOK1;

            ID = 734;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You have slain the orcs, their blood weeping into the ancient flagstones. You found five CRUDE BLADES (Fighting +0). Turning your attention to the table you examine the artefacts that the orcs seem to have dug up from the earth. Is this what the orc expedition is about? Simple treasure hunting?\n\nSome of the artefacts are simple bits of pottery with no real value, but you do find a HANDSOME BROOCH (Charisma +1) and several other pieces of jewellery you can sell for 350 silver coins.\n\nThere are two exits from the chamber.\n\nNote: You gained the code A74.";

            Choices.clear();
            Choices.push_back(Choice::Base("Go through the north door", {Book::Type::BOOK1, 23}));
            Choices.push_back(Choice::Base("Go through the east door", {Book::Type::BOOK1, 755}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::CRUDE_BLADE, Equipment::HANDSOME_BROOCH1};

            Limit = 6;

            Engine::GET_CODES(party, {Codes::A(74)});

            Engine::GAIN_MONEY(party, 350);
        }
    };

    class Story735 : public Story::Base
    {
    public:
        Story735()
        {
            BookID = Book::Type::BOOK1;

            ID = 735;

            Text = "Akihiro summersaults over an intervening foe, landing in front of Sar Jessica just as the axe blade falls. Clang! With one swift move he knocks aside the axe blade, sweeping his sword across the barbarian's throat in a single motion. The dumbstruck barbarian stumbles back, blood pouring from his neck, before collapsing in a heap.\n\nSar Jessica, astonished at this peerless swordplay, gapes wordlessly.\n\n\"Come, Sar Jessica,\" says Akihiro softly. \"It is too soon to die, yet.\"\n\nTaking his hand, Sar Jessica rejoins the fight -- but she will not forget this moment.\n\nNote: Jessica has gained a heart for Akihiro. Akihiro also gains a heart for Jessca.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GAIN_HEARTS(party, Character::Type::SAR_JESSICA_DAYNE, Character::Type::AKIHIRO_OF_CHALICE, 1);
            Engine::GAIN_HEARTS(party, Character::Type::AKIHIRO_OF_CHALICE, Character::Type::SAR_JESSICA_DAYNE, 1);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 753}; }
    };

    class Story736 : public Story::Base
    {
    public:
        Story736()
        {
            BookID = Book::Type::BOOK1;

            ID = 736;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You are in a long corridor, that runs north-south. A heavy looking door is in the west wall bearing a large lock. In the east wall is a more ordinary looking door. To the north is a door from which pleasant food smells waft. You think you see a crossroads to the south.";

            Choices.clear();
            Choices.push_back(Choice::Base("Unlock the west door with the IRON KEY", {Book::Type::BOOK1, 306}, {Equipment::IRON_KEY}));
            Choices.push_back(Choice::Base("Go through the east door", {Book::Type::BOOK1, 723}));
            Choices.push_back(Choice::Base("Go through the north door", {Book::Type::BOOK1, 551}));
            Choices.push_back(Choice::Base("Go south to the crossroads", {Book::Type::BOOK1, 566}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story737 : public Story::Base
    {
    public:
        Story737()
        {
            BookID = Book::Type::BOOK1;

            ID = 737;

            Location = Location::Type::WITHERED_STEPPES;

            Text = "You broach the subject of the queen, and her requirement for more soldiers to prosecute her war against the patriarch of Cursus. He laughs as you extol her virtues as a ruler. \"You do not have to tell me what she is like, why, she is my own daughter,\" he laughs.\n\n\"You are the Everchild's father?\" you gasp.\n\n\"I am Milagros's father,\" he chides. \"This tale about her being the eternal queen is just so much nonsense. The girl was too easily led by her aunt, who was a fabulous storyteller, but didn't have an ounce of wit about her.\"\n\n\"But surely her magical powers are enough to convince...\" you begin.\n\n\"She can cast a spell or two, to be sure, but no more than she has learnt from the hedge wizards of her own tribe,\" he smiles indulgently. \"The Everchild of legend could raise mountains and turn seas to fire. Have you ever seen Milagros do that?\"\n\nYou are silent, suddenly filled with doubt.\n\n\"Mark my words, many in the valley will meet their deaths before my child is done with her ambitions, and you'll not see a whit of change for the better,\" he warns.\n\nYou rise, now uncertain that you have backed the right monarch, but the nomad chief calls you back. \"She is still family,\" he shrugs. \"Tell her she shall have my finest horsemen, but bid her remember where she comes from. It is not out of the pages of a story book, that is for certain.\"\n\nNote: These soldiers are added to your Saltdad barracks:\n\n[Nomad Horsemen]: Strength 4, Morale 3\n\nYou gained the code A37.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            party.Army.push_back(Army::Base("Nomad Horsemen", Army::Type::NOMAD_HORSEMEN, Location::Type::SALTDAD, 4, 3, false));

            Engine::GET_CODES(party, {Codes::A(37)});
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 473}; }
    };

    class Story738 : public Story::Base
    {
    public:
        Story738()
        {
            BookID = Book::Type::BOOK1;

            ID = 738;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "The slaves you rescued from the dungeons of Mordain are here. They have already boarded the ship and made it seaworthy. They urge you to become their new captain and lead them to fame and riches.\n\nNote: You gained the code A68.";

            Choices.clear();
            Choices.push_back(Choice::Base("Agree to their request and set sail", {Book::Type::BOOK1, 112}));
            Choices.push_back(Choice::Base("Decline, gifting them the ship and wishing them luck", {Book::Type::BOOK1, 800}));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::GET_CODES(party, {Codes::A(68)});
        }
    };

    class Story739 : public Story::Base
    {
    public:
        std::string PreText = "";

        Engine::Destination destination = {};

        Story739()
        {
            BookID = Book::Type::BOOK1;

            ID = 739;

            Location = Location::Type::SALT_MINES;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take.clear();

            Monsters.clear();

            Limit = 0;

            PreText = "The mine lift comes shuddering to a halt as you emerge onto the twelfth level of the mines.";

            if (!Engine::VERIFY_CODES(party, {Codes::A(24)}))
            {
                PreText += "\n\nIt does not take long to find trouble. A horde of fleeing miners barge past you, pursued tightly by a gang of three scaly troglodytes. Trapped between the fleeing miners and the aggressive troglodytes you have little option but to fight.";

                Monsters = {
                    Monster::Base("Troglodyte", 2, 3, 4, 4, 0),
                    Monster::Base("Troglodyte", 3, 3, 4, 3, 0),
                    Monster::Base("Troglodyte", 2, 3, 4, 3, 0)};
            }
            else
            {
                destination = {Book::Type::BOOK1, 817};
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            destination = {Book::Type::BOOK1, 135};

            Bye = NULL;

            if (result == Engine::Combat::VICTORY)
            {
                Take = {Equipment::TROGLODYTE_HEAD, Equipment::TROGLODYTE_HEAD, Equipment::TROGLODYTE_HEAD};

                Limit = 3;

                Engine::GET_CODES(party, {Codes::A(24)});

                if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::TROGLODYTE_HEAD}) > 0)
                {
                    Bye = "You take up the troglodyte heads from the unlucky beasts.\n\nNote: You gained the code A24.";
                }
                else
                {
                    Bye = "You gained the code A24.";
                }
            }
        }
    };

    class Story740 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story740()
        {
            BookID = Book::Type::BOOK1;

            ID = 740;

            Location = Location::Type::LHASBREATH_JUNGLE;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "Night falls and you make camp in a clearing under the stars. Emlyn Pass-Ross tends to her scratches and wounds by firelight as you begin cooking something tasty from the ration bags.";

            if (!Engine::IN_PARTY(party, Character::Type::AMELIA_PASS_DAYNE))
            {
                PreText += "\n\n\"So, what made you want to take up the life of an explorer?\" you ask idly. She shrugs. \"I suppose for the opportunity,\" she says, the fire reflecting in her eyes. \"I am bastard-born, so there is nothing to inherit at home. Fortunately, we Ross's have a strong adventurous streak in us, so when my father was asked to lead this expedition he was happy to bring me along.\"\n\n\"You seem close to your father,\" you say. \"Does he acknowledge you in court?\"\n\n\"A bit,\" she smiles. \"As much as can be expected. He can show more affection out here in the barbarian lands. But when I go home it will be much as is ever was, I suppose. As long as I don't embarrass the baroness I am welcome in Strongstone. That's better than most illegitimate children get.\"\n\nIt is late. Wishing Emlyn a good evening you settle down to sleep.";
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 674}; }
    };

    class Story741 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story741()
        {
            BookID = Book::Type::BOOK1;

            ID = 741;

            Location = Location::Type::CLIFFTOP;

            Choices.clear();
            Choices.push_back(Choice::Base("See your fate", {{2, "You are sold to the Saltdad Arena", {Book::Type::BOOK1, 631}}, {4, "You are sold to the taskmasters of Clifftop", {Book::Type::BOOK1, 866}}, {6, "You are sold to the priests of Cursus", {Book::Type::BOOK1, 531}}}, 1));

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Engine::SINK_SHIP(party);

            PreText = "Your mast is split, and many of your crew are dead. The pirates swarm your vessel, cutlasses to your throats. You have been captured and your future looks bleak. You are stripped of all the equipment and money you are carrying, and brutally scourged and abused by the pirates.\n\nThe pirates sail up the coast to Clifftop, where you are sold publicly at the slave market.\n\nNote: Each party member loses ";

            party.Money = 0;

            Engine::LOSE_ALL(party);

            auto loss = Engine::ROLL(1);

            PreText += std::to_string(loss) + " health point";

            if (loss > 1)
            {
                PreText += "s";
            }

            PreText += ".";

            Engine::GAIN_HEALTH(party, -loss);

            Text = PreText.c_str();
        }
    };

    class Story742 : public Story::Base
    {
    public:
        std::string PreText = "";

        Story742()
        {
            BookID = Book::Type::BOOK1;

            ID = 742;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            PreText = "Fighting a bear without weapons is a recipe for disaster. The bear mauls you dreadfully before the barbarians mercifully throw you down a rope for your rescue.\n\n";

            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                Engine::GAIN_HEALTH(party.Members[party.LastSelected], -5);

                PreText += std::string(party.Members[party.LastSelected].Name) + " loses 5 health points.";
            }

            PreText += "\n\nKing Scarrenden and his chosen warriors soon lose interest in you, and you skulk away to lick your wounds.";

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 775}; }
    };

    class Story743 : public Story::Base
    {
    public:
        Story743()
        {
            BookID = Book::Type::BOOK1;

            ID = 743;

            Location = Location::Type::SALTDAD_ARENA;

            IsCity = true;

            Text = "Che Long steps forward, giving his seat to the Everchild. \"The arena is ancient and was once much bigger. There are vaults and tunnels that lead deep into the earth. We have, in secret, excavated one such tunnel. We cannot be sure that it leads to the surface, but we are willing to chance it.\"\n\n\"Why have you not gone already?\" you ask.\n\n\"We have no weapons, and there are... creatures down there in the dark,\" mutters Che Long. \"We were driven back in our last venture. It is too dangerous to proceed unarmed. Unfortunately, the guards keep the weapons very well secured. They are not keen on allowing slave gladiators unfettered access to arms.\"\n\n\"How can we help?\" you ask.\n\n\"We need to get the weapons out of the gatehouses and into our hands,\" says Che Long. \"To do that we will need stealth and a good distraction.\"";

            Choices.clear();
            Choices.push_back(Choice::Base("Volunteer to get the weapons", {Book::Type::BOOK1, 191}));
            Choices.push_back(Choice::Base("Back out of this risky escape plan", {Book::Type::BOOK1, 223}));
            Choices.push_back(Choice::Base("Inform the guards of the Everchild's plans", {Book::Type::BOOK1, 106}));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story744 : public Story::Base
    {
    public:
        Story744()
        {
            BookID = Book::Type::BOOK1;

            ID = 744;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Text = "The sister is not worldly and has not heard the rumours of the Everchild's resurrection. Fortunately, one of her kensai is more knowledgeable of current affairs, and takes you aside.\n\n\"I have seen the young girl you speak of,\" he confides. \"I too believe she is the Everchild of legend. You will never persuade sister Emiko to let you see the God King. But you may enter if you challenge one of the God King's champions to a duel. I would be willing to duel one of you. The battle must be to the death, and I must fight with all my skill if I am to keep my oath to the God King.\"\n\n";

            Choices.clear();
            Choices.push_back(Choice::Base("Choose a party member to to duel the kensai", {Book::Type::BOOK1, -744}, Choice::Type::CHOOSE_PARTY_MEMBER));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Event744 : public Story::Base
    {
    public:
        std::string PreText = "";

        Engine::Destination destination = {};

        Team::Type previousTeam = Team::Type::NONE;

        Event744()
        {
            BookID = Book::Type::BOOK1;

            ID = -744;

            DisplayID = 744;

            Location = Location::Type::CHALICE;

            IsCity = true;

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            destination = {Book::Type::BOOK1, 502};

            Team = Team::Type::NONE;

            previousTeam = Team::Type::NONE;

            if (Engine::IS_ACTIVE(party, party.LastSelected))
            {
                PreText = std::string(party.Members[party.LastSelected].Name) + " will duel with the Kensai to the death.";

                Team = Engine::GET_TEAM(party.Members[party.LastSelected]);

                previousTeam = party.Members[party.LastSelected].Team;

                Engine::SET_TEAM(party.Members[party.LastSelected]);

                Monsters = {Monster::Base("Kensai", 6, 4, 4, 9, 0)};
            }
            else
            {
                PreText = "No one was brave enough to duel with the Kensai.";

                Monsters.clear();
            }

            Text = PreText.c_str();
        }

        Engine::Destination Continue(Party::Base &party) { return destination; }

        void AfterCombat(Party::Base &party, Engine::Combat result)
        {
            if (result == Engine::Combat::VICTORY)
            {
                if (Engine::IS_ACTIVE(party, party.LastSelected))
                {
                    party.Members[party.LastSelected].Team = previousTeam;
                }

                destination = {Book::Type::BOOK1, 418};
            }
            else
            {
                destination = {Book::Type::BOOK1, 502};
            }
        }
    };

    class Story745 : public Story::Base
    {
    public:
        Story745()
        {
            BookID = Book::Type::BOOK1;

            ID = 745;

            Text = "The rope is tied. Now the rest of the party must try to haul it aboard whilst it is guided into place by the diver.\n\nNote: Your diver cannot help in the following skill check.";

            Choices.clear();
            Choices.push_back(Choice::Base("Haul up the cogwheel (Team check: Fighting 5+, Successes: 3)", {Book::Type::BOOK1, 352}, {Book::Type::BOOK1, 807}, Choice::Type::PARTY_EXCEPT_WITHSTATUS, {Character::Status::FOUND_COGWHEEL}, {Attribute::Type::FIGHTING}, 5, 3, false));

            Controls = Story::Controls::STANDARD;
        }
    };

    class Story746 : public Story::Base
    {
    public:
        Story746()
        {
            BookID = Book::Type::BOOK1;

            ID = 746;

            Location = Location::Type::LUUTANESH;

            Text = "\"The God King wishes to see my handwriting?\" says the Everchild aghast. \"Whatever for?\"\n\n\"He believes that through your hand he may glimpse the honesty of your soul,\" you explain sheepishly. \"He will not be moved otherwise.\"\n\nThe Everchild sighs and closes her eyes. \"Such a letter will require the finest components. I will need some CALLIGRAPHY INK. This is not easily found in the Valley of Bones.\"\n\n\"Any suggestions where we could find some?\" you ask.\n\n\"Powerful sorcerers might own such a thing,\" suggests the Everchild. \"Otherwise the markets of the sea cities might have it for sale, though it would cost a fortune.\"\n\nWhy is nothing simple?";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::VERIFY_EQUIPMENT(party, {Equipment::Type::CALLIGRAPHY_INK}))
            {
                return {Book::Type::BOOK1, 330};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 263}; }
    };

    class Story747 : public Story::Base
    {
    public:
        Story747()
        {
            BookID = Book::Type::BOOK1;

            ID = 747;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "You make your way down the long stairwell for quite some time. You must have descended at least fifty feet into the earth. Eventually the stairs terminate at another tunnel.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 23}; }
    };

    class Story748 : public Story::Base
    {
    public:
        Story748()
        {
            BookID = Book::Type::BOOK1;

            ID = 748;

            Location = Location::Type::TEMPLE_OFTHE_UNBROKEN;

            Text = "You wonder how many more snakemen can fit into this temple! In the devastation you find plenty of religious silverwork worth 250 silver coins. A HANDSOME BROOCH (Charisma +1) lies amongst the chalices and statuettes you loot. There is a way onwards, your torchlight reflecting some bronze plating ahead. Intrigued you make your way down the passageway.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        void Event(Party::Base &party)
        {
            Take = {Equipment::HANDSOME_BROOCH1};

            Limit = 1;

            Engine::GAIN_MONEY(party, 250);
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 20}; }
    };

    class Story749 : public Story::Base
    {
    public:
        Story749()
        {
            BookID = Book::Type::BOOK1;

            ID = 749;

            Location = Location::Type::MORDAIN_EXCAVATED_DUNGEONS;

            Text = "As you round the corner of the corridor you come face to face with a hideous female ogre. She hefts her club to attack. Unknown to you, the ogre's mate is in a room not far away.\n\nNote: At the end of the second round of combat he will join the attack.";

            Choices.clear();

            Controls = Story::Controls::STANDARD;
        }

        Engine::Destination Background(Party::Base &party)
        {
            if (Engine::IN_PARTY(party, Character::Type::SKULLCRACKER))
            {
                return {Book::Type::BOOK1, 269};
            }
            else if (Engine::VERIFY_CODES(party, {Codes::A(76)}))
            {
                return {Book::Type::BOOK1, 165};
            }
            else
            {
                return {Book::Type::NONE, -1};
            }
        }

        void Event(Party::Base &party)
        {
            Monsters = {
                Monster::Base("Daisy", 9, 4, 4, 13, 0),
                Monster::Base("Skullcracker", 8, 4, 4, 12, 0, 2)};
        }

        Engine::Destination Continue(Party::Base &party) { return {Book::Type::BOOK1, 431}; }
    };

    auto story001 = Story001();
    auto story002 = Story002();
    auto story003 = Story003();
    auto story004 = Story004();
    auto story005 = Story005();
    auto story006 = Story006();
    auto story007 = Story007();
    auto story008 = Story008();
    auto story009 = Story009();
    auto story010 = Story010();
    auto story011 = Story011();
    auto story012 = Story012();
    auto story013 = Story013();
    auto story014 = Story014();
    auto story015 = Story015();
    auto story016 = Story016();
    auto story017 = Story017();
    auto story018 = Story018();
    auto event018 = Event018();
    auto story019 = Story019();
    auto story020 = Story020();
    auto story021 = Story021();
    auto story022 = Story022();
    auto story023 = Story023();
    auto story024 = Story024();
    auto story025 = Story025();
    auto story026 = Story026();
    auto event027 = Event027();
    auto story027 = Story027();
    auto story028 = Story028();
    auto event028 = Event028();
    auto story029 = Story029();
    auto story030 = Story030();
    auto story031 = Story031();
    auto story032 = Story032();
    auto story033 = Story033();
    auto story034 = Story034();
    auto story035 = Story035();
    auto story036 = Story036();
    auto story037 = Story037();
    auto story038 = Story038();
    auto story039 = Story039();
    auto story040 = Story040();
    auto story041 = Story041();
    auto story042 = Story042();
    auto story043 = Story043();
    auto story044 = Story044();
    auto event044 = Event044();
    auto story045 = Story045();
    auto story046 = Story046();
    auto story047 = Story047();
    auto story048 = Story048();
    auto story049 = Story049();
    auto story050 = Story050();
    auto story051 = Story051();
    auto story052 = Story052();
    auto story053 = Story053();
    auto story054 = Story054();
    auto story055 = Story055();
    auto story056 = Story056();
    auto story057 = Story057();
    auto story058 = Story058();
    auto story059 = Story059();
    auto story060 = Story060();
    auto story061 = Story061();
    auto story062 = Story062();
    auto story063 = Story063();
    auto story064 = Story064();
    auto story065 = Story065();
    auto story066 = Story066();
    auto story067 = Story067();
    auto event067 = Event067();
    auto story068 = Story068();
    auto story069 = Story069();
    auto story070 = Story070();
    auto story071 = Story071();
    auto story072 = Story072();
    auto story073 = Story073();
    auto event073 = Event073();
    auto story074 = Story074();
    auto story075 = Story075();
    auto story076 = Story076();
    auto event076 = Event076();
    auto story077 = Story077();
    auto story078 = Story078();
    auto event078 = Event078();
    auto story079 = Story079();
    auto story080 = Story080();
    auto story081 = Story081();
    auto story082 = Story082();
    auto story083 = Story083();
    auto story084 = Story084();
    auto story085 = Story085();
    auto story086 = Story086();
    auto story087 = Story087();
    auto e087_001 = E087_001();
    auto e087_002 = E087_002();
    auto e087_003 = E087_003();
    auto story088 = Story088();
    auto story089 = Story089();
    auto event089 = Event089();
    auto story090 = Story090();
    auto story091 = Story091();
    auto story092 = Story092();
    auto story093 = Story093();
    auto story094 = Story094();
    auto story095 = Story095();
    auto story096 = Story096();
    auto story097 = Story097();
    auto story098 = Story098();
    auto event098 = Event098();
    auto story099 = Story099();
    auto story100 = Story100();
    auto story101 = Story101();
    auto story102 = Story102();
    auto event102 = Event102();
    auto story103 = Story103();
    auto story104 = Story104();
    auto story105 = Story105();
    auto story106 = Story106();
    auto story107 = Story107();
    auto story108 = Story108();
    auto story109 = Story109();
    auto story110 = Story110();
    auto story111 = Story111();
    auto story112 = Story112();
    auto story113 = Story113();
    auto story114 = Story114();
    auto story115 = Story115();
    auto e115_001 = E115_001();
    auto e115_002 = E115_002();
    auto story116 = Story116();
    auto story117 = Story117();
    auto story118 = Story118();
    auto story119 = Story119();
    auto story120 = Story120();
    auto story121 = Story121();
    auto story122 = Story122();
    auto story123 = Story123();
    auto story124 = Story124();
    auto story125 = Story125();
    auto story126 = Story126();
    auto story127 = Story127();
    auto story128 = Story128();
    auto e128_001 = E128_001();
    auto e128_002 = E128_002();
    auto story129 = Story129();
    auto story130 = Story130();
    auto story131 = Story131();
    auto story132 = Story132();
    auto story133 = Story133();
    auto story134 = Story134();
    auto story135 = Story135();
    auto story136 = Story136();
    auto story137 = Story137();
    auto story138 = Story138();
    auto story139 = Story139();
    auto story140 = Story140();
    auto story141 = Story141();
    auto story142 = Story142();
    auto story143 = Story143();
    auto story144 = Story144();
    auto story145 = Story145();
    auto story146 = Story146();
    auto story147 = Story147();
    auto story148 = Story148();
    auto story149 = Story149();
    auto story150 = Story150();
    auto story151 = Story151();
    auto story152 = Story152();
    auto story153 = Story153();
    auto story154 = Story154();
    auto story155 = Story155();
    auto story156 = Story156();
    auto story157 = Story157();
    auto story158 = Story158();
    auto story159 = Story159();
    auto story160 = Story160();
    auto event160 = Event160();
    auto story161 = Story161();
    auto story162 = Story162();
    auto story163 = Story163();
    auto story164 = Story164();
    auto story165 = Story165();
    auto story166 = Story166();
    auto story167 = Story167();
    auto story168 = Story168();
    auto story169 = Story169();
    auto story170 = Story170();
    auto story171 = Story171();
    auto story172 = Story172();
    auto story173 = Story173();
    auto story174 = Story174();
    auto story175 = Story175();
    auto story176 = Story176();
    auto story177 = Story177();
    auto story178 = Story178();
    auto story179 = Story179();
    auto story180 = Story180();
    auto story181 = Story181();
    auto story182 = Story182();
    auto story183 = Story183();
    auto event183 = Event183();
    auto story184 = Story184();
    auto story185 = Story185();
    auto story186 = Story186();
    auto event186 = Event186();
    auto story187 = Story187();
    auto story188 = Story188();
    auto event188 = Event188();
    auto story189 = Story189();
    auto story190 = Story190();
    auto story191 = Story191();
    auto story192 = Story192();
    auto story193 = Story193();
    auto story194 = Story194();
    auto story195 = Story195();
    auto story196 = Story196();
    auto story197 = Story197();
    auto story198 = Story198();
    auto story199 = Story199();
    auto story200 = Story200();
    auto story201 = Story201();
    auto story202 = Story202();
    auto event202 = Event202();
    auto story203 = Story203();
    auto story204 = Story204();
    auto story205 = Story205();
    auto story206 = Story206();
    auto story207 = Story207();
    auto event207 = Event207();
    auto story208 = Story208();
    auto story209 = Story209();
    auto story210 = Story210();
    auto story211 = Story211();
    auto story212 = Story212();
    auto story213 = Story213();
    auto story214 = Story214();
    auto story215 = Story215();
    auto story216 = Story216();
    auto story217 = Story217();
    auto story218 = Story218();
    auto story219 = Story219();
    auto story220 = Story220();
    auto story221 = Story221();
    auto story222 = Story222();
    auto story223 = Story223();
    auto event223 = Event223();
    auto story224 = Story224();
    auto event224 = Event224();
    auto story225 = Story225();
    auto story226 = Story226();
    auto story227 = Story227();
    auto story228 = Story228();
    auto story229 = Story229();
    auto story230 = Story230();
    auto story231 = Story231();
    auto story232 = Story232();
    auto story233 = Story233();
    auto story234 = Story234();
    auto story235 = Story235();
    auto story236 = Story236();
    auto story237 = Story237();
    auto story238 = Story238();
    auto story239 = Story239();
    auto story240 = Story240();
    auto story241 = Story241();
    auto story242 = Story242();
    auto story243 = Story243();
    auto story244 = Story244();
    auto story245 = Story245();
    auto story246 = Story246();
    auto story247 = Story247();
    auto story248 = Story248();
    auto story249 = Story249();
    auto story250 = Story250();
    auto story251 = Story251();
    auto story252 = Story252();
    auto story253 = Story253();
    auto story254 = Story254();
    auto story255 = Story255();
    auto story256 = Story256();
    auto story257 = Story257();
    auto story258 = Story258();
    auto story259 = Story259();
    auto story260 = Story260();
    auto story261 = Story261();
    auto story262 = Story262();
    auto story263 = Story263();
    auto story264 = Story264();
    auto story265 = Story265();
    auto story266 = Story266();
    auto story267 = Story267();
    auto story268 = Story268();
    auto story269 = Story269();
    auto story270 = Story270();
    auto story271 = Story271();
    auto story272 = Story272();
    auto event272 = Event272();
    auto story273 = Story273();
    auto event273 = Event273();
    auto story274 = Story274();
    auto story275 = Story275();
    auto story276 = Story276();
    auto story277 = Story277();
    auto story278 = Story278();
    auto story279 = Story279();
    auto story280 = Story280();
    auto story281 = Story281();
    auto story282 = Story282();
    auto story283 = Story283();
    auto story284 = Story284();
    auto story285 = Story285();
    auto story286 = Story286();
    auto story287 = Story287();
    auto story288 = Story288();
    auto story289 = Story289();
    auto story290 = Story290();
    auto story291 = Story291();
    auto story292 = Story292();
    auto story293 = Story293();
    auto story294 = Story294();
    auto story295 = Story295();
    auto story296 = Story296();
    auto story297 = Story297();
    auto story298 = Story298();
    auto story299 = Story299();
    auto story300 = Story300();
    auto story301 = Story301();
    auto story302 = Story302();
    auto story303 = Story303();
    auto story304 = Story304();
    auto story305 = Story305();
    auto story306 = Story306();
    auto story307 = Story307();
    auto story308 = Story308();
    auto story309 = Story309();
    auto story310 = Story310();
    auto story311 = Story311();
    auto story312 = Story312();
    auto story313 = Story313();
    auto story314 = Story314();
    auto story315 = Story315();
    auto story316 = Story316();
    auto event316 = Event316();
    auto story317 = Story317();
    auto story318 = Story318();
    auto story319 = Story319();
    auto story320 = Story320();
    auto story321 = Story321();
    auto story322 = Story322();
    auto story323 = Story323();
    auto story324 = Story324();
    auto event324 = Event324();
    auto story325 = Story325();
    auto story326 = Story326();
    auto story327 = Story327();
    auto story328 = Story328();
    auto story329 = Story329();
    auto story330 = Story330();
    auto story331 = Story331();
    auto story332 = Story332();
    auto story333 = Story333();
    auto story334 = Story334();
    auto story335 = Story335();
    auto story336 = Story336();
    auto story337 = Story337();
    auto story338 = Story338();
    auto story339 = Story339();
    auto story340 = Story340();
    auto story341 = Story341();
    auto story342 = Story342();
    auto story343 = Story343();
    auto event343 = Event343();
    auto story344 = Story344();
    auto story345 = Story345();
    auto story346 = Story346();
    auto story347 = Story347();
    auto story348 = Story348();
    auto story349 = Story349();
    auto story350 = Story350();
    auto story351 = Story351();
    auto story352 = Story352();
    auto story353 = Story353();
    auto story354 = Story354();
    auto story355 = Story355();
    auto story356 = Story356();
    auto story357 = Story357();
    auto story358 = Story358();
    auto story359 = Story359();
    auto story360 = Story360();
    auto story361 = Story361();
    auto story362 = Story362();
    auto story363 = Story363();
    auto story364 = Story364();
    auto story365 = Story365();
    auto story366 = Story366();
    auto story367 = Story367();
    auto story368 = Story368();
    auto story369 = Story369();
    auto story370 = Story370();
    auto story371 = Story371();
    auto story372 = Story372();
    auto story373 = Story373();
    auto story374 = Story374();
    auto story375 = Story375();
    auto story376 = Story376();
    auto story377 = Story377();
    auto story378 = Story378();
    auto story379 = Story379();
    auto story380 = Story380();
    auto story381 = Story381();
    auto story382 = Story382();
    auto story383 = Story383();
    auto story384 = Story384();
    auto story385 = Story385();
    auto story386 = Story386();
    auto story387 = Story387();
    auto story388 = Story388();
    auto event388 = Event388();
    auto story389 = Story389();
    auto story390 = Story390();
    auto story391 = Story391();
    auto story392 = Story392();
    auto story393 = Story393();
    auto story394 = Story394();
    auto story395 = Story395();
    auto story396 = Story396();
    auto story397 = Story397();
    auto event397 = Event397();
    auto story398 = Story398();
    auto story399 = Story399();
    auto story400 = Story400();
    auto event400 = Event400();
    auto story401 = Story401();
    auto story402 = Story402();
    auto story403 = Story403();
    auto story404 = Story404();
    auto story405 = Story405();
    auto story406 = Story406();
    auto event406 = Event406();
    auto story407 = Story407();
    auto story408 = Story408();
    auto event408 = Event408();
    auto story409 = Story409();
    auto story410 = Story410();
    auto story411 = Story411();
    auto story412 = Story412();
    auto story413 = Story413();
    auto story414 = Story414();
    auto story415 = Story415();
    auto story416 = Story416();
    auto story417 = Story417();
    auto story418 = Story418();
    auto story419 = Story419();
    auto story420 = Story420();
    auto story421 = Story421();
    auto story422 = Story422();
    auto story423 = Story423();
    auto story424 = Story424();
    auto story425 = Story425();
    auto story426 = Story426();
    auto story427 = Story427();
    auto story428 = Story428();
    auto story429 = Story429();
    auto story430 = Story430();
    auto story431 = Story431();
    auto story432 = Story432();
    auto story433 = Story433();
    auto story434 = Story434();
    auto story435 = Story435();
    auto story436 = Story436();
    auto story437 = Story437();
    auto story438 = Story438();
    auto story439 = Story439();
    auto story440 = Story440();
    auto story441 = Story441();
    auto story442 = Story442();
    auto story443 = Story443();
    auto story444 = Story444();
    auto story445 = Story445();
    auto story446 = Story446();
    auto story447 = Story447();
    auto story448 = Story448();
    auto story449 = Story449();
    auto story450 = Story450();
    auto story451 = Story451();
    auto story452 = Story452();
    auto story453 = Story453();
    auto story454 = Story454();
    auto story455 = Story455();
    auto story456 = Story456();
    auto story457 = Story457();
    auto story458 = Story458();
    auto story459 = Story459();
    auto story460 = Story460();
    auto story461 = Story461();
    auto story462 = Story462();
    auto story463 = Story463();
    auto story464 = Story464();
    auto story465 = Story465();
    auto story466 = Story466();
    auto event466 = Event466();
    auto story467 = Story467();
    auto story468 = Story468();
    auto story469 = Story469();
    auto story470 = Story470();
    auto story471 = Story471();
    auto story472 = Story472();
    auto story473 = Story473();
    auto story474 = Story474();
    auto story475 = Story475();
    auto story476 = Story476();
    auto story477 = Story477();
    auto story478 = Story478();
    auto story479 = Story479();
    auto story480 = Story480();
    auto story481 = Story481();
    auto story482 = Story482();
    auto story483 = Story483();
    auto story484 = Story484();
    auto story485 = Story485();
    auto story486 = Story486();
    auto story487 = Story487();
    auto story488 = Story488();
    auto story489 = Story489();
    auto story490 = Story490();
    auto story491 = Story491();
    auto story492 = Story492();
    auto story493 = Story493();
    auto story494 = Story494();
    auto story495 = Story495();
    auto story496 = Story496();
    auto story497 = Story497();
    auto story498 = Story498();
    auto story499 = Story499();
    auto story500 = Story500();
    auto story501 = Story501();
    auto story502 = Story502();
    auto story503 = Story503();
    auto story504 = Story504();
    auto event504 = Event504();
    auto story505 = Story505();
    auto story506 = Story506();
    auto story507 = Story507();
    auto story508 = Story508();
    auto story509 = Story509();
    auto event509 = Event509();
    auto story510 = Story510();
    auto story511 = Story511();
    auto story512 = Story512();
    auto story513 = Story513();
    auto story514 = Story514();
    auto story515 = Story515();
    auto story516 = Story516();
    auto story517 = Story517();
    auto story518 = Story518();
    auto story519 = Story519();
    auto story520 = Story520();
    auto story521 = Story521();
    auto story522 = Story522();
    auto story523 = Story523();
    auto story524 = Story524();
    auto story525 = Story525();
    auto story526 = Story526();
    auto story527 = Story527();
    auto story528 = Story528();
    auto story529 = Story529();
    auto event529 = Event529();
    auto story530 = Story530();
    auto story531 = Story531();
    auto story532 = Story532();
    auto story533 = Story533();
    auto story534 = Story534();
    auto story535 = Story535();
    auto story536 = Story536();
    auto story537 = Story537();
    auto event537 = Event537();
    auto story538 = Story538();
    auto story539 = Story539();
    auto story540 = Story540();
    auto story541 = Story541();
    auto event541 = Event541();
    auto story542 = Story542();
    auto story543 = Story543();
    auto story544 = Story544();
    auto story545 = Story545();
    auto event545 = Event545();
    auto story546 = Story546();
    auto story547 = Story547();
    auto story548 = Story548();
    auto story549 = Story549();
    auto story550 = Story550();
    auto story551 = Story551();
    auto story552 = Story552();
    auto story553 = Story553();
    auto story554 = Story554();
    auto story555 = Story555();
    auto story556 = Story556();
    auto story557 = Story557();
    auto story558 = Story558();
    auto event558 = Event558();
    auto story559 = Story559();
    auto story560 = Story560();
    auto story561 = Story561();
    auto story562 = Story562();
    auto story563 = Story563();
    auto story564 = Story564();
    auto story565 = Story565();
    auto story566 = Story566();
    auto story567 = Story567();
    auto story568 = Story568();
    auto story569 = Story569();
    auto story570 = Story570();
    auto event570 = Event570();
    auto story571 = Story571();
    auto story572 = Story572();
    auto story573 = Story573();
    auto e573_001 = E573_001();
    auto e573_002 = E573_002();
    auto story574 = Story574();
    auto story575 = Story575();
    auto event575 = Event575();
    auto story576 = Story576();
    auto story577 = Story577();
    auto story578 = Story578();
    auto story579 = Story579();
    auto story580 = Story580();
    auto event580 = Event580();
    auto story581 = Story581();
    auto story582 = Story582();
    auto story583 = Story583();
    auto story584 = Story584();
    auto story585 = Story585();
    auto story586 = Story586();
    auto story587 = Story587();
    auto story588 = Story588();
    auto story589 = Story589();
    auto event589 = Event589();
    auto story590 = Story590();
    auto story591 = Story591();
    auto story592 = Story592();
    auto story593 = Story593();
    auto story594 = Story594();
    auto story595 = Story595();
    auto story596 = Story596();
    auto story597 = Story597();
    auto event597 = Event597();
    auto story598 = Story598();
    auto story599 = Story599();
    auto story600 = Story600();
    auto story601 = Story601();
    auto story602 = Story602();
    auto story603 = Story603();
    auto story604 = Story604();
    auto story605 = Story605();
    auto story606 = Story606();
    auto story607 = Story607();
    auto story608 = Story608();
    auto story609 = Story609();
    auto story610 = Story610();
    auto story611 = Story611();
    auto story612 = Story612();
    auto story613 = Story613();
    auto story614 = Story614();
    auto story615 = Story615();
    auto story616 = Story616();
    auto story617 = Story617();
    auto event617 = Event617();
    auto story618 = Story618();
    auto story619 = Story619();
    auto story620 = Story620();
    auto story621 = Story621();
    auto story622 = Story622();
    auto story623 = Story623();
    auto story624 = Story624();
    auto story625 = Story625();
    auto story626 = Story626();
    auto event626 = Event626();
    auto story627 = Story627();
    auto story628 = Story628();
    auto story629 = Story629();
    auto story630 = Story630();
    auto story631 = Story631();
    auto story632 = Story632();
    auto story633 = Story633();
    auto story634 = Story634();
    auto story635 = Story635();
    auto story636 = Story636();
    auto story637 = Story637();
    auto story638 = Story638();
    auto story639 = Story639();
    auto event639 = Event639();
    auto story640 = Story640();
    auto story641 = Story641();
    auto story642 = Story642();
    auto story643 = Story643();
    auto story644 = Story644();
    auto story645 = Story645();
    auto story646 = Story646();
    auto story647 = Story647();
    auto story648 = Story648();
    auto story649 = Story649();
    auto story650 = Story650();
    auto story651 = Story651();
    auto story652 = Story652();
    auto story653 = Story653();
    auto story654 = Story654();
    auto story655 = Story655();
    auto story656 = Story656();
    auto story657 = Story657();
    auto event657 = Event657();
    auto story658 = Story658();
    auto story659 = Story659();
    auto story660 = Story660();
    auto story661 = Story661();
    auto story662 = Story662();
    auto story663 = Story663();
    auto story664 = Story664();
    auto story665 = Story665();
    auto story666 = Story666();
    auto event666 = Event666();
    auto story667 = Story667();
    auto story668 = Story668();
    auto story669 = Story669();
    auto story670 = Story670();
    auto story671 = Story671();
    auto story672 = Story672();
    auto story673 = Story673();
    auto story674 = Story674();
    auto story675 = Story675();
    auto story676 = Story676();
    auto event676 = Event676();
    auto story677 = Story677();
    auto story678 = Story678();
    auto story679 = Story679();
    auto story680 = Story680();
    auto story681 = Story681();
    auto story682 = Story682();
    auto story683 = Story683();
    auto story684 = Story684();
    auto story685 = Story685();
    auto story686 = Story686();
    auto story687 = Story687();
    auto story688 = Story688();
    auto story689 = Story689();
    auto story690 = Story690();
    auto event690 = Event690();
    auto story691 = Story691();
    auto story692 = Story692();
    auto event692 = Event692();
    auto story693 = Story693();
    auto story694 = Story694();
    auto story695 = Story695();
    auto story696 = Story696();
    auto story697 = Story697();
    auto story698 = Story698();
    auto story699 = Story699();
    auto story700 = Story700();
    auto story701 = Story701();
    auto story702 = Story702();
    auto story703 = Story703();
    auto story704 = Story704();
    auto story705 = Story705();
    auto story706 = Story706();
    auto story707 = Story707();
    auto story708 = Story708();
    auto story709 = Story709();
    auto story710 = Story710();
    auto story711 = Story711();
    auto story712 = Story712();
    auto story713 = Story713();
    auto story714 = Story714();
    auto story715 = Story715();
    auto story716 = Story716();
    auto story717 = Story717();
    auto story718 = Story718();
    auto story719 = Story719();
    auto story720 = Story720();
    auto story721 = Story721();
    auto story722 = Story722();
    auto story723 = Story723();
    auto story724 = Story724();
    auto story725 = Story725();
    auto event725 = Event725();
    auto story726 = Story726();
    auto story727 = Story727();
    auto story728 = Story728();
    auto story729 = Story729();
    auto story730 = Story730();
    auto story731 = Story731();
    auto story732 = Story732();
    auto story733 = Story733();
    auto story734 = Story734();
    auto story735 = Story735();
    auto story736 = Story736();
    auto story737 = Story737();
    auto story738 = Story738();
    auto story739 = Story739();
    auto story740 = Story740();
    auto story741 = Story741();
    auto story742 = Story742();
    auto story743 = Story743();
    auto story744 = Story744();
    auto event744 = Event744();
    auto story745 = Story745();
    auto story746 = Story746();
    auto story747 = Story747();
    auto story748 = Story748();
    auto story749 = Story749();

    void InitializeStories()
    {
        Book1::Stories = {
            &event018, &event027, &event028, &event044, &event067, &event073, &event076, &event078, &e087_001, &e087_002,
            &e087_003, &event089, &event098, &event102, &e115_001, &e115_002, &e128_001, &e128_002, &event160, &event183,
            &event186, &event188, &event202, &event207, &event223, &event224, &event272, &event273, &event316, &event324,
            &event343, &event388, &event397, &event400, &event406, &event408, &event466, &event504, &event509, &event529,
            &event537, &event541, &event545, &event558, &event570, &e573_001, &e573_002, &event575, &event580, &event589,
            &event597, &event617, &event626, &event639, &event657, &event666, &event676, &event690, &event692, &event725,
            &event744,
            &story001, &story002, &story003, &story004, &story005, &story006, &story007, &story008, &story009,
            &story010, &story011, &story012, &story013, &story014, &story015, &story016, &story017, &story018, &story019,
            &story020, &story021, &story022, &story023, &story024, &story025, &story026, &story027, &story028, &story029,
            &story030, &story031, &story032, &story033, &story034, &story035, &story036, &story037, &story038, &story039,
            &story040, &story041, &story042, &story043, &story044, &story045, &story046, &story047, &story048, &story049,
            &story050, &story051, &story052, &story053, &story054, &story055, &story056, &story057, &story058, &story059,
            &story060, &story061, &story062, &story063, &story064, &story065, &story066, &story067, &story068, &story069,
            &story070, &story071, &story072, &story073, &story074, &story075, &story076, &story077, &story078, &story079,
            &story080, &story081, &story082, &story083, &story084, &story085, &story086, &story087, &story088, &story089,
            &story090, &story091, &story092, &story093, &story094, &story095, &story096, &story097, &story098, &story099,
            &story100, &story101, &story102, &story103, &story104, &story105, &story106, &story107, &story108, &story109,
            &story110, &story111, &story112, &story113, &story114, &story115, &story116, &story117, &story118, &story119,
            &story120, &story121, &story122, &story123, &story124, &story125, &story126, &story127, &story128, &story129,
            &story130, &story131, &story132, &story133, &story134, &story135, &story136, &story137, &story138, &story139,
            &story140, &story141, &story142, &story143, &story144, &story145, &story146, &story147, &story148, &story149,
            &story150, &story151, &story152, &story153, &story154, &story155, &story156, &story157, &story158, &story159,
            &story160, &story161, &story162, &story163, &story164, &story165, &story166, &story167, &story168, &story169,
            &story170, &story171, &story172, &story173, &story174, &story175, &story176, &story177, &story178, &story179,
            &story180, &story181, &story182, &story183, &story184, &story185, &story186, &story187, &story188, &story189,
            &story190, &story191, &story192, &story193, &story194, &story195, &story196, &story197, &story198, &story199,
            &story200, &story201, &story202, &story203, &story204, &story205, &story206, &story207, &story208, &story209,
            &story210, &story211, &story212, &story213, &story214, &story215, &story216, &story217, &story218, &story219,
            &story220, &story221, &story222, &story223, &story224, &story225, &story226, &story227, &story228, &story229,
            &story230, &story231, &story232, &story233, &story234, &story235, &story236, &story237, &story238, &story239,
            &story240, &story241, &story242, &story243, &story244, &story245, &story246, &story247, &story248, &story249,
            &story250, &story251, &story252, &story253, &story254, &story255, &story256, &story257, &story258, &story259,
            &story260, &story261, &story262, &story263, &story264, &story265, &story266, &story267, &story268, &story269,
            &story270, &story271, &story272, &story273, &story274, &story275, &story276, &story277, &story278, &story279,
            &story280, &story281, &story282, &story283, &story284, &story285, &story286, &story287, &story288, &story289,
            &story290, &story291, &story292, &story293, &story294, &story295, &story296, &story297, &story298, &story299,
            &story300, &story301, &story302, &story303, &story304, &story305, &story306, &story307, &story308, &story309,
            &story310, &story311, &story312, &story313, &story314, &story315, &story316, &story317, &story318, &story319,
            &story320, &story321, &story322, &story323, &story324, &story325, &story326, &story327, &story328, &story329,
            &story330, &story331, &story332, &story333, &story334, &story335, &story336, &story337, &story338, &story339,
            &story340, &story341, &story342, &story343, &story344, &story345, &story346, &story347, &story348, &story349,
            &story350, &story351, &story352, &story353, &story354, &story355, &story356, &story357, &story358, &story359,
            &story360, &story361, &story362, &story363, &story364, &story365, &story366, &story367, &story368, &story369,
            &story370, &story371, &story372, &story373, &story374, &story375, &story376, &story377, &story378, &story379,
            &story380, &story381, &story382, &story383, &story384, &story385, &story386, &story387, &story388, &story389,
            &story390, &story391, &story392, &story393, &story394, &story395, &story396, &story397, &story398, &story399,
            &story400, &story401, &story402, &story403, &story404, &story405, &story406, &story407, &story408, &story409,
            &story410, &story411, &story412, &story413, &story414, &story415, &story416, &story417, &story418, &story419,
            &story420, &story421, &story422, &story423, &story424, &story425, &story426, &story427, &story428, &story429,
            &story430, &story431, &story432, &story433, &story434, &story435, &story436, &story437, &story438, &story439,
            &story440, &story441, &story442, &story443, &story444, &story445, &story446, &story447, &story448, &story449,
            &story450, &story451, &story452, &story453, &story454, &story455, &story456, &story457, &story458, &story459,
            &story460, &story461, &story462, &story463, &story464, &story465, &story466, &story467, &story468, &story469,
            &story470, &story471, &story472, &story473, &story474, &story475, &story476, &story477, &story478, &story479,
            &story480, &story481, &story482, &story483, &story484, &story485, &story486, &story487, &story488, &story489,
            &story490, &story491, &story492, &story493, &story494, &story495, &story496, &story497, &story498, &story499,
            &story500, &story501, &story502, &story503, &story504, &story505, &story506, &story507, &story508, &story509,
            &story510, &story511, &story512, &story513, &story514, &story515, &story516, &story517, &story518, &story519,
            &story520, &story521, &story522, &story523, &story524, &story525, &story526, &story527, &story528, &story529,
            &story530, &story531, &story532, &story533, &story534, &story535, &story536, &story537, &story538, &story539,
            &story540, &story541, &story542, &story543, &story544, &story545, &story546, &story547, &story548, &story549,
            &story550, &story551, &story552, &story553, &story554, &story555, &story556, &story557, &story558, &story559,
            &story560, &story561, &story562, &story563, &story564, &story565, &story566, &story567, &story568, &story569,
            &story570, &story571, &story572, &story573, &story574, &story575, &story576, &story577, &story578, &story579,
            &story580, &story581, &story582, &story583, &story584, &story585, &story586, &story587, &story588, &story589,
            &story590, &story591, &story592, &story593, &story594, &story595, &story596, &story597, &story598, &story599,
            &story600, &story601, &story602, &story603, &story604, &story605, &story606, &story607, &story608, &story609,
            &story610, &story611, &story612, &story613, &story614, &story615, &story616, &story617, &story618, &story619,
            &story620, &story621, &story622, &story623, &story624, &story625, &story626, &story627, &story628, &story629,
            &story630, &story631, &story632, &story633, &story634, &story635, &story636, &story637, &story638, &story639,
            &story640, &story641, &story642, &story643, &story644, &story645, &story646, &story647, &story648, &story649,
            &story650, &story651, &story652, &story653, &story654, &story655, &story656, &story657, &story658, &story659,
            &story660, &story661, &story662, &story663, &story664, &story665, &story666, &story667, &story668, &story669,
            &story670, &story671, &story672, &story673, &story674, &story675, &story676, &story677, &story678, &story679,
            &story680, &story681, &story682, &story683, &story684, &story685, &story686, &story687, &story688, &story689,
            &story690, &story691, &story692, &story693, &story694, &story695, &story696, &story697, &story698, &story699,
            &story700, &story701, &story702, &story703, &story704, &story705, &story706, &story707, &story708, &story709,
            &story710, &story711, &story712, &story713, &story714, &story715, &story716, &story717, &story718, &story719,
            &story720, &story721, &story722, &story723, &story724, &story725, &story726, &story727, &story728, &story729,
            &story730, &story731, &story732, &story733, &story734, &story735, &story736, &story737, &story738, &story739,
            &story740, &story741, &story742, &story743, &story744, &story745, &story746, &story747, &story748, &story749};
    }
}
#endif
