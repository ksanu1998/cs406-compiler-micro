ASTNode* root;
ID_List* id_lst;
list <toList*> myList;
list <char*> intList;
list <char*> floatList;
char* type;
map <char*, char*> stringList;
long long reg_count = 0;
list <IR*> ir_list;
IR* push;
int prim = 0;
vector <string> threeAC;
stringstream buffer;
list <new_threeAC*> threeAC_list;
list <Tiny*> tiny_list;
long long scope_count = 1;
list <string> conditions;

long long link_num;
int link_count_enable = 0;
list <char *> param_intList;
list <char *> param_floatList;
char return_reg[10];
int insert_expr_list = 0;
int from_call = 0;
list <ASTNode *> exprList;
list <char *> comp_exprList;
char comb_expr[40];
int from_call_expr = 0;
string call_expr_id;
char new_reg1[10];
char new_reg2[10];
char new_reg3[10];
long long return_reg_place = 0;

char temp1[10];
char temp2[10];
char temp3[10];

char* error() {
  for (int i = 0; i < myVector.size(); i++) {
    for (int j = i + 1; j < myVector.size(); j++) {
      if (strcmp(myVector[i], myVector[j]) == 0) {
        return myVector[i];
      }
    }
  }
  return NULL;
};

void clear_toList() {
  myList.clear();
}

char* findType(char* id) {
  list <char*>::iterator it;
  char* temp;
  for (it=intList.begin(); it!=intList.end(); ++it) {
    if (!strcmp(*it, id)) {
      temp = (char*)"INT";
      return temp;
    }
  }
  for (it=floatList.begin(); it!=floatList.end(); ++it) {
    if (!strcmp(*it, id)) {
      temp = (char*)"FLOAT";
      return temp;
    }
  }
  for (it=param_intList.begin(); it!=param_intList.end(); ++it) {
    if (!strcmp(*it, id)) {
      temp = (char*)"INT";
      return temp;
    }
  }
  for (it=param_floatList.begin(); it!=param_floatList.end(); ++it) {
    if (!strcmp(*it, id)) {
      temp = (char*)"FLOAT";
      return temp;
    }
  }
  temp = (char*)"STRING";
  return temp;
}

void print_sign(ASTNode* node) {
  cout << node -> sign << endl;
}
void print_id(ASTNode* node) {
  cout << node -> id << endl;
}

char* find_fromList(char* reg) {
  list<char *>::iterator it;
  long long count = 1;
  for (it=intList.begin(); it!=intList.end(); ++it) {
    if (!strcmp((*it), reg)) {
      strcpy(return_reg, "$");
      strcat(return_reg, to_string((count * -1)).c_str());
      return return_reg;
    }
    count++;
  }
  count = 1;
  for (it=floatList.begin(); it!=floatList.end(); ++it) {
    if (!strcmp((*it), reg)) {
      strcpy(return_reg, "$");
      strcat(return_reg, to_string((count * -1)).c_str());
      return return_reg;
    }
    count++;
  }
  count = 1;
  for (it=param_intList.begin(); it!=param_intList.end(); ++it) {
    if (!strcmp((*it), reg)) {
      strcpy(return_reg, "$");
      strcat(return_reg, to_string((count + 1)).c_str());
      return return_reg;
    }
    count++;
  }
  count = 1;
  for (it=param_floatList.begin(); it!=param_floatList.end(); ++it) {
    if (!strcmp((*it), reg)) {
      strcpy(return_reg, "$");
      strcat(return_reg, to_string((count + 1)).c_str());
      return return_reg;
    }
    count++;
  }
  return reg;
}

void print_fromList() {
  list<char *>::iterator it;
  int count = 1;
  for (it=intList.begin(); it!=intList.end(); ++it) {
    cout << (*it) << "intList " << count << endl;
  }
  for (it=floatList.begin(); it!=floatList.end(); ++it) {
    cout << (*it) << "floatList " << count << endl;
  }
  for (it=param_intList.begin(); it!=param_intList.end(); ++it) {
    cout << (*it) << "param_intList " << count << endl;
  }
  for (it=param_floatList.begin(); it!=param_floatList.end(); ++it) {
    cout << (*it) << "param_floatList " << count << endl;
  }
}

void push_ir(char* op, char* reg1, char* reg2, char* reg3) {
  push = new IR();
  push -> addOp(op);
  if (reg1 != NULL) {
    strcpy(new_reg1, find_fromList(reg1));
    push -> addReg1(new_reg1);
  }
  else {
    push -> addReg1(reg1);
  }
  if (reg2 != NULL) {
    strcpy(new_reg2, find_fromList(reg2));
    push -> addReg2(new_reg2);
  }
  else {
    push -> addReg2(reg2);
  }
  if (reg3 != NULL) {
    strcpy(new_reg3, find_fromList(reg3));
    push -> addReg3(new_reg3);
  }
  else {
    push -> addReg3(reg3);
  }
  buffer << ";" << push -> op << " " << push -> reg1 << " " << push -> reg2 << " " << push -> reg3 << endl;
  threeAC.push_back(buffer.str());
  buffer.str("");
}

