#ifndef PQUEUE_H
#define PQUEUE_H

#include <QQueue>
#include <QDebug>

template<class T>
class pQueue
{
public:
    /**
    * @brief priority queue constructor
    */
    pQueue()
    {}

    /**
    * @brief adds item to priority queue
    *
    * Adds item to priority queue
    *
    * @param priority
    * @param value
    */
    void enqueue(int priority,T value)
    {
        Item<T> item(priority, value);
        for(int i = 0 ; i < queue.count() ; ++i ) {
            const Item<T>& otherItem = queue[i];
            if( priority < otherItem.priority )  {
                queue.insert(i,item);
                return;
            }
        }
        queue.append(item);
    }

    /**
    * @brief gets first value in priority queue
    *
    * gets first value in priority queue
    *
    * @returns front value of priority queue
    */
    T getShortestTrip()
    {
        return queue.front().value;
    }

    /**
    * @brief gets lowest item in priority queue
    *
    * gets lowest item in priority queue
    *
    * @returns front priority of priority queue
    */
    int getLowestPriority()
    {
        return queue.front().priority;
    }

    /**
    * @brief dequeues item from priority queue
    *
    * dequeues item from priority queue
    *
    * @returns deleted value
    */
    T dequeue()
    {
        const Item<T>& item = queue.dequeue();
        return item.value;
    }

    /**
    * @brief gets count from priority queue
    *
    * gets count from priority queue
    *
    * @returns count
    */
    int count()
    {
        return queue.count();
    }

    /**
    * @brief prints priority queue
    *
    * prints priority queue
    *
    */
    void printQueue()
    {
        QQueue< Item<T > > tempQ = queue;
        while (tempQ.count() > 0)
        {
            qDebug() << "Priority:  " << tempQ.front().priority << "  Value:  " << tempQ.front().value;
            tempQ.dequeue();
        }
    }

private:

    /**
    * @brief struct for priority queue
    */
    template<class C>
    struct Item
    {
        /**
        * @brief item priority
        */
        int priority;

        /**
        * @brief item value
        */
        C value;

        /**
        * @brief struct constructor
        */
        Item(int priority, C value)
        {
            this->priority = priority;
            this->value = value;
        }
    };

    /**
    * @brief priority queue
    */
    QQueue<Item<T>> queue;
};


#endif // PQUEUE_H
