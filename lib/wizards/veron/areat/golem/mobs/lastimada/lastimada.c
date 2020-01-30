inherit "obj/monster";
int e = random(3);
int i;

reset(arg) {
    object neku,popot,mask;
    
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_level(random(10)+65);
    set_str(query_str()*2);
    set_con(query_con()*3);
    set_int(query_int()*2);
    set_max_hp(query_hp()+150000);
    query_max_hp();
    set_name("lastimada");
    set_race("griffin");
    set_alias("griffin");
    set_short("Lastimada the ancient griffin");
    set_long("The huge griffin Lastimada is an impressive creature. It's face and body\n"+
             "are full of scars from the numerous fights it has been in. The creature's\n"+
             "fur is already turning gray and there are wrinkles around it's eyes. \n"+
             "Lastimada seems to wait for a battle, it's beak is half-open and eyes burn\n"+
             "red.\n");
  
    set_al(9);
    set_aggressive(0);
    set_special(20);
    set_skill("tumble", 45);
    set_skill("critical", 30);
    set_skill("doublehit", 90);
    set_skill("counter spell", 20);
    set_skill("stun", 30);
    set_spell_chance(40, "exs zzt strm");
    set_spell_chance(30, "exs brr strm"); 
    set_skill("chanting", 90);
    set_skill("cast essence", 100);
    set_skill("cast electric", 100);
    set_skill("cast fire", 100);
    set_skill("cast ice", 100);
    set_skill("cast storm", 100);
    set_skill("riposte", 60);
    set_skill("theory of electricity", 100);
    set_skill("lore of cold", 100);
    set_skill("mana control", 100);
    set_log();


  

  if(e == 0) {
   neku = clone_object("/wizards/veron/areat/golem/mobs/lastimada/lneku");
    move_object(neku, this_object());
    init_command("wear necklace");      
  
}
  if(e == 1) {
    popot = clone_object("/wizards/veron/areat/golem/mobs/lastimada/boots");
    move_object(popot, this_object());
    init_command("wear slippers");      
   
}
   if(e == 2) {
    mask = clone_object("/wizards/veron/areat/golem/mobs/lastimada/mask");
    move_object(mask, this_object());
    init_command("wear mask");      
  

}
       


}


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

tell_object(ob,"Lastimada swings his tail and you fall down from the roof!\n");
tell_room(environment(ob),"Lastimada swings his tail and "+ob->query_name()+" falls down from the roof!\n", ({ob,}));
move_object(ob,"/wizards/veron/areat/golem/room1.c");

}
