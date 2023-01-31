#include <cstring>
#include <functional>
#include <memory>
#include <ostream>
#include <queue>
#include <vector>

enum VisitState: uint8_t
{
    NOT_VISITED = 0,
    BEING_VISITED = 1,
    VISITED = 2
};

template<class T> class SimpleGraph;

template<class T>
class SimpleGraphNode : public std::enable_shared_from_this<SimpleGraphNode<T> >
{

public:
    typedef T value_type;

    std::shared_ptr<SimpleGraphNode<T> > getptr()
    {
        return this->shared_from_this();
    }

    friend std::ostream& operator<<(std::ostream &out, std::shared_ptr<SimpleGraphNode<T> > node)
    {
        out << node->getValue();
        return out;
    }

protected:
    [[nodiscard]] static std::shared_ptr<SimpleGraphNode<T> > create(const T value, const size_t index)
    {
        return std::shared_ptr<SimpleGraphNode<T> >(new SimpleGraphNode<T>(value, index));
    }

    inline void addAdjacent(std::shared_ptr<SimpleGraphNode<T> > &toNode)
    {
        m_adjacents.push_back(toNode);
    }    

    inline size_t getIndex() const { return m_index; }

    inline T getValue() const { return m_value; }

    inline const std::vector<std::shared_ptr<SimpleGraphNode<T> > >& getAdjacents() const { return m_adjacents; }

private:
    explicit SimpleGraphNode(const T value, size_t index) :
        m_value(value), m_index(index)
    {}

    T m_value;

    size_t m_index;

    std::vector<std::shared_ptr<SimpleGraphNode<T> > > m_adjacents;

    friend class SimpleGraph<T>;
};

template<class T>
class SimpleGraph 
{

public:
    SimpleGraph() = default;

    std::shared_ptr<SimpleGraphNode<T> > addVertice(const T value)
    {
        auto index = m_vertices.size();
        auto node = SimpleGraphNode<T>::create(value, index);
        m_vertices.push_back(node);
        m_visitState.emplace_back();

        return node;
    }

    void addEdge(std::shared_ptr<SimpleGraphNode<T> > &fromNode, 
                 std::shared_ptr<SimpleGraphNode<T> > &toNode)
    {
        fromNode->addAdjacent(toNode);
    }

    void dfs(std::function<void(std::shared_ptr<SimpleGraphNode<T> >)> visitFunc)
    {
        if (!m_vertices.empty())
        {
           dfs(m_vertices.front(), visitFunc); 
        }     
        std::memset(m_visitState.data(), 0, m_vertices.size() * sizeof(uint8_t));
    }

    void bfs(std::function<void(std::shared_ptr<SimpleGraphNode<T> >)> visitFunc)
    {
        if (!m_vertices.empty())
        {
           bfs(m_vertices.front(), visitFunc); 
        }     
        std::memset(m_visitState.data(), 0, m_vertices.size() * sizeof(uint8_t));
    }

private:
    SimpleGraph(const SimpleGraph&);
    SimpleGraph(const SimpleGraph&&);
    SimpleGraph& operator=(const SimpleGraph);
    SimpleGraph& operator=(const SimpleGraph&&);

    void dfs(std::shared_ptr<SimpleGraphNode<T> > node, 
             std::function<void(const std::shared_ptr<SimpleGraphNode<T> >)> visitFunc)
    {
        visitFunc(node);
        m_visitState[node->getIndex()] = VisitState::VISITED;
        for (const auto adjacent: node->getAdjacents())
        {
            if (m_visitState[adjacent->getIndex()] == VisitState::NOT_VISITED)
            {
                m_visitState[adjacent->getIndex()] = VisitState::BEING_VISITED;
                dfs(adjacent, visitFunc);
            }
        }
    }

    void bfs(std::shared_ptr<SimpleGraphNode<T> > node, 
             std::function<void(const std::shared_ptr<SimpleGraphNode<T> >)> visitFunc)
    {
        std::queue<std::shared_ptr<SimpleGraphNode<T> > > nodeQueue;
        nodeQueue.push(node);
        while (!nodeQueue.empty())
        {
            const auto current = nodeQueue.front();
            nodeQueue.pop();
            visitFunc(current);
            m_visitState[current->getIndex()] = VisitState::VISITED;
            for (const auto adjacent: current->getAdjacents())
            {
                if (m_visitState[adjacent->getIndex()] == VisitState::NOT_VISITED)
                {
                    m_visitState[adjacent->getIndex()] = VisitState::BEING_VISITED;
                    nodeQueue.push(adjacent);
                }
            }
        }
    }

    std::vector<std::shared_ptr<SimpleGraphNode<T> > > m_vertices;

    std::vector<VisitState> m_visitState;
};