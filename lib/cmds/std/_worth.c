worthi(ob) {

        int i,a;
        string stemp,stemp2;
        object player;

        if(ob) player = ob;
        else player = this_player();

        stemp = player->query_total_string();

        if(strlen(stemp) <= 6) return "Below 1 M";
        stemp2 = "";
        a = strlen(stemp);
        a -= 6;
        for(i=0;i<a;i++) {

                stemp2 += stemp[i..i];
        }

a = to_int(stemp2);

if(a>=1000) {
        stemp = ((a-(a%1000))/1000)+"G ";
        a=a%1000;
        stemp += a+"M";
}
else stemp = a+"M";

return stemp;

}

cmd_worth(string arg) {
  object tp;
  if(arg && this_player()->query_wiz())
    tp = find_player(arg);
  if(!tp) tp = this_player();
  write("Total worth: "+worthi(tp)+"\n");
  return 1;
}
