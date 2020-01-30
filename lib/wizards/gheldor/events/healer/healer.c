inherit "obj/monster";

int seconds,i;
object *user;

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) return;
    set_level(80);
    set_name("verot");
    set_alias("healer");
    set_race("human");
    set_short("Travelling healer giving a free healings");
    set_long("blabla\n");
    set_al(50);
    set_heart_beat(1);
}

void heart_beat() {
   ::heart_beat();
  user = users();
  seconds++;
  seconds++;
  if(seconds >= 60) {
    for(i=0;i<sizeof(user);i++) {
       if(user[i]->query_hp() < user[i]->query_max_hp()) {
         tell_object(user[i],"The healer heals your wounds from distance.\n");
         user[i]->heal_self(50+random(51));
       }
    }
         say("The healer claps his hands and chants 'TsukiNagiHiilinakki!'\n");
  seconds = 0;
  }
}

query_seconds() { return seconds; }
