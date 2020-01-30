// Racial eq-daemon, Azathoth (28.10.2000), Initial coding.
// Handles weapons and equipment.
// If no race is given as an argument, this_player()->query_race() is used.
// I pondered if I should do a save_object version, that's easily configured
// by funcionts, but I came to the conclusion to keep this small and compact. :P

mapping eq;
mapping weapons;

reset(arg) {
if (arg) return;
eq = ([
"example":({"/wizards/tremor/example", "/wizards/tremor/example2", }),
]);
weapons = ([
"dwarf":({
"/wizards/tremor/race_eq/dwarf/broad_axe",
"/wizards/tremor/race_eq/dwarf/battle_axe",
"/wizards/tremor/race_eq/dwarf/two_edged_axe",
"/wizards/tremor/race_eq/dwarf/two_edged_axe",
}),
"dark elf":({
"/wizards/tremor/race_eq/dark_elf/dagger",
"/wizards/tremor/race_eq/dark_elf/sabre",
"/wizards/tremor/race_eq/dark_elf/scimitar",
}),
    ]);
}
mixed query_eq(string race) {
int x;
if (!race) race = this_player()->query_race();

race=lower_case(race);
if(!eq[race]) return -1;
x = random(sizeof(eq[race]));
return eq[race][x];
}
mapping query_all_eq() {
return eq;
}

mixed query_all_race_eq(string race) {
if (!race) race = this_player()->query_race();
race = lower_case(race);
if (!eq[race]) return -1;
return eq[race];
}
mixed query_weapon(string race) {
int x;
if (!race) race = this_player()->query_race();
race = lower_case(race);
if (!weapons[race]) return -1;
x = random(sizeof(weapons[race]));
return weapons[race][x];
}
mixed query_all_weapon() {
return weapons;
}

mixed query_all_race_weapons(string race) {
if (!race) this_player()->query_race();
race = lower_case(race);
if (!weapons[race]) return -1;
return weapons[race];
}
