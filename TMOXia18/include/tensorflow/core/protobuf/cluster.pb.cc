// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cluster.proto

#include "cluster.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_cluster_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_JobDef_cluster_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_cluster_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_JobDef_TasksEntry_DoNotUse_cluster_2eproto;
namespace tensorflow {
class JobDef_TasksEntry_DoNotUseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<JobDef_TasksEntry_DoNotUse> _instance;
} _JobDef_TasksEntry_DoNotUse_default_instance_;
class JobDefDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<JobDef> _instance;
} _JobDef_default_instance_;
class ClusterDefDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ClusterDef> _instance;
} _ClusterDef_default_instance_;
}  // namespace tensorflow
static void InitDefaultsscc_info_ClusterDef_cluster_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::tensorflow::_ClusterDef_default_instance_;
    new (ptr) ::tensorflow::ClusterDef();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::tensorflow::ClusterDef::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ClusterDef_cluster_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsscc_info_ClusterDef_cluster_2eproto}, {
      &scc_info_JobDef_cluster_2eproto.base,}};

static void InitDefaultsscc_info_JobDef_cluster_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::tensorflow::_JobDef_default_instance_;
    new (ptr) ::tensorflow::JobDef();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::tensorflow::JobDef::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_JobDef_cluster_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsscc_info_JobDef_cluster_2eproto}, {
      &scc_info_JobDef_TasksEntry_DoNotUse_cluster_2eproto.base,}};

static void InitDefaultsscc_info_JobDef_TasksEntry_DoNotUse_cluster_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::tensorflow::_JobDef_TasksEntry_DoNotUse_default_instance_;
    new (ptr) ::tensorflow::JobDef_TasksEntry_DoNotUse();
  }
  ::tensorflow::JobDef_TasksEntry_DoNotUse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_JobDef_TasksEntry_DoNotUse_cluster_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_JobDef_TasksEntry_DoNotUse_cluster_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_cluster_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_cluster_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_cluster_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_cluster_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::tensorflow::JobDef_TasksEntry_DoNotUse, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::tensorflow::JobDef_TasksEntry_DoNotUse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::tensorflow::JobDef_TasksEntry_DoNotUse, key_),
  PROTOBUF_FIELD_OFFSET(::tensorflow::JobDef_TasksEntry_DoNotUse, value_),
  0,
  1,
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::tensorflow::JobDef, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::tensorflow::JobDef, name_),
  PROTOBUF_FIELD_OFFSET(::tensorflow::JobDef, tasks_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::tensorflow::ClusterDef, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::tensorflow::ClusterDef, job_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::tensorflow::JobDef_TasksEntry_DoNotUse)},
  { 9, -1, sizeof(::tensorflow::JobDef)},
  { 16, -1, sizeof(::tensorflow::ClusterDef)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tensorflow::_JobDef_TasksEntry_DoNotUse_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tensorflow::_JobDef_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tensorflow::_ClusterDef_default_instance_),
};

const char descriptor_table_protodef_cluster_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rcluster.proto\022\ntensorflow\"r\n\006JobDef\022\014\n"
  "\004name\030\001 \001(\t\022,\n\005tasks\030\002 \003(\0132\035.tensorflow."
  "JobDef.TasksEntry\032,\n\nTasksEntry\022\013\n\003key\030\001"
  " \001(\005\022\r\n\005value\030\002 \001(\t:\0028\001\"-\n\nClusterDef\022\037\n"
  "\003job\030\001 \003(\0132\022.tensorflow.JobDefB\207\001\n\032org.t"
  "ensorflow.distruntimeB\rClusterProtosP\001ZU"
  "github.com/tensorflow/tensorflow/tensorf"
  "low/go/core/protobuf/for_core_protos_go_"
  "proto\370\001\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_cluster_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_cluster_2eproto_sccs[3] = {
  &scc_info_ClusterDef_cluster_2eproto.base,
  &scc_info_JobDef_cluster_2eproto.base,
  &scc_info_JobDef_TasksEntry_DoNotUse_cluster_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_cluster_2eproto_once;
