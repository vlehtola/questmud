#include "/sys/ansi.h"
#define GRENADE_DAMAGE 10

reset(arg) {
  if(arg) return;
}

short() {
  return "120mm finnish mortar";
}

id(str) {
  return str == "mortar";

}

 long() {
  write("This mortar is used by finnish army mortar-mens.\n"+
        "They are known from their deadly accuracy and effective firepower\n");
}

get() {
        return 0;
}

init() {
        add_action("shoot","shoot");
}

status pelaajat(object ob) {
        if(interactive(ob))return 1;
        return 0;
}


status shoot(string str) {
string target;
int amount,i,j;
object *obs,target_room;
        
        if(!str) {
                write("usage: shoot <target> <amount of grenades>\n");
                return 1;
        }
        
        if(sscanf(str,"%s %d",target,amount) != 2) {
                write("usage: shoot <target> <amount of grenades>\n");
                return 1;
        }
        if(!find_player(target)) {
                write("No such player!\n");
                return 1;
        }
        target_room = environment(find_player(target));
        obs = all_inventory(target_room);
        obs = filter_array(obs,"pelaajat");
        
        for(j = 0;j<amount;j++) {
                tell_room(target_room,"You hear a distant explosion..\n"+
                                              "Something whistles, and its getting closer, and closer..\n"+
                                              "A black 120mm grenade flies through the skies..\n"+
                                              "AND IT DROPS RIGHT HERE!\n"+
                                              "RUN FOR YOUR LIVES!\n"+
                                              "KABOOOOOOM!\n");        
        for(i = 0;i<sizeof(obs);i++) {
                tell_object(obs[i],"Grenade explodes, fragments TEARS your skin, the heat of the explosion BURNS your skin!\n");
                obs[i]->hit_with_spell(GRENADE_DAMAGE,"fire");
        }
}

return 1;
}

query_weight() {
return 100000;
}