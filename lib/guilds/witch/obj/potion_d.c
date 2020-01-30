int full,prepared,quality,size,effect,max_doze,doze_left,identified;
int query_full() { return full; }
int query_prepared() { return prepared; }
int query_quality() { return quality; }
int query_size() { return size; }
int query_max_doze() { return max_doze; }
int query_doze_left() { return doze_left; }
get_vial_size(string i) {
        switch(i) {
                case 1:return "small";
                case 2:return "average";
                case 3:return "large";
        }
}
get_short(string word) {
        switch(word) {
                case "armour_strength":return "A vial full of bright blue liquid";
                case "strength":return "A vial full of blue liquid";
                case "strength_curse":return "A vial full of dim blue liquid";
                case "armour_dexterity":return "A vial full of bright yellow liquid";
                case "dexterity":return "A vial full of yellow liquid";
                case "dexterity_curse":return "A vial full of dim yellow liquid";
                case "armour_constitution":return "A vial full of bright magenta liquid";
                case "constitution":return "A vial full of magenta liquid";
                case "constitution_curse":return "A vial full of dim magenta liquid";
                case "armour_intelligence":return "A vial full of bright orange liquid";
                case "intelligence":return "A vial full of orange liquid";
                case "intelligence_curse":return "A vial full of dim orange liquid";
                case "armour_wisdom":return "A vial full of bright white liquid";
                case "wisdom":return "A vial full of white liquid";
                case "wisdom_curse":return "A vial full of dim white liquid";
                case "poison":return "A vial full of grey liquid";
                case "antidote":return "A vial full of green liquid";
                case "stunres":return "A vial full of violet liquid";
                case "heal_hp":return "A vial full of red liquid";
                case "heal_sp":return "A vial full of shimmering red liquid";
                case "heal_ep":return "A vial full of vine red liquid";
                case "curse":return "A vial full of black liquid";
                case "curecurse":return "A vial full of pink liquid";
                case "fire_single":return "A vial full of radiating gold liquid";
                case "cold_single":return "A vial full of glowing gold liquid";
                case "electric_single":return "A vial full of shimmering gold liquid";
                case "firewall":return "A vial full of radiating silver liquid";
                case "coldwall":return "A vial full of glowing silver liquid";
                case "electricwall":return "A vial full of shimmering silver liquid";
                case "stun":return "A vial full of shimmering grey liquid";
                case "hp_reg":return "A vial full of bright red liquid";
                case "ep_reg":return "A vial full of dim red liquid";
                case "sp_reg":return "A vial full of dark red liquid";
                case "armour_fire":return "A vial full of burning liquid";
                case "armour_cold":return "A vial full of freezed liquid";
                case "armour_electric":return "A vial full of bright liquid";
                case "reduce_sp":return "A vial full of multicoloured liquid";
                case "reduce_hp":return "A vial full of bright multicoloured liquid";
                case "reduce_ep":return "A vial full of dim multicoloured liquid";
                case "say_curse":return "A vial full of black and white liquid";
}
return "A empty vial";
}

get_quality(int i) {
        switch(i) {
                case 0..10:return "poor";
                case 11..20:return "lousy";
                case 21..30:return "average";
                case 31..40:return "fair";
                case 41..50:return "quite good";
                case 51..60:return "good";
                case 61..70:return "very good";
                case 71..80:return "great";
                case 81..90:return "magnificent";
                case 91..100:return "outstanding";
        }
        return "empty";
}

can_drink(string word) {
        switch(word) {
                                case "armour_fire":return 0;
                                case "armour_cold":return 0;
                                case "armour_electric":return 0;
                                case "armour_strength":return 0;
                                case "armour_dexterity":return 0;
                                case "armour_constitution":return 0;
                                case "armour_intelligence":return 0;
                                case "armour_wisdom":return 0;
                                }
                                return 1;
                                        }

get_identify(string word) {
        switch(word) {
                case "strength":return "strength";
                case "dexterity":return "dexterity";
                case "constitution":return "constitution";
                case "intelligence":return "intelligence";
                case "wisdom":return "wisdom";
                case "poison":return "poison";
                case "antidote":return "remove poison";
                case "heal_hp":return "hit point heal";
                case "heal_sp":return "spell point heal";
                case "heal_ep":return "endurance heal";
                case "curse":return "curse";
                case "curecurse":return "remove curse";
                case "fire_single":return "fire damage";
                case "cold_single":return "cold damage";
                case "electric_single":return "electric damage";
                case "strength_curse":return "strength curse";
                case "dexterity_curse":return "dexterity curse";
                case "constitution_curse":return "constitution curse";
                case "wisdom_curse":return "wisdom curse";
                case "intelligence_curse":return "intelligence curse";
                case "firewall":return "fire damage";
                case "electricwall":return "electric damage";
                case "coldwall":return "cold damage";
                case "stun":return "stun";
                case "hp_reg":return "hit point regeneration";
                case "sp_reg":return "spell point regeneration";
                case "ep_reg":return "endurance point regeneration";
                case "armour_fire":return "armour fire resistance";
                case "armour_cold":return "armour cold resistance";
                case "armour_electric":return "armour electric resistance";
                case "armour_strength":return "armour strength";
                case "armour_dexterity":return "armour dexterity";
                case "armour_constitution":return "armour constitution";
                case "armour_intelligence":return "armour intelligence";
                case "armour_wisdom":return "armour wisdom";
                case "reduce_sp":return "drain spell points";
                case "reduce_hp":return "drain hitpoints";
                case "reduce_ep":return "drain endurance";
                case "say_curse":return "communicate curse";
}
return "misc";
}
