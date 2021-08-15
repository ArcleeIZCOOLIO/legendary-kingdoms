#ifndef __STORY__HPP__
#define __STORY__HPP__

#include <tuple>
#include <vector>

#include "constants.hpp"
#include "controls.hpp"
#include "codes.hpp"
#include "equipment.hpp"
#include "attribute.hpp"
#include "character.hpp"
#include "monster.hpp"
#include "engine.hpp"

namespace Choice
{
    enum class Type
    {
        NORMAL = 0, // No requirements
        EQUIPMENT,
        ANY_EQUIPMENT,
        GET_EQUIPMENT,
        GET_EQUIPMENT_CODE,
        LOSE_EQUIPMENT,
        LIMIT_EQUIPMENT,
        MONEY,
        GAIN_MONEY,
        LIFE,
        LOSE_LIFE,
        ATTRIBUTES,
        LAST_CHARACTER,
        TEAM_ATTRIBUTES,
        LOSE_ATTRIBUTES,
        LOSE_ALL,
        CODES,
        GET_CODES,
        LOSE_CODES,
        BRIBE,
        PAY_WITH,
        SELL,
        BARTER,
        SHIP,
        ADD_MAX_HEALTH,
        TEAM_MAX_HEALTH,
        GAIN_HEALTH,
        BRIBE_CODEWORD,
        LASTCHARACTER_ROLLS_FOR_ATTRIBUTEINCREASE,
        ROLL_FOR_ATTRIBUTE_INCREASE,
        ROLL_ATTRIBUTE_WITH_STATUS,
        RAISE_ATTRIBUTE_SCORE,
        PARTY_RAISE_ATTRIBUTE,
        PARTY_RAISE_HEALTH,
        RANDOM_EVENT,
        CHOOSE_PARTY_MEMBER,
        RETREAT,
        DELIVER,
        SET_STATUS_FROM_LIST,
        HAS_STATUS,
        ASSIGN_TEAMS,
        RAISE_LOWEST_ATTRIBUTE,
        LAST_INDIVIDUAL_CHECK,
        LAST_PARTY_CHECK,
        RAISEATTRIBUTE_WITH_BLESSING,
        PAYFORBLESSING_WITH_ITEM,
        PAYFORSTATUS_WITH_HEALTH,
        GAIN_HEALTH_ATTRIBUTE,
        GAIN_MORALE,
        SET_PARTY_ORDER,
        ORDER_SKILL_CHECK,
        RESET_SHOP,
        CHOOSE_CHARACTER_EXCEPT,
        EVERYONE_SKILL_CHECKS,
        GAIN_HEART,
        SAIL
    };

    class Base
    {
    public:
        const char *Text = NULL;

        Choice::Type Type = Choice::Type::NORMAL;

        Engine::Destination Destination = {Book::Type::NONE, -1};

        Engine::Destination DestinationFailed = {Book::Type::NONE, -1};

        std::vector<Attribute::Type> Attributes = std::vector<Attribute::Type>();

        std::vector<Equipment::Base> Equipment = std::vector<Equipment::Base>();

        std::vector<Codes::Base> Codes = std::vector<Codes::Base>();

        std::vector<Codes::Type> InvisibleCodes = std::vector<Codes::Type>();

        std::vector<Engine::RandomDestination> RandomDestinations = {};

        std::vector<Character::Status> Status = {};

        std::vector<Engine::TeamAssignment> Teams = {};

        std::vector<Cargo::Type> Delivery = {};

        Location::Type Location = Location::Type::NONE;

        Team::Type Team = Team::Type::NONE;

        Character::Type Character = Character::Type::NONE;

        Character::Type SecondCharacter = Character::Type::NONE;

        int Value = 0;

        int Difficulty = 0;

        int Success = 0;

        // Use in Skill checks involving Fighting skill
        bool UseWeapon = true;

        Base(const char *text, Engine::Destination destination)
        {
            Text = text;

            Destination = destination;

            Type = Choice::Type::NORMAL;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type)
        {
            Text = text;

            Destination = destination;

            Type = type;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, Team::Type team)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Team = team;
        }

