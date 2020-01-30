inherit "obj/weapon"; 
int lite;
 
reset(arg) {
    ::reset(arg);
    set_name("rod");
    set_short("Rod of 7 parts <Assembled>");
    set_long("This is the Rod of 7 parts. It gives you some strange powers, now that you have brought" +
"together all the different parts. Try to command it by using 'to come' and 'something'.\n");
    set_material(6);
    set_class(30);
    set_weapon_type("bludgeon");
    set_value(15000);
 
set_weight(4);
}
 
init() {
    add_action("shirak", "shirak");
    add_action("dulak", "dulak");
}
 
shirak() {
    if (lite)  { write("Staff is already lit.\n"); return 1; }
    write("You utter the word, 'shirak' and the staff starts to glow in a strange light.\n");
    say(this_player()->query_name()+" utter the word 'shirak' and his staff starts to glow in"+
 "a strange light.\n");
    set_light(1);
    lite = 1;
}
 
dulak() {
    if (!lite)  { write("Staff is not lited.\n"); return 1; }
    write("You utter the word, 'dulak' and the staff's light fades out.\n");
    say(this_player()->query_name()+" utter the word 'dulak' and his staff's light fades out.\n");
    set_light(-1);
}


