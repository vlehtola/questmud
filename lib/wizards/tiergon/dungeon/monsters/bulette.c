inherit "obj/monster";

reset(arg) {
    string a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(30);
    set_exp(query_exp()*1.5);
    set_name("Bulette");
    set_alias("bulette");
    set_short("A bulette feasting on some corpses");
    set_long("The bulette is a truly frightening creature, also known as the landshark.\n"+
             "this particular specimen appears to be a marvellous example of it's kind: Mean tempered, stupid and deadly.\n");
    set_special(10);
    set_animal(1);
    set_al(-10);
    set_animal(1);
    set_aggressive(1);
    set_block_dir("south");
 }


special_move() {
   object ob;
   if (!attacker_ob) { return; }
   ob = first_inventory(environment(this_object()));
   while(ob) {
        if (!ob->query_npc() && living(ob)) {
          tell_object(ob,"The bulette swallows you whole!\n");
          ob->lited("*OUCH*\n");
          ob->reduce_hp(50000);
          return 1;
        }
        ob = next_inventory(ob);
   }
}