        Base(const char *text, Engine::Destination destination, std::vector<Equipment::Base> equipment)
        {
            Text = text;

            Destination = destination;

            Equipment = equipment;

            Type = Choice::Type::EQUIPMENT;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Equipment::Base> equipment)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Equipment = equipment;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Equipment::Base> equipment, std::vector<Codes::Base> codes, std::vector<Codes::Type> invisibleCodes)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Equipment = equipment;

            Codes = codes;

            InvisibleCodes = invisibleCodes;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Equipment::Base> equipment, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Equipment = equipment;

            Value = value;
        }

        Base(const char *text, Engine::Destination destination, Engine::Destination destinationFailed, Team::Type team, std::vector<Attribute::Type> attributes, int difficulty, int success)
        {
            Text = text;

            Destination = destination;

            DestinationFailed = destinationFailed;

            Team = team;

            Attributes = attributes;

            Difficulty = difficulty;

            Success = success;

            Type = Choice::Type::ATTRIBUTES;
        }

        Base(const char *text, Engine::Destination destination, Engine::Destination destinationFailed, Team::Type team, std::vector<Attribute::Type> attributes, int difficulty, int success, bool useWeapon)
        {
            Text = text;

            Destination = destination;

            DestinationFailed = destinationFailed;

            Team = team;

            Attributes = attributes;

            Difficulty = difficulty;

            Success = success;

            UseWeapon = useWeapon;

            Type = Choice::Type::ATTRIBUTES;
        }

        Base(const char *text, Engine::Destination destination, Engine::Destination destinationFailed, std::vector<Attribute::Type> attributes, int difficulty, int success)
        {
            Text = text;

            Destination = destination;

            DestinationFailed = destinationFailed;

            Attributes = attributes;

            Difficulty = difficulty;

            Success = success;

            Type = Choice::Type::ATTRIBUTES;
        }

        Base(const char *text, Engine::Destination destination, Engine::Destination destinationFailed, std::vector<Attribute::Type> attributes, int difficulty, int success, bool useWeapon)
        {
            Text = text;

            Destination = destination;

            DestinationFailed = destinationFailed;

            Attributes = attributes;

            Difficulty = difficulty;

            Success = success;

            UseWeapon = useWeapon;

            Type = Choice::Type::ATTRIBUTES;
        }

        Base(const char *text, Engine::Destination destination, Engine::Destination destinationFailed, Choice::Type type, std::vector<Attribute::Type> attributes, int difficulty, int success)
        {
            Text = text;

            Destination = destination;

            DestinationFailed = destinationFailed;

            Type = type;

            Attributes = attributes;

            Difficulty = difficulty;

            Success = success;
        }

        Base(const char *text, Engine::Destination destination, Engine::Destination destinationFailed, Choice::Type type, std::vector<Attribute::Type> attributes, int difficulty, int success, bool useWeapon)
        {
            Text = text;

            Destination = destination;

            DestinationFailed = destinationFailed;

            Type = type;

            Attributes = attributes;

            Difficulty = difficulty;

            Success = success;

            UseWeapon = useWeapon;
        }

        Base(const char *text, Engine::Destination destination, Engine::Destination destinationFailed, Choice::Type type, Team::Type team, std::vector<Attribute::Type> attributes, int difficulty, int success)
        {
            Text = text;

            Destination = destination;

            DestinationFailed = destinationFailed;

            Type = type;

            Team = team;

            Attributes = attributes;

            Difficulty = difficulty;

            Success = success;
        }

        Base(const char *text, Engine::Destination destination, Engine::Destination destinationFailed, Choice::Type type, Team::Type team, std::vector<Attribute::Type> attributes, int difficulty, int success, bool useWeapon)
        {
            Text = text;

            Destination = destination;

            DestinationFailed = destinationFailed;

            Type = type;

            Team = team;

            Attributes = attributes;

            Difficulty = difficulty;

            Success = success;

            UseWeapon = useWeapon;
        }

        Base(const char *text, Engine::Destination destination, std::vector<Codes::Base> codes)
        {
            Text = text;

            Destination = destination;

            Codes = codes;

            Type = Choice::Type::CODES;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Codes::Base> codes)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Codes = codes;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Codes::Type> codes)
        {
            Text = text;

            Destination = destination;

            Type = type;

            InvisibleCodes = codes;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Value = value;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Equipment::Base> equipment, std::vector<Codes::Type> codes, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Equipment = equipment;

            InvisibleCodes = codes;

            Value = value;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Attribute::Type> attributes, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Attributes = attributes;

            Value = value;
        }

        Base(const char *text, std::vector<Engine::RandomDestination> destinations, int value)
        {
            Text = text;

            RandomDestinations = destinations;

            Value = value;

            Type = Choice::Type::RANDOM_EVENT;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, Location::Type location, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Location = location;

            Value = value;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, Location::Type location)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Location = location;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Cargo::Type> delivery, Location::Type location, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Delivery = delivery;

            Location = location;

            Value = value;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Character::Status> status)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Status = status;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Character::Status> status, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Status = status;

            Value = value;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Engine::TeamAssignment> teams)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Teams = teams;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Engine::TeamAssignment> teams, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Teams = teams;

            Value = value;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Attribute::Type> attributes, int value, int difficulty, int success)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Attributes = attributes;

            Value = value;

            Difficulty = difficulty;

            Success = success;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, Team::Type team, std::vector<Attribute::Type> attributes, int value, int difficulty, int success)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Team = team;

            Attributes = attributes;

            Value = value;

            Difficulty = difficulty;

            Success = success;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Equipment::Base> equipment, std::vector<Attribute::Type> attributes, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Equipment = equipment;

            Attributes = attributes;

            Value = value;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, int value, int success)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Value = value;

            Success = success;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, Location::Type location, int value, int success)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Location = location;

            Value = value;

            Success = success;
        }

        Base(const char *text, Engine::Destination destination, Engine::Destination destinationFailed, Choice::Type type, int value, std::vector<Attribute::Type> attributes, int difficulty, int success)
        {
            Text = text;

            Destination = destination;

            DestinationFailed = destinationFailed;

            Type = type;

            Value = value;

            Attributes = attributes;

            Difficulty = difficulty;

            Success = success;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Character::Status> status, std::vector<Attribute::Type> attributes, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Status = status;

            Attributes = attributes;

            Value = value;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, std::vector<Character::Status> status, std::vector<Attribute::Type> attributes, int value, int difficulty, int success)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Status = status;

            Attributes = attributes;

            Value = value;

            Difficulty = difficulty;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, Character::Type character)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Character = character;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, Character::Type character, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Character = character;

            Value = value;
        }

        Base(const char *text, Engine::Destination destination, Choice::Type type, Character::Type character, Character::Type secondCharacter, int value)
        {
            Text = text;

            Destination = destination;

            Type = type;

            Character = character;

            SecondCharacter = secondCharacter;

            Value = value;
        }
    };

} // namespace Choice

