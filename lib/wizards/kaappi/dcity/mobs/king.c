inherit "obj/monster";
int apurit;

reset(arg) {
object crown,shield,axe;
string chat_str;

  ::reset(arg);
  if(arg) { return; }
  set_level(100+random(3));
  set_name("thordim");
  set_alias("king");
  set_race("dwarf");
  set_short("Thordim Goodsteel, The king of Amaranthgard, sitting on his Throne");
  set_gender(1);
  set_long("Thordim, the king of Amaranthgard. He is very old\n"+
           "but he seems to be in a good shape. Many scars can\n"+
           "be seen in his face and he is well known for his\n"+
           "achievements in battles. He is one of the dwarves\n"
           "whose picture is in the gates of the city.\n");
  set_al(60);
  set_al_aggr(200);
  set_aggressive(0);
  set_special(20);

set_max_hp(query_hp() + 500000);
set_str(query_str()*2);
set_con(query_con()*2);
set_special(30);
set_skill("stun", 100);
set_skill("attack", 100);
set_skill("strike", 60);
set_skill("axes", 100);
set_skill("tumble", 70);
set_skill("find weakness", 70);
set_skill("agility", 90);
set_skill("critical", 90);
set_skill("enhance critical", 90);
set_skill("dodge", 100);
set_skill("foresee attack", 100);
set_skill("counter spell", 100);
set_skill("double strike", 100);
set_skill("reflect spell", 100);
set_skill("doublehit", 100);
set_skill("cut", 100);
set_skill_chance("strike", 25);
set_log();

crown = clone_object("/wizards/kaappi/dcity/items/crown.c");
move_object(crown, this_object());
init_command("wear crown");

move_object(clone_object("/wizards/kaappi/dcity/items/shield"), this_object());
init_command("wield shield");

move_object(clone_object("/wizards/kaappi/dcity/items/axe"), this_object());
init_command("wield axe");

if(!chat_str) {
   chat_str = allocate(3);
    chat_str[0] = "Thordim smiles and says: 'Good to be home again!'\n";
     chat_str[1] = "Thordim smiles and says: 'This is a very beautiful city, isn't it?'\n";
    chat_str[2] = "Thordim winks at you and asks: 'Have you already visited in our underground park? It's amazing!'\n";

}

load_chat(1, chat_str);
}

special_move() {

  if(apurit < 2) {
     say("Thordim curses you and yells with a strong voice:GUAAARDS! Help me to kill these bastards!\n");
     move_object(clone_object("/wizards/kaappi/dcity/mobs/kinguard"), environment(this_object()));
    apurit++;
 }
}

reduceapurit() {
  apurit--;
}
