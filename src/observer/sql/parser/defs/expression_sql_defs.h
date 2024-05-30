#pragma once

#include "sql/expr/expr_type.h"
#include "sql/parser/value.h"
#include "sql_node_fwd.h"
#include "comp_op.h"

class ExpressionSqlNode
{
public:
  ExprType    expr_type = ExprType::NONE;
  std::string name;
};

class ValueExpressionSqlNode : public ExpressionSqlNode
{
public:
  Value value;

  ValueExpressionSqlNode() { ExpressionSqlNode::expr_type = ExprType::VALUE; }
};

class FieldExpressionSqlNode : public ExpressionSqlNode
{
public:
  RelAttrSqlNode field;

  FieldExpressionSqlNode() { ExpressionSqlNode::expr_type = ExprType::FIELD; }
};

class ArithmeticExpressionSqlNode : public ExpressionSqlNode
{
public:
  ExpressionSqlNode *left = nullptr;
  ExpressionSqlNode *right = nullptr;
  ArithmeticType     arithmetic_type;

  ArithmeticExpressionSqlNode() { ExpressionSqlNode::expr_type = ExprType::ARITHMETIC; }
  ~ArithmeticExpressionSqlNode() { delete left; left = nullptr; delete right; right = nullptr;}
};

class ComparisonExpressionSqlNode : public ExpressionSqlNode
{
public:
  ExpressionSqlNode *left = nullptr;
  ExpressionSqlNode *right = nullptr;
  CompOp             comp_op;

  ComparisonExpressionSqlNode() { ExpressionSqlNode::expr_type = ExprType::COMPARISON; }
  ~ComparisonExpressionSqlNode() { delete left; left = nullptr; delete right; right = nullptr;}
};

class ConjunctionExpressionSqlNode : public ExpressionSqlNode
{
public:
  ExpressionSqlNode *left = nullptr;
  ExpressionSqlNode *right = nullptr;
  ConjunctionType    conjunction_type;

  ConjunctionExpressionSqlNode() { ExpressionSqlNode::expr_type = ExprType::CONJUNCTION; }
  ~ConjunctionExpressionSqlNode() { delete left; left = nullptr; delete right; right = nullptr;}
};

class AggregateExpressionSqlNode : public ExpressionSqlNode
{
public:
  AggregateType      aggregate_type;
  ExpressionSqlNode *child = nullptr;

  AggregateExpressionSqlNode() { ExpressionSqlNode::expr_type = ExprType::AGGREGATE; }
  ~AggregateExpressionSqlNode() { delete child; child = nullptr;}
};

class CastExpressionSqlNode : public ExpressionSqlNode
{
  public:
  AttrType target_type;
  ExpressionSqlNode *child = nullptr;

  CastExpressionSqlNode() { ExpressionSqlNode::expr_type = ExprType::CAST; }
  ~CastExpressionSqlNode() { delete child; child = nullptr;}
};