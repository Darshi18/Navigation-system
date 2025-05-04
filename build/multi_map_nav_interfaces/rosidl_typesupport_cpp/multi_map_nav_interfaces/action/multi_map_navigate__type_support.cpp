// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from multi_map_nav_interfaces:action/MultiMapNavigate.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MultiMapNavigate_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MultiMapNavigate_Goal_type_support_ids_t;

static const _MultiMapNavigate_Goal_type_support_ids_t _MultiMapNavigate_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MultiMapNavigate_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MultiMapNavigate_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MultiMapNavigate_Goal_type_support_symbol_names_t _MultiMapNavigate_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_Goal)),
  }
};

typedef struct _MultiMapNavigate_Goal_type_support_data_t
{
  void * data[2];
} _MultiMapNavigate_Goal_type_support_data_t;

static _MultiMapNavigate_Goal_type_support_data_t _MultiMapNavigate_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MultiMapNavigate_Goal_message_typesupport_map = {
  2,
  "multi_map_nav_interfaces",
  &_MultiMapNavigate_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_MultiMapNavigate_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_MultiMapNavigate_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MultiMapNavigate_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MultiMapNavigate_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_Goal>()
{
  return &::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_Goal)() {
  return get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MultiMapNavigate_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MultiMapNavigate_Result_type_support_ids_t;

static const _MultiMapNavigate_Result_type_support_ids_t _MultiMapNavigate_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MultiMapNavigate_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MultiMapNavigate_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MultiMapNavigate_Result_type_support_symbol_names_t _MultiMapNavigate_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_Result)),
  }
};

typedef struct _MultiMapNavigate_Result_type_support_data_t
{
  void * data[2];
} _MultiMapNavigate_Result_type_support_data_t;

static _MultiMapNavigate_Result_type_support_data_t _MultiMapNavigate_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MultiMapNavigate_Result_message_typesupport_map = {
  2,
  "multi_map_nav_interfaces",
  &_MultiMapNavigate_Result_message_typesupport_ids.typesupport_identifier[0],
  &_MultiMapNavigate_Result_message_typesupport_symbol_names.symbol_name[0],
  &_MultiMapNavigate_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MultiMapNavigate_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MultiMapNavigate_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_Result>()
{
  return &::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_Result)() {
  return get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MultiMapNavigate_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MultiMapNavigate_Feedback_type_support_ids_t;

static const _MultiMapNavigate_Feedback_type_support_ids_t _MultiMapNavigate_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MultiMapNavigate_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MultiMapNavigate_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MultiMapNavigate_Feedback_type_support_symbol_names_t _MultiMapNavigate_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_Feedback)),
  }
};

typedef struct _MultiMapNavigate_Feedback_type_support_data_t
{
  void * data[2];
} _MultiMapNavigate_Feedback_type_support_data_t;

static _MultiMapNavigate_Feedback_type_support_data_t _MultiMapNavigate_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MultiMapNavigate_Feedback_message_typesupport_map = {
  2,
  "multi_map_nav_interfaces",
  &_MultiMapNavigate_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_MultiMapNavigate_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_MultiMapNavigate_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MultiMapNavigate_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MultiMapNavigate_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_Feedback>()
{
  return &::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_Feedback)() {
  return get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MultiMapNavigate_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MultiMapNavigate_SendGoal_Request_type_support_ids_t;

static const _MultiMapNavigate_SendGoal_Request_type_support_ids_t _MultiMapNavigate_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MultiMapNavigate_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MultiMapNavigate_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MultiMapNavigate_SendGoal_Request_type_support_symbol_names_t _MultiMapNavigate_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_SendGoal_Request)),
  }
};

typedef struct _MultiMapNavigate_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _MultiMapNavigate_SendGoal_Request_type_support_data_t;

static _MultiMapNavigate_SendGoal_Request_type_support_data_t _MultiMapNavigate_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MultiMapNavigate_SendGoal_Request_message_typesupport_map = {
  2,
  "multi_map_nav_interfaces",
  &_MultiMapNavigate_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MultiMapNavigate_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MultiMapNavigate_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MultiMapNavigate_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MultiMapNavigate_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Request>()
{
  return &::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_SendGoal_Request)() {
  return get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MultiMapNavigate_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MultiMapNavigate_SendGoal_Response_type_support_ids_t;

static const _MultiMapNavigate_SendGoal_Response_type_support_ids_t _MultiMapNavigate_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MultiMapNavigate_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MultiMapNavigate_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MultiMapNavigate_SendGoal_Response_type_support_symbol_names_t _MultiMapNavigate_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_SendGoal_Response)),
  }
};

typedef struct _MultiMapNavigate_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _MultiMapNavigate_SendGoal_Response_type_support_data_t;

static _MultiMapNavigate_SendGoal_Response_type_support_data_t _MultiMapNavigate_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MultiMapNavigate_SendGoal_Response_message_typesupport_map = {
  2,
  "multi_map_nav_interfaces",
  &_MultiMapNavigate_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MultiMapNavigate_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MultiMapNavigate_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MultiMapNavigate_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MultiMapNavigate_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Response>()
{
  return &::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_SendGoal_Response)() {
  return get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MultiMapNavigate_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MultiMapNavigate_SendGoal_type_support_ids_t;

static const _MultiMapNavigate_SendGoal_type_support_ids_t _MultiMapNavigate_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MultiMapNavigate_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MultiMapNavigate_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MultiMapNavigate_SendGoal_type_support_symbol_names_t _MultiMapNavigate_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_SendGoal)),
  }
};

