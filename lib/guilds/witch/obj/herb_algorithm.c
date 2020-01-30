
/* input n herbs, output potion //Celtron */

#define NUMBER_OF_HERBS 3       // how many herbs for a potion
#define DIR             "/guilds/witch/potions/"
#define ALPHA           "/daemons/alpha"

// define all potions
#define POTIONS ({ "strength", "dexterity", "constitution", "wisdom", "intelligence", "poison", "antidote", "curse", "curecurse", "heal_hp", "heal_ep", "heal_sp", "fire_single", "cold_single", "electric_single", "strength_curse", "dexterity_curse", "constitution_curse", "wisdom_curse", "intelligence_curse", "stun", "hp_reg", "sp_reg", "ep_reg", "firewall", "electricwall", "coldwall", "armour_strength", "armour_constitution", "armour_dexterity", "armour_intelligence", "armour_wisdom", "armour_fire", "armour_cold", "armour_electric", "reduce_ep", "reduce_sp", "reduce_hp", "say_curse", })

// put all herbs here
#define HERBS           ({ "chives", "ginger", "pine", "dogwood", "buttercup", "foxglove", "clover", "oak", "rose", "blackberry", })
int jakojaannos(int a, int b) {
  a = a - ( a / b * b );
  return a;
}

int get_herb(string herb) {
  int value,i;
  for(i=0; i < sizeof(HERBS); i++) {
    if(HERBS[i] == herb) {
        value = i;
        break;
    }
  }
  value += jakojaannos(ALPHA->get_value(this_player()->query_name(), 4), value+NUMBER_OF_HERBS);
  return value;
}

// returns the filename of the potion made
make_potion(object ob) {
  int potion,effect,i;
  object *obs,vial;
  obs = all_inventory(this_object());
  vial = present(ob, this_player());
  effect = 0;
  if(!vial) { write("You dont have vial.\n"); return 1; }
  if(sizeof(obs) != NUMBER_OF_HERBS) { write("You need three herbs in cauldron to make a potion.\n"); return 1; }
  for(i=0; i < sizeof(obs); i++) {
          if(!obs[i]->herbs()) { write("Only herbs can be used to make potions.\n"); return 1; }
          if(this_object()->query_blood() < 10) { write("You don't have enough blood in the cauldron.\n"); return 1; }
    // each herb has a numerical value
    potion += get_herb(obs[i]->query_name());
    effect += obs[i]->query_quality();
    obs[i]->dest_me();
    // jakojaannos
    potion = jakojaannos(potion, sizeof(POTIONS));
  }
  effect += this_player()->query_wis();
  effect += this_player()->query_mastery()["herbal mixing"];
  effect = effect/7;
  if(this_player()->query_wiz())write(effect+"\n");
  vial->set_effect(effect,POTIONS[potion]);
  this_object()->drain_blood();
  write("You finish making the potion and quickly pour the liquid inside the vial.\n");
  say(this_player()->query_name()+" finish making a potion and quickly pours the liquid inside the vial.\n");
  if(!random(this_player()->query_mastery()["herbal maxing"]+1)) {
  this_player()->set_mastery("herbal mixing", this_player()->query_mastery()["herbal mixing"]+1);
  if(find_player("siki"))tell_object(find_player("siki"), this_player()->query_name()+" makes potion of "+POTIONS[potion]+":"+effect+"\n");
  }
  return DIR+POTIONS[potion];
}