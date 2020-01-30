//Muuta t�t� jos jailin paikka muuttuu
#define JAIL "/wizards/jenny/city/jail/jailroom"
inherit "obj/monster";
object prisoner;
string location;

reset(arg) {

    int i;
    string str;
    ::reset(arg);
    if(arg) { return; }
    i = random(5);
    if(i==0) str = "sturdy looking guard is patrolling around";
    if(i==1) str = "mean looking guard is walking on the street";
    if(i==2) str = "brave looking guard is guarding the city";
    if(i==3) str = "stupid looking guard is keeping order here";
    if(i==4) str = "kind looking guard is watching around";

    set_level(random(2)+60);
    set_race("human");
    set_max_hp(query_max_hp()*50);
    set_exp(100);
    set_name("guard");
    set_alias("cityguard");
    set_short("A "+str+"");
    set_long("A young man who was hired to patrol in the\n"+
             "city of Duranghom. He looks strong and he will\n"+
             "keep order and peace in town no matter what.\n"+
             "All criminals and dissidents will be expeled\n"+
             "from the city and some may be even executed.\n");

    set_gender(1);
}

move_out() {
location = file_name(environment(this_object()));
//jos joku ajaa guglahit tai robberit ni guardit menee voidii
tell_room(environment(this_object()),"Guard panics and flees!\n");
move_object(this_object(),"/wizards/jenny/city/void");
}

move_in() {
//kuha eventti loppuu ni guardit tulee takas voidist tms
tell_room(environment(this_object()),"A city guard calmly walks back into the room\n");
move_object(this_object(),location);
}

catch_tell(str) {
  string name1, name2;
  object ob1;
  ::catch_tell(str);

  if (sscanf(str, "%s attacks %s!", name1, name2) == 2 ||
      sscanf(str, "%s starts concentrating on an offensive spell.",name1) == 1 ||
      sscanf(str, "%s starts concentrating on the offensive skill.",name1) == 1) {
    ob1 = find_player(lower_case(name1));
    if(ob1) {
    tell_room(environment(this_object()),"Guard grabs "+ob1->query_name()+" from the neck and says: 'You going to jail kid!'\n");
    ob1->move_player("X#"+JAIL);
    JAIL->jail(ob1);
  call_out("stopperi",2,ob1);
    prisoner = clone_object("/wizards/jenny/city/jail/prisoner_ob.c");
    prisoner->start(this_player());

    return 1; }
}
 }
stopperi(ob) {
  ob->stop_all();
  ob->stop_fight();
  ob->reset_hunter_list();
  this_object()->stop_all();
  this_object()->stop_fight();
  this_object()->reset_hunter_list();
}
