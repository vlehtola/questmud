object liv;

start(object ob) {
   if (!ob) { return; }
   liv = ob;
   shadow(liv,1);
}

move_player(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9) {
   liv->move_player(arg1,arg2,arg4,arg4,arg5,arg6,arg7,arg8,arg9);
   destruct(this_object());
}
if(liv->query_hp() < 0) {
call_out("death", 1);
return 1;
}
death() {
   liv->query_attack()->stop_fight();
   liv->query_attack()->stop_all_hunting();
   liv->stop_fight();
   liv->stop_all_hunting();
   liv->move_player("X#/world/arena/temproom");
   tell_object(liv, "\n\nYou die.\n\n");
   tell_room("/world/arena/arena", "You have won the battle.\n");
   liv->set_hp(10);
   liv->remove_death();
   call_out("revive", 1);
   return 1;
}

revive() {
   tell_object(liv,"You are brought back to life.\n");
   move_object(liv, "/world/arena/entrance");
   destruct(this_object());
   return 1;
}

query_death_shadow() {
   return 1;
}

end_death_shadow() {
        destruct(this_object());
        return 1;
}

