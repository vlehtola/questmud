status viltteri(object ob) {

if(living(ob) && !ob->query_npc())return 1;
return 0;
}


special_move() {

object *obs;
object ob;

obs = all_inventory(environment(this_object()));

if(!obs && sizeof(obs) == 0)return;

obs = filter_array(obs,"viltteri");

ob = obs[random(sizeof(obs))];

if(!ob)return;

tell_object(ob,"Pilipalipompom sut siirrettiin puis\n");
tell_room(environment(ob),"Pilipalipompom "+ob->query_name()+" siirrettiin puis.\n", ({ob,}));
move_object(ob,"/wizards/veron/areat/golem/room1.c");

}
