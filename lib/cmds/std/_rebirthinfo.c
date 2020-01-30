cmd_rebirthinfo() {

if(!this_player()->query_rebirth() && this_player()->query_wiz() < 3) return 0;

write(
"REBIRTH FEATURES (affecting parameters)\n\n"+
"- avoid death (level, rebirth level)\n"+
"- natural ability to absorb offensive bolts (level, rebirth level)\n"+
"- improved natural regen (rebirth level)\n"+
"- regen partially in combat (rebirth level)\n"
"- increased chance to gain masteries (rebirth level)\n"
);

write(
"\n"+
"SPECIAL FEATURES FOR 1st REBIRTH\n\n"+
"- +5 to racial exprate\n"+
"- +allskills bonus\n"+
"- natural bonus to all resists\n"+
"- 3 better races available\n"
);

if(this_player()->query_rebirth() == 1 && !this_player()->query_wiz()) return 1;

write(
"\n"+
"SPECIAL FEATURES FOR 2nd REBIRTH\n\n"+
"- total of +10 to racial exprate (not cumulative with previous bonus)\n"+
"- 'destroy' command to get rid of corpses\n"+
"- increased plan, surname and tell status length\n"+
"- no background for quicker reincs\n"+
"- free services from Khaland\n"+
"- decreased death penalty time\n"+
"- 2 new races\n"
);

if(this_player()->query_rebirth() == 2 && !this_player()->query_wiz()) return 1;

write(
"\n"+
"SPECIAL FEATURES FOR 3rd REBIRTH\n\n"+
"- total of +15 to racial exprate (not cumulative with previous bonus)\n"+
"- +50 max level\n"+
"- +1% all stats bonus each level after 150\n"+
"- increased hp/sp/ep-max\n"+
"- ability to avoid ambushes\n"+
"- increased party name length\n"+
"- decreased death penalty time (better than 2nd rebirth)\n"
);

return 1;
}
