inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    set_level(60);
    set_name("shark");
    set_short("A great white shark");
    set_long("The shark is huge. It got long sharp teeth.\n");
    set_animal(1);
    set_al(0);
    set_aggressive(0);
    set_init_ob(this_object());
}

catch_tell(str) {
   string tmp1, tmp2;
   ::catch_tell(str);
   if (sscanf(str, "%s gives An Icecube to %s.", tmp1, tmp2) == 2) {
     if (present("icecube", this_object()) && this_player()->query_name() == tmp1) {
       write("It seems like the shark is extremely happy now that it has his icecube.\n");
       if (!this_player()->query_quest("Return the icecube to the great white shark")) {
         this_player()->set_quest("Return the icecube to the great white shark");
       }
       "/wizards/gynter/element/water/3"->quest_completed();
       call_out("nuke", 1);
       return;
     }
   }
}

nuke() {
  object emerald;
  say("The shark starts to disolve and right before it vanishes it hands "+this_player()->query_name()+" an emerald.\n");
    emerald = clone_object("/wizards/gynter/element/eq/emerald");
  move_object(emerald, this_player());
  destruct(present("icecube", this_object()));
  destruct(this_object());
  return 1;
}
