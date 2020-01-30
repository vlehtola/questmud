inherit "obj/monster";

reset(arg) {
    string a_chat_str;
    object money;
    ::reset(arg);
    if (arg) { return; }
    set_level(20);
    set_name("Lock lurker");
    set_alias("lurker");
    set_short("A little lock lurker");
    set_long("This little creature looks roughly like a large gold coin with a scorpion's tail.\n");
    set_special(100);
    set_al(-10);
    set_animal(1);
    set_aggressive(1);
    set_block_dir("south");
 }


special_move() {
   object ob;
   if (!attacker_ob || random(2) > 0) { return; }
   ob = first_inventory(environment(this_object()));
   while(ob) {
        if (!ob->query_npc() && living(ob) && !random(3)) {
          tell_object(ob,"The lock lurker hops up and stings your nose!\n");
          ob->lited("*OUCH*\n");
          ob->set_poison(1);
          ob->reduce_hp(random(5)+5);
          return 1;
        }
        ob = next_inventory(ob);
   }
}
