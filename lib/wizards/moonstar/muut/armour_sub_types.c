mapping a;

valid_slot(string slot) {
  switch(slot) {
  case "finger": return 1;
  case "cloak": return 1;
  case "forehead": return 1; /* race leadership star */
  case "tattoo": return 1; /*  Moonstar's special eq */
  case "amulet": return 1;
  }
}

query_type(int class, string sub_type) {
  string str,tmp,tmp2;
  str = "";
  sub_type = "a"+sub_type+"a";
  if(class/3*3 == class) str = " fine";

  if(sscanf(sub_type, "%sleather%s", tmp,tmp2) == 2) {
    if(class < 3) return " soft";
    else if(class < 7) str += " rigid";
    else if(class > 6) str += " studded";
    return str;
  }

  if(class < 3) str += "";
  else if(class < 7) str += " iron";
  else if(class < 10) str += " steel";
  else if(class < 13) str += " mithril";
  return str;
}

query_number(string armour, string type) {
  int ac,weight,cost;
  string str, slot;
  str = a[armour];
  if(!str) return -1;
  if(sscanf(str, "%d %d %d %s", ac,weight,cost,slot) != 4) {
    write("Error in armour sub type data!\n");
    return -1;
  } else {
    if(type == "ac") return ac;
    if(type == "weight") return weight;
    if(type == "cost") return cost;
    if(type == "slot") return slot;
    write("query_damage_amount(string weapon, string type) [Error in argument 2!]\n");
  }
}
reset(arg) {
  if(arg) return;
  a = ([ ]);
  a += (["chain coif":"25 10 5 head"]);
  a += (["cap":       "50 20 15 head"]);
  a += (["helm":      "75 50 30 head"]);
  a += (["great helm":"100 100 100 head"]);

  a += (["leather gloves":   "25 10 5 hands"]);
  a += (["leather gauntlets":"40 30 20 hands"]);
  a += (["chain gauntlets":  "100 100 100 hands"]);

  a += (["leather bracers":"30 20 5 arms"]);
  a += (["bracers":        "60 60 30 arms"]);
  a += (["arm guards":     "100 100 100 arms"]);

  a += (["leather boots":"40 20 20 feet"]);
  a += (["boots":        "100 100 100 feet"]);

  a += (["leather leggings":"30 30 15 legs"]);
  a += (["leggings":        "100 100 100 legs"]);

  a += (["leather coat":          "10 5 1 torso"]);
  a += (["leather armour":        "20 10 3 torso"]);
  a += (["banded mail":           "35 25 12 torso"]);
  a += (["chain mail":            "50 40 25 torso"]);
  a += (["scale mail":            "75 60 40 torso"]);
  a += (["plate mail":            "100 100 100 torso"]);
}

