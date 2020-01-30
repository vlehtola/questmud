/* sharpen_ob lasts on a weapon until it's repaired. after repair it can be polished and sharpened again. */

#define SUBTYPES "/daemons/weapon_sub_types"

object weapon;
int factor;

void start(object ob) {
  int slash;
  weapon = ob;
  slash = SUBTYPES->query_damage_amount(weapon->query_sub_type(), "slash");
  slash += SUBTYPES->query_damage_amount(weapon->query_sub_type(), "pierce")/3;
  if(!slash) {
    write("This weapon has no edge that could be sharpened.\n");
    destruct(this_object());
    return;
  }
  factor = this_player()->query_skills("sharpen");
  /* factor = [1,80] * [10,100] / 100, NOTE: few weapons have slash > 60 */
  /* 80 * 60 / 200 = 24, maxx 30% */
  factor = factor * slash / 200;
  if(factor > 10) factor = 10 + (factor-10)/2;
  if(factor > 30) factor = 30;
  shadow(weapon, 1);
  write("You use your craft to make "+weapon->short()+"'s edge sharper and deadlier.\n");
  if(this_player()->query_wiz()) write("factor: "+factor+" slash%: "+slash+"\n");
}

query_sharpen() {
  return this_object();
}

query_wc() {
  int i;
  i = weapon->query_wc();
  i = i + (i * factor / 100);
  return i;
}

repair_weapon(i,ii) {
  tell_object(this_player(), "The weapon loses it's edge as you repair it.\n");
  weapon->repair_weapon(i,ii);
  destruct(this_object());
}

