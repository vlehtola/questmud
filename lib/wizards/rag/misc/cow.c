inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
    set_name("cow");
    set_short("A scottish cow playing the bag pipes ");
    set_long(   "������������� \\ (__)\n"+
		"������������� \\\\(oo)\n"+
		"�������� /-----\\\\\\/\n"+
		"������� / |��� (##)\n"+
		"������ *� ||----||\n"+
		"          ^^    ^^\n");
    set_animal(1);
    set_al(0);
    set_log();
    set_aggressive(0);   
}