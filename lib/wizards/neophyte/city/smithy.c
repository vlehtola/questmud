inherit "obj/monster";
reset(arg) {
	::reset(arg);
	if(arg) {return; }
	set_name("smithy");
	set_level(55);
	set_gender(1);
	set_race("human");
	set_al(-10);
	set_special(70);
	set_short("Caulos the city smithy");
	set_long(".\n");
	set_skill("cranekick", 80);
	set_skill_chance("cranekick", 50);
}
void special_move() {
	   int dama;
	   write("Hep!\n");
	   dama = random(50) + 30;
	   this_player()->reduce_hp(dama);

}
