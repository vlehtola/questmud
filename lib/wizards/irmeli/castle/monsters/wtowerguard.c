inherit "obj/monster";
reset(arg) {
    object weapon;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
set_name("knight");
set_alias("human");
set_short("A black knight standing by the tower of Asgroth");
    set_long("The black knight is standing by the tower. His job is to keep outsiders\n"+
             "of the tower. He is a teacher in the knight school. His hair is blond\n"+
             "and he has black beard. He is very skilled with swords.\n");
    set_al(0); 
    set_aggressive(0);
    set_init_ob(this_object());
    set_race("human");
    set_gender(1);
set_move_at_random(0);

weapon = clone_object("/wizards/irmeli/castle/eq/sword.c");
    move_object(weapon, this_object());
    init_command("wield sword");  

   if (!chat_str) {
        chat_str = allocate(2);
         chat_str[0] = "Knight says: 'Kill that evil Executioner for me!'\n";
         chat_str[1] = "Knight asks: 'Could you?'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Knight shouts: 'I'll give you one chance to leave!'\n";
    }
    load_chat(10, chat_str);
    load_a_chat(1, a_chat_str); 

}
catch_tell(str) {
 object ob;
 string filu, tmp, tmp2;
 int id;
  if(sscanf(str, "%s gives %s to you.",tmp,tmp2) == 2) {
   ob = present("head", this_object());
   if(ob) {
   if(sscanf(file_name(ob),"%s#%d",filu,id) == 2) {
    if(filu == "/wizards/irmeli/castle/object/exehead") {
     destruct(ob);
     write("Knight says: 'Finally someone killed the evil Executioner!'\n");
     write("As a reward I'll let you inside the tower.\n");
     write("Slowly the door starts to open.\n");
     call_out("delay_entrance", 6);
     return 1;
  }
 }
}
}
}

int delay_entrance() {
 write("Finally the door opens completely.\n");
 write("The knight throws you inside the tower.\n");
 move_object(this_player(),"/wizards/irmeli/castle/wtower.c");
 this_player()->look();
 this_player()->set_quest("Return the head of the Executioner");
 reset();
}


