#pragma once
#include <array>
#include <iostream>
namespace Potion
{
    enum Type
    {
        healingPotion,
        manaPotion,
        speedPotion,
        invisibilityPotion,
        maxPotion
    };

    constexpr std::array<Potion::Type, maxPotion> potions{ healingPotion, manaPotion, speedPotion, invisibilityPotion };
    constexpr std::array<std::string_view, maxPotion> name{ "healing", "mana", "speed", "invisibility" };
    static_assert(std::size(name) == maxPotion);

    constexpr std::array cost{ 20, 30, 12, 50 };
    static_assert(std::size(cost) == maxPotion);
}