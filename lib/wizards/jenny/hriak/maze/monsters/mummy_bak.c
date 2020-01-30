inherit "obj/monster";

static string *limbs;
static int limb_count;
static string org_long;

death(arg) {
  string str;
  int i;
  if(limb_count >= 4) {
    say("Mummy's head is cut loose by irresistable force and it's body drops!\n");
    ::death();
    return;
  }
  say("Mummy's "+limbs[limb_count]+" is cut off, but otherwise it seems unharmed!\n");
  limb_count += 1;
  set_level(query_level()-5);
  set_log(1);
  str = "";
  while(i<limb_count) {
    if(i > 0 && i == limb_count -1) str += " and ";
    else if(i > 0) str += ", ";
    str += limbs[i];
    i += 1;
  }
  set_long(org_long + "It is missing "+str+".\n");
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_level(60);
  set_exp(query_exp()*3);
  set_log(1);
  set_name("mummy");
  set_short("A dirty mummy in yellow wrapping");
  set_long("Uuh what a smell. Luckily you don't fall unconscious. The yellow wrapping tied\n"+
        "around the mummy is really dirty and dusty. Mean white glow emits from the head of\n"+
        "the mummy, from the places that once were the eyes of this body.\n");
  org_long = long_desc;
  limbs = ({"left leg", "right leg", "left arm", "right arm", "head", });
  set_mage(1);
  set_aggressive(1);
  set_block_dir("northwest");
}
