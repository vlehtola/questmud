status cmd_clones() {
  int i,x;
  mapping clones;
  object *all;
  string *ip;
  all = users();
  clones = ([ ]);

  for(i=0;i<sizeof(all);i++) {
     if(!clones[query_ip_number(all[i])]) clones += ([ query_ip_number(all[i]):({ capitalize(all[i]->query_name(1)), }), ]);
     else clones[query_ip_number(all[i])] += ({ capitalize(all[i]->query_name(1)), });
  }

  write("Here are the people sorted by their IP-number into groups:\n");
  ip = m_indices(clones);

  for(i=0;i<sizeof(ip);i++) {
     write(ip[i]+" : ");
     for(x=0;x<sizeof(clones[ip[i]]);x++)
        write(clones[ip[i]][x]+", ");
     write("\n");
  }
return 1;
}

