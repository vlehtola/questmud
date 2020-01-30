
inherit"obj/monster";
reset(arg) {
string chat_str;
::reset(arg);
if(arg) return;
set_name("guard");
set_alias("guard");
set_short("Guardian of Unseen University");
set_long(
"Guardian making his usual guarding tour. Are these guards also mages, can they\n"
+ "cast spells? You never know until you test. They let you enter the tower and\n"
+ "are not even try to block your way.\n";
set_skill ("attack", 60);
set_skill ("doublehit", 60);
set_skill ("stun", 60);
set_level(38);
set_race("human");
set_hp(34000);
set_dex(120);
set_con(170);
set_str(200);
set_siz(100);
set_wc(60);
set_ac(70);
set_aggressive(0);
add_money(231);
}