namespace Story
{
    enum class Type
    {
        NORMAL = 0,
        DOOM
    };

    enum class Controls
    {
        NONE = 0,
        STANDARD,
        SHOP,
        BARTER,
        HARBOUR,
        INN,
        RECRUIT
    };

    class Base
    {
    public:
        Location::Type Location = Location::Type::NONE;

        bool IsCity = false;

        Book::Type BookID = Book::Type::NONE;

        int ID = -1;

        int DisplayID = -1;

        const char *Text = NULL;

        const char *Title = NULL;

        const char *Bye = NULL;

        const char *Image = NULL;

        Story::Type Type = Story::Type::NORMAL;

        Team::Type Team = Team::Type::NONE;

        Story::Controls Controls = Story::Controls::NONE;

        std::vector<Choice::Base> Choices = {};
        std::vector<Engine::EquipmentPrice> Shop = {};
        std::vector<Engine::BarterExchanges> Barter = {};

        // Player selects items to take up to a certain limit
        std::vector<Equipment::Base> Take = {};

        // Player selects spells to learn
        std::vector<Spells::Base> Spells = {};

        // Player selects units to add to army
        std::vector<Army::Base> Army = {};

        // Player selects items to lose
        std::vector<Equipment::Base> ToLose = {};

        // Combat encounters
        std::vector<Monster::Base> Monsters = {};
        std::vector<Ship::Base> EnemyFleet = {};
        int FleeRound = -1;
        int RoundLimit = -1;
        bool CanFlee = false;

        std::vector<Allies::Type> Allies = {};

        // Limits
        int Limit = 0;

        // Harbour
        std::vector<Engine::ShipPrices> Ships = {};
        std::vector<Engine::CargoPrices> Cargo = {};
        int ShipRepairPrice = -1;

        // Inn Defaults
        int RestPrice = -1;
        int CanRecharge = false;

        // Mass Combat Enemy Troops
        std::vector<Army::Base> EnemyArmy = {};
        std::vector<Engine::BattlefieldSpells> EnemySpells = {};
        std::vector<Engine::ArmyStatus> EnemyArmyStatus = {};
        Location::Type BattleLocation = Location::Type::NONE;

