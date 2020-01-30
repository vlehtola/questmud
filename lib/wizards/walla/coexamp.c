inherit "obj/monster";

reset(arg) {
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_exp(58000);
    set_name("miner");
    set_short("A spectral miner");
    set_long("A spectral apparition of a tormented miner. He seems intent on achieving some goal.\n");
    set_al(0);
}

catch_tell(str) {
    string giver,item;
    object ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to Miner.", giver, item) == 2) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }
      if (!present("pick", this_object())) {
         write("The miner looks at you furiously and shrieks shrilly.\n");
         write("The miner throws the "+capitalize(item)+" back at you angrily.\n");
         move_object(present(item,this_object()), ob);
         return 0;
      } 
      call_out("jatko", 1,item);
   }   
}
jatko(item) {
      say("The spectre takes the pick greedily and disappears.\n");
      say("A strange force starts hacking at the boulders vigorously.\n");
      call_other(environment(this_object()), "add_exit", "south", "/wizards/tiergon/dungeon/a6"); 
      destruct(present(item,this_object()));
      destruct(present("coins",this_object()));
      destruct(this_object());     
      return 1;     
}