void traverse(ASTNode* node, char* type, char* scope) {
  if (node == NULL) {
    return;
  }
  traverse(node -> left, type, scope);
  traverse(node -> right, type, scope);
  if (node -> sign != NULL) {
    if (!strcmp(node -> sign, "+")) {
      strcpy(temp1, "ADD");
      strcat(temp1, type);
      strcpy(temp2, "!T");
      strcat(temp2, to_string(reg_count).c_str());
      push_ir(temp1, node -> left -> id, node -> right -> id, (char*)temp2);
      node -> left = NULL;
      node -> right = NULL;
      char* temp3 = new char[10];
      strcpy(temp3, temp2);
      node -> id = temp3;
      node -> sign = NULL;
      node -> type = (char*)"REG";
      reg_count++;
    }
    else if (!strcmp(node -> sign, "-")) {
      strcpy(temp1, "SUB");
      strcat(temp1, type);
      strcpy(temp2, "!T");
      strcat(temp2, to_string(reg_count).c_str());
      push_ir(temp1, node -> left -> id, node -> right -> id, (char*)temp2);
      node -> left = NULL;
      node -> right = NULL;
      char* temp3 = new char[10];
      strcpy(temp3, temp2);
      node -> id = temp3;
      node -> sign = NULL;
      node -> type = (char*)"REG";
      reg_count++;
    }
    else if (!strcmp(node -> sign, "*")) {
      strcpy(temp1, "MUL");
      strcat(temp1, type);
      strcpy(temp2, "!T");
      strcat(temp2, to_string(reg_count).c_str());
      push_ir(temp1, node -> right -> id, node -> left -> id, (char*)temp2);
      node -> left = NULL;
      node -> right = NULL;
      char* temp3 = new char[10];
      strcpy(temp3, temp2);
      node -> id = temp3;
      node -> sign = NULL;
      node -> type = (char*)"REG";
      reg_count++;
    }
    else if (!strcmp(node -> sign, "/")) {
      strcpy(temp1, "DIV");
      strcat(temp1, type);
      strcpy(temp2, "!T");
      strcat(temp2, to_string(reg_count).c_str());
      push_ir(temp1, node -> right -> id, node -> left -> id, (char*)temp2);
      node -> left = NULL;
      node -> right = NULL;
      char* temp3 = new char[10];
      strcpy(temp3, temp2);
      node -> id = temp3;
      node -> sign = NULL;
      node -> type = (char*)"REG";
      reg_count++;
    }
    else if (!strcmp(node -> sign, ">")) {
      if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
        char* ty = findType(node -> right -> id);
        char* right_reg = find_fromList(node -> right -> id);
        if (!strcmp(ty, "INT")) {
          buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        else {
          buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        threeAC.push_back(buffer.str());
        buffer.str("");
        strcpy(temp1, "LE");
        strcat(temp1, type);
        char* temp_reg = new char[10];
        strcpy(temp_reg, "!T");
        strcat(temp_reg, to_string(reg_count).c_str());
        push_ir(temp1, node -> left -> id, temp_reg, scope);
        buffer.str("");
        reg_count++;
      }
      else {
        strcpy(temp1, "LE");
        strcat(temp1, type);
        push_ir(temp1, node -> left -> id, node -> right -> id, scope);
      }
      node -> left = NULL;
      node -> right = NULL;
      char* temp3 = new char[20];
      strcpy(temp3, temp2);
      node -> id = temp3;
      node -> sign = NULL;
      node -> type = (char*)"CONDITION";
      reg_count++;
    }
    else if (!strcmp(node -> sign, "!=")) {
      if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
        char* ty = findType(node -> right -> id);
        char* right_reg = find_fromList(node -> right -> id);
        if (!strcmp(ty, "INT")) {
          buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        else {
          buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        threeAC.push_back(buffer.str());
        buffer.str("");
        strcpy(temp1, "EQ");
        strcat(temp1, type);
        char* temp_reg = new char[10];
        strcpy(temp_reg, "!T");
        strcat(temp_reg, to_string(reg_count).c_str());
        push_ir(temp1, node -> left -> id, temp_reg, scope);
        buffer.str("");
        reg_count++;
      }
      else {
        strcpy(temp1, "EQ");
        strcat(temp1, type);
        push_ir(temp1, node -> left -> id, node -> right -> id, scope);
      }
      node -> left = NULL;
      node -> right = NULL;
      char* temp3 = new char[20];
      strcpy(temp3, temp2);
      node -> id = temp3;
      node -> sign = NULL;
      node -> type = (char*)"CONDITION";
      reg_count++;
    }
    else if (!strcmp(node -> sign, "=")) {
      if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
        char* ty = findType(node -> right -> id);
        char* right_reg = find_fromList(node -> right -> id);
        if (!strcmp(ty, "INT")) {
          buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        else {
          buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        threeAC.push_back(buffer.str());
        buffer.str("");
        strcpy(temp1, "NE");
        strcat(temp1, type);
        char* temp_reg = new char[10];
        strcpy(temp_reg, "!T");
        strcat(temp_reg, to_string(reg_count).c_str());
        push_ir(temp1, node -> left -> id, temp_reg, scope);
        buffer.str("");
        reg_count++;
      }
      else {
        strcpy(temp1, "NE");
        strcat(temp1, type);
        push_ir(temp1, node -> left -> id, node -> right -> id, scope);
      }
      node -> left = NULL;
      node -> right = NULL;
      char* temp3 = new char[20];
      strcpy(temp3, temp2);
      node -> id = temp3;
      node -> sign = NULL;
      node -> type = (char*)"CONDITION";
      reg_count++;
    }
    else if (!strcmp(node -> sign, "<")) {
      if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
        char* ty = findType(node -> right -> id);
        char* right_reg = find_fromList(node -> right -> id);
        if (!strcmp(ty, "INT")) {
          buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        else {
          buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        threeAC.push_back(buffer.str());
        buffer.str("");
        strcpy(temp1, "GE");
        strcat(temp1, type);
        char* temp_reg = new char[10];
        strcpy(temp_reg, "!T");
        strcat(temp_reg, to_string(reg_count).c_str());
        push_ir(temp1, node -> left -> id, temp_reg, scope);
        buffer.str("");
        reg_count++;
      }
      else {
        strcpy(temp1, "GE");
        strcat(temp1, type);
        push_ir(temp1, node -> left -> id, node -> right -> id, scope);
      }
      node -> left = NULL;
      node -> right = NULL;
      char* temp3 = new char[20];
      strcpy(temp3, temp2);
      node -> id = temp3;
      node -> sign = NULL;
      node -> type = (char*)"CONDITION";
      reg_count++;
    }
    else if (!strcmp(node -> sign, "<=")) {
      if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
        char* ty = findType(node -> right -> id);
        char* right_reg = find_fromList(node -> right -> id);
        if (!strcmp(ty, "INT")) {
          buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        else {
          buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        threeAC.push_back(buffer.str());
        buffer.str("");
        strcpy(temp1, "GT");
        strcat(temp1, type);
        char* temp_reg = new char[10];
        strcpy(temp_reg, "!T");
        strcat(temp_reg, to_string(reg_count).c_str());
        push_ir(temp1, node -> left -> id, temp_reg, scope);
        buffer.str("");
        reg_count++;
      }
      else {
        strcpy(temp1, "GT");
        strcat(temp1, type);
        push_ir(temp1, node -> left -> id, node -> right -> id, scope);
      }
      node -> left = NULL;
      node -> right = NULL;
      char* temp3 = new char[20];
      strcpy(temp3, temp2);
      node -> id = temp3;
      node -> sign = NULL;
      node -> type = (char*)"CONDITION";
      reg_count++;
    }
    else if (!strcmp(node -> sign, ">=")) {
      if (!(!strcmp(node -> right -> type, "INTLITERAL") || !strcmp(node -> right -> type, "FLOATLITERAL"))) {
        char* ty = findType(node -> right -> id);
        char* right_reg = find_fromList(node -> right -> id);
        if (!strcmp(ty, "INT")) {
          buffer << ";STOREI " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        else {
          buffer << ";STOREF " << right_reg << " !T" << to_string(reg_count) << endl;
        }
        threeAC.push_back(buffer.str());
        buffer.str("");
        strcpy(temp1, "LT");
        strcat(temp1, type);
        char* temp_reg = new char[10];
        strcpy(temp_reg, "!T");
        strcat(temp_reg, to_string(reg_count).c_str());
        push_ir(temp1, node -> left -> id, temp_reg, scope);
        buffer.str("");
        reg_count++;
      }
      else {
        strcpy(temp1, "LT");
        strcat(temp1, type);
        push_ir(temp1, node -> left -> id, node -> right -> id, scope);
      }
      node -> left = NULL;
      node -> right = NULL;
      char* temp3 = new char[20];
      strcpy(temp3, temp2);
      node -> id = temp3;
      node -> sign = NULL;
      node -> type = (char*)"CONDITION";
      reg_count++;
    }
  }
  else if (!strcmp(node -> type, "INTLITERAL")) {
    strcpy(temp2, "!T");
    strcat(temp2, to_string(reg_count).c_str());
    buffer << ";STOREI " << node -> id << " !T" << to_string(reg_count) << endl;
    threeAC.push_back(buffer.str());
    buffer.str("");
    node -> left = NULL;
    node -> right = NULL;
    char* temp3 = new char[10];
    strcpy(temp3, temp2);
    node -> id = temp3;
    node -> sign = NULL;
    node -> type = (char*)"INTLITERAL";
    reg_count++;
  }
  else if (!strcmp(node -> type, "FLOATLITERAL")) {
    strcpy(temp2, "!T");
    strcat(temp2, to_string(reg_count).c_str());
    buffer << ";STOREF " << node -> id << " !T" << to_string(reg_count) << endl;
    threeAC.push_back(buffer.str());
    buffer.str("");
    node -> left = NULL;
    node -> right = NULL;
    char* temp3 = new char[10];
    strcpy(temp3, temp2);
    node -> id = temp3;
    node -> sign = NULL;
    node -> type = (char*)"FLOATLITERAL";
    reg_count++;
  }
}

void print_toList() {
  list<toList*>::iterator it;
  for (it=myList.begin(); it!=myList.end(); ++it) {
    if (!strcmp((*it) -> op, "IF_COND_START")) {
      if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "INT")) {
        char* ifstart = new char[20];
        strcpy(ifstart, "ELSE_");
        strcat(ifstart, to_string(scope_count++).c_str());
        //push to condition list
        conditions.push_back(ifstart);
        traverse((*it) -> node, (char*)"I", ifstart);
      }
      else if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "FLOAT")) {
        char* ifstart = new char[20];
        strcpy(ifstart, "ELSE_");
        strcat(ifstart, to_string(scope_count++).c_str());
        //push to condition list
        conditions.push_back(ifstart);
        traverse((*it) -> node, (char*)"F", ifstart);
      }
    }
    else if (!strcmp((*it) -> op, "IF_COND_END")) {
      //FIND END_IF_ELSE_
      size_t found;
      char* return_if_else = new char[20];
      list<string>::reverse_iterator rev_it;
      for (rev_it=conditions.rbegin(); rev_it!=conditions.rend(); ++rev_it) {
        found = (*rev_it).find("END_IF_ELSE_");
        if (found == 0) {
          strcpy(return_if_else, (*rev_it).c_str());
          break;
        }
      }
      buffer << ";LABEL " << return_if_else << endl;
      threeAC.push_back(buffer.str());
      buffer.str("");
      conditions.remove(return_if_else);
    }
    else if (!strcmp((*it) -> op, "WHILE_COND_START")) {
      if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "INT")) {
        buffer << ";LABEL WHILE_START_" << to_string(scope_count).c_str() << endl;
        threeAC.push_back(buffer.str());
        buffer.str("");
        //push to condition list
        buffer << "WHILE_START_" << to_string(scope_count++).c_str() << endl;
        conditions.push_back(buffer.str());
        buffer.str("");
        char* whileend = new char[20];
        strcpy(whileend, "WHILE_END_");
        strcat(whileend, to_string(scope_count++).c_str());
        conditions.push_back(whileend);
        traverse((*it) -> node, (char*)"I", whileend);
      }
      else if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "FLOAT")) {
        buffer << ";LABEL WHILE_START_" << to_string(scope_count).c_str() << endl;
        threeAC.push_back(buffer.str());
        buffer.str("");
        //push to condition list
        buffer << "WHILE_START_" << to_string(scope_count++).c_str() << endl;
        conditions.push_back(buffer.str());
        buffer.str("");
        char* whileend = new char[20];
        strcpy(whileend, "WHILE_END_");
        strcat(whileend, to_string(scope_count++).c_str());
        conditions.push_back(whileend);
        traverse((*it) -> node, (char*)"F", whileend);
      }
    }

    else if (!strcmp((*it) -> op, "WHILE_COND_END")) {
      //FIND WHILE_START_
      size_t found;
      char* return_while_start = new char[20];
      list<string>::reverse_iterator rev_it;
      for (rev_it=conditions.rbegin(); rev_it!=conditions.rend(); ++rev_it) {
        found = (*rev_it).find("WHILE_START_");
        if (found == 0) {
          strcpy(return_while_start, (*rev_it).c_str());
          break;
        }
      }
      buffer << ";JUMP " << return_while_start << endl;
      threeAC.push_back(buffer.str());
      buffer.str("");
      conditions.remove(return_while_start);

      //FIND WHILE_START_
      char* return_while_end = new char[20];
      for (rev_it=conditions.rbegin(); rev_it!=conditions.rend(); ++rev_it) {
        found = (*rev_it).find("WHILE_END_");
        if (found == 0) {
          strcpy(return_while_end, (*rev_it).c_str());
          break;
        }
      }
      buffer << ";LABEL " << return_while_end << endl;
      threeAC.push_back(buffer.str());
      buffer.str("");
      conditions.remove(return_while_end);
    }

    else if (!strcmp((*it) -> op, "ELSE_COND")) {
      buffer << ";JUMP END_IF_ELSE_" << to_string(scope_count).c_str() << endl;
      threeAC.push_back(buffer.str());
      buffer.str("");

      //push to condition list
      buffer << "END_IF_ELSE_" << to_string(scope_count++).c_str() << endl;
      conditions.push_back(buffer.str());
      buffer.str("");

      //FIND ELSE_
      size_t found;
      char* return_else_label = new char[10];
      list<string>::reverse_iterator rev_it;
      for (rev_it=conditions.rbegin(); rev_it!=conditions.rend(); ++rev_it) {
        found = (*rev_it).find("ELSE_");
        if (found == 0) {
          strcpy(return_else_label, (*rev_it).c_str());
          break;
        }
      }
      buffer << ";LABEL " << return_else_label << endl;
      threeAC.push_back(buffer.str());
      buffer.str("");
      conditions.remove(return_else_label);
    }
    else if (!strcmp((*it) -> op, "ASSIGN")) {
      if ((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "INT")) {
        traverse((*it) -> node, (char*)"I", NULL);
        if ((!strcmp((*it) -> node -> type, "INT") || !strcmp((*it) -> node -> type, "FLOAT")) && from_call_expr == 0) {
          buffer << ";STOREI " << (*it) -> node -> id << " !T" << to_string(reg_count) << endl;
          threeAC.push_back(buffer.str());
          buffer.str("");
          buffer << ";STOREI " << " !T" << to_string(reg_count) << " !T" << to_string(reg_count + 1) << endl;
          threeAC.push_back(buffer.str());
          buffer.str("");
          reg_count++;
          buffer << ";STOREI " << "!T" << to_string(reg_count) << " " << (*it) -> destination << endl;
          threeAC.push_back(buffer.str());
          buffer.str("");
          reg_count++;
        }
        else {
          reg_count--;
          if (from_call_expr == 0) {
            /*
            buffer << ";STOREI " << " !T" << to_string(reg_count) << " !T" << to_string(reg_count + 1) << endl;
            threeAC.push_back(buffer.str());
            buffer.str("");
            */
            char* dest_id = find_fromList((*it) -> destination);
            buffer << ";STOREI " << "!T" << to_string(reg_count++) << " " << dest_id << endl;
            threeAC.push_back(buffer.str());
            buffer.str("");
            reg_count++;
          }
        }
      }
      else if (((*it) -> destination_type != NULL && !strcmp((*it) -> destination_type, "FLOAT")) && from_call_expr == 0) {
        traverse((*it) -> node, (char*)"F", NULL);
        if (!strcmp((*it) -> node -> type, "INT") || !strcmp((*it) -> node -> type, "FLOAT")) {
          buffer << ";STOREF " << (*it) -> node -> id << " !T" << to_string(reg_count) << endl;
          threeAC.push_back(buffer.str());
          buffer.str("");
          buffer << ";STOREF " << " !T" << to_string(reg_count) << " !T" << to_string(reg_count + 1) << endl;
          threeAC.push_back(buffer.str());
          buffer.str("");
          reg_count++;
          buffer << ";STOREF " << "!T" << to_string(reg_count) << " " << (*it) -> destination << endl;
          threeAC.push_back(buffer.str());
          buffer.str("");
          reg_count++;
        }
        else {
          reg_count--;
          if (from_call_expr == 0) {
            /*
            buffer << ";STOREF " << " !T" << to_string(reg_count) << " !T" << to_string(reg_count + 1) << endl;
            threeAC.push_back(buffer.str());
            buffer.str("");
            */
            char* dest_id = find_fromList((*it) -> destination);
            buffer << ";STOREF " << "!T" << to_string(reg_count) << " " << dest_id << endl;
            threeAC.push_back(buffer.str());
            buffer.str("");
            reg_count++;
          }
        }
      }
    }
    else if (!strcmp((*it) -> op, "READ") || !strcmp((*it) -> op, "WRITE")) {
      while ((*it) -> ids != NULL) {
        char* temp;
        temp = findType((*it) -> ids -> id);
        char variable[20];
        strcpy(variable,find_fromList((*it) -> ids -> id));
        if (!strcmp(temp, "INT")) {
          buffer << ";" << (*it) -> destination << "I " << variable << endl;
          threeAC.push_back(buffer.str());
          buffer.str("");
          (*it) -> ids = (*it) -> ids -> id_tail;
        }
        else if (!strcmp(temp, "FLOAT")) {
          buffer << ";" << (*it) -> destination << "F " << variable << endl;
          threeAC.push_back(buffer.str());
          buffer.str("");
          (*it) -> ids = (*it) -> ids -> id_tail;
        }
        else {
          buffer << ";" << (*it) -> destination << "S " << variable << endl;
          threeAC.push_back(buffer.str());
          buffer.str("");
          (*it) -> ids = (*it) -> ids -> id_tail;
        }
      }
    }
    else if (!strcmp((*it) -> op, "RETURN")) {
      if ((*it) -> node -> id != NULL) {
        char variable[10];
        strcpy(variable,find_fromList((*it) -> node -> id));
        buffer << ";STORE" << (*it) -> node -> type[0] << " " << variable << " !T" << to_string(reg_count) << endl;
        threeAC.push_back(buffer.str());
        buffer.str("");
        buffer << ";STORE" << (*it) -> node -> type[0] << " !T" << to_string(reg_count) << " $" << to_string(6 + return_reg_place) << endl;
        reg_count++;
        threeAC.push_back(buffer.str());
        buffer.str("");
      }
      else {
        char* type_return = findType((*it) -> node -> right -> id);
        if (!strcmp(type_return, "INT")) {
          traverse((*it) -> node, (char*)"I", NULL);
        }
        else {
          traverse((*it) -> node, (char*)"F", NULL);
        }
        buffer << ";STORE" << type_return[0] << " !T" << to_string(reg_count - 1) << " $" << to_string(6 + return_reg_place) << endl;
        reg_count++;
        threeAC.push_back(buffer.str());
        buffer.str("");
      }
      buffer << ";UNLINK" << endl;
      threeAC.push_back(buffer.str());
      buffer.str("");
      buffer << ";RET" << endl;
      threeAC.push_back(buffer.str());
      buffer.str("");
    }
  }
}