        // temporary string
        std::string temp_string = "";

        bool ResetShop = false;

        // Handle background events
        virtual Engine::Destination Background(Party::Base &party) { return {Book::Type::NONE, -1}; };

        // Handle events before story branches
        virtual void Event(Party::Base &party){};

        // Jump to next book/section
        virtual Engine::Destination Continue(Party::Base &party) { return {Book::Type::NONE, -1}; };

        // Callbacks
        virtual void SkillCheck(Party::Base &party, bool outcome, std::vector<int> selection){};
        virtual void AfterCombat(Party::Base &party, Engine::Combat result){};

        Base()
        {
        }

        Base(int id)
        {
            ID = id;
        }

        Base(int id, const char *text, Story::Type type)
        {
            ID = id;
            Text = text;
            Type = type;
        }

        Base(const char *text, Story::Type type)
        {
            Text = text;
            Type = type;
        }
    };

    std::vector<Button> StandardControls(bool compact = false)
    {
        auto idx = 0;

        auto controls = std::vector<Button>();

        if (!compact)
        {
            controls.push_back(Button(0, "icons/up-arrow.png", 0, 1, 0, 1, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + border_space, Control::Type::SCROLL_UP));
            controls.push_back(Button(1, "icons/down-arrow.png", 0, 2, 0, 2, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + text_bounds - arrow_size - border_space, Control::Type::SCROLL_DOWN));

            idx = 2;
        }

        controls.push_back(Button(idx, "icons/map.png", idx, idx + 1, compact ? idx : 1, idx, startx, buttony, Control::Type::MAP));
        controls.push_back(Button(idx + 1, "icons/disk.png", idx, idx + 2, compact ? idx + 1 : 1, idx + 1, startx + gridsize, buttony, Control::Type::GAME));
        controls.push_back(Button(idx + 2, "icons/user.png", idx + 1, idx + 3, compact ? idx + 2 : 1, idx + 2, startx + 2 * gridsize, buttony, Control::Type::PARTY));
        controls.push_back(Button(idx + 3, "icons/next.png", idx + 2, idx + 4, compact ? idx + 3 : 1, idx + 3, startx + 3 * gridsize, buttony, Control::Type::NEXT));
        controls.push_back(Button(idx + 4, "icons/exit.png", idx + 3, idx + 4, compact ? idx + 4 : 1, idx + 4, (1.0 - Margin) * SCREEN_WIDTH - buttonw, buttony, Control::Type::BACK));

        return controls;
    }

    std::vector<Button> ShopControls(bool compact = false)
    {
        auto idx = 0;

        auto controls = std::vector<Button>();

        if (!compact)
        {
            controls.push_back(Button(0, "icons/up-arrow.png", 0, 1, 0, 1, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + border_space, Control::Type::SCROLL_UP));
            controls.push_back(Button(1, "icons/down-arrow.png", 0, 2, 0, 2, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + text_bounds - arrow_size - border_space, Control::Type::SCROLL_DOWN));

            idx = 2;
        }

        controls.push_back(Button(idx, "icons/map.png", idx, idx + 1, compact ? idx : 1, idx, startx, buttony, Control::Type::MAP));
        controls.push_back(Button(idx + 1, "icons/disk.png", idx, idx + 2, compact ? idx + 1 : 1, idx + 1, startx + gridsize, buttony, Control::Type::GAME));
        controls.push_back(Button(idx + 2, "icons/user.png", idx + 1, idx + 3, compact ? idx + 2 : 1, idx + 2, startx + 2 * gridsize, buttony, Control::Type::PARTY));
        controls.push_back(Button(idx + 3, "icons/shop.png", idx + 2, idx + 4, compact ? idx + 3 : 1, idx + 3, startx + 3 * gridsize, buttony, Control::Type::SHOP));
        controls.push_back(Button(idx + 4, "icons/next.png", idx + 3, idx + 5, compact ? idx + 4 : 1, idx + 4, startx + 4 * gridsize, buttony, Control::Type::NEXT));
        controls.push_back(Button(idx + 5, "icons/exit.png", idx + 4, idx + 5, compact ? idx + 5 : 1, idx + 5, (1.0 - Margin) * SCREEN_WIDTH - buttonw, buttony, Control::Type::BACK));

        return controls;
    }

