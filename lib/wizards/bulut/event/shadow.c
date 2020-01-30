object liv;
string attacker;

start(object mina) {
   if (!mina) { return; }
   liv = mina;
   shadow(liv,1);         
}
self_destruct() {
destruct(this_object());
}

death() {
   attacker = liv->query_attack()->query_name();
   find_object("/wizards/bulut/event/pkobj")->someone_died(lower_case(liv->query_name()));                                                                   
   shout("Gerdy shouts: " + liv->query_name() + " just got " +liv->query_attack()->query_possessive() + " ass kicked by " + attacker + "!\n"); 
   tell_object(liv, "\n\nYou are defeated by " + attacker + "!\n\n");
   tell_room(environment(liv), liv->query_name()+"'s fight is over.\n");
   liv->move_player("X#/world/city/inn.c");
   liv->query_attack()->stop_fight();
   liv->query_attack()->stop_all_hunting();
   liv->move_interrupt_spell();
   liv->stop_fight();
   liv->stop_all_hunting();
   liv->set_hp(5000);
   liv->remove_death();
   destruct(this_object());
   return 1;
}              

quit() {
   find_object("/wizards/bulut/event/pkobj")->someone_died(lower_case(liv->query_name()));                                                                   
   shout("Gerdy shouts: " + liv->query_name() + " decided to withdraw!\n"); 
   unshadow();
   liv->quit();
destruct(this_object());

}

link_death() {
   find_object("/wizards/bulut/event/pkobj")->someone_died(lower_case(liv->query_name()));                                                                   
   shout("Gerdy shouts: " + liv->query_name() + " decided to withdraw!\n"); 
   liv->move_player("X#/world/city/inn.c");
   unshadow();
   liv->link_death();
destruct(this_object());

}
 

query_shadowed() {
return 1;
}                           