static bool descriptor_table_cluster_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cluster_2eproto = {
  &descriptor_table_cluster_2eproto_initialized, descriptor_table_protodef_cluster_2eproto, "cluster.proto", 336,
  &descriptor_table_cluster_2eproto_once, descriptor_table_cluster_2eproto_sccs, descriptor_table_cluster_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_cluster_2eproto::offsets,
  file_level_metadata_cluster_2eproto, 3, file_level_enum_descriptors_cluster_2eproto, file_level_service_descriptors_cluster_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_cluster_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_cluster_2eproto), true);
namespace tensorflow {

// ===================================================================

JobDef_TasksEntry_DoNotUse::JobDef_TasksEntry_DoNotUse() {}
JobDef_TasksEntry_DoNotUse::JobDef_TasksEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
    : SuperType(arena) {}
void JobDef_TasksEntry_DoNotUse::MergeFrom(const JobDef_TasksEntry_DoNotUse& other) {
  MergeFromInternal(other);
}
::PROTOBUF_NAMESPACE_ID::Metadata JobDef_TasksEntry_DoNotUse::GetMetadata() const {
  return GetMetadataStatic();
}
void JobDef_TasksEntry_DoNotUse::MergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::Message& other) {
  ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom(other);
}


// ===================================================================

void JobDef::InitAsDefaultInstance() {
}
class JobDef::_Internal {
 public:
};

JobDef::JobDef()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.JobDef)
}
JobDef::JobDef(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
  _internal_metadata_(arena),
  tasks_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.JobDef)
}
JobDef::JobDef(const JobDef& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  tasks_.MergeFrom(from.tasks_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from.name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name(),
      GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(copy_constructor:tensorflow.JobDef)
}

void JobDef::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_JobDef_cluster_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

JobDef::~JobDef() {
  // @@protoc_insertion_point(destructor:tensorflow.JobDef)
  SharedDtor();
}

void JobDef::SharedDtor() {
  GOOGLE_DCHECK(GetArenaNoVirtual() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void JobDef::ArenaDtor(void* object) {
  JobDef* _this = reinterpret_cast< JobDef* >(object);
  (void)_this;
}
void JobDef::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void JobDef::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const JobDef& JobDef::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_JobDef_cluster_2eproto.base);
  return *internal_default_instance();
}


void JobDef::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.JobDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  tasks_.Clear();
  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* JobDef::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArenaNoVirtual(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(mutable_name(), ptr, ctx, "tensorflow.JobDef.name");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // map<int32, string> tasks = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(&tasks_, ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint8>(ptr) == 18);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool JobDef::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.JobDef)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string name = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), static_cast<int>(this->name().length()),
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE,
            "tensorflow.JobDef.name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // map<int32, string> tasks = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (18 & 0xFF)) {
          JobDef_TasksEntry_DoNotUse::Parser< ::PROTOBUF_NAMESPACE_ID::internal::MapField<
              JobDef_TasksEntry_DoNotUse,
              ::PROTOBUF_NAMESPACE_ID::int32, std::string,
              ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32,
              ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
              0 >,
            ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string > > parser(&tasks_);
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessageNoVirtual(
              input, &parser));
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
            parser.value().data(), static_cast<int>(parser.value().length()),
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE,
            "tensorflow.JobDef.TasksEntry.value"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tensorflow.JobDef)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.JobDef)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void JobDef::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.JobDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tensorflow.JobDef.name");
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->name(), output);
  }

  // map<int32, string> tasks = 2;
  if (!this->tasks().empty()) {
    typedef ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_pointer
        ConstPtr;
    typedef ::PROTOBUF_NAMESPACE_ID::internal::SortItem< ::PROTOBUF_NAMESPACE_ID::int32, ConstPtr > SortItem;
    typedef ::PROTOBUF_NAMESPACE_ID::internal::CompareByFirstField<SortItem> Less;
    struct Utf8Check {
      static void Check(ConstPtr p) {
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
          p->second.data(), static_cast<int>(p->second.length()),
          ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
          "tensorflow.JobDef.TasksEntry.value");
      }
    };

    if (output->IsSerializationDeterministic() &&
        this->tasks().size() > 1) {
      ::std::unique_ptr<SortItem[]> items(
          new SortItem[this->tasks().size()]);
      typedef ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::size_type size_type;
      size_type n = 0;
      for (::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_iterator
          it = this->tasks().begin();
          it != this->tasks().end(); ++it, ++n) {
        items[static_cast<ptrdiff_t>(n)] = SortItem(&*it);
      }
      ::std::sort(&items[0], &items[static_cast<ptrdiff_t>(n)], Less());
      for (size_type i = 0; i < n; i++) {
        JobDef_TasksEntry_DoNotUse::Funcs::SerializeToCodedStream(2, items[static_cast<ptrdiff_t>(i)].second->first, items[static_cast<ptrdiff_t>(i)].second->second, output);
        Utf8Check::Check(&(*items[static_cast<ptrdiff_t>(i)].second));
      }
    } else {
      for (::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_iterator
          it = this->tasks().begin();
          it != this->tasks().end(); ++it) {
        JobDef_TasksEntry_DoNotUse::Funcs::SerializeToCodedStream(2, it->first, it->second, output);
        Utf8Check::Check(&(*it));
      }
    }
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:tensorflow.JobDef)
}

