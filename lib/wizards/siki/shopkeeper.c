//#define ROOM_COST 30000
//#define CHEST_COST 100000
//#define GUARD_COST 4000

#define ROOM_COST 50000
#define CHEST_COST 10000
#define GUARD_COST 5000
#define DEMO_COST 10000
#define MASTERKEY_COST 30000

inherit "obj/monster";

int cost;
string *label;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(95);
  set_name("duran");
  set_alias("shopkeeper");
  set_short("Duran Blackblade");
  set_long("Duran Blackblade, the castle shop keeper.\n");
  set_race("dwarf");
  set_aggressive(0);
  set_random_pick(0);
  set_regen(query_max_hp()/20);
  set_resists("physical", 90);
  set_al(0);
  set_max_hp(query_max_hp()*5);
  set_str(query_str()*10);
  set_gender(1);
  set_mage(1);
  set_exp(1000000);
}

void init() {
  ::init();
  add_action("list", "list");
  add_action("buy", "buy");
  add_action("countries", "countries");
  add_action("view", "view");
}

buy(arg) {
  string *file;
  int i, type, rooms, b_type, alloc, index;

  file = explode(read_file("/castle/castle_list"), "\n");
  sscanf(file[0], "castles: %d", alloc);
  cost = allocate(alloc);
  for(i=0; i<sizeof(file); i++) {
    if(sscanf(file[i], "num_rooms[%d] = %d", type, rooms) == 2) cost[type] = rooms*ROOM_COST;
  }

  if(!arg) {
    write("Duran says 'Buy WHAT?'\n");
    return 1;
  }
  if(sscanf(arg, "%d", index) != 1) {
    if(sscanf(arg, "castle %d", b_type)) {
      write("Duran grunts 'Ah, now we'r getting into business..\n");

      if(b_type > alloc) {
	write("Duran grunts 'Not selling that type of castle here.'\n");
	return 1;
      }
      if(this_player()->query_money(3) < cost[b_type]) {
	write("Duran grunts '..But you don't have '"+cost[b_type]+"' bronze coins!\n");
	return 1;
      }

      buy_castlecube(b_type);
      return 1;
    }
    else {
      write("Duran grunts 'Not selling that type of castle here.'\n");
      return 1;
    }
  }
  else {
    switch(index) {
    case 1:
      if(this_player()->query_money(3) < CHEST_COST) {
	write("Duran grunts 'You do not have '"+CHEST_COST+"' bronze coins!\n");
      }
      else {
	buy_chest();
      }
      break;
    case 2:
      if(this_player()->query_money(3) < GUARD_COST) {
        write("Duran grunts 'You do not have '"+GUARD_COST+"' bronze coins!\n");
      }
      else {
        buy_figu();
      }
      break;
    case 3:
      if(this_player()->query_money(3) < DEMO_COST) {
        write("Duran grunts 'You do not have '"+DEMO_COST+"' bronze coins!\n");
      }
      else {
        buy_democube();
      }
      break;
    case 4:
      if(this_player()->query_money(3) < MASTERKEY_COST) {
        write("Duran grunts 'You do not have '"+MASTERKEY_COST+"' bronze coins!\n");
      }
      else {
        buy_masterkey();
      }
      break;
    default:
      write("Duran grunts 'Hmpf, not selling one of those to you.'\n");
    }

    return 1;
  }
}

write_castle_prizes() {
  int *cost, rooms, type, i, alloc;
  string *file, labels;

  file = explode(read_file("/castle/castle_list"), "\n");
  sscanf(file[0], "castles: %d", alloc);
  cost = allocate(alloc);
  label = allocate(alloc);

  for(i=0; i<sizeof(file); i++) {
    if(sscanf(file[i], "num_rooms[%d] = %d", type, rooms) == 2) {
      cost[type] = rooms*ROOM_COST;
    }
    if(sscanf(file[i], "label[%d] = %s", type, labels) == 2) label[type] = labels;
  }

  for(i=0; i<sizeof(cost); i++) {
    write(sprintf("|%3d |%15s |%7d bronze |\n", i, label[i], cost[i]));
    //write("| "+i+"  | "+cost[i]+" bronze\n");
  }
  return 1;
}

buy_castlecube(int type) {
  object chest;

  chest = clone_object("/castle/obj/castle_cube");
  chest->set_type(type);
  chest->set_cost(cost[type]);
  chest->set_label(label[type]);
  move_object(chest, this_player());
  write("Duran takes your money, and gives you a small cube.\n");
  return 1;
}

buy_masterkey(int type) {
  object chest;

  chest = clone_object("/castle/obj/masterkey");
  move_object(chest, this_player());
  chest->set_type(type);
  chest->set_cost(cost[type]);
  chest->set_label(type);
  write("Duran takes your money, and gives you masterkey.\n");
  return 1;
}

buy_democube(int type) {
  object chest;

  chest = clone_object("/castle/obj/castle_democube");
  move_object(chest, this_player());
  write("Duran takes your money, and gives you a small cube.\n");
  return 1;
}

buy_chest() {
  object chest;

  chest = clone_object("/castle/obj/chest");
  move_object(chest, this_player());
  write("Duran takes your money, and gives you a chest.\n");
  return 1;
}

buy_figu() {
  object chest;

  chest = clone_object("/castle/obj/castle_guard_figurine");
  move_object(chest, this_player());
  write("Duran takes your money, and gives you a figurine.\n");
  return 1;
}

view(arg) {
  string a, d1, d2;

  if(!arg) {
    write("No such castle with that ID.\n");
    return 1;
  }
  if(sscanf(arg, "%s %s", d1, d2) == 2) {
    write("No such castle with that ID.\n");
    return 1;
  }
  if(file_size(a = "/castle/blueprints/"+arg) != -1) cat(a);
  else write("No such castle with that ID.\n");
  return 1;
}

list() {
  write(" ID:  Item:                                  Cost:\n");
  write("+----+--------------------------------------+---------------+\n");
  write(sprintf("|  1 | Chest (10 slots)                     |%7d bronze |\n", CHEST_COST));
  write(sprintf("|  2 | Figurine of guard (basic guard)      |%7d bronze |\n", GUARD_COST));
  write(sprintf("|  3 | Demolition kit                       |%7d bronze |\n", DEMO_COST));
  write(sprintf("|  4 | Masterkey                            |%7d bronze |\n", MASTERKEY_COST));
  write("+-------------------------------------------+---------------+\n");
  write("\n Castles\n");
  write(" ID:  Name:            Cost:\n");
  write("+----+----------------+---------------+\n");
  write_castle_prizes();
  write("+----+----------------+---------------+\n");
  return 1;
}
