inherit "/obj/monster";
string who;
object ob;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(1);
    set_max_hp(100000);
    set_name("servant");
    set_short("A tall servant wearing a black cape");
    set_long("A beatiful woman, worshipping " + previous_object()->query_name() + "\n");
    set_al(0);
    set_al_aggr(200);
    set_gender(2);
    set_race("human");

}               

catch_tell(str) {
if(sscanf(str,"%s leaves",who)) {
call_out("helb", 2);
	}
}
helb() {
if ( who == "Bulut" ) {
tell_room(environment(find_player(lower_case(who))),"A servant arrives.\n");
move_object(this_object(),environment(find_player(lower_case(who))));
 }                      
}                                         
