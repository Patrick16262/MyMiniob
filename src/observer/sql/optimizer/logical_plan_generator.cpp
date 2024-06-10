/* Copyright (c) 2023 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2023/08/16.
//

#include "sql/optimizer/logical_plan_generator.h"

#include <cassert>
#include <common/log/log.h>
#include <memory>
#include <type_traits>
#include <utility>

#include "sql/operator/calc_logical_operator.h"
#include "sql/operator/delete_logical_operator.h"
#include "sql/operator/explain_logical_operator.h"
#include "sql/operator/insert_logical_operator.h"
#include "sql/operator/join_logical_operator.h"
#include "sql/operator/logical_operator.h"
#include "sql/operator/predicate_logical_operator.h"
#include "sql/operator/project_logical_operator.h"
#include "sql/operator/table_get_logical_operator.h"

#include "sql/stmt/calc_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/explain_stmt.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/stmt.h"
#include "storage/field/field.h"
#include "storage/field/field_meta.h"
#include "storage/table/table.h"

using namespace std;

RC LogicalPlanGenerator::create(Stmt *stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  RC rc = RC::SUCCESS;
  switch (stmt->type()) {
    case StmtType::CALC: {
      CalcStmt *calc_stmt = static_cast<CalcStmt *>(stmt);

      rc = create_plan(calc_stmt, logical_operator);
    } break;

    case StmtType::SELECT: {
      SelectStmt *select_stmt = static_cast<SelectStmt *>(stmt);

      rc = create_plan(select_stmt, logical_operator);
    } break;

    case StmtType::INSERT: {
      InsertStmt *insert_stmt = static_cast<InsertStmt *>(stmt);

      rc = create_plan(insert_stmt, logical_operator);
    } break;

    case StmtType::DELETE: {
      DeleteStmt *delete_stmt = static_cast<DeleteStmt *>(stmt);

      rc = create_plan(delete_stmt, logical_operator);
    } break;

    case StmtType::EXPLAIN: {
      ExplainStmt *explain_stmt = static_cast<ExplainStmt *>(stmt);

      rc = create_plan(explain_stmt, logical_operator);
    } break;
    case StmtType::TABLE: {
      TableStmt *table_stmt = static_cast<TableStmt *>(stmt);

      rc = create_plan(table_stmt, logical_operator);
    } break;
    default: {
      LOG_WARN("unsupported stmt type: %d", stmt->type());
      assert(false);
      rc = RC::UNIMPLENMENT;
    }
  }
  return rc;
}

RC LogicalPlanGenerator::create_plan(CalcStmt *calc_stmt, std::unique_ptr<LogicalOperator> &logical_operator)
{
  return RC::UNIMPLENMENT;
  // logical_operator.reset(new CalcLogicalOperator(std::move(calc_stmt->expressions())));
  // return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(TableStmt *table_stmt, std::unique_ptr<LogicalOperator> &logical_operator)
{
  switch (table_stmt->relation_type()) {
    case RelationType::TABLE:
    case RelationType::SELECT:
    case RelationType::JOIN:
    case RelationType::VIEW: 
    default: {
      LOG_WARN("unsupported relation type: %d", table_stmt->relation_type());
      assert(false);
      return RC::UNIMPLENMENT;
    }
  }
}

RC LogicalPlanGenerator::create_plan(SelectStmt *select_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  logical_operator.reset(new ProjectLogicalOperator(select_stmt->project_expr_list(), select_stmt->tuple_schema()));

  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(InsertStmt *insert_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  return RC::UNIMPLENMENT;
  //   Table        *table = insert_stmt->table();
  //   vector<Value> values(insert_stmt->values(), insert_stmt->values() + insert_stmt->value_amount());

  //   InsertLogicalOperator *insert_operator = new InsertLogicalOperator(table, values);
  //   logical_operator.reset(insert_operator);
  //   return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(DeleteStmt *delete_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  return RC::UNIMPLENMENT;
  //   Table             *table       = delete_stmt->table();
  //   FilterStmt        *filter_stmt = delete_stmt->filter_stmt();
  //   std::vector<Field> fields;
  //   for (int i = table->table_meta().sys_field_num(); i < table->table_meta().field_num(); i++) {
  //     const FieldMeta *field_meta = table->table_meta().field(i);
  //     fields.push_back(Field(table, field_meta));
  //   }
  //   unique_ptr<LogicalOperator> table_get_oper(new TableGetLogicalOperator(table, fields,
  //   ReadWriteMode::READ_WRITE));

  //   unique_ptr<LogicalOperator> predicate_oper;
  //   RC                          rc = create_plan(filter_stmt, predicate_oper);
  //   if (rc != RC::SUCCESS) {
  //     return rc;
  //   }

  //   unique_ptr<LogicalOperator> delete_oper(new DeleteLogicalOperator(table));

  //   if (predicate_oper) {
  //     predicate_oper->add_child(std::move(table_get_oper));
  //     delete_oper->add_child(std::move(predicate_oper));
  //   } else {
  //     delete_oper->add_child(std::move(table_get_oper));
  //   }

  //   logical_operator = std::move(delete_oper);
  //   return rc;
}

RC LogicalPlanGenerator::create_plan(ExplainStmt *explain_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  unique_ptr<LogicalOperator> child_oper;

  Stmt *child_stmt = explain_stmt->child();

  RC rc = create(child_stmt, child_oper);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create explain's child operator. rc=%s", strrc(rc));
    return rc;
  }

  logical_operator = unique_ptr<LogicalOperator>(new ExplainLogicalOperator);
  logical_operator->add_child(std::move(child_oper));
  return rc;
}