    std::vector<Button> BarterControls(bool compact = false)
    {
        auto idx = 0;

        auto controls = std::vector<Button>();

        if (!compact)
        {
            controls.push_back(Button(0, "icons/up-arrow.png", 0, 1, 0, 1, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + border_space, Control::Type::SCROLL_UP));
            controls.push_back(Button(1, "icons/down-arrow.png", 0, 2, 0, 2, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + text_bounds - arrow_size - border_space, Control::Type::SCROLL_DOWN));

            idx = 2;
        }

        controls.push_back(Button(idx, "icons/map.png", idx, idx + 1, compact ? idx : 1, idx, startx, buttony, Control::Type::MAP));
        controls.push_back(Button(idx + 1, "icons/disk.png", idx, idx + 2, compact ? idx + 1 : 1, idx + 1, startx + gridsize, buttony, Control::Type::GAME));
        controls.push_back(Button(idx + 2, "icons/user.png", idx + 1, idx + 3, compact ? idx + 2 : 1, idx + 2, startx + 2 * gridsize, buttony, Control::Type::PARTY));
        controls.push_back(Button(idx + 3, "icons/exchange.png", idx + 2, idx + 4, compact ? idx + 3 : 1, idx + 3, startx + 3 * gridsize, buttony, Control::Type::BARTER));
        controls.push_back(Button(idx + 4, "icons/next.png", idx + 3, idx + 5, compact ? idx + 4 : 1, idx + 4, startx + 4 * gridsize, buttony, Control::Type::NEXT));
        controls.push_back(Button(idx + 5, "icons/exit.png", idx + 4, idx + 5, compact ? idx + 5 : 1, idx + 5, (1.0 - Margin) * SCREEN_WIDTH - buttonw, buttony, Control::Type::BACK));

        return controls;
    }

    std::vector<Button> HarbourControls(bool compact = false)
    {
        auto idx = 0;

        auto controls = std::vector<Button>();

        if (!compact)
        {
            controls.push_back(Button(0, "icons/up-arrow.png", 0, 1, 0, 1, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + border_space, Control::Type::SCROLL_UP));
            controls.push_back(Button(1, "icons/down-arrow.png", 0, 2, 0, 2, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + text_bounds - arrow_size - border_space, Control::Type::SCROLL_DOWN));

            idx = 2;
        }

        controls.push_back(Button(idx, "icons/map.png", idx, idx + 1, compact ? idx : 1, idx, startx, buttony, Control::Type::MAP));
        controls.push_back(Button(idx + 1, "icons/disk.png", idx, idx + 2, compact ? idx + 1 : 1, idx + 1, startx + gridsize, buttony, Control::Type::GAME));
        controls.push_back(Button(idx + 2, "icons/user.png", idx + 1, idx + 3, compact ? idx + 2 : 1, idx + 2, startx + 2 * gridsize, buttony, Control::Type::PARTY));
        controls.push_back(Button(idx + 3, "icons/anchors.png", idx + 2, idx + 4, compact ? idx + 3 : 1, idx + 3, startx + 3 * gridsize, buttony, Control::Type::HARBOUR));
        controls.push_back(Button(idx + 4, "icons/next.png", idx + 3, idx + 5, compact ? idx + 4 : 1, idx + 4, startx + 4 * gridsize, buttony, Control::Type::NEXT));
        controls.push_back(Button(idx + 5, "icons/exit.png", idx + 4, idx + 5, compact ? idx + 5 : 1, idx + 5, (1.0 - Margin) * SCREEN_WIDTH - buttonw, buttony, Control::Type::BACK));

        return controls;
    }

