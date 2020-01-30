static mapping objects;
static string savefile;
int balance;

#define SAVEFILE	"/data/shops/"+this_object()->short()

reset(arg) {
  if(arg) {
    return;
  }
  objects = ([ ]);
  move_object(clone_object("/world/objects/trashcan"), this_object());
  savefile = "/data/shops/"+extract(file_name(this_object()), 12);
  if(!restore_object(SAVEFILE)) {
    save_object(SAVEFILE);
  }
}

query_balance() {
  return balance;
}

add_balance(int value) {
  balance += value;
  save_object(SAVEFILE);
}

shop_commands() {
  add_action("sell_item", "sell");
  add_action("buy_item", "buy");
  add_action("list_inventory","list");
}

load_item(str,min,max) {
  int i;
  i = random(max+1)+min;
  objects += ([ str:i ]);
}

reduce_item(file) {
  if(objects[file] > 1) {
    objects[file] -= 1;
    return 1;
  }
  objects -= ([ file ]);
  return 1;
}

add_item(file) {
  if(objects[file]) {
    objects[file] += 1;
    return 1;
  }
  objects += ([ file : 1 ]);
  return 1;
}

sell_item(mixed str, status do_loop) {
  object ob, item_o;
  string file,tmp;
  int value, divider, i;
  if(!str) {
    write("Sell what?\n");
    return 1;
  }
  if(stringp(str)) {
    ob = present(str,this_player());
  }
  if(!ob && !do_loop) {
    item_o = call_other("/daemons/filter", "EQ_FILTER", str, this_player());
    for(i=0; i < sizeof(item_o); i++) {
      if(item_o[i]->short()) sell_item(item_o[i], 1);
    }
  } else if(!ob) {
    ob = str;
  }
  if(!ob) {
    write("You don't have such item.\n");
    return 1;
  }
  if(!this_object()->can_sell(ob) || this_player()->query_keep(ob) ||
	ob->id("money")) {
    if (ob) write("Cannot sell '"+ob->short()+"'.\n");
    return 1;
  }
  sscanf(file_name(ob), "%s#%s",file,tmp);
  value = ob->query_value() / 2;
  divider = objects[file] / 20 + 1;
  value = value / divider;
  if(value <0) value = 0;
  if (value == 0) { write(ob->short() + " has no value.\n"); return 1; }
  if (value > 1000) {
    write("The shopkeeper says '"+
	"Hmm.. I don't have enough money to buy this item.'\n");
    return 1;
  }
  if(value) "/room/bank"->add_bank_money(value, 3, this_player()->query_name());
  write("You sell "+ob->short()+" for "+value+" bronze coins. (coins transferred to your account)\n");
  say(this_player()->query_name()+" sells "+ob->short()+".\n");
  destruct(ob);
  add_item(file);
  add_balance(-value);
  this_player()->fix_weight();
  return 1;
}

buy_item(string arg) {
  object ob;
  string str,file,tmp;
  int i, value;
  str = m_indices(objects);
  if(!arg || sscanf(arg,"%d",i) != 1) {
    write("Usage: buy <number>\n");
    return 1;
  }
  i -= 1;
  if(i<0 || i>= sizeof(str)) {
    write("No such an item for sale.\n");
    return 1;
  }
  if(this_player()->query_wiz()) {
	write(str[i]+"\n");
  }
    
  if(!str[i]) { /* || file_size(str[i]+".c") == -1) { */
    write("That item is not for sale anymore, sorry.\n");
    return 1;
  }

  ob = clone_object(str[i]);
  value = ob->query_value();
  if(value > this_player()->query_money(3)) {
    write("You don't have enough bronze coins.\n");
    destruct(ob);
    return 1;
  }
  if(!this_player()->add_weight(ob->query_weight())) {
    write("You cannot carry it.\n");
    destruct(ob);
    return 1;
  }
  sscanf(file_name(ob), "%s#%s",file,tmp);
  reduce_item(file);
  this_player()->reduce_money(value,3, 1); /* 1 for selling */
  move_object(ob,this_player());
  write("You buy "+ob->short()+" for "+value+" bronzes.\n");
  say(this_player()->query_name()+" buys "+ob->short()+".\n");
  add_balance(value);
  return 1;
}

list_inventory() {
  object ob;
  int i,num;
  string str,tmp,tmp2,tmp3,tmp4,space;
  str = m_indices(objects);
  num = m_values(objects);
  space = "                                                   ";
  write("+----+-----------------------------------------+----+------+\n");
  write("|  # | Item:                                   |Left| Cost |\n");
  write("+----+-----------------------------------------+----+------+\n");
  while(i<sizeof(num)) {
    tmp = "| "+(i+1)+".| ";
    if(i<9) tmp = "|  "+(i+1)+".| ";
    if(str[i] && clone_object(str[i])) {
     ob = clone_object(str[i]);
     tmp2 = ob->short()+extract(space,0,38-strlen(ob->short()));
     tmp3 = " | "+num[i]+" |";
     if(num[i]<10) tmp3 = " |  "+num[i]+" |";
     tmp4 = ob->query_value()+"|";
     tmp4 = extract(space,0,6-strlen(tmp4))+tmp4;
     write(tmp+tmp2+tmp3+tmp4+"\n");
    }
    i+= 1;
  }
  write("+----+-----------------------------------------+----+------+\n");
  if (ob) destruct(ob);
  return 1;
}