void print_buffer() {
  vector<string>::iterator it;
  for (it=threeAC.begin(); it!=threeAC.end(); ++it) {
    cout << (*it);
  }
}

void print_threeAC() {
  list<new_threeAC*>::iterator it;
  for (it=threeAC_list.begin(); it!=threeAC_list.end(); ++it) {
    cout << (*it) -> op << " " << (*it) -> reg1 << " " << (*it) -> reg2 << " " << (*it) -> reg3 << " " << endl;
  }
}

void insert_threeAC() {
  vector<string>::iterator it;
  for (it=threeAC.begin(); it!=threeAC.end(); ++it) {
    istringstream buf((*it));
    istream_iterator<string> beg(buf), end;
    vector<string> tokens(beg, end);
    new_threeAC* newthreeAC = new new_threeAC();
    vector<string>::iterator its;
    for(its=tokens.begin(); its!=tokens.end(); ++its) {
      if ((newthreeAC -> op).empty()) {
        newthreeAC -> addOp((*its));
      }
      else if ((newthreeAC -> reg1).empty()) {
        newthreeAC -> addReg1((*its));
      }
      else if ((newthreeAC -> reg2).empty()) {
        newthreeAC -> addReg2((*its));
      }
      else if ((newthreeAC -> reg3).empty()) {
        newthreeAC -> addReg3((*its));
      }
    }
    threeAC_list.push_back(newthreeAC);
  }
}

