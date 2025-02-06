#pragma once
#include <string>
#include <vector>
#include <stdint.h>

namespace Glypto
{
    enum class ShaderDataType : uint8_t
    {
        FLOAT,
        FLOAT2,
        FLOAT3,
        FLOAT4,
        MAT3,
        MAT4,
        INT,
        INT2,
        INT3,
        INT4,
        BOOL
    };

    static uint32_t SizeOfShaderDataType(ShaderDataType type)
    {
        switch (type)
        {
        case ShaderDataType::BOOL:
            return 1;
        case ShaderDataType::INT4:
            return 4 * 4;
        case ShaderDataType::INT3:
            return 4 * 3;
        case ShaderDataType::INT2:
            return 4 * 2;
        case ShaderDataType::INT:
            return 4;
        case ShaderDataType::MAT4:
            return 4 * 4 * 4;
        case ShaderDataType::MAT3:
            return 4 * 3 * 3;
        case ShaderDataType::FLOAT:
            return 4;
        case ShaderDataType::FLOAT2:
            return 4 * 2;
        case ShaderDataType::FLOAT3:
            return 4 * 3;
        case ShaderDataType::FLOAT4:
            return 4 * 4;
        default:
            return 0;
        }
    }

    static uint32_t CountOfShaderDataType(ShaderDataType type)
    {
        switch (type)
        {
        case ShaderDataType::BOOL:
            return 1;
        case ShaderDataType::INT4:
            return 4;
        case ShaderDataType::INT3:
            return 3;
        case ShaderDataType::INT2:
            return 2;
        case ShaderDataType::INT:
            return 1;
        case ShaderDataType::MAT4:
            return 4 * 4;
        case ShaderDataType::MAT3:
            return 3 * 3;
        case ShaderDataType::FLOAT:
            return 1;
        case ShaderDataType::FLOAT2:
            return 2;
        case ShaderDataType::FLOAT3:
            return 3;
        case ShaderDataType::FLOAT4:
            return 4;
        default:
            return 0;
        }
    }

    struct BufferElement
    {
        std::string name;
        ShaderDataType data_type;
        uint32_t offset;
        uint32_t size;
        uint8_t normalized;

        BufferElement(const std::string &name, ShaderDataType type)
            : name(name), data_type(type), size(SizeOfShaderDataType(type)), offset(0), normalized(0)
        {
        }
    };

    class BufferLayout
    {
    public:
        BufferLayout() {}
        BufferLayout(const std::initializer_list<BufferElement> &elements) : m_Elements(elements)
        {
            uint32_t offset = 0;
            m_Stride = 0;
            for (BufferElement& element : m_Elements)
            {
                element.offset = offset;
                offset += element.size;
                m_Stride += element.size;
            }
        }
        inline const std::vector<BufferElement> &GetElements() const { return m_Elements; }
        inline const uint32_t &GetStride() const { return m_Stride; }

    private:
        uint32_t m_Stride;
        std::vector<BufferElement> m_Elements;
    };

    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() {}
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void SetLayout(const BufferLayout &layout) = 0;
        virtual const BufferLayout &GetLayout() const = 0;

        static VertexBuffer *Create(float *vertices, uint32_t size);
    };

    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() {}

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        virtual uint32_t GetCount() = 0;

        static IndexBuffer *Create(uint32_t *indices, uint32_t size);
    };

}