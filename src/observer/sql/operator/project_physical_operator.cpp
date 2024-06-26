/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by WangYunlai on 2022/07/01.
//

#include "sql/operator/project_physical_operator.h"
#include "common/log/log.h"
#include "sql/expr/tuple.h"
#include "storage/table/table.h"

using namespace std;

Tuple *fake_tuple = new ValueListTuple;

RC ProjectPhysicalOperator::open(Trx *trx)
{
  if (children_.empty()) {
    LOG_INFO("const select operator, no need to open child operator");
    return RC::SUCCESS;
  }

  PhysicalOperator *child = children_[0].get();
  RC                rc    = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC ProjectPhysicalOperator::next()
{
  if (children_.empty()) {
    if (!const_eof_) {
      const_eof_ = true;
      return RC::SUCCESS;
    } else {
      return RC::RECORD_EOF;
    }
  } else {
    return children_[0]->next();
  }
}

RC ProjectPhysicalOperator::close()
{
  RC rc;
  if (children_.empty()) {
    
  } else {
    rc = children_[0]->close();
    if (rc != RC::SUCCESS) {
      string child_name = children_[0]->name().c_str();
      LOG_WARN("failed to close child operator: rc=%s, child=%s", strrc(rc),child_name.c_str() );
      return rc;
    }
  }
  return RC::SUCCESS;
}
Tuple *ProjectPhysicalOperator::current_tuple()
{
  if (children_.empty()) {
    tuple_.set_tuple(fake_tuple);
  } else {
    tuple_.set_tuple(children_[0]->current_tuple());
  }
  return &tuple_;
}