typedef struct _MultiMapNavigate_SendGoal_type_support_data_t
{
  void * data[2];
} _MultiMapNavigate_SendGoal_type_support_data_t;

static _MultiMapNavigate_SendGoal_type_support_data_t _MultiMapNavigate_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MultiMapNavigate_SendGoal_service_typesupport_map = {
  2,
  "multi_map_nav_interfaces",
  &_MultiMapNavigate_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_MultiMapNavigate_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_MultiMapNavigate_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MultiMapNavigate_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MultiMapNavigate_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal>()
{
  return &::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MultiMapNavigate_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MultiMapNavigate_GetResult_Request_type_support_ids_t;

static const _MultiMapNavigate_GetResult_Request_type_support_ids_t _MultiMapNavigate_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MultiMapNavigate_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MultiMapNavigate_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MultiMapNavigate_GetResult_Request_type_support_symbol_names_t _MultiMapNavigate_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_GetResult_Request)),
  }
};

typedef struct _MultiMapNavigate_GetResult_Request_type_support_data_t
{
  void * data[2];
} _MultiMapNavigate_GetResult_Request_type_support_data_t;

static _MultiMapNavigate_GetResult_Request_type_support_data_t _MultiMapNavigate_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MultiMapNavigate_GetResult_Request_message_typesupport_map = {
  2,
  "multi_map_nav_interfaces",
  &_MultiMapNavigate_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MultiMapNavigate_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MultiMapNavigate_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MultiMapNavigate_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MultiMapNavigate_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Request>()
{
  return &::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_GetResult_Request)() {
  return get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MultiMapNavigate_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MultiMapNavigate_GetResult_Response_type_support_ids_t;

static const _MultiMapNavigate_GetResult_Response_type_support_ids_t _MultiMapNavigate_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MultiMapNavigate_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MultiMapNavigate_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MultiMapNavigate_GetResult_Response_type_support_symbol_names_t _MultiMapNavigate_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_GetResult_Response)),
  }
};

typedef struct _MultiMapNavigate_GetResult_Response_type_support_data_t
{
  void * data[2];
} _MultiMapNavigate_GetResult_Response_type_support_data_t;

static _MultiMapNavigate_GetResult_Response_type_support_data_t _MultiMapNavigate_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MultiMapNavigate_GetResult_Response_message_typesupport_map = {
  2,
  "multi_map_nav_interfaces",
  &_MultiMapNavigate_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MultiMapNavigate_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MultiMapNavigate_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MultiMapNavigate_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MultiMapNavigate_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Response>()
{
  return &::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_GetResult_Response)() {
  return get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MultiMapNavigate_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MultiMapNavigate_GetResult_type_support_ids_t;

static const _MultiMapNavigate_GetResult_type_support_ids_t _MultiMapNavigate_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MultiMapNavigate_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MultiMapNavigate_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MultiMapNavigate_GetResult_type_support_symbol_names_t _MultiMapNavigate_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_GetResult)),
  }
};

typedef struct _MultiMapNavigate_GetResult_type_support_data_t
{
  void * data[2];
} _MultiMapNavigate_GetResult_type_support_data_t;

static _MultiMapNavigate_GetResult_type_support_data_t _MultiMapNavigate_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MultiMapNavigate_GetResult_service_typesupport_map = {
  2,
  "multi_map_nav_interfaces",
  &_MultiMapNavigate_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_MultiMapNavigate_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_MultiMapNavigate_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MultiMapNavigate_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MultiMapNavigate_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_GetResult>()
{
  return &::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _MultiMapNavigate_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MultiMapNavigate_FeedbackMessage_type_support_ids_t;

static const _MultiMapNavigate_FeedbackMessage_type_support_ids_t _MultiMapNavigate_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MultiMapNavigate_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MultiMapNavigate_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MultiMapNavigate_FeedbackMessage_type_support_symbol_names_t _MultiMapNavigate_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_FeedbackMessage)),
  }
};

typedef struct _MultiMapNavigate_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _MultiMapNavigate_FeedbackMessage_type_support_data_t;

static _MultiMapNavigate_FeedbackMessage_type_support_data_t _MultiMapNavigate_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MultiMapNavigate_FeedbackMessage_message_typesupport_map = {
  2,
  "multi_map_nav_interfaces",
  &_MultiMapNavigate_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_MultiMapNavigate_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_MultiMapNavigate_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MultiMapNavigate_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MultiMapNavigate_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_FeedbackMessage>()
{
  return &::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate_FeedbackMessage)() {
  return get_message_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace multi_map_nav_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t MultiMapNavigate_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace multi_map_nav_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate>()
{
  using ::multi_map_nav_interfaces::action::rosidl_typesupport_cpp::MultiMapNavigate_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  MultiMapNavigate_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::multi_map_nav_interfaces::action::MultiMapNavigate::Impl::SendGoalService>();
  MultiMapNavigate_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::multi_map_nav_interfaces::action::MultiMapNavigate::Impl::GetResultService>();
  MultiMapNavigate_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::multi_map_nav_interfaces::action::MultiMapNavigate::Impl::CancelGoalService>();
  MultiMapNavigate_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::multi_map_nav_interfaces::action::MultiMapNavigate::Impl::FeedbackMessage>();
  MultiMapNavigate_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::multi_map_nav_interfaces::action::MultiMapNavigate::Impl::GoalStatusMessage>();
  return &MultiMapNavigate_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, multi_map_nav_interfaces, action, MultiMapNavigate)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<multi_map_nav_interfaces::action::MultiMapNavigate>();
}

#ifdef __cplusplus
}
#endif
