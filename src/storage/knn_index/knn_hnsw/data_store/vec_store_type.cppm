// Copyright(C) 2023 InfiniFlow, Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

module;

export module vec_store_type;

import stl;
import plain_vec_store;
import lvq_vec_store;
import dist_func_l2;
import dist_func_ip;

namespace infinity {

export template <typename DataT>
class PlainL2VecStoreType {
public:
    using DataType = DataT;
    using Meta = PlainVecStoreMeta<DataType>;
    using Inner = PlainVecStoreInner<DataType>;
    using StoreType = typename Meta::StoreType;
    using QueryType = typename Meta::QueryType;
    using Distance = PlainL2Dist<DataType>;
};

export template <typename DataT>
class PlainIPVecStoreType {
public:
    using DataType = DataT;
    using Meta = PlainVecStoreMeta<DataType>;
    using Inner = PlainVecStoreInner<DataType>;
    using StoreType = typename Meta::StoreType;
    using QueryType = typename Meta::QueryType;
    using Distance = PlainIPDist<DataType>;
};

export template <typename DataT, typename CompressT>
class LVQL2VecStoreType {
public:
    using DataType = DataT;
    using CompressType = CompressT;
    using Meta = LVQVecStoreMeta<DataType, CompressType, LVQL2Cache<DataType, CompressType>>;
    using Inner = LVQVecStoreInner<DataType, CompressType, LVQL2Cache<DataType, CompressType>>;
    using StoreType = typename Meta::StoreType;
    using QueryType = typename Meta::QueryType;
    using Distance = LVQL2Dist<DataType, CompressType>;
};

export template <typename DataT, typename CompressT>
class LVQIPVecStoreType {
public:
    using DataType = DataT;
    using CompressType = CompressT;
    using Meta = LVQVecStoreMeta<DataType, CompressType, LVQIPCache<DataType, CompressType>>;
    using Inner = LVQVecStoreInner<DataType, CompressType, LVQIPCache<DataType, CompressType>>;
    using StoreType = typename Meta::StoreType;
    using QueryType = typename Meta::QueryType;
    using Distance = LVQIPDist<DataType, CompressType>;
};

} // namespace infinity