::PROTOBUF_NAMESPACE_ID::uint8* JobDef::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.JobDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tensorflow.JobDef.name");
    target =
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // map<int32, string> tasks = 2;
  if (!this->tasks().empty()) {
    typedef ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_pointer
        ConstPtr;
    typedef ::PROTOBUF_NAMESPACE_ID::internal::SortItem< ::PROTOBUF_NAMESPACE_ID::int32, ConstPtr > SortItem;
    typedef ::PROTOBUF_NAMESPACE_ID::internal::CompareByFirstField<SortItem> Less;
    struct Utf8Check {
      static void Check(ConstPtr p) {
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
          p->second.data(), static_cast<int>(p->second.length()),
          ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
          "tensorflow.JobDef.TasksEntry.value");
      }
    };

    if (false &&
        this->tasks().size() > 1) {
      ::std::unique_ptr<SortItem[]> items(
          new SortItem[this->tasks().size()]);
      typedef ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::size_type size_type;
      size_type n = 0;
      for (::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_iterator
          it = this->tasks().begin();
          it != this->tasks().end(); ++it, ++n) {
        items[static_cast<ptrdiff_t>(n)] = SortItem(&*it);
      }
      ::std::sort(&items[0], &items[static_cast<ptrdiff_t>(n)], Less());
      for (size_type i = 0; i < n; i++) {
        target = JobDef_TasksEntry_DoNotUse::Funcs::SerializeToArray(2, items[static_cast<ptrdiff_t>(i)].second->first, items[static_cast<ptrdiff_t>(i)].second->second, target);
        Utf8Check::Check(&(*items[static_cast<ptrdiff_t>(i)].second));
      }
    } else {
      for (::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_iterator
          it = this->tasks().begin();
          it != this->tasks().end(); ++it) {
        target = JobDef_TasksEntry_DoNotUse::Funcs::SerializeToArray(2, it->first, it->second, target);
        Utf8Check::Check(&(*it));
      }
    }
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.JobDef)
  return target;
}

size_t JobDef::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.JobDef)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // map<int32, string> tasks = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(this->tasks_size());
  for (::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_iterator
      it = this->tasks().begin();
      it != this->tasks().end(); ++it) {
    total_size += JobDef_TasksEntry_DoNotUse::Funcs::ByteSizeLong(it->first, it->second);
  }

  // string name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->name());
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void JobDef::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.JobDef)
  GOOGLE_DCHECK_NE(&from, this);
  const JobDef* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<JobDef>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.JobDef)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.JobDef)
    MergeFrom(*source);
  }
}

