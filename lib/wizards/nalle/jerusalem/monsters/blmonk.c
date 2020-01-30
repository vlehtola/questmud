inherit "obj/monster";
reset(arg) {
   ::reset(arg);
if(arg) return;
set_name("monk");
set_level(35);
set_gender(1);
set_race("human");
set_block_dir("north");
set_block_message("The monk booms: 'You have no business there.'");
set_alias("Monk");
set_short("A benedictine monk");
set_long("A well built monk clad in brown robes.\n"+
"It seems he has developped a quite big stomach.\n");
}

