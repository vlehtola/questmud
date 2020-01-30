//This is a general object, not an armour
//Change all these "armours" to this format -- Rag 26.5.04

short() { return "A map"; }

long(str) {
  write("Take on'  tep to#ard %@rth, one to e&st, two to north\n"+
        "one !o west, th% go one $tep t¤ so_th and ¤%e to wes!,\n"+
        "two $+eps t* north then t^ree step  to e&st you #ill find\n"+
        "hole w^ich !s big e%ough to enter\n");
  return;
}

id(str) { return str == "map"; }

get() { return 1; }
