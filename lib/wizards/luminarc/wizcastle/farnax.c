inherit "obj/monster";
reset(arg) {
    object armour; object weapon;
    string str; string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_name("wizard");
    set_alias("farnax");
    set_short("Blurred image of Farnax the gnomish wizard");
    set_long("This old and long-bearded man looks almost invisible. The man seems to be in great pain\n"+
            "for some reason. his face looks pale and his beard is shaggy. He has been undead long time, maybe\n"+
            "you could help him somehow.\n");
    set_al(10);
    set_level(60);
    set_mage();
   set_con(query_con()*4); 
   set_str(query_str()*2);
    set_max_hp(query_hp()*3);
    set_race("gnome");
    set_gender(1);
    set_undead(1);
    set_log();
     weapon = clone_object("/wizards/luminarc/wizcastle/armours/fsword");
    move_object(weapon, this_object());
    init_command("wield claymore");
armour = clone_object("/wizards/luminarc/wizcastle/armours/bhelm");
    move_object(armour, this_object());
    init_command("wear helm"); 
     if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] = "Farnax says: 'Please return my soulstone so i can finally rest!'\n";
        chat_str[1] = "Farnax says: 'My experiment went somehow wrong'\n";
        chat_str[2] = "Farnax says: 'Please help me!'\n";
        }
load_chat(5, chat_str);
}
catch_tell(str) {
   string tmp1,tmp2;
   ::catch_tell(str);
   if (sscanf(str, "%s gives soulstone %s.", tmp1, tmp2) == 2) {
    return 1;
  }  
    if (present("soulstone", this_object()) && this_player()->query_name()== tmp1) {
           
           write("As you give the stone to the farnax, he puts the smile on his face and says:\n");
           write("'Thank you for returning that. finally i can rest again!'\n");
           write("Farnax bows and fades away.\n");
           this_object()->stop_fight();
           this_player()->stop_fight();
           this_player()->set_quest("Return the Farnax's soulstone");
           destruct(this_object());

} 


}
