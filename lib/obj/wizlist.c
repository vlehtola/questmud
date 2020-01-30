string wiz_scores;

reset(arg) {
  if(arg) { return; }
  if (!restore_object("data/wizlist")) {
    wiz_scores = allocate(51);
    save_object("data/wizlist");
  }
}

list() {
  int i, num, rank;
  string str;
  write("List of awards:\n");
  while(i < sizeof(wiz_scores) - 1) {
    if(wiz_scores[i]) {
      str = explode(wiz_scores[i], " ");
      num += 1;
      rank = i + 1;
      write(rank+": "+implode(str, "\t") + " levels\n");
    }
    i += 1;
  }
  return num;
}

update_list(name,num) {  
  int i, score, old_place, new_score;
  string nimi;
  write("Started updating.."+num+"\n");
  i = 50;
  while(i >= 0) {
    if(wiz_scores[i]) {  
      if(sscanf(wiz_scores[i], "%s %d", nimi, score) != 2) {
        write("BUG BUG! Wizlist is bugged.\n");
        return 1;
      }
      if(lower_case(nimi) == lower_case(name)) {
        write("Wiz found.\n");
        new_score = score + num;
        old_place = i;
      }
      if (new_score && new_score < score || i == 0 && new_score) {
        write("Wr:score: "+new_score+", new_place - 1: " + i + "\n");
        if (new_score < score) {
            i += 1;
        }
        make_change(name,new_score,old_place,i);
        return 1;
      }
    }
    i -= 1;
  }
  if(!wiz_scores[0] && new_score) {
    write("No other wizzes found.\n");
    make_change(name,new_score,0,0);
    return 1;
  }
  add_new_wiz(name,num);
  return 1;
}

add_new_wiz(name,num) {
  wiz_scores[50] = name + " 0";
  write("Made a new wiz..starting from beginning.\n");
  update_list(name,num);
  return 1;
}

make_change(name,score,old_place,new_place) {
  int i;
  i = old_place;
  if(old_place == new_place) {
    save_list(name,score,new_place);
    return 1;
  }
  while(i > new_place) {
    if (i == 0) {
       break; 
    }
    wiz_scores[i] = wiz_scores[i-1];  
    i -= 1;
  }
  write("New place: " + new_place + "\n");
  wiz_scores[new_place] = name + " " + score;
  save_list(name,score,new_place);
  return 1;
}

save_list(name,score,num) {
  write("New place: "+num+"\n");
  wiz_scores[num] = name + " " + score;
  save_object("data/wizlist");
  write("Wizlist updated.\n");
  return 1;
}
