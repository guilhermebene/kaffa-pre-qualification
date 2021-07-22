import Vue from 'vue'
import VueRouter from 'vue-router'
import Home from '../views/Home.vue'
import Ex4 from '../views/Ex4.vue'
import Ex5 from '../views/Ex5.vue'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'Home',
    component: Home
  },
  {
    path: '/about',
    name: 'About',
    // route level code-splitting
    // this generates a separate chunk (about.[hash].js) for this route
    // which is lazy-loaded when the route is visited.
    component: () => import(/* webpackChunkName: "about" */ '../views/About.vue')
  },
  {
    path: '/ex4',
    name: 'Ex4',
    component: Ex4
  },
  {
    path: '/ex5',
    name: 'Ex5',
    component: Ex5
  }
]

const router = new VueRouter({
  routes
})

export default router