    std::vector<Button> InnControls(bool compact = false)
    {
        auto idx = 0;

        auto controls = std::vector<Button>();

        if (!compact)
        {
            controls.push_back(Button(0, "icons/up-arrow.png", 0, 1, 0, 1, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + border_space, Control::Type::SCROLL_UP));
            controls.push_back(Button(1, "icons/down-arrow.png", 0, 2, 0, 2, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + text_bounds - arrow_size - border_space, Control::Type::SCROLL_DOWN));

            idx = 2;
        }

        controls.push_back(Button(idx, "icons/map.png", idx, idx + 1, compact ? idx : 1, idx, startx, buttony, Control::Type::MAP));
        controls.push_back(Button(idx + 1, "icons/disk.png", idx, idx + 2, compact ? idx + 1 : 1, idx + 1, startx + gridsize, buttony, Control::Type::GAME));
        controls.push_back(Button(idx + 2, "icons/user.png", idx + 1, idx + 3, compact ? idx + 2 : 1, idx + 2, startx + 2 * gridsize, buttony, Control::Type::PARTY));
        controls.push_back(Button(idx + 3, "icons/inn.png", idx + 2, idx + 4, compact ? idx + 3 : 1, idx + 3, startx + 3 * gridsize, buttony, Control::Type::INN));
        controls.push_back(Button(idx + 4, "icons/next.png", idx + 3, idx + 5, compact ? idx + 4 : 1, idx + 4, startx + 4 * gridsize, buttony, Control::Type::NEXT));
        controls.push_back(Button(idx + 5, "icons/exit.png", idx + 4, idx + 5, compact ? idx + 5 : 1, idx + 5, (1.0 - Margin) * SCREEN_WIDTH - buttonw, buttony, Control::Type::BACK));

        return controls;
    }

    std::vector<Button> RecruitmentConrols(bool compact = false)
    {
        auto idx = 0;

        auto controls = std::vector<Button>();

        if (!compact)
        {
            controls.push_back(Button(0, "icons/up-arrow.png", 0, 1, 0, 1, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + border_space, Control::Type::SCROLL_UP));
            controls.push_back(Button(1, "icons/down-arrow.png", 0, 2, 0, 2, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + text_bounds - arrow_size - border_space, Control::Type::SCROLL_DOWN));

            idx = 2;
        }

        controls.push_back(Button(idx, "icons/map.png", idx, idx + 1, compact ? idx : 1, idx, startx, buttony, Control::Type::MAP));
        controls.push_back(Button(idx + 1, "icons/disk.png", idx, idx + 2, compact ? idx + 1 : 1, idx + 1, startx + gridsize, buttony, Control::Type::GAME));
        controls.push_back(Button(idx + 2, "icons/user.png", idx + 1, idx + 3, compact ? idx + 2 : 1, idx + 2, startx + 2 * gridsize, buttony, Control::Type::PARTY));
        controls.push_back(Button(idx + 3, "icons/interaction.png", idx + 2, idx + 4, compact ? idx + 3 : 1, idx + 3, startx + 3 * gridsize, buttony, Control::Type::RECRUIT));
        controls.push_back(Button(idx + 4, "icons/next.png", idx + 3, idx + 5, compact ? idx + 4 : 1, idx + 4, startx + 4 * gridsize, buttony, Control::Type::NEXT));
        controls.push_back(Button(idx + 5, "icons/exit.png", idx + 4, idx + 5, compact ? idx + 5 : 1, idx + 5, (1.0 - Margin) * SCREEN_WIDTH - buttonw, buttony, Control::Type::BACK));

        return controls;
    }

    std::vector<Button> ExitControls(bool compact = false)
    {
        auto idx = 0;

        auto controls = std::vector<Button>();

        if (!compact)
        {
            controls.push_back(Button(0, "icons/up-arrow.png", 0, 1, 0, 1, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + border_space, Control::Type::SCROLL_UP));
            controls.push_back(Button(1, "icons/down-arrow.png", 0, 2, 0, 2, (1.0 - Margin) * SCREEN_WIDTH - arrow_size, texty + text_bounds - arrow_size - border_space, Control::Type::SCROLL_DOWN));

            idx = 2;
        }

        controls.push_back(Button(idx, "icons/exit.png", compact ? idx : idx - 1, idx, compact ? idx : idx - 1, idx, (1.0 - Margin) * SCREEN_WIDTH - buttonw, buttony, Control::Type::BACK));

        return controls;
    }

    class NotImplemented : public Story::Base
    {
    public:
        NotImplemented()
        {
            BookID = Book::Type::NONE;

            ID = -1;

            Title = "Not implemented yet";

            Controls = Story::Controls::NONE;
        }
    };

    auto notImplemented = NotImplemented();

    void *FIND_STORY(int id, std::vector<Story::Base *> &Stories)
    {
        Story::Base *story = &notImplemented;

        if (Stories.size() > 0)
        {
            for (auto i = 0; i < Stories.size(); i++)
            {
                if (((Story::Base *)Stories[i])->ID == id)
                {
                    story = (Story::Base *)Stories[i];

                    break;
                }
            }
        }

        return story;
    }
}
#endif