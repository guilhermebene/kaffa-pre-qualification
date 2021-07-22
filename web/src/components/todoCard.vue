<template>
    <div>
        <b-card
        :title="'TO-DO #' + index"
        style="max-width: 80rem;"
        align="center">
        <b-card-text>
        {{todo.content}}
        </b-card-text>

        <b-button variant="primary" @click="onClickDelete(todo)">Delete</b-button>
    </b-card>
    </div>
</template>

<script>

// import axios from 'axios';

export default {
    props: ['todo', 'index'],
    methods: {
        onclickDelete: function(todo){
            this.$emit('delete-todo', todo)
        }
    }
}
</script>
