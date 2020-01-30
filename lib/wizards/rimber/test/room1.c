inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 set_not_out(1);
 short_desc = "Test room";
 long_desc = "This is where Rimber tests something sometimes.\n";
 add_exit("west", "/wizards/rimber/test/room2.c");
 add_exit("cs", "/wizards/rimber/workroom.c");
}

init() {
 ::init();
 add_action("kutsu", "kutsu");
}

kutsu(str) {
 object dreik;
 if(str != "dragon") return 0;
 dreik = clone_object("/wizards/rimber/test/dragon.c");
 move_object(dreik, this_object());
 say("Dragon booms: 'Yes master?'\n");
}