void print_tinylist() {
  list<Tiny*>::iterator it;
  for (it=tiny_list.begin(); it!=tiny_list.end(); ++it) {
    cout << (*it) -> op << " " << (*it) -> reg1 << " " << (*it) -> reg2 << " " << endl;
  }
}

void addTinyList() {
  list<char*>::iterator it;
  /*
  for (it=intList.begin(); it!=intList.end(); ++it) {
    Tiny* tiny = new Tiny();
    string s = string("var");
    tiny -> addOp(s);
    tiny -> addReg1((*it));
    tiny_list.push_back(tiny);
  }
  for (it=floatList.begin(); it!=floatList.end(); ++it) {
    Tiny* tiny = new Tiny();
    string s = string("var");
    tiny -> addOp(s);
    tiny -> addReg1((*it));
    tiny_list.push_back(tiny);
  }
  */
  map<char*, char*>::iterator iter;
  for (iter=stringList.begin(); iter!=stringList.end(); ++iter) {
    Tiny* tiny = new Tiny();
    string s = string("str");
    string s2 = string(iter -> first);
    string s3 = string(iter -> second);
    tiny -> addOp(s);
    tiny -> addReg1(s2);
    tiny -> addReg2(s3);
    tiny_list.push_back(tiny);
  }
  list<new_threeAC*>::iterator its;
  for (its=threeAC_list.begin(); its!=threeAC_list.end(); ++its) {
    string operation = string((*its) -> op);
    operation.erase(0,1);
    if (operation == "STOREI" || operation == "STOREF") {
      Tiny* tiny = new Tiny();
      string s = string("move");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
    }
    else if (operation == "PUSHREGS") {
      long long count_push_register = 0;
      for (count_push_register = 0; count_push_register < 4; count_push_register++) {
        Tiny* tiny = new Tiny();
        string s = string("push");
        string s2 = string("r" + to_string(count_push_register));
        tiny -> addOp(s);
        tiny -> addReg1(s2);
        tiny_list.push_back(tiny);
      }
    }
    else if (operation == "POPREGS") {
      long long count_pop_register = 3;
      for (count_pop_register = 3; count_pop_register > -1; count_pop_register--) {
        Tiny* tiny = new Tiny();
        string s = string("pop");
        string s2 = string("r" + to_string(count_pop_register));
        tiny -> addOp(s);
        tiny -> addReg1(s2);
        tiny_list.push_back(tiny);
      }
    }

    else if (operation == "WRITEI") {
      Tiny* tiny = new Tiny();
      string s = string("sys");
      string s2 = string("writei");
      string s3 = string((*its) -> reg1);
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
    }
    else if (operation == "UNLINK") {
      Tiny* tiny = new Tiny();
      string s = string("unlnk");
      tiny -> addOp(s);
      tiny_list.push_back(tiny);
    }
    else if (operation == "HALT") {
      Tiny* tiny = new Tiny();
      string s = string("sys halt");
      tiny -> addOp(s);
      tiny_list.push_back(tiny);
    }
    else if (operation == "RET") {
      Tiny* tiny = new Tiny();
      string s = string("ret");
      tiny -> addOp(s);
      tiny_list.push_back(tiny);
    }
    else if (operation == "WRITEF") {
      Tiny* tiny = new Tiny();
      string s = string("sys");
      string s2 = string("writer");
      string s3 = string((*its) -> reg1);
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
    }
    else if (operation == "WRITES") {
      Tiny* tiny = new Tiny();
      string s = string("sys");
      string s2 = string("writes");
      string s3 = string((*its) -> reg1);
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
    }
    else if (operation == "READI") {
      Tiny* tiny = new Tiny();
      string s = string("sys");
      string s2 = string("readi");
      string s3 = string((*its) -> reg1);
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
    }
    else if (operation == "READF") {
      Tiny* tiny = new Tiny();
      string s = string("sys");
      string s2 = string("readr");
      string s3 = string((*its) -> reg1);
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
    }
    else if (operation == "ADDI") {
      Tiny* tiny = new Tiny();
      string s = string("move");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string s4 = string((*its) -> reg3);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      if (s4.find("!T") != string::npos) {
        s4.erase(0,2);
        s4 = r + s4;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s4);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("addi");
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s3);
      tiny2 -> addReg2(s4);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "SUBI") {
      Tiny* tiny = new Tiny();
      string s = string("move");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string s4 = string((*its) -> reg3);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      if (s4.find("!T") != string::npos) {
        s4.erase(0,2);
        s4 = r + s4;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s4);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("subi");
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s3);
      tiny2 -> addReg2(s4);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "MULI") {
      Tiny* tiny = new Tiny();
      string s = string("move");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string s4 = string((*its) -> reg3);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      if (s4.find("!T") != string::npos) {
        s4.erase(0,2);
        s4 = r + s4;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s4);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("muli");
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s3);
      tiny2 -> addReg2(s4);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "DIVI") {
      Tiny* tiny = new Tiny();
      string s = string("move");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string s4 = string((*its) -> reg3);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      if (s4.find("!T") != string::npos) {
        s4.erase(0,2);
        s4 = r + s4;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s4);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("divi");
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s3);
      tiny2 -> addReg2(s4);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "ADDF") {
      Tiny* tiny = new Tiny();
      string s = string("move");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string s4 = string((*its) -> reg3);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      if (s4.find("!T") != string::npos) {
        s4.erase(0,2);
        s4 = r + s4;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s4);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("addr");
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s3);
      tiny2 -> addReg2(s4);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "SUBF") {
      Tiny* tiny = new Tiny();
      string s = string("move");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string s4 = string((*its) -> reg3);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      if (s4.find("!T") != string::npos) {
        s4.erase(0,2);
        s4 = r + s4;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s4);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("subr");
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s3);
      tiny2 -> addReg2(s4);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "MULF") {
      Tiny* tiny = new Tiny();
      string s = string("move");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string s4 = string((*its) -> reg3);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      if (s4.find("!T") != string::npos) {
        s4.erase(0,2);
        s4 = r + s4;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s4);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("mulr");
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s3);
      tiny2 -> addReg2(s4);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "DIVF") {
      Tiny* tiny = new Tiny();
      string s = string("move");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string s4 = string((*its) -> reg3);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      if (s4.find("!T") != string::npos) {
        s4.erase(0,2);
        s4 = r + s4;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s4);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("divr");
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s3);
      tiny2 -> addReg2(s4);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "PUSH") {
      Tiny* tiny = new Tiny();
      string s = string("push ");
      string s1 = string((*its) -> reg1);
      string r = string("r");
      if (s1.find("!T") != string::npos) {
        s1.erase(0,2);
        s1 = r + s1;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s1);
      tiny_list.push_back(tiny);
    }
    else if (operation == "POP") {
      Tiny* tiny = new Tiny();
      string s = string("pop ");
      string s1 = string((*its) -> reg1);
      string r = string("r");
      if (s1.find("!T") != string::npos) {
        s1.erase(0,2);
        s1 = r + s1;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s1);
      tiny_list.push_back(tiny);
    }
    else if (operation == "JSR") {
      Tiny* tiny = new Tiny();
      string s = string("jsr ");
      string s2 = string((*its) -> reg1);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny_list.push_back(tiny);
    }
    else if (operation == "LABEL") {
      Tiny* tiny = new Tiny();
      string s = string("label ");
      string s2 = string((*its) -> reg1);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny_list.push_back(tiny);
    }
    else if (operation == "JUMP") {
      Tiny* tiny = new Tiny();
      string s = string("jmp ");
      string s2 = string((*its) -> reg1);
      string r = string("r");
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny_list.push_back(tiny);
    }
    else if (operation == "LINK") {
      Tiny* tiny = new Tiny();
      string s = string("link ");
      string s2 = string((*its) -> reg1);
      string r = string("r");
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny_list.push_back(tiny);
    }
    else if (operation == "EQI") {
      Tiny* tiny = new Tiny();
      string s = string("cmpi ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jeq ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "NEI") {
      Tiny* tiny = new Tiny();
      string s = string("cmpi ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jne ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "LEI") {
      Tiny* tiny = new Tiny();
      string s = string("cmpi ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jle ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "GEI") {
      Tiny* tiny = new Tiny();
      string s = string("cmpi ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jge ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "GTI") {
      Tiny* tiny = new Tiny();
      string s = string("cmpi ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jgt ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "LTI") {
      Tiny* tiny = new Tiny();
      string s = string("cmpi ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jlt ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "EQF") {
      Tiny* tiny = new Tiny();
      string s = string("cmpr ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jeq ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "NEF") {
      Tiny* tiny = new Tiny();
      string s = string("cmpr ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jne ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "LEF") {
      Tiny* tiny = new Tiny();
      string s = string("cmpr ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jle ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "GEF") {
      Tiny* tiny = new Tiny();
      string s = string("cmpr ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jge ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "GTF") {
      Tiny* tiny = new Tiny();
      string s = string("cmpr ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jgt ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
    else if (operation == "LTF") {
      Tiny* tiny = new Tiny();
      string s = string("cmpr ");
      string s2 = string((*its) -> reg1);
      string s3 = string((*its) -> reg2);
      string r = string("r");
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      if (s3.find("!T") != string::npos) {
        s3.erase(0,2);
        s3 = r + s3;
      }
      tiny -> addOp(s);
      tiny -> addReg1(s2);
      tiny -> addReg2(s3);
      tiny_list.push_back(tiny);
      Tiny* tiny2 = new Tiny();
      s = string("jlt ");
      s2 = string((*its) -> reg3);
      if (s2.find("!T") != string::npos) {
        s2.erase(0,2);
        s2 = r + s2;
      }
      tiny2 -> addOp(s);
      tiny2 -> addReg1(s2);
      tiny_list.push_back(tiny2);
    }
  }
}

void print_conditions() {
  list<string>::iterator it;
  for (it=conditions.begin(); it!=conditions.end(); ++it) {
    cout << (*it) << endl;
  }
}

void clear_varlist() {
  intList.clear();
  floatList.clear();
  param_intList.clear();
  param_floatList.clear();
  exprList.clear();
  comp_exprList.clear();
}

void combine_expr(ASTNode* exprNode) {
  if (exprNode == NULL) {
    return;
  }
  combine_expr(exprNode -> left);
  if (comb_expr[0] == '\0') {
    if (exprNode -> id) {
      strcpy(comb_expr, exprNode -> id);
    }
    else if (exprNode -> sign) {
      strcpy(comb_expr, exprNode -> sign);
    }
  }
  else {
    if (exprNode -> id) {
      strcat(comb_expr, exprNode -> id);
    }
    else if (exprNode -> sign) {
      strcat(comb_expr, exprNode -> sign);
    }
  }
  combine_expr(exprNode -> right);
}

void print_exprList() {
  list<char*>::iterator it;
  for (it=comp_exprList.begin(); it!=comp_exprList.end(); ++it) {
    cout << (*it) << endl;
  }
}

//WORK ON HARDCOPY
void push_comp_exprList() {
  list<ASTNode *>::iterator it;
  for (it=exprList.begin(); it!=exprList.end(); ++it) {
    combine_expr((*it));
    char* cpyexpr = new char[40];
    strcpy(cpyexpr, comb_expr);
    comp_exprList.push_back(cpyexpr);
    memset(comb_expr, 0, sizeof(comb_expr));
  }
}