void JobDef::MergeFrom(const JobDef& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.JobDef)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  tasks_.MergeFrom(from.tasks_);
  if (from.name().size() > 0) {
    set_name(from.name());
  }
}

void JobDef::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.JobDef)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void JobDef::CopyFrom(const JobDef& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.JobDef)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool JobDef::IsInitialized() const {
  return true;
}

void JobDef::InternalSwap(JobDef* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  tasks_.Swap(&other->tasks_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata JobDef::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void ClusterDef::InitAsDefaultInstance() {
}
class ClusterDef::_Internal {
 public:
};

ClusterDef::ClusterDef()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.ClusterDef)
}
ClusterDef::ClusterDef(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
  _internal_metadata_(arena),
  job_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.ClusterDef)
}
ClusterDef::ClusterDef(const ClusterDef& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      job_(from.job_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:tensorflow.ClusterDef)
}

void ClusterDef::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ClusterDef_cluster_2eproto.base);
}

ClusterDef::~ClusterDef() {
  // @@protoc_insertion_point(destructor:tensorflow.ClusterDef)
  SharedDtor();
}

void ClusterDef::SharedDtor() {
  GOOGLE_DCHECK(GetArenaNoVirtual() == nullptr);
}

void ClusterDef::ArenaDtor(void* object) {
  ClusterDef* _this = reinterpret_cast< ClusterDef* >(object);
  (void)_this;
}
void ClusterDef::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ClusterDef::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ClusterDef& ClusterDef::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ClusterDef_cluster_2eproto.base);
  return *internal_default_instance();
}


void ClusterDef::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.ClusterDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  job_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* ClusterDef::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArenaNoVirtual(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .tensorflow.JobDef job = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(add_job(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint8>(ptr) == 10);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool ClusterDef::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.ClusterDef)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .tensorflow.JobDef job = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
                input, add_job()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tensorflow.ClusterDef)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.ClusterDef)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void ClusterDef::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.ClusterDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .tensorflow.JobDef job = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->job_size()); i < n; i++) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessageMaybeToArray(
      1,
      this->job(static_cast<int>(i)),
      output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:tensorflow.ClusterDef)
}

::PROTOBUF_NAMESPACE_ID::uint8* ClusterDef::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.ClusterDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .tensorflow.JobDef job = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->job_size()); i < n; i++) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->job(static_cast<int>(i)), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.ClusterDef)
  return target;
}

size_t ClusterDef::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.ClusterDef)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .tensorflow.JobDef job = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->job_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          this->job(static_cast<int>(i)));
    }
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ClusterDef::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.ClusterDef)
  GOOGLE_DCHECK_NE(&from, this);
  const ClusterDef* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ClusterDef>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.ClusterDef)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.ClusterDef)
    MergeFrom(*source);
  }
}

void ClusterDef::MergeFrom(const ClusterDef& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.ClusterDef)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  job_.MergeFrom(from.job_);
}

void ClusterDef::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.ClusterDef)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ClusterDef::CopyFrom(const ClusterDef& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.ClusterDef)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClusterDef::IsInitialized() const {
  return true;
}

void ClusterDef::InternalSwap(ClusterDef* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  CastToBase(&job_)->InternalSwap(CastToBase(&other->job_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ClusterDef::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace tensorflow
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::tensorflow::JobDef_TasksEntry_DoNotUse* Arena::CreateMaybeMessage< ::tensorflow::JobDef_TasksEntry_DoNotUse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tensorflow::JobDef_TasksEntry_DoNotUse >(arena);
}
template<> PROTOBUF_NOINLINE ::tensorflow::JobDef* Arena::CreateMaybeMessage< ::tensorflow::JobDef >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tensorflow::JobDef >(arena);
}
template<> PROTOBUF_NOINLINE ::tensorflow::ClusterDef* Arena::CreateMaybeMessage< ::tensorflow::ClusterDef >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tensorflow::ClusterDef >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
